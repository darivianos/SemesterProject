close all
clear all

%% variable initialization

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% SIMULATION
STEP=0.01;
simuldata = load('simuldata.mat');%load('simuldata_hex_leica.mat');%load('simuldata_accRMS1-0Max3_gyrRMS0-5.mat');%load('simuldata_hex.mat');
ptam_time = simuldata.time_cam;%-0.03;
cb_time =simuldata.time_imu;
idx_ptam=100;
idx_ptam_start=idx_ptam;
idx=find(cb_time<ptam_time(idx_ptam));
idx_cb=idx(end);
idx_cb_start = idx_cb;
ptam_pos = simuldata.pos_cam';%-quatrot(diag([1 -1 -1 -1])*simuldata.att_cam,simuldata.pos_cam)';
ptam_att = simuldata.att_cam';
ptam_vel = simuldata.vel_cam';
cb_gyr = simuldata.gyr_imu';
cb_acc = simuldata.acc_imu';
t_start=ptam_time(idx_ptam);

g =simuldata.g;
q_ic = simuldata.q_ic; %[0 1 0 0]'; % attitude cam-modell
q_vw = [1 0 0 0]';
p_ic =simuldata.p_ic;               % pos cam-modell
b_a = simuldata.acc_bias;
b_w =  [0 0 0]';
L = 1;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%aux variables: buffers for 1st order integration: check init procedure....
ew_old=cb_gyr(idx_cb,:)';	% estimated rot velocity at t=k w=w_m-b_w
ea_old=cb_acc(idx_cb,:)';   % estimated acc at t=k

