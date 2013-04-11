%==========================================================================
%
% Project:  AIR control for the Hquad 
%
%
% Function: Validate the pitch dynamics of the attitude controller
%
% Author:   Andreas Rüesch
%           Michael Burri
%
%
%--------------------------------------------------------------------------
% created:  10.08.2011  v0.1    burrimi
%==========================================================================

% close all;
SAMPLINGTIME = 0.009;

% -------------------------------------------------------------------------
% prepare data
% -------------------------------------------------------------------------

%10 degree
load hquad_traj_controller1.mat

plot(pose_traj_controller(1,:),[pose_traj_controller(4,:)',pose_traj_controller(5,:)']);
pitch_ident1=pose_traj_controller(:,24*1/SAMPLINGTIME:44*1/SAMPLINGTIME);

val_data_in=pitch_ident1(4,:)';
val_data_out=pitch_ident1(5,:)'*pitch_cmd2pitch_1stOrd;
N = length(val_data_in);
tStart   = 0;       % [s]
tFinal   = (N-1)*SAMPLINGTIME;      % [s]
tSample  = SAMPLINGTIME;    % [s]

simin_pitch.time = (tStart:tSample:tFinal);
simin_pitch.signals.values = val_data_in;

% -------------------------------------------------------------------------
% run simulation
% -------------------------------------------------------------------------

sim('SimulinkModel_ID_sub_pitch', [tStart, tFinal])

% -------------------------------------------------------------------------
% visualization, plots
% -------------------------------------------------------------------------
figure('Name',['Validation Pitch Dynamics - delay : ' num2str(Td_pitch_1stOrd*1e3) 'ms'])
subplot(2,2,1)
plot(simin_pitch.time, simin_pitch.signals.values(:,1),'b')
title('Model validation with Dataset 01 -- Input ')
legend('input')
xlabel 'time (sec)'
ylabel 'command (rad)'
subplot(2,2,2)
plot(simout_pitch.time, val_data_out,'r',...
     simout_pitch.time, simout_pitch.signals.values(:,1),'--b')
xlabel 'time (sec)'
ylabel 'pitch (rad)'
legend('measured output','model output')
title('Model validation with Dataset 01 -- Output ')

clear simin_pitch simout_pitch

% -------------------------------------------------------------------------
% prepare data
% -------------------------------------------------------------------------


% 10 degree
load hquad_traj_controller5.mat

pitch_ident5=pose_traj_controller(:,20*1/SAMPLINGTIME:40*1/SAMPLINGTIME);

SAMPLINGTIME = 0.009;
val_data_in=pitch_ident5(4,:)';
val_data_out=pitch_ident5(5,:)'*pitch_cmd2pitch_1stOrd;
N = length(val_data_in);
tStart   = 0;       % [s]
tFinal   = (N-1)*SAMPLINGTIME;      % [s]
tSample  = SAMPLINGTIME;    % [s]

simin_pitch.time = (tStart:tSample:tFinal);
simin_pitch.signals.values = val_data_in;

% -------------------------------------------------------------------------
% run simulation
% -------------------------------------------------------------------------

sim('SimulinkModel_ID_sub_pitch', [tStart, tFinal])

% -------------------------------------------------------------------------
% visualization, plots
% -------------------------------------------------------------------------
subplot(2,2,3)
plot(simin_pitch.time, simin_pitch.signals.values(:,1),'b')
title('Model validation with Dataset 05 -- Input ')
legend('input')
xlabel 'time (sec)'
ylabel 'command (rad)'
subplot(2,2,4)
plot(simout_pitch.time, val_data_out,'r',...
     simout_pitch.time, simout_pitch.signals.values(:,1),'--b')
xlabel 'time (sec)'
ylabel 'pitch (rad)'
legend('measured output','model output')
title('Model validation with Dataset 05 -- Output ')

clear simin_pitch simout_pitch