[A_x_est, B_x_est, C_x_est, D_x_est] = ...
          linmod( 'SimulinkModel_hquad_lin_pitch_1stOrd')
% di = ss(A_x_est, B_x_est, C_x_est, D_x_est);
pitch_delayed=ss(A_x_est, B_x_est, C_x_est, D_x_est, 'Inputdelay', Td_pitch);
pitch_test=ss(A_x_est, B_x_est, C_x_est, D_x_est);
[A_y_est, B_y_est, C_y_est, D_y_est] = ...
          linmod( 'SimulinkModel_hquad_lin_roll_1stOrd');
% di = ss(A_y_est, B_y_est, C_y_est, D_y_est);
roll_delayed=ss(A_y_est, B_y_est, C_y_est, D_y_est, 'Inputdelay', Td_roll);

[A_z_est, B_z_est, C_z_est, D_z_est] = ...
          linmod( 'SimulinkModel_hquad_lin_thrust_kalman');
% di = ss(A_z_est, B_z_est, C_z_est, D_z_est);
thrust_delayed=ss(A_z_est, B_z_est, C_z_est, D_z_est, 'Inputdelay', Td_thrust);

[A_yaw_est, B_yaw_est, C_yaw_est, D_yaw_est] = ...
          linmod( 'SimulinkModel_hquad_lin_yaw');
yaw_delayed=ss(A_yaw_est, B_yaw_est, C_yaw_est, D_yaw_est, 'Inputdelay', Td_yaw);

[AA, BB, CC, DD] = dlinmod('SimulinkModel_hquad_lin_pitch_1stOrd',Ts);

 

% 
% clear sysStruct probStruct
% 
% sysStruct = mpt_sys(di, Ts);
% 
% %set constraints on output
% sysStruct.ymin    =   [-5, -2, -10*pi/180]';
% sysStruct.ymax    =  [ 5,  2, 10*pi/180]';
% 
% %set constraints on input
% sysStruct.umin    =   [-10*pi/180]';
% sysStruct.umax    =  [10*pi/180]';
% 
% %set constraints on input slew rate
% sysStruct.dumin   =   -inf*ones(1,1);
% sysStruct.dumax   =   inf*ones(1,1);
% 
% 
% probStruct.norm=2;
% probStruct.Q=eye(4);
% probStruct.R=0.1*eye(1);
% probStruct.N=5;
% probStruct.x0bound=0;
% probStruct.subopt_lev=0;
% 
% %ctrl = mpt_control(sysStruct, probStruct)
