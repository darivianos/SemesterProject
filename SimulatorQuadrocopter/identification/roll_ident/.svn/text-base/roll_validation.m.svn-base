%==========================================================================
%
% Project:  AIR control for the Hquad 
%
%
% Function: Validate the roll dynamics of the attitude controller
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

% 10 degree
load hquad_traj_controller2.mat

roll_ident2=pose_traj_controller(:,40*1/SAMPLINGTIME:60*1/SAMPLINGTIME);

SAMPLINGTIME = 0.009;
val_data_in=roll_ident2(5,:)';
val_data_out=roll_ident2(4,:)'*roll_cmd2roll_1stOrd;
N = length(val_data_in);
tStart   = 0;       % [s]
tFinal   = (N-1)*SAMPLINGTIME;      % [s]
tSample  = SAMPLINGTIME;    % [s]

simin_roll.time = (tStart:tSample:tFinal);
simin_roll.signals.values = val_data_in;

% -------------------------------------------------------------------------
% run simulation
% -------------------------------------------------------------------------

sim('SimulinkModel_ID_sub_roll', [tStart, tFinal])

% -------------------------------------------------------------------------
% visualization, plots
% -------------------------------------------------------------------------
figure('Name',['Validation roll Dynamics - delay : ' num2str(Td_roll_1stOrd*1e3) 'ms'])
subplot(2,2,1)
plot(simin_roll.time, simin_roll.signals.values(:,1),'b')
title('Model validation with Dataset 02 -- Input ')
legend('input')
xlabel 'time (sec)'
ylabel 'command (rad)'
subplot(2,2,2)
plot(simout_roll.time, val_data_out,'r',...
     simout_roll.time, simout_roll.signals.values(:,1),'--b')
xlabel 'time (sec)'
ylabel 'roll (rad)'
legend('measured output','model output')
title('Model validation with Dataset 02 -- Output ')

clear simin_roll simout_roll

% -------------------------------------------------------------------------
% prepare data
% -------------------------------------------------------------------------

%20 degree
load hquad_traj_controller4.mat

roll_ident4=pose_traj_controller(:,45*1/SAMPLINGTIME:65*1/SAMPLINGTIME);

val_data_in=roll_ident4(5,:)';
val_data_out=roll_ident4(4,:)'*roll_cmd2roll_1stOrd;
N = length(val_data_in);
tStart   = 0;       % [s]
tFinal   = (N-1)*SAMPLINGTIME;      % [s]
tSample  = SAMPLINGTIME;    % [s]

simin_roll.time = (tStart:tSample:tFinal);
simin_roll.signals.values = val_data_in;

% -------------------------------------------------------------------------
% run simulation
% -------------------------------------------------------------------------

sim('SimulinkModel_ID_sub_roll', [tStart, tFinal])

% -------------------------------------------------------------------------
% visualization, plots
% -------------------------------------------------------------------------

subplot(2,2,3)
plot(simin_roll.time, simin_roll.signals.values(:,1),'b')
title('Model validation with Dataset 04 -- Input ')
legend('input')
xlabel 'time (sec)'
ylabel 'command (rad)'
subplot(2,2,4)
plot(simout_roll.time, val_data_out,'r',...
     simout_roll.time, simout_roll.signals.values(:,1),'--b')
xlabel 'time (sec)'
ylabel 'roll (rad)'
legend('measured output','model output')
title('Model validation with Dataset 04 -- Output ')

clear simin_roll simout_roll
