% close all
% clear all

GPS_SIMUL = 0;      % (1/0) adds offset to pos_cam
GPS_MAG_SIMUL = 0;  % (1/0) adds beta!=0 to mag simulation

D=320*0.5;
N=240*0.5;	% # of splines
T=0.01;% resolution per spline (0.1 = 10 intermediate samples)

%% attitude
x=(rand(1,N)-0.5)*1.5;
y=(rand(1,N)-0.5)*1.5;
z=(rand(1,N)-0.5)*1.5;

F=spline((0:D/(N-1):D),[x;y;z]);

% Trajectory
t=0:T:D;
origtime = t;
Ft=ppval(F,t);

% figure(11)
% clf
% hold on
% 	plot3(Ft(1,:),Ft(2,:),Ft(3,:),'b');
% 	plot3(x,y,z,'ro');
% hold off

origq = rpy2quat(Ft);
origdq = quat2rotvel(mul_quat(diag([1 -1 -1 -1])*origq,origq(:,[2:end end])))./T;


%% position
x=(rand(1,N)-0.5)*5;    %5,2.5,1.5 for 3.3,2.0,1.0 acc RMS
y=(rand(1,N)-0.5)*5;
z=(rand(1,N)-0.5)*5;

F=spline((0:D/(N-1):D),[x;y;z]);
dF=fnder(F,1);
iF=fnint(F);
% F = spapi(6,(0:D/(N-1):D),[x;y;z]);
% dF = fnder(F,1);
% ddF =fnder(F,2);

% Trajectory
t=0:T:D;
Ft=ppval(F,t);
dFt=ppval(dF,t);
iFt=ppval(iF,t);
% iFt=fnval(F,t);
% Ft=fnval(dF,t);
% dFt=fnval(ddF,t);

% figure(10)
% clf
% hold on
% 	plot3(Ft(1,:),Ft(2,:),Ft(3,:),'b');
% 	plot3(x,y,z,'ro');
% hold off

origpos = iFt;%Ft;		%take integrated splines as pos
origvel = Ft;%dFt;		%to avoid piecewise linear accelerations
origacc = dFt;%ddFt;

