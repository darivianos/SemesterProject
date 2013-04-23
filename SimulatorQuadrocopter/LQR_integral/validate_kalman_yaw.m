%==========================================================================
%
% Project:  IR control for the Hquad
%
% function: validate the kalman filter for the yaw rate
%
% Author:   Michael Burri
%
%--------------------------------------------------------------------------
% created:  19.08.2011  v0.1    burrimi 
%==========================================================================
close all;

load validation_data/hquad_pos_lqri_sample_flight.mat;

%1: time
%2: x
%3: x_dot
%4: pitch
%5: x_ref
%6: pitch_cmd
%7: y
%8: y_dot
%9: roll
%10: y_ref
%11: roll_cmd
%12: z
%13: z_dot
%14: z_ref
%15: thrust cmd
%16: yaw
%17: ang vel z
%18: yaw ref
%19: yaw rate cmd

%% start simulation

% set parameters for the kalman filter
cmd=hquad_pos_lqri(19,:);
y_meas=[hquad_pos_lqri(16,:);hquad_pos_lqri(17,:)];
x_init=[y_meas(:,1)];


% simulate filter
x_est=simulate_kalman(kalm_lqri_yaw, cmd, y_meas, x_init);


% plot filter results
num_of_steps=size(x_est,2);

time=0:Ts:((num_of_steps-1)*Ts);

figure
plot(time,[x_est(1,:)',y_meas(1,:)']);
legend('yaw est','yaw meas')

figure
plot(time,[x_est(2,:)',y_meas(2,:)']);
legend('yaw rate est','yaw rate meas')


% axis([0 10 -1 4]);
