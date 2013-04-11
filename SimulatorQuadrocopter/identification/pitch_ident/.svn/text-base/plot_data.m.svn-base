close all

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
pitch_ident05 = iddata(pitch_ident2(5,:)',pitch_ident2(4,:)',Ts);

% [k_pitch, omega_pitch, d_pitch, Td_pitch, est_mod] = estimate_2ndOrdSys...
%             (pitch_ident2(4,:)', pitch_ident2(5,:)', Ts, -1 );
% 
% dynamics_pitch_SI05 = tf( [ 0, 0, k_pitch * omega_pitch^2 ], ...
%                      [ 1, 2*d_pitch*omega_pitch, omega_pitch^2 ] );

%15 degree
load hquad_traj_controller3.mat

figure
plot(pose_traj_controller(1,:),[pose_traj_controller(4,:)',pose_traj_controller(5,:)']);
pitch_ident3=pose_traj_controller(:,65*1/Ts:100*1/Ts);
pitch_ident15 = iddata(pitch_ident3(5,:)',pitch_ident3(4,:)',Ts);

%20 degree
load hquad_traj_controller4.mat

figure
pose_traj_controller(5,:)=pose_traj_controller(5,:)-0.03;
plot(pose_traj_controller(1,:),[pose_traj_controller(4,:)',pose_traj_controller(5,:)']);
pitch_ident4=pose_traj_controller(:,20*1/Ts:45*1/Ts);
pitch_ident20 = iddata(pitch_ident4(5,:)',pitch_ident4(4,:)',Ts);

[k_pitch, omega_pitch, d_pitch, Td_pitch, est_mod] = estimate_2ndOrdSys...
            (pitch_ident4(4,:)', pitch_ident4(5,:)', Ts, -1 );

dynamics_pitch_SI = tf( [ 0, 0, k_pitch * omega_pitch^2 ], ...
                     [ 1, 2*d_pitch*omega_pitch, omega_pitch^2 ] );


%10 degree
load hquad_traj_controller5.mat

figure
plot(pose_traj_controller(1,:),[pose_traj_controller(4,:)',pose_traj_controller(5,:)']);

pitch_ident5=pose_traj_controller(:,20*1/Ts:60*1/Ts);
pitch_ident10 = iddata(pitch_ident5(5,:)',pitch_ident5(4,:)',Ts);

[k_pitch, omega_pitch, d_pitch, Td_pitch, est_mod] = estimate_2ndOrdSys...
            (pitch_ident5(4,:)', pitch_ident5(5,:)', Ts, -1);

dynamics_pitch_SI10 = tf( [ 0, 0, k_pitch * omega_pitch^2 ], ...
                     [ 1, 2*d_pitch*omega_pitch, omega_pitch^2 ] );
