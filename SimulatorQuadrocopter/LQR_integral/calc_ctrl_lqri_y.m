%==========================================================================
%
% Project:  IR control for the Hquad 
%
% Task:     LQR - Controlling decoupled SISO case
%
% function: calculate and design the LQR - controller for the y axis
%
%
% Important: If you change the pade approximation of the delay, check the
% order of the states (1st position, 2nd velocity)
%
%
% Author:   Rueesch Andreas
%           Michael Burri
%
%--------------------------------------------------------------------------
% created:  14.04.2010  v0.1    arue
%           13.05.2010  v0.2    burrimi changed lqr calculations for new
%                                       lqr controller with time delay and
%                                       full model
%==========================================================================


%--------------------------------------------------------------------------
% set point for the linarization: hovering
%--------------------------------------------------------------------------
output_lin = [0 0 0 0];
input_lin  = [0];


%--------------------------------------------------------------------------
% linearize System
%--------------------------------------------------------------------------

[A_y_est, B_y_est, C_y_est, D_y_est] = ...
          linmod( 'SimulinkModel_hquad_lin_roll_2ndOrd', output_lin, input_lin );
      
% use the position output for position control-> remove velocity and
% roll
A_y=A_y_est;
B_y=B_y_est;
C_y=C_y_est(1,:);
D_y=D_y_est(1,:);
      
p = size(C_y,1);
[n,m]= size(B_y);


%==========================================================================
%
% LQR / LQRI - controller 
%
%==========================================================================

%--------------------------------------------------------------------------
% tuning parameters
%--------------------------------------------------------------------------

% % -----------------------------
% % version 1
% % -----------------------------
% VERSION_NR = 1;
% Q_x = 1*diag([100,30,0.01*ones(1,delay_pade_order),0.1,8000]);      % states ( x, x_dot , ??, ??)
% R_x = 300;                       % inputs ( pitch )
% gamma_x = 150;                     % integral action



% % -----------------------------
% % version 2 - optimized for vicon
% % -----------------------------
% VERSION_NR = 2;
Q_y = 1*diag([100,40,0.01*ones(1,delay_pade_order),20,0.000001]);      % states ( x, x_dot , ??, ??)
R_y = 250;                       % inputs ( pitch )
gamma_y = 30;                     % integral action



% % -----------------------------
% % version 3 - optimized for camera
% % -----------------------------
VERSION_NR = 3;
% Q_y = 1*diag([100,30,0.01*ones(1,delay_pade_order),70,0.0001]);      % states ( y, y_dot , roll, ...)
% R_y = 120;                       % inputs ( pitch )
% gamma_y = 30;                     % integral action



%--------------------------------------------------------------------------
% lqri controller discret
%--------------------------------------------------------------------------

Znm= zeros(n,m); Zmm=zeros(m,m);
Znn=zeros(n,n); Zmn= zeros(m,n);

% add integrator to the lqr controller for position
A = [A_y Znm; -C_y Zmm];
B = [B_y;-D_y];

Q_yint = [Q_y Znm; Zmn gamma_y*eye(m,m)];

% get discrete lqr gain
Kr=lqrd(A,B,Q_yint,R_y,Ts);

% split gain into integral and non integral part
K_lqri_y = Kr(1:m,1:n);
K_I_lqri_y = Kr(1:m,n+1:n+m);



%==========================================================================
%
% Save the Controller
%
%==========================================================================


PATH_CTRL_y = ['../Hquad_CTRL_OBSV_parameters/ctrl_lqri_y_v'...
     num2str(VERSION_NR) '.mat'];
save(PATH_CTRL_y, 'K_lqri_y', 'K_I_lqri_y');

%==========================================================================
%
% Testing / Run the Simulation
%
%==========================================================================
% lqr_sim
% 
