%--------------------------------------------------------------------------
% observer : kalman filter
%--------------------------------------------------------------------------
Q =  1*diag([0.007,0.007,0.007,0.00001]); % Q kalman   
R =  1*diag([0.00707,0.07,0.007]);   % R kalman


[A_x_est, B_x_est, C_x_est, D_x_est] = ...
          dlinmod( 'SimulinkModel_hquad_lin_pitch_1stOrd',Ts);
[n,m]=size(B_x_est);
[p,~]=size(C_x_est);
A_obsv_x=[A_x_est B_x_est; zeros(m,n) eye(m)]
B_obsv_x=[B_x_est; zeros(m)]
C_obsv_x=[C_x_est zeros(p,m)]
D_obsv_x=[D_x_est]

%--------------------------------------------------------------------------
% linear model (with bias-extention)
%--------------------------------------------------------------------------

Bnoise = [eye(n+m)];

plant = ss(A_obsv_x, [B_obsv_x Bnoise], C_obsv_x, 0,Ts);
% transform to a discret model
%plant = c2d( plant_c, Ts );
                      


[kalmf_bias_x,L_kalm_x,P_kalm_x,M_kalm_x] = kalman( plant, Q, R)


% create kalman filter struct
kalm_mpc_x=struct();
kalm_mpc_x.A=A_obsv_x;
kalm_mpc_x.B=B_obsv_x;
kalm_mpc_x.C=C_obsv_x;
kalm_mpc_x.D=D_obsv_x;
kalm_mpc_x.Q=Q;
kalm_mpc_x.R=R;
kalm_mpc_x.M=M_kalm_x;
kalm_mpc_x.L=L_kalm_x;
kalm_mpc_x.P=P_kalm_x;
kalm_mpc_x.Ts=Ts;





[A_y_est, B_y_est, C_y_est, D_y_est] = ...
          dlinmod( 'SimulinkModel_hquad_lin_roll_1stOrd',Ts);
[n,m]=size(B_y_est);
[p,~]=size(C_y_est);
A_obsv_y=[A_y_est B_y_est; zeros(m,n) eye(m)]
B_obsv_y=[B_y_est; zeros(m)]
C_obsv_y=[C_y_est zeros(p,m)]
D_obsv_y=[D_y_est]

%--------------------------------------------------------------------------
% linear model (with bias-extention)
%--------------------------------------------------------------------------

Bnoise = [eye(n+m)];

plant = ss(A_obsv_y, [B_obsv_y Bnoise], C_obsv_y, 0,Ts);
% transform to a discret model
%plant = c2d( plant_c, Ts );
                      

[kalmf_bias_y,L_kalm_y,P_kalm_y] = kalman( plant, Q, R )


Q =  1*diag([0.007,0.007,0.00001]); % Q kalman   
R =  1*diag([0.00707,0.07]);   % R kalman

[A_z_est, B_z_est, C_z_est, D_z_est] = ...
          dlinmod( 'SimulinkModel_hquad_lin_thrust_0thOrd',Ts);
[n,m]=size(B_z_est);
[p,~]=size(C_z_est);
A_obsv_z=[A_z_est B_z_est; zeros(m,n) eye(m)]
B_obsv_z=[B_z_est; zeros(m)]
C_obsv_z=[C_z_est zeros(p,m)]
D_obsv_z=[D_z_est]

%--------------------------------------------------------------------------
% linear model (with bias-extention)
%--------------------------------------------------------------------------

Bnoise = [eye(n+m)];

plant = ss(A_obsv_z, [B_obsv_z Bnoise], C_obsv_z, 0,Ts);
% transform to a discret model
%plant = c2d( plant_c, Ts );
                      

[kalmf_bias_z,L_kalm_z,P_kalm_z] = kalman( plant, Q, R )
