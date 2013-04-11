%==========================================================================
%
% Project:  AIR control for the Hquad 
%
%
% Function: Validate the thrust dynamics of the attitude controller
%
% Author:   Andreas Rüesch
%           Michael Burri
%
%
%--------------------------------------------------------------------------
% created:  10.08.2011  v0.1    burrimi
%==========================================================================

% close all;
SAMPLINGTIME = 0.02;

% -------------------------------------------------------------------------
% prepare data
% -------------------------------------------------------------------------

% force cmd = 1 N
load thrust_1N_camera.mat

%plot(udp_xmit_time_sec,[control_thrust_scaled',thrust'*thrust_cmd2thrust]);
control_thrust_scaled=control_thrust_scaled(:,10*1/SAMPLINGTIME:30*1/SAMPLINGTIME);
thrust=thrust(:,10*1/SAMPLINGTIME:30*1/SAMPLINGTIME);

val_data_in=control_thrust_scaled';
val_data_out=thrust'*thrust_cmd2thrust_0thOrd;
N = length(val_data_in);
tStart   = 0;       % [s]
tFinal   = (N-1)*SAMPLINGTIME;      % [s]
tSample  = SAMPLINGTIME;    % [s]

simin_thrust.time = (tStart:tSample:tFinal);
simin_thrust.signals.values = val_data_in;

% -------------------------------------------------------------------------
% run simulation
% -------------------------------------------------------------------------

sim('SimulinkModel_ID_sub_thrust', [tStart, tFinal])

% -------------------------------------------------------------------------
% visualization, plots
% -------------------------------------------------------------------------
figure('Name',['Validation thrust Dynamics - delay : ' num2str(Td_thrust_0thOrd*1e3) 'ms'])
subplot(2,2,1)
plot(simin_thrust.time, simin_thrust.signals.values(:,1),'b')
title('Model validation with Dataset 1N -- Input ')
legend('input')
xlabel 'time (sec)'
ylabel 'command (N)'
subplot(2,2,2)
plot(simout_thrust.time, val_data_out,'r',...
     simout_thrust.time, simout_thrust.signals.values(:,1),'--b')
xlabel 'time (sec)'
ylabel 'force (N)'
legend('measured output','model output')
title('Model validation with Dataset 1N -- Output ')

clear simin_thrust simout_thrust

% -------------------------------------------------------------------------
% prepare data
% -------------------------------------------------------------------------

% step of 1 meter with mpc controller
load thrust_1m_camera.mat

control_thrust_scaled=control_thrust_scaled(:,40*1/SAMPLINGTIME:60*1/SAMPLINGTIME);
thrust=thrust(:,40*1/SAMPLINGTIME:60*1/SAMPLINGTIME);

val_data_in=control_thrust_scaled';
val_data_out=thrust'*thrust_cmd2thrust_0thOrd;
N = length(val_data_in);
tStart   = 0;       % [s]
tFinal   = (N-1)*SAMPLINGTIME;      % [s]
tSample  = SAMPLINGTIME;    % [s]

simin_thrust.time = (tStart:tSample:tFinal);
simin_thrust.signals.values = val_data_in;

% -------------------------------------------------------------------------
% run simulation
% -------------------------------------------------------------------------

sim('SimulinkModel_ID_sub_thrust', [tStart, tFinal])

% -------------------------------------------------------------------------
% visualization, plots
% -------------------------------------------------------------------------

subplot(2,2,3)
plot(simin_thrust.time, simin_thrust.signals.values(:,1),'b')
title('Model validation with Dataset 1m -- Input ')
legend('input')
xlabel 'time (sec)'
ylabel 'command (N)'
subplot(2,2,4)
plot(simout_thrust.time, val_data_out,'r',...
     simout_thrust.time, simout_thrust.signals.values(:,1),'--b')
xlabel 'time (sec)'
ylabel 'force (N)'
legend('measured output','model output')
title('Model validation with Dataset 1m -- Output ')

clear simin_thrust simout_thrust

