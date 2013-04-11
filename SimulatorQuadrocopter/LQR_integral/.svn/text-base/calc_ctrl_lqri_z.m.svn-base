%==========================================================================
%
% Project:  IR control for the Hquad 
%
% Task:     LQR - Controlling decoupled SISO case
%
% function: calculate and design the LQR - controller for z axis
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



%--------------------------------------------------------------------------
% set point for the linarization: hovering
%--------------------------------------------------------------------------
output_lin = 0;
input_lin  = 0;


%--------------------------------------------------------------------------
% linearize System
%--------------------------------------------------------------------------
[A_z_est, B_z_est, C_z_est, D_z_est] = ...
          linmod( 'SimulinkModel_hquad_lin_thrust_0thOrd', output_lin, input_lin );      


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


%--------------------------------------------------------------------------
% lqr controller discret
%--------------------------------------------------------------------------


Znm= zeros(n,m); Zmm=zeros(m,m);
Znn=zeros(n,n); Zmn= zeros(m,n);

% add integrator to the lqr controller for position
A = [A_z Znm; -C_z Zmm];
B = [B_z;-D_z];

Q_z_int = [Q_z Znm; Zmn gamma_z*eye(m,m)];


% get discrete lqr gain
Kr=lqrd(A,B,Q_z_int,R_z,Ts);

% split gain into integral and non integral part
K_lqri_z = Kr(1:m,1:n);
K_I_lqri_z = Kr(1:m,n+1:n+m);


%==========================================================================
%
%% Save the Controller
%
%==========================================================================
PATH_CTRL_alt = ['../Hquad_CTRL_OBSV_parameters/ctrl_lqri_z_v'...
                    num2str(VERSION_NR) '.mat'];
save(PATH_CTRL_alt, 'K_lqri_z', 'K_I_lqri_z')


%==========================================================================
%
%% Testing / Run the Simulation
%
%==========================================================================
% lqr_sim
