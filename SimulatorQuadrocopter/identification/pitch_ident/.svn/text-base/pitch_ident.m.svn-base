%==========================================================================
%
% Project:  AIR control for the Hquad 
%
%
% Function: Identifie the pitch dynamics of the attitude controller
%
% Author:   Michael Burri
%
%--------------------------------------------------------------------------
% created:  10.08.2011  v0.1    burrimi
%==========================================================================

close all

% NOTE: be careful with the sampling rate. The pitch identification was done with
% the old model which run at 111 Hz!
Ts=0.009;

%% prepare data for the identification toolbox

%10 degree
load hquad_traj_controller1.mat

figure
plot(pose_traj_controller(1,:),[pose_traj_controller(4,:)',pose_traj_controller(5,:)']);
pitch_ident1=pose_traj_controller(:,37*1/Ts:47*1/Ts);
pitch_ident1 = iddata(pitch_ident1(5,:)',pitch_ident1(4,:)',Ts);

%5 degree
load hquad_traj_controller2.mat

figure
plot(pose_traj_controller(1,:),[pose_traj_controller(4,:)',pose_traj_controller(5,:)']);
pitch_ident2=pose_traj_controller(:,20*1/Ts:50*1/Ts);
pitch_ident2 = iddata(pitch_ident2(5,:)',pitch_ident2(4,:)',Ts);


%15 degree
load hquad_traj_controller3.mat

figure
plot(pose_traj_controller(1,:),[pose_traj_controller(4,:)',pose_traj_controller(5,:)']);
pitch_ident3=pose_traj_controller(:,65*1/Ts:100*1/Ts);
pitch_ident3 = iddata(pitch_ident3(5,:)',pitch_ident3(4,:)',Ts);


%20 degree
load hquad_traj_controller4.mat

figure
pose_traj_controller(5,:)=pose_traj_controller(5,:)-0.03;
plot(pose_traj_controller(1,:),[pose_traj_controller(4,:)',pose_traj_controller(5,:)']);
pitch_ident4=pose_traj_controller(:,20*1/Ts:45*1/Ts);
pitch_ident4 = iddata(pitch_ident4(5,:)',pitch_ident4(4,:)',Ts);


%10 degree
load hquad_traj_controller5.mat

pitch_ident5=pose_traj_controller(:,20*1/Ts:60*1/Ts);
pitch_ident5 = iddata(pitch_ident5(5,:)',pitch_ident5(4,:)',Ts);

figure
plot(pose_traj_controller(1,:),[pose_traj_controller(4,:)',pose_traj_controller(5,:)'*pitch_cmd2pitch]);


%% do the identification with dataset 3 for the 1stOrd system
[k_pitch, omega_pitch, Td_pitch, est_mod] = estimate_1stOrdSys...
            (pitch_ident3.InputData, pitch_ident3.OutputData, Ts, -1)

% NOTE: numerator should be  tf( [ 0, k_pitch*omega_pitch ],...
% but we want SI units as inputs and as outputs -> we remove the scaling 
% factor from the TF and instead multiply the input of the plant with this
% scaling factor
dynamics_pitch_1stOrd_tf = tf( [ 0, omega_pitch ],[ 1, omega_pitch ] );

% to avoid strange state scaling behaviour of simulink store the model in
% observable canonical form. This should guarantee, that the first state is
% always the pitch angle.
dynamics_pitch_1stOrd = ss(-omega_pitch,omega_pitch,1,0);

pitch_cmd2pitch_1stOrd=1/k_pitch;

Td_pitch_1stOrd=Td_pitch;


%% do the identification with dataset 5 for the 2ndOrd system
%the identification is done with dataset 5 and not 3 because this lead to
%better overall performance

[k_pitch, omega_pitch, d_pitch, Td_pitch, est_mod] = estimate_2ndOrdSys...
            (pitch_ident5.InputData, pitch_ident5.OutputData, Ts, -1);

        
% NOTE: numerator should be  tf( [ 0, 0, k_pitch * omega_pitch^2 ], ...
% but we want SI units as inputs and as outputs -> we remove the scaling 
% factor from the TF and instead multiply the input of the plant with this
% scaling factor
dynamics_pitch_2ndOrd_tf = tf( [ 0, 0, omega_pitch^2 ], ...
                     [ 1, 2*d_pitch*omega_pitch, omega_pitch^2 ] );
                 
% to avoid strange state scaling behaviour of simulink store the model in
% observable canonical form. This should guarantee, that the first state is
% always the pitch angle.
dynamics_pitch_2ndOrd = ss([-2*d_pitch*omega_pitch, 1;-omega_pitch^2,0],...
                                [0;omega_pitch^2],[1,0],0);

pitch_cmd2pitch_2ndOrd=1/k_pitch;

Td_pitch_2ndOrd=Td_pitch;

%% get time delay with xbee communication


% Note: this data is recorded with a diffrent sampling rate!
Ts=0.018;

%15 degree
load hquad_identification_no_camera.mat
hquad_identification(2,:)=hquad_identification(2,:)+0.05;

pitch_ident_xbee=hquad_identification(:,40*1/Ts:76*1/Ts);

figure
plot(pitch_ident_xbee(1,:),[pitch_ident_xbee(2,:)'*180/pi,pitch_ident_xbee(3,:)'*180/pi]);

pitch_ident_xbee = iddata(pitch_ident_xbee(2,:)',pitch_ident_xbee(3,:)',Ts);


[k_pitch, omega_pitch, Td_pitch, est_mod] = estimate_1stOrdSys...
            (pitch_ident_xbee.InputData, pitch_ident_xbee.OutputData, Ts, -1);


Td_pitch_xbee = Td_pitch

PATH_CTRL = ['dynamics_pitch.mat'];
save(PATH_CTRL, 'pitch_cmd2pitch_1stOrd', 'Td_pitch_1stOrd', 'dynamics_pitch_1stOrd', 'dynamics_pitch_1stOrd_tf',...
    'pitch_cmd2pitch_2ndOrd', 'Td_pitch_2ndOrd', 'dynamics_pitch_2ndOrd', 'dynamics_pitch_2ndOrd_tf');


