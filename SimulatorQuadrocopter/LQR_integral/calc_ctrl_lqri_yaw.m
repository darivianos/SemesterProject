%==========================================================================
%
% Project:  IR control for the Hquad 
%
% Task:     LQR - Controlling decoupled SISO case
%
% function: calculate and design the LQR - controller for the yaw angle
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
[A_yaw_est, B_yaw_est, C_yaw_est, D_yaw_est] = ...
          linmod( 'SimulinkModel_hquad_lin_yaw_1stOrd', output_lin, input_lin );      



% use the position output for position control-> remove velocity
A_yaw=A_yaw_est;
B_yaw=B_yaw_est;
C_yaw=C_yaw_est(1,:);
D_yaw=D_yaw_est(1,:);
p = size(C_yaw,1);

[n,m]= size(B_yaw);

%==========================================================================
%
% LQG / LQGI - controller 
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
% Q_yaw = 1*diag([100,10,0.001*ones(1,delay_pade_order),0.0001]);           % states ( h, h_dot, h_ddot, .. )
% R_yaw = 15;                         % inputs ( thrust )
% gamma_yaw =15;
% 


% ------------------------
% version 2
% ------------------------
VERSION_NR = 2;
Q_yaw = 1*diag([9,3]);           % states ( yaw, yaw_rate )
R_yaw = 3.5;                         % inputs ( yaw_rate_cmd )
gamma_yaw = 0.5;



%--------------------------------------------------------------------------
% lqr controller discret
%--------------------------------------------------------------------------

Znm= zeros(n,m); Zmm=zeros(m,m);
Znn=zeros(n,n); Zmn= zeros(m,n);

% add integrator to the lqr controller for the yaw angle
A = [A_yaw Znm; -C_yaw Zmm];
B = [B_yaw;-D_yaw];

Q_yaw_int = [Q_yaw Znm; Zmn gamma_yaw*eye(m,m)];


% get discrete lqr gain
Kr=lqrd(A,B,Q_yaw_int,R_yaw,Ts);

% split gain into integral and non integral part
K_lqri_yaw = Kr(1:m,1:n);
K_I_lqri_yaw = Kr(1:m,n+1:n+m);



%==========================================================================
%
% Save the Controller
%
%==========================================================================
PATH_CTRL_alt = ['../Hquad_CTRL_OBSV_parameters/ctrl_lqri_yaw_v'...
                    num2str(VERSION_NR) '.mat'];
save(PATH_CTRL_alt, 'K_lqri_yaw', 'K_I_lqri_yaw');


%==========================================================================
%
% Testing / Run the Simulation
%
%==========================================================================
% lqr_sim