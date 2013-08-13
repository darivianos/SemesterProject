function traj_FG = ReferenceCreator(maxdisty,maxdistz,scale_y,scale_z)
% Simple GUI for drawing trajectories on the wall
% 
% traj_FG = ReferenceCreator(maxdisty,maxdistz,interpy,interpz)
% maxdisty : borders in y direction from center
% maxdistz : borders in z direction from center
% interpy : Distance between interpolated points in y direction
% interpz : Distance between interpolated points in z direction
%
% Created by Darivianakis Georgios (gdarivia@student.ethz.ch)
% Date: 7/7/2013

maxdisty = abs(maxdisty);
maxdistz = abs(maxdistz);

figure;
axis([-maxdisty,maxdisty,-maxdistz,maxdistz]);

yvec = zeros(1,1000);
zvec = zeros(1,1000);

disp('Central point (0,0)');
disp('Press right mouse button for default option : ASL');
disp('Left mouse button, new point');
disp('Right mouse button for final point');

[yvec(1),zvec(1)] = ginput(1);
counter = 1;
while ~strcmp(get(gcf,'SelectionType'),'alt')
    counter = counter + 1;    
    [yvec(counter),zvec(counter)] = ginput(1);
    plot(yvec(1:counter),zvec(1:counter));
    axis([-maxdisty,maxdisty,-maxdistz,maxdistz]);
end

% hack
%%
if counter == 1
    %%
    flag_type = 1;
    disp('Default Option : ASL -> Blame Kostas for the awful design');
    YY_REF = [-0.75 -0.58 -0.45 -0.30 -0.16 -0.1 0.4  0.65  0.4 0.15 -0.05   0.15 0.65 0.9 0.8  0.82 1.3];
    ZZ_REF = [-0.4   0.3   0.4   0.3  -0.4  -0.4 -0.4 -0.2 0.0 0.0  0.2 0.4  0.4       0.4 -0.4 -0.4 -0.4];
    Coarsity = 300; 
%     disp('Rectangle Option');
%     flag_type = 2;
%     YY_REF = [-0.75 -0.75 -0.10 -0.1 -0.75];
%     ZZ_REF = [0.4   -0.4  -0.4 0.4   0.4];
%     Coarsity = 500; 
    [YY_WPTS_S,ZZ_WPTS_S,~,~] = ACX_Smooth_Trajectory(YY_REF,ZZ_REF,Coarsity,1);
    %%
%     disp('SineWave');
%     flag_type = 3;
%     YY_WPTS_S = 0:0.01:1;
%     ZZ_WPTS_S = -0.45*sin(2*pi*YY_WPTS_S);
%     YY_WPTS_S = YY_WPTS_S  -0.5; 
%     plot(YY_WPTS_S,-ZZ_WPTS_S,'o-r','LineWidth',2);
    
%     disp('Circle');
%     tim = 0:0.01:1;
%     ZZ_WPTS_S = 0.35*cos(2*pi*tim);
%     YY_WPTS_S = 0.35*sin(2*pi*tim);
%     
%     disp('vertical sine');
%     flag_type = 5;
%     %%
%     ZZ_WPTS_S = 0:0.005:1;
%     YY_WPTS_S = -0.65*sin(2*pi*ZZ_WPTS_S);
%     ZZ_WPTS_S = ZZ_WPTS_S - 0.35;
%     ZZ_WPTS_S = - ZZ_WPTS_S;
%     plot(YY_WPTS_S,-ZZ_WPTS_S,'o-r','LineWidth',2);
%     disp('Inspection Maneuver')
%     flag_type = 6;
%     YY_REF = [-0.7 0.3  0.3 -0.7 -0.7 0.3  0.3 -0.7];
%     ZZ_REF = [ 0.6 0.6  0.3  0.3  0.0 0.0 -0.3 -0.3];
%     ZZ_REF = 0.8*ZZ_REF;
%     YY_REF = 1.6*YY_REF;
%     Coarsity = 500; 
%     [YY_WPTS_S,ZZ_WPTS_S,~,~] = ACX_Smooth_Trajectory(YY_REF,ZZ_REF,Coarsity,1);
    flag_type = 7;
    disp('Pipe Inspection');
    YY_REF = [0    0    0    0   0  ];
    ZZ_REF = [0.1 -0.5 -0.8 -0.3 0.1];
    Coarsity = 500; 
    [YY_WPTS_S,ZZ_WPTS_S,~,~] = ACX_Smooth_Trajectory(YY_REF,ZZ_REF,Coarsity,1);
    %%
else
    disp('Custom Design -> Good luck with that');
    YY_REF = yvec(1:counter);
    ZZ_REF = zvec(1:counter);
    Coarsity = 600; 
    [YY_WPTS_S,ZZ_WPTS_S,~,~] = ACX_Smooth_Trajectory(YY_REF,ZZ_REF,Coarsity,1);  
end
%%
%
y = YY_WPTS_S;
z = ZZ_WPTS_S;



z_prime = z*scale_z;
z_prime = z_prime - min(z_prime); 
z_prime = z_prime + min(z);
z = z_prime;
z = -z;

y_prime = y*scale_y;
% y_prime = y_prime - min(y_prime);
% y_prime = y_prime + min(y);
% y = y_prime;
y = y_prime;

counter = length(YY_WPTS_S);


% create X_ref 
X_ref_x=[zeros(1,counter); zeros(1,counter);zeros(1,counter)]; % In x axis the wall position is at zero
X_ref_y=[y; zeros(1,counter);zeros(1,counter)]; % No velocity references, controller does all the job...
X_ref_z=[z; zeros(1,counter)];
X_ref_yaw=[zeros(1,counter);zeros(1,counter)];  % No yaw


traj_FG = struct();
traj_FG.X_ref_x=X_ref_x;
traj_FG.X_ref_y=X_ref_y;
traj_FG.X_ref_z=X_ref_z;
traj_FG.X_ref_yaw=X_ref_yaw;
traj_FG.X_ref_z_real = -ZZ_WPTS_S;
traj_FG.X_ref_y_real = YY_WPTS_S;
traj_FG.total_samples=counter;

return