%% adjust data to different frames
camsample = 1;
g = [0 0 9.8]';
q_ic = rpy2quat([0 0 0]');	%[0 0 1 0]';	% rot imu->cam
p_ic = [0 0 0]';			% distance imu->cam in imu frame
q_im = rpy2quat(0,0,0);
%%% drift vision world
qvwsamples = floor(size(origq,2)/camsample);
q_vw = repmat(rpy2quat([0 0 0]'),1,qvwsamples);
% rpy controlled drift, careful with pi/2, pi overpassings....
driftq = cumsum(repmat([0 0 0]',1,qvwsamples),2);
q_vw = rpy2quat(quat2rpy(q_vw)+driftq);
% kind of random drift in all rpy, use with magnetometer...
% driftq = cumsum(repmat([1/5000*pi -1/4000*pi 1/6000*pi*0]',1,qvwsamples),2);
% q_vw = mul_quat(q_vw,rpy2quat(driftq));

q_vw = [interp1(origtime(1:camsample:end),q_vw(1,:),origtime,'nearest');
		interp1(origtime(1:camsample:end),q_vw(2,:),origtime,'nearest');
		interp1(origtime(1:camsample:end),q_vw(3,:),origtime,'nearest');
		interp1(origtime(1:camsample:end),q_vw(4,:),origtime,'nearest')];

att_imu = origq;
gyr_imu = origdq;
att_cam = diag([1 -1 -1 -1])*mul_quat(q_vw, mul_quat(att_imu, q_ic));
gyr_cam = quat2rot(q_ic)'*gyr_imu;

acc_imu = origacc+repmat(g,1,length(origacc));			% add gravity
acc_imu = quatrot(diag([1 -1 -1 -1])*att_imu,acc_imu); 	% in imu frame
vel_imu = origvel;	% in world frame
pos_imu = origpos;	% in world frame
pos_cam = quatrot(q_vw,pos_imu+quatrot(att_imu,p_ic));
vel_cam = origvel;
% pos_cam1 = zeros(3,size(q_vw,2));
% for i=1:size(q_vw,2)
%     pos_cam1(:,i) = quat2rot(q_vw(:,i))*(pos_imu(:,i)+quat2rot(att_imu(:,i))*p_ic);%+[1.2, -1.5, 2.1]';
% end
time_cam = origtime;
time_imu = origtime;

%% magnetometer
alpha = rand(1);
beta = rand(1)*GPS_MAG_SIMUL;
mag_vec =[sin(beta)*cos(alpha) cos(beta)*cos(alpha) sin(alpha)]';	
mag_vec=mag_vec/norm(mag_vec);
mag_imu = quat2rot(q_im)'*quatrot(diag([1 -1 -1 -1])*att_imu,mag_vec);
mag_imu = mag_imu + 0.01*randn(size(mag_imu));
% add magnetometer bias: only corrupts q_im in the filter :-)
mag_bias =[0 0 0]';%[0.2, -0.1, 0.15]'; % [0.02, -0.01, 0.015]';%[0 0 0]';
mag_imu = mag_imu + repmat(mag_bias,1,size(mag_imu,2));
bu = mag_imu.*mag_imu;
bu = sqrt(bu'*[1 1 1]');
mag_imu=mag_imu./bu(:,[1 1 1])';


%% GPS
p_vw = [1.1 -2.1 3.1]'*GPS_SIMUL;
pos_cam = pos_cam+p_vw(:,ones(size(pos_cam,2),1));   % visual position drift/bias
p_ig = [0.5 -1.1 1.5]';
gps = pos_imu + quatrot(att_imu,p_ig);
gps = gps + 0.5*randn(size(gps));


%% bias, noise and multirate

% add bias
gyr_bias = [0 0 0]';
acc_bias = [-0.1 -0.2 0.15]';
gyr_imu = gyr_imu + repmat(gyr_bias,1,length(gyr_imu));
acc_imu = acc_imu + repmat(acc_bias,1,length(acc_imu));

% add noise
att_cam = att_cam + 0.01*randn(size(att_cam));%0.08*randn(size(att_cam));
pos_cam = pos_cam + 0.01*randn(size(pos_cam));%1*randn(size(pos_cam));
gyr_imu = gyr_imu + 0.0013*randn(size(gyr_imu));
acc_imu = acc_imu + 0.083*randn(size(acc_imu));
att_imu = att_imu + 0.01*randn(size(att_imu));

% multi rate cam vs imu
buff = 1:length(time_cam);
idxbuff = buff(mod(buff,camsample)-1~=0);
time_cam(idxbuff)=[];
pos_cam(:,idxbuff)=[];
att_cam(:,idxbuff)=[];
gyr_cam(:,idxbuff)=[];
q_vw(:,idxbuff)=[];
mag_imu(:,idxbuff)=[];
gps(:,idxbuff)=[];

acc_cam = [diff(pos_cam,2,2) [0 0;0 0;0 0]];

% add scale
% scale = max(0.3,0.5 + repmat(cumsum(0.001*randn(1,size(pos_cam,2)),2),3,1));	% bounded random walk
scale = repmat(1, size(pos_cam));
% % % scale = repmat(0.5:0.5/(size(pos_cam,2)-1):1,3,1);
% % % scale = repmat(0.5+0.1*sin((0:size(pos_cam,2)-1)*(2*pi/8000)),3,1);
% scale=0.5;
pos_cam = pos_cam .* scale;

save simuldata camsample p_vw p_ig gps alpha beta q_im acc_cam mag_vec mag_imu time_cam pos_cam vel_cam att_cam gyr_cam time_imu pos_imu vel_imu acc_imu att_imu gyr_imu q_vw q_ic p_ic g gyr_bias acc_bias scale

display('simulation data generated');





