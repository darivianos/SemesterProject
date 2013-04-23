%==========================================================================
%
% Project:  AIR control for the Hquad 
%
%
% Function: Identifie the sample dynamics of the attitude controller
%
% Author:   Michael Burri
%
%--------------------------------------------------------------------------
% created:  10.08.2011  v0.1    burrimi
%==========================================================================

close all
Ts=0.009;

%% prepare data for the identification toolbox

%load data from exlipse target
load hquad_identification.mat

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

id_measured=4;
id_command=6;

% view the recorded data to select start and endtime for the
% identification
figure
plot(hquad_identification(1,:),[hquad_identification(id_measured,:)',hquad_identification(id_command,:)']);
legend('measured','command');

start_time=30;
end_time=50;

ident_sample_data=hquad_identification(:,start_time*1/Ts:end_time*1/Ts);

% note that the order in iddata is special:
% iddata(output (measured),input (command),sampling_rate)
ident_sample_data = iddata(ident_sample_data(id_measured,:)',ident_sample_data(id_command,:)',Ts);


%% do the identification with 0thOrd


[k_sample, Td_sample, est_mod] = estimate_0thOrdSys...
            (ident_sample_data.InputData, ident_sample_data.OutputData , Ts, -1 );

% NOTE: dynmics should be tf(k_sample) but we remove scaling from the TF
% and instead multiply the input of the plant with this scaling factor
dynamics_sample_0thOrd = 1;

sample_cmd2sample_0thOrd=1/k_sample;
Td_sample_0thOrd=Td_sample;

%% do the identification 1stOrd system
[k_sample, omega_sample, Td_sample, est_mod] = estimate_1stOrdSys...
            (ident_sample_data.InputData, ident_sample_data.OutputData, Ts, -1);

% NOTE: numerator should be  tf( [ 0, k_sample*omega_sample ],...
% but we want SI units as inputs and as outputs -> we remove the scaling 
% factor from the TF and instead multiply the input of the plant with this
% scaling factor
dynamics_sample_1stOrd_tf = tf( [ 0, omega_sample ],[ 1, omega_sample ] );


% to avoid strange state scaling behaviour of simulink store the model in
% observable canonical form. This should guarantee, that the first state is
% always the state we ned for the point mass model.
dynamics_sample_1stOrd = ss(-omega_sample,omega_sample,1,0);


sample_cmd2sample_1stOrd=1/k_sample;
Td_sample_1stOrd=Td_sample;

%% do the identification 2ndOrder

[k_sample, omega_sample, d_sample, Td_sample, est_mod] = estimate_2ndOrdSys...
            (ident_sample_data.InputData, ident_sample_data.OutputData, Ts, -1 );

% NOTE: numerator should be  tf( [ 0, 0, k_sample * omega_sample^2 ], ...
% but we want SI units as inputs and as outputs -> we remove the scaling 
% factor from the TF and instead multiply the input of the plant with this
% scaling factor
dynamics_sample_2ndOrd_tf = tf( [ 0, 0, omega_sample^2 ], ...
                     [ 1, 2*d_sample*omega_sample, omega_sample^2 ] );
                 
% to avoid strange state scaling behaviour of simulink store the model in
% observable canonical form. This should guarantee, that the first state is
% always the state we need for the point mass model
dynamics_sample_2ndOrd = ss([-2*d_sample*omega_sample, 1;-omega_sample^2,0],...
                                [0;omega_sample^2],[1,0],0);                 

sample_cmd2sample_2ndOrd=1/k_sample;
Td_sample_2ndOrd=Td_sample;


