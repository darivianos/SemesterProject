%==========================================================================
%
% Project:  AIR control for the Hquad 
%
%
% Function: Validate the yaw rate of the attitude controller
%
% Author:   Andreas Rüesch
%           Michael Burri
%
%
%--------------------------------------------------------------------------
% created:  10.08.2011  v0.1    burrimi
%==========================================================================


SAMPLINGTIME = 0.009;

% -------------------------------------------------------------------------
% prepare data
% -------------------------------------------------------------------------

%rate = pi/4
load hquad_traj_controller1.mat

% plot(pose_traj_controller(1,:),[pose_traj_controller(4,:)',pose_traj_controller(3,:)']);
yaw_ident1=pose_traj_controller(:,24*1/SAMPLINGTIME:44*1/SAMPLINGTIME);

val_data_in=yaw_ident1(4,:)';
val_data_out=yaw_ident1(3,:)'*yaw_cmd2yaw_1stOrd;
N = length(val_data_in);
tStart   = 0;       % [s]
tFinal   = (N-1)*SAMPLINGTIME;      % [s]
tSample  = SAMPLINGTIME;    % [s]


simin_yaw.time = (tStart:tSample:tFinal);
simin_yaw.signals.values = val_data_in;

% -------------------------------------------------------------------------
% run simulation
% -------------------------------------------------------------------------

sim('SimulinkModel_ID_sub_yaw', [tStart, tFinal])

% -------------------------------------------------------------------------
% visualization, plots
% -------------------------------------------------------------------------
figure('Name',['Validation Yaw Rate Dynamics - delay : ' num2str(Td_yaw_1stOrd*1e3) 'ms'])
subplot(2,2,1)
plot(simin_yaw.time, simin_yaw.signals.values(:,1),'b')
title('Model validation with Dataset 01 -- Input ')
legend('input')
xlabel 'time (sec)'
ylabel 'command (rad/s)'
subplot(2,2,2)
plot(simout_yaw.time, val_data_out,'r',...
     simout_yaw.time, simout_yaw.signals.values(:,1),'--b')
xlabel 'time (sec)'
ylabel 'yaw rate (rad/s)'
legend('measured output','model output')
title('Model validation with Dataset 01 -- Output ')

clear simin_yaw simout_yaw

% -------------------------------------------------------------------------
% prepare data
% -------------------------------------------------------------------------

%rate = pi
load hquad_traj_controller4.mat

yaw_ident4=pose_traj_controller(:,30*1/SAMPLINGTIME:50*1/SAMPLINGTIME);

val_data_in=yaw_ident4(4,:)';
val_data_out=yaw_ident4(3,:)'*yaw_cmd2yaw_1stOrd;
N = length(val_data_in);
tStart   = 0;       % [s]
tFinal   = (N-1)*SAMPLINGTIME;      % [s]
tSample  = SAMPLINGTIME;    % [s]

simin_yaw.time = (tStart:tSample:tFinal);
simin_yaw.signals.values = val_data_in;

% -------------------------------------------------------------------------
% run simulation
% -------------------------------------------------------------------------

sim('SimulinkModel_ID_sub_yaw', [tStart, tFinal])

% -------------------------------------------------------------------------
% visualization, plots
% -------------------------------------------------------------------------

subplot(2,2,3)
plot(simin_yaw.time, simin_yaw.signals.values(:,1),'b')
title('Model validation with Dataset 04 -- Input ')
legend('input')
xlabel 'time (sec)'
ylabel 'command (rad/s)'
subplot(2,2,4)
plot(simout_yaw.time, val_data_out,'r',...
     simout_yaw.time, simout_yaw.signals.values(:,1),'--b')
xlabel 'time (sec)'
ylabel 'yaw rate (rad/s)'
legend('measured output','model output')
title('Model validation with Dataset 04 -- Output ')

clear simin_yaw simout_yaw