%state: check init procedure...	
v = [0 0 0]';                                                               % scaled vel in world
q = diag([1 -1 -1 -1])*mul_quat(q_ic,mul_quat(ptam_att(idx_ptam,:)',q_vw));	% world to imu
p = quat2rot(q_vw)'*ptam_pos(idx_ptam,:)'/L-quat2rot(q)*p_ic;               % scaled imu position in world
X = [p' v' q' b_w' b_a' L' p_ic' q_ic' q_vw']';

%error state
dp = [0 0 0]';       % scaled position error in world
dv = [0 0 0]';       % scaled vel error in world
dtheta = [0 0 0]';   % rotation error imu = q =dq*qhat, dq~0.5dTheta
db_w = [0 0 0]';     % rot bias error
db_a = [0 0 0]';     % acc bias error
dL = 0;              % scale factor error
dp_ic = [0 0 0]';	 % distance imu->cam error
dtheta_ic = [0 0 0]';% rotation imu->cam error q =dq*qhat, dq~0.5dTheta
dtheta_vw = [0 0 0]';% rotation vision->world error q =dq*qhat, dq~0.5dTheta
dx = [dp' dv' dtheta' db_w' db_a' dL' dtheta_vw']';

%error state covariance init:
P =load('Pinit_imuvis');
P = P.Pinit;
% delete rows/cols: 10:12, 16, 23:25
Pinit=P;    % save init for debug purpose

% EKF update variables init
K=0;
z_q=zeros(4,1);
r_theta=zeros(3,1);

%debug variables:
plotdebug=zeros(length(cb_time),28);
tdebug=zeros(length(cb_time),1);

%% Main Loop
for t=t_start:STEP:ptam_time(end)
	if t>cb_time(idx_cb)
        
        %user info
        if mod(t,10)<STEP
            clc
            display([num2str(t) ' of ' num2str(ptam_time(end)-t_start) ' seconds elapsed...']);
        end
	
		%read inputs
		w_m = cb_gyr(idx_cb,:)';
		a_m = cb_acc(idx_cb,:)'; 

		%get time
		dt = cb_time(idx_cb)-cb_time(idx_cb-1);
		
		%noise is dependent on time, sigma (NOT sigma^2)
		n_w=(4.5*pi/(180*60))*ones(3,1)/1;      % rot noise         rad^2/sec
% 		n_bw=n_w;                               % rot bias noise    rad^3/sec^2
		n_a=(0.5/60)*10*ones(3,1)/1;            % acc noise         m^2/sec^3
		n_ba=n_a;                               % acc bias noise    m^2/sec^5
% 		n_L=0.005;                              % scale noise: TODO: add timedep.
% 		n_qvw = 0.01;                           % vision world drift noise: TODO: add timedep.
		n_pic = 0.01;                           % imu-cam translation noise: TODO: add timedep.
        n_qic = 0.01;                           % imu-cam rotation noise: TODO: add timedep.
  
		%state propagation
% 		eb_w = b_w;
		eb_a = b_a;
% 		eL = L;
		ep_ic = p_ic;
		eq_ic = q_ic;
% 		eq_vw = q_vw;
		ew = w_m - eb_w;
		ea = a_m - eb_a;
		eq = (expm(1/2*quatskew([0;ew_old+ew]/2)*dt) +... 
				1/48*(quatskew([0;ew])*quatskew([0;ew_old])-quatskew([0;ew_old])*quatskew([0;ew]))*(dt^2)) *...
				q;
		ev = v + ((quat2rot(q)*ea_old + quat2rot(eq)*ea)/2 - g)*dt;
		ep = p + (v+ev)/2*dt;
				
		%Block parts of Fd and Qd:
		if norm(eq)>1.5
			display('eq has weird norm...quit');
			return
		end
		C_eq = quat2rot(eq)';
		Ca3 = C_eq'*skew(ea);
		ew_sk = skew(ew);
		A = Ca3*(-dt^2/2*eye(3) + dt^3/6*ew_sk - dt^4/24*ew_sk^2);
		B = Ca3*(dt^3/6*eye(3) - dt^4/24*ew_sk + dt^5/120*ew_sk^2);
		D = -A;
		E = eye(3) - dt*ew_sk + dt^2/2*ew_sk^2;
		F = -dt*eye(3) + dt^2/2*ew_sk - dt^3/6*(ew_sk^2);
 		C = Ca3*F;

		%discrete error state propagation Matrix Fd
		Fd(:,:) = eye(18);
		Fd(1:3,4:6) = dt*eye(3);
		Fd(1:3,7:9) = A;
		Fd(1:3,10:12) = B;
		Fd(1:3,13:15) = -C_eq'*dt^2/2;

		Fd(4:6,7:9) = C;
		Fd(4:6,10:12) = D;
		Fd(4:6,13:15) = -C_eq'*dt;

		Fd(7:9,7:9) = E;
		Fd(7:9,10:12) = F;		

		%discrete error state uncertainty propagation matrix Qd:
		Qd = zeros(18);
		Qd(1:3,1:3) = dt^3/3*C_eq'*diag(n_a.^2)*C_eq + dt^5/20*C_eq'*diag(n_ba.^2)*C_eq + calc_MdiagMtr(ew_sk,ew_sk^2,Ca3,diag(n_w.^2),dt,0) + calc_MdiagMtr(ew_sk,ew_sk^2,Ca3,diag(n_bw.^2),dt,1);
		Qd(1:3,4:6) = dt^2/2*C_eq'*diag(n_a.^2)*C_eq + dt^4/8*C_eq'*diag(n_ba.^2)*C_eq + calc_MdiagMtr(ew_sk,ew_sk^2,Ca3,diag(n_w.^2),dt,2) + calc_MdiagMtr(ew_sk,ew_sk^2,Ca3,diag(n_bw.^2),dt,3);
		Qd(1:3,7:9) = calc_MdiagMtr(ew_sk,ew_sk^2,Ca3,diag(n_w.^2),dt,4) + calc_MdiagMtr(ew_sk,ew_sk^2,Ca3,diag(n_bw.^2),dt,5);
		Qd(1:3,10:12) = calc_MdiagMtr(ew_sk,ew_sk^2,Ca3,diag(n_bw.^2),dt,6);
		Qd(1:3,13:15) = -dt^3/6*C_eq'*diag(n_ba.^2);
		
		Qd(4:6,1:3) = dt^2/2*C_eq'*diag(n_a.^2)*C_eq + dt^4/8*C_eq'*diag(n_ba.^2)*C_eq + calc_MdiagMtr(ew_sk,ew_sk^2,Ca3,diag(n_w.^2),dt,7) + calc_MdiagMtr(ew_sk,ew_sk^2,Ca3,diag(n_bw.^2),dt,8);
		Qd(4:6,4:6) = dt*C_eq'*diag(n_a.^2)*C_eq + dt^3/3*C_eq'*diag(n_ba.^2)*C_eq + calc_MdiagMtr(ew_sk,ew_sk^2,Ca3,diag(n_w.^2),dt,9) + calc_MdiagMtr(ew_sk,ew_sk^2,Ca3,diag(n_bw.^2),dt,10);
		Qd(4:6,7:9) = calc_MdiagMtr(ew_sk,ew_sk^2,Ca3,diag(n_w.^2),dt,11) + calc_MdiagMtr(ew_sk,ew_sk^2,Ca3,diag(n_bw.^2),dt,12);
		Qd(4:6,10:12) = calc_MdiagMtr(ew_sk,ew_sk^2,Ca3,diag(n_bw.^2),dt,13);
		Qd(4:6,13:15) = -dt^2/2*C_eq'*diag(n_ba.^2);
		
		Qd(7:9,1:3) = calc_MdiagMtr(ew_sk,ew_sk^2,Ca3,diag(n_w.^2),dt,14) + calc_MdiagMtr(ew_sk,ew_sk^2,Ca3,diag(n_bw.^2),dt,15);
		Qd(7:9,4:6) = calc_MdiagMtr(ew_sk,ew_sk^2,Ca3,diag(n_w.^2),dt,16) + calc_MdiagMtr(ew_sk,ew_sk^2,Ca3,diag(n_bw.^2),dt,17);
		Qd(7:9,7:9) = calc_MdiagMtr(ew_sk,ew_sk^2,Ca3,diag(n_w.^2),dt,18) + calc_MdiagMtr(ew_sk,ew_sk^2,Ca3,diag(n_bw.^2),dt,19);
		Qd(7:9,10:12) = calc_MdiagMtr(ew_sk,ew_sk^2,Ca3,diag(n_bw.^2),dt,20);
		
% 		Qd(10:12,1:3) = calc_MdiagMtr(ew_sk,ew_sk^2,Ca3,diag(n_bw.^2),dt,21);
% 		Qd(10:12,4:6) = calc_MdiagMtr(ew_sk,ew_sk^2,Ca3,diag(n_bw.^2),dt,22);
% 		Qd(10:12,7:9) = calc_MdiagMtr(ew_sk,ew_sk^2,Ca3,diag(n_bw.^2),dt,23);
% 		Qd(10:12,10:12) = dt*diag(n_bw.^2);
		
		Qd(10:12,1:3) = (-dt^3/6*diag(n_ba.^2)*C_eq);
		Qd(10:12,4:6) = -dt^2/2*diag(n_ba.^2)*C_eq;
		Qd(10:12,13:15) = dt*diag(n_ba.^2);
		
% 		Qd(16,16) = dt*n_L^2;
		
		Qd(13:15,17:19) = eye(3)*dt*n_pic^2;
		Qd(16:18,20:22) = eye(3)*dt*n_qic^2;
% 		Qd(19:21,23:25) = eye(3)*dt*n_qvw^2;
        
        % logging some data
        plotdebug(idx_cb-idx_cb_start+1,:) = [ep' ev' eq' eb_w' eb_a' eL' ep_ic' eq_ic' eq_vw'];
		tdebug(idx_cb-idx_cb_start+1,:)=cb_time(idx_cb);

		%error state error propagation:
		eP = Fd*P*Fd'+Qd;
		ew_old = ew;
		ea_old = ea;
		
		idx_cb=idx_cb+1;
	end

%%%%Update:

    if t>ptam_time(idx_ptam)
		%auxiliaries:
		z0 = zeros(3);
		C_vw = quat2rot(eq_vw)';
		C_eq = quat2rot(eq)';
		C_ic = quat2rot(eq_ic)';
		
		%measurements:
		z_p=ptam_pos(idx_ptam,:)';
		z_q=ptam_att(idx_ptam,:)';
		z_v=ptam_vel(idx_ptam,:)';

		%measurement noise: get from LBA error propagation
		n_p = [0.01 0.01 0.01]';        %position measurement noise in [m]
		n_q = [0.01 0.01 0.01]';        %attitude measurement noise (0.01=0.5degrees)
		n_v = [0.01 0.01 0.01]';        %velocity measurement noise in [m/s]
%         n_qvw = [0.001 0.001 0.001]';   %q_vw measurement noise (0.01=0.5degrees)
        
		%measurement matrix H:	
		%col:dp	dv	dtheta	db_w	db_a	dL	dp_ic dtheta_ic dtheta_vw
		H = [C_vw'*eL	z0		-C_vw'*C_eq'*skew(p_ic)*eL	z0 C_vw'*C_eq'*eL z0;
			 z0			z0			C_ic		z0 z0 eye(3);
			 z0			eye(3)			z0		z0 z0 z0;
			 ];	
% 		H = [C_vw'*eL	z0		-C_vw'*C_eq'*skew(p_ic)*eL	z0	z0	C_vw'*C_eq'*p_ic+C_vw'*ep C_vw'*C_eq'*eL z0 -C_vw'*skew((ep+C_eq'*p_ic)*eL);
% 			 z0			z0			z0		z0	z0	[0 0 0]' z0 eye(3) z0;
% 			 z0			z0			z0		z0	z0	[0 0 0]' z0 z0 eye(3);
% 			 ];	
         
		%measurement noise matrix R:
		R = [diag(n_p.^2)	z0 z0;
			 z0			diag(n_q.^2) z0;
			 z0			z0 diag(n_v.^2);
			];
% 		R = [diag(n_p.^2)	z0 z0;
% 			 z0			diag(n_q.^2) z0;
%             z0  	 z0 diag(n_q.^2);
% 			];

		%residual:
% 		dtm = ptam_time(idx_ptam)-ptam_time(idx_ptam-1);
		r_p = z_p - C_vw'*(ep + C_eq'*ep_ic)*eL;
		r_q = mul_quat(diag([1 -1 -1 -1])*mul_quat(q_vw,mul_quat(eq,eq_ic)),diag([1 -1 -1 -1])*z_q);
		r_theta=(r_q(2:4)/r_q(1))*2; %because dq=[1 1/2*dtheta]
        r_v = z_v - ev;
		
        r = [r_p;r_theta;r_v];

% 		r_qic = -(q_ic(2:4)/q_ic(1))*2;
% 		r_qvw = -(q_vw(2:4)/q_vw(1))*2;
% 		r = [r_p;r_qic;r_qvw];
		
		%update:
		S = H*eP*H'+R;
		K = eP*H'/S;
		dx = K*r;

		%error state correction vector:
		dp =	dx(1:3,1);
		dv =	dx(4:6,1);
		dtheta = dx(7:9,1);
		db_a =	dx(10:12,1);
		dp_ic = dx(13:15,1);
		dtheta_ic = dx(16:18,1);
		
		%state update:
		p = ep+dp;
		v = ev+dv;
		if(norm(dtheta/2)<1)
			q = mul_quat(eq,[sqrt(1-norm(dtheta/2)^2);dtheta/2]);
		else
			q = mul_quat(eq,[1;dtheta/2]/sqrt(1+norm(dtheta/2)^2));
		end
		q=renorm(q);
		if(norm(dtheta_ic/2)<1)
			q_ic = mul_quat(eq_ic,[sqrt(1-norm(dtheta_ic/2)^2);dtheta_ic/2]);
		else
			q_ic = mul_quat(eq_ic,[1;dtheta_ic/2]/sqrt(1+norm(dtheta_ic/2)^2));
		end
		q_ic=renorm(q_ic);
		b_a = eb_a+db_a;
		p_ic=ep_ic+dp_ic;

        %covariance update
		P = (eye(18)-K*H)*eP*(eye(18)-K*H)'+K*R*K';

		%save for idle mode:
		ep=p;
		ev=v;
		eq=q;
		eb_a=b_a;
		ep_ic = p_ic;
		eq_ic = q_ic;
		eP=P;
        
		idx_ptam=idx_ptam+1;

	else %no update took place, so just propagate the state
		p = ep;
		v = ev;
		q = eq;
		b_a = eb_a;
		p_ic = ep_ic;
		q_ic = eq_ic;
		P=eP;
    end
    
%     if t>100.2
%         break
%     end
end

%% plotting
plotdebug(idx_cb-idx_cb_start+1:end,:)=[];
tdebug(idx_cb-idx_cb_start+1:end)=[];
RMST = 10; %timespan to consider after convergence in seconds

figure(1); 
subplot(2,1,1); plot(tdebug,plotdebug(:,1:3));
hold on; plot(simuldata.time_imu(idx_cb_start:idx_cb-1),simuldata.pos_imu(:,idx_cb_start:idx_cb-1),'-'); hold off;
ylabel('position [m]')
subplot(2,1,2); plot(tdebug,simuldata.pos_imu(:,idx_cb_start:idx_cb-1)'-plotdebug(:,1:3));
ylabel('position error [m]')
title({['total rms: ' num2str(rms(simuldata.pos_imu(:,idx_cb_start:idx_cb-1)',plotdebug(:,1:3))) ' [m]'];...
        ['rms t-' num2str(RMST) 's: ' num2str(rms(simuldata.pos_imu(:,idx_cb-1-floor(RMST/STEP):idx_cb-1)',plotdebug(end-floor(RMST/STEP):end,1:3))) ' [m]']});

figure(2); 
subplot(2,1,1); plot(tdebug,plotdebug(:,4:6));
hold on; plot(simuldata.time_imu(idx_cb_start:idx_cb-1),simuldata.vel_imu(:,idx_cb_start:idx_cb-1),'-'); hold off;
ylabel('velocity [m/s]')
subplot(2,1,2); plot(tdebug,simuldata.vel_imu(:,idx_cb_start:idx_cb-1)'-plotdebug(:,4:6));
ylabel('velocity error [m/s]')
title({['total rms: ' num2str(rms(simuldata.vel_imu(:,idx_cb_start:idx_cb-1)',plotdebug(:,4:6))) ' [m/s]'];...
        ['rms t-' num2str(RMST) 's: ' num2str(rms(simuldata.vel_imu(:,idx_cb-1-floor(RMST/STEP):idx_cb-1)',plotdebug(end-floor(RMST/STEP):end,4:6))) ' [m/s]']});

figure(3); 
subplot(2,1,1); plot(tdebug,quat2rpy(plotdebug(:,7:10)')');
hold on; plot(simuldata.time_imu(idx_cb_start:idx_cb-1),quat2rpy(simuldata.att_imu(:,idx_cb_start:idx_cb-1)),'-'); hold off;
ylabel('attitude [rad]')
subplot(2,1,2); plot(tdebug,quat2rpy(mul_quat(simuldata.att_imu(:,idx_cb_start:idx_cb-1),diag([1 -1 -1 -1])*plotdebug(:,7:10)'))');
ylabel('attitude error [rad]')
title({['total rms: ' num2str(rms(quat2rpy(simuldata.att_imu(:,idx_cb_start:idx_cb-1))',quat2rpy(plotdebug(:,7:10)')')) ' [rad]'];...
        ['rms t-' num2str(RMST) 's: ' num2str(rms(quat2rpy(simuldata.att_imu(:,idx_cb-1-floor(RMST/STEP):idx_cb-1))',quat2rpy(plotdebug(end-floor(RMST/STEP):end,7:10)')')) ' [rad]']});

figure(4); 
subplot(2,1,1); plot(tdebug,plotdebug(:,11:13));
hold on; plot(simuldata.time_imu(idx_cb_start:idx_cb-1),simuldata.gyr_bias(:,ones(idx_cb-idx_cb_start,1)),'-'); hold off;
ylabel('gyr bias [rad/s]')
subplot(2,1,2); plot(tdebug,simuldata.gyr_bias(:,ones(idx_cb-idx_cb_start,1))'-plotdebug(:,11:13));
ylabel('gyr bias error [rad/s]')
title({['total rms: ' num2str(rms(simuldata.gyr_bias(:,ones(idx_cb-idx_cb_start,1))',plotdebug(:,11:13))) ' [rad/s]'];...
        ['rms t-' num2str(RMST) 's: ' num2str(rms(simuldata.gyr_bias(:,ones(floor(RMST/STEP)+1,1))',plotdebug(end-floor(RMST/STEP):end,11:13))) ' [rad/s]']});

figure(5); 
subplot(2,1,1); plot(tdebug,plotdebug(:,14:16));
hold on; plot(simuldata.time_imu(idx_cb_start:idx_cb-1),simuldata.acc_bias(:,ones(idx_cb-idx_cb_start,1)),'-'); hold off;
ylabel('acc bias [m/s^2]')
subplot(2,1,2); plot(tdebug,simuldata.acc_bias(:,ones(idx_cb-idx_cb_start,1))'-plotdebug(:,14:16));
ylabel('acc bias error [m/s^2]')
title({['total rms: ' num2str(rms(simuldata.acc_bias(:,ones(idx_cb-idx_cb_start,1))',plotdebug(:,14:16))) ' [m/s^2]'];...
        ['rms t-' num2str(RMST) 's: ' num2str(rms(simuldata.acc_bias(:,ones(floor(RMST/STEP)+1,1))',plotdebug(end-floor(RMST/STEP):end,14:16))) ' [m/s^2]']});

figure(6); 
subplot(2,1,1); plot(tdebug,plotdebug(:,17));
hold on; plot(simuldata.time_cam(idx_ptam_start:idx_ptam-1),simuldata.scale(1,idx_ptam_start:idx_ptam-1),'-'); hold off;
ylabel('scale')
subplot(2,1,2); plot(simuldata.time_cam(idx_ptam_start:idx_ptam-1),simuldata.scale(1,idx_ptam_start:idx_ptam-1)'-plotdebug(1:simuldata.camsample:end-1,17));
ylabel('scale error')
title({['total rms: ' num2str(rms(simuldata.scale(1,idx_ptam_start:idx_ptam-1)',plotdebug(1:simuldata.camsample:end-1,17)))];...
        ['rms t-' num2str(RMST) 's: ' num2str(rms(simuldata.scale(1,idx_ptam-floor(RMST/(STEP*simuldata.camsample))),plotdebug(end-floor(RMST/STEP):simuldata.camsample:end-1,17)))]});

figure(7); 
subplot(2,1,1); plot(tdebug,plotdebug(:,18:20));
hold on; plot(simuldata.time_imu(idx_cb_start:idx_cb-1),simuldata.p_ic(:,ones(idx_cb-idx_cb_start,1)),'-'); hold off;
ylabel('p imu-cam [m]')
subplot(2,1,2); plot(tdebug,simuldata.p_ic(:,ones(idx_cb-idx_cb_start,1))'-plotdebug(:,18:20));
ylabel('p imu-cam error [m]')
title({['total rms: ' num2str(rms(simuldata.p_ic(:,ones(idx_cb-idx_cb_start,1))',plotdebug(:,18:20))) ' [m]'];...
        ['rms t-' num2str(RMST) 's: ' num2str(rms(simuldata.p_ic(:,ones(floor(RMST/STEP)+1,1))',plotdebug(end-floor(RMST/STEP):end,18:20))) ' [m]']});

figure(8); 
subplot(2,1,1); plot(tdebug,quat2rpy(plotdebug(:,21:24)')');
hold on; plot(simuldata.time_imu(idx_cb_start:idx_cb-1),quat2rpy(simuldata.q_ic(:,ones(idx_cb-idx_cb_start,1))),'-'); hold off;
ylabel('q imu-cam [rad]')
subplot(2,1,2); plot(tdebug,quat2rpy(mul_quat(simuldata.q_ic(:,ones(idx_cb-idx_cb_start,1)),diag([1 -1 -1 -1])*plotdebug(:,21:24)'))');
ylabel('q imu-cam error [rad]')
title({['total rms: ' num2str(rms(quat2rpy(simuldata.q_ic(:,ones(idx_cb-idx_cb_start,1)))',quat2rpy(plotdebug(:,21:24)')')) ' [rad]'];...
        ['rms t-' num2str(RMST) 's: ' num2str(rms(quat2rpy(simuldata.q_ic(:,ones(floor(RMST/STEP)+1,1)))',quat2rpy(plotdebug(end-floor(RMST/STEP):end,21:24)')')) ' [rad]']});


figure(9); 
subplot(2,1,1); plot(tdebug,quat2rpy(plotdebug(:,25:28)')');
hold on; plot(simuldata.time_cam(idx_ptam_start:idx_ptam-1),quat2rpy(simuldata.q_vw(:,idx_ptam_start:idx_ptam-1))','-'); hold off;
ylabel('q v-w drift [rad]')
subplot(2,1,2); plot(simuldata.time_cam(idx_ptam_start:idx_ptam-1),quat2rpy(mul_quat(simuldata.q_vw(:,idx_ptam_start:idx_ptam-1),diag([1 -1 -1 -1])*plotdebug(1:simuldata.camsample:end-1,25:28)'))');
ylabel('q v-w drift error [rad]')
title({['total rms: ' num2str(rms(quat2rpy(simuldata.q_vw(:,idx_ptam_start:idx_ptam-1))',quat2rpy(plotdebug(1:simuldata.camsample:end-1,25:28)')')) ' [rad]'];...
        ['rms t-' num2str(RMST) 's: ' num2str(rms(quat2rpy(simuldata.q_vw(:,idx_ptam-floor(RMST/(STEP*simuldata.camsample)):idx_ptam-1))',quat2rpy(plotdebug(end-floor(RMST/STEP):simuldata.camsample:end-1,25:28)')')) ' [rad]']});


% save self_calib_imuvis_run plotdebug tdebug
display('finished');









