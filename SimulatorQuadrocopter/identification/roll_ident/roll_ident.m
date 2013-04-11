%==========================================================================
%
% Project:  AIR control for the Hquad 
%
%
% Function: Identifie the roll dynamics of the attitude controller
%
% Author:   Michael Burri
%
%--------------------------------------------------------------------------
% created:  10.08.2011  v0.1    burrimi
%==========================================================================

close all
Ts=0.009;

%% prepare data for the identification toolbox

%5 degree
load hquad_traj_controller1.mat

figure
plot(pose_traj_controller(1,:),[pose_traj_controller(5,:)',pose_traj_controller(4,:)']);
roll_ident1=pose_traj_controller(:,30*1/Ts:50*1/Ts);
roll_ident1 = iddata(roll_ident1(4,:)',roll_ident1(5,:)',Ts);

%10 degree
load hquad_traj_controller2.mat

roll_ident2 = pose_traj_controller(:,35*1/Ts:50*1/Ts);
roll_ident2 = iddata(roll_ident2(4,:)',roll_ident2(5,:)',Ts);

figure
plot(pose_traj_controller(1,:),[pose_traj_controller(5,:)',pose_traj_controller(4,:)'*roll_cmd2roll]);


%15 degree
load hquad_traj_controller3.mat

figure
plot(pose_traj_controller(1,:),[pose_traj_controller(5,:)',pose_traj_controller(4,:)']);
roll_ident3=pose_traj_controller(:,50*1/Ts:64*1/Ts);
roll_ident3 = iddata(roll_ident3(4,:)',roll_ident3(5,:)',Ts);


%20 degree
load hquad_traj_controller4.mat

figure
plot(pose_traj_controller(1,:),[pose_traj_controller(5,:)',pose_traj_controller(4,:)']);

roll_ident4=pose_traj_controller(:,40*1/Ts:60*1/Ts);
roll_ident4 = iddata(roll_ident4(4,:)',roll_ident4(5,:)',Ts);

%% do the identification with dataset 3 for the 1stOrd system

[k_roll, omega_roll, Td_roll, est_mod] = estimate_1stOrdSys...
            (roll_ident3.InputData, roll_ident3.OutputData, Ts, -1);

% NOTE: numerator should be  tf( [ 0, k_roll*omega_roll ],...
% but we want SI units as inputs and as outputs -> we remove the scaling 
% factor from the TF and instead multiply the input of the plant with this
% scaling factor
dynamics_roll_1stOrd_tf = tf( [ 0, omega_roll ],[ 1, omega_roll ] );

% to avoid strange state scaling behaviour of simulink store the model in
% observable canonical form. This should guarantee, that the first state is
% always the roll angle.
dynamics_roll_1stOrd = ss(-omega_roll,omega_roll,1,0);

roll_cmd2roll_1stOrd=1/k_roll;

Td_roll_1stOrd=Td_roll;

%% do the identification with dataset 2 for the 2ndOrd system
%the identification is done with dataset 2 and not 3 because this lead to
%better overall performance

[k_roll, omega_roll, d_roll, Td_roll, est_mod] = estimate_2ndOrdSys...
            (roll_ident2.InputData, roll_ident2.OutputData, Ts, -1 );

% NOTE: numerator should be  tf( [ 0, 0, k_roll * omega_roll^2 ], ...
% but we want SI units as inputs and as outputs -> we remove the scaling 
% factor from the TF and instead multiply the input of the plant with this
% scaling factor
dynamics_roll_2ndOrd_tf = tf( [ 0, 0, omega_roll^2 ], ...
                     [ 1, 2*d_roll*omega_roll, omega_roll^2 ] );

% to avoid strange state scaling behaviour of simulink store the model in
% observable canonical form. This should guarantee, that the first state is
% always the roll angle.
dynamics_roll_2ndOrd = ss([-2*d_roll*omega_roll, 1;-omega_roll^2,0],...
                                [0;omega_roll^2],[1,0],0);
                 
                 
roll_cmd2roll_2ndOrd=1/k_roll;

Td_roll_2ndOrd=Td_roll;

PATH_CTRL = ['dynamics_roll.mat'];
save(PATH_CTRL, 'roll_cmd2roll_1stOrd', 'Td_roll_1stOrd', 'dynamics_roll_1stOrd', 'dynamics_roll_1stOrd_tf',...
    'roll_cmd2roll_2ndOrd', 'Td_roll_2ndOrd', 'dynamics_roll_2ndOrd', 'dynamics_roll_2ndOrd_tf');
