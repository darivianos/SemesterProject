%==========================================================================
%
% Project:  IR control for the Hquad 
%
% Task:     LQR - Controlling decoupled SISO case
%
% function: calculate and design the LQR - controller for the altitude
%
% Important: If you change the pade approximation of the delay, check the
% order of the states (1st position, 2nd velocity)
% 
% Author:   Rueesch Andreas
%           Michael Burri
%
%--------------------------------------------------------------------------
% created:  14.04.2010  v0.1    arue
%           13.05.2010  v0.2    burrimi changed lqr calculations for new
%                                       lqr controller with time delay
%==========================================================================


%==========================================================================
%
% linearize the subsystem for the altitude 
%     (assume that pitch, roll, yaw are equal to zero)get doc ss
%
%==========================================================================

%--------------------------------------------------------------------------
% set point for the linarization: hovering in 0.40 m
%--------------------------------------------------------------------------
output_lin = 0;
input_lin  = 0;


%--------------------------------------------------------------------------
% linearize System
%--------------------------------------------------------------------------
[A_z_est, B_z_est, C_z_est, D_z_est] = ...
          linmod( 'SimulinkModel_hquad_lin_thrust_kalman', output_lin, input_lin );      



% use the position output for position control-> remove velocity
A_z=A_z_est;
B_z=B_z_est;
C_z=C_z_est(1,:);
D_z=D_z_est(1,:);

p = size(C_z,1);

[n,m]= size(B_z);

%==========================================================================
%
%% LQG / LQGI - controller 
%
%==========================================================================

%--------------------------------------------------------------------------
% tuning parameters
%--------------------------------------------------------------------------

% % ------------------------
% % version 1
% % ------------------------
% VERSION_NR = 1;
% 
% Q_z = 1*diag([100,10,0.001*ones(1,delay_pade_order),0.0001]);           % states ( h, h_dot, h_ddot, .. )
% R_z = 15;                         % inputs ( thrust )
% gamma_z =15;
% 
% W_z= 1*diag([1,100,0.001*ones(1,delay_pade_order),0.001]); % Q kalman
% V_z = diag([0.005,0.005]);   % R kalman

% % ------------------------
% % version 2 - optimized for vicon
% % ------------------------
% VERSION_NR = 2;
% 
% Q_z = 1*diag([100,30,0.001*ones(1,delay_pade_order)]);           % states ( h, h_dot, h_ddot, .. )
% R_z = 20;                         % inputs ( thrust )
% gamma_z = 50;
% W_z= 1*diag([1,1,0.001*ones(1,delay_pade_order)]); % Q kalman
% V_z = diag([0.000707,0.0007]);   % R kalman

% % ------------------------
% % version 3 - optimized for vicon
% % ------------------------
VERSION_NR = 4;
Q_z = 1*diag([100,40,0.001*ones(1,delay_pade_order)]);           % states ( h, h_dot, h_ddot, .. )
R_z = 40;                         % inputs ( thrust )
gamma_z = 20;

W_z= 1*diag([1,1,0.001*ones(1,delay_pade_order)]); % Q kalman
V_z = diag([0.000707,0.0007]);   % R kalman


%--------------------------------------------------------------------------
% lqr controller discret
%--------------------------------------------------------------------------


Znm= zeros(n,m); Zmm=zeros(m,m);
Znn=zeros(n,n); Zmn= zeros(m,n);

% add integrator to the lqr controller for position
A = [A_z Znm; -C_z Zmm];
B = [B_z;-D_z];

sysLin_zint = ss(A,B,[C_z Zmm],D_z);
sysdLin_zint = c2d(sysLin_zint, Ts, 'zoh');

Q_z_int = [Q_z Znm; Zmn gamma_z*eye(m,m)];

Kr=dlqr(sysdLin_zint.a,sysdLin_zint.b,Q_z_int,R_z);

K_z_SI = Kr(1:m,1:n);
K_I_z_SI = Kr(1:m,n+1:n+m);

%--------------------------------------------------------------------------
% kalman estimator discret
%--------------------------------------------------------------------------


Bnoise =1*eye(n);

Estss = ss(A_z_est, [B_z_est Bnoise], C_z_est,0);
[kest_z_SI,L,P] = kalman(Estss,W_z,V_z);
kest_z_SI=c2d(kest_z_SI,Ts, 'zoh');



%==========================================================================
%
%% Save the Controller
%
%==========================================================================
PATH_CTRL_alt = ['../Hquad_CTRL_OBSV_parameters/ctrl_lqri_z_v'...
                    num2str(VERSION_NR) '.mat'];
save(PATH_CTRL_alt, 'K_z_SI', 'K_I_z_SI', 'kest_z_SI')


%==========================================================================
%
%% Testing / Run the Simulation
%
%==========================================================================
% lqr_sim
