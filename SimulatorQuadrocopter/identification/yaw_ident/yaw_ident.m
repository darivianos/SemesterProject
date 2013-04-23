%==========================================================================
%
% Project:  AIR control for the Hquad 
%
%
% Function: Identifie the yaw rate dynamics of the attitude controller
%
% Author:   Michael Burri
%
%--------------------------------------------------------------------------
% created:  10.08.2011  v0.1    burrimi
%==========================================================================

close all

Ts=0.009;

%% prepare data for the identification toolbox

%rate = pi/4
load hquad_traj_controller1.mat

figure
plot(pose_traj_controller(1,:),[pose_traj_controller(4,:)',pose_traj_controller(3,:)']);
yaw_ident1=pose_traj_controller(:,45*1/Ts:65*1/Ts);
% prepare data for the identification toolbox
yaw_ident1 = iddata(yaw_ident1(3,:)',yaw_ident1(4,:)',Ts);

%rate = pi/3
load hquad_traj_controller2.mat

figure
plot(pose_traj_controller(1,:),[pose_traj_controller(4,:)',pose_traj_controller(3,:)']);
yaw_ident2=pose_traj_controller(:,25*1/Ts:55*1/Ts);
% prepare data for the identification toolbox
yaw_ident2 = iddata(yaw_ident2(3,:)',yaw_ident2(4,:)',Ts);

%rate = pi/2
%best result
load hquad_traj_controller3.mat

figure
plot(pose_traj_controller(1,:),[pose_traj_controller(4,:)',pose_traj_controller(3,:)']);
yaw_ident3=pose_traj_controller(:,30*1/Ts:60*1/Ts);

% prepare data for the identification toolbox
yaw_ident3 = iddata(yaw_ident3(3,:)',yaw_ident3(4,:)',Ts);

%rate = pi
load hquad_traj_controller4.mat

figure
plot(pose_traj_controller(1,:),[pose_traj_controller(4,:)',pose_traj_controller(3,:)']);
yaw_ident4=pose_traj_controller(:,30*1/Ts:60*1/Ts);

% prepare data for the identification toolbox
yaw_ident4 = iddata(yaw_ident4(3,:)',yaw_ident4(4,:)',Ts);

%% do the identification with dataset 3

[k_yaw, omega_yaw, Td_yaw, est_mod] = estimate_1stOrdSys...
            (yaw_ident3.InputData, yaw_ident3.OutputData, Ts, -1 );
        
% NOTE: numerator should be  tf( [ 0, k_yaw*omega_yaw ],...
% but we want SI units as inputs and as outputs -> we remove the scaling 
% factor from the TF and instead multiply the input of the plant with this
% scaling factor
dynamics_yaw_1stOrd_tf = tf( [ 0, omega_yaw ],[ 1, omega_yaw ] );

% to avoid strange state scaling behaviour of simulink store the model in
% observable canonical form. This should guarantee, that the first state is
% always the yaw rate.
dynamics_yaw_1stOrd = ss(-omega_yaw,omega_yaw,1,0);

yaw_cmd2yaw_1stOrd=1/k_yaw;
Td_yaw_1stOrd=Td_yaw;

figure
plot(pose_traj_controller(1,:),[pose_traj_controller(4,:)',pose_traj_controller(3,:)'*yaw_cmd2yaw]);


PATH_CTRL = ['dynamics_yaw.mat'];
save(PATH_CTRL, 'yaw_cmd2yaw_1stOrd', 'Td_yaw_1stOrd', 'dynamics_yaw_1stOrd', 'dynamics_yaw_1stOrd_tf');
