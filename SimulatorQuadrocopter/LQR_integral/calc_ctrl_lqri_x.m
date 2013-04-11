%==========================================================================
%
% Project:  IR control for the Hquad 
%
% Task:     LQR - Controlling decoupled SISO case
%
% function: calculate and design the LQRI - controller in the x axis
%
%
% Important: If you change the pade approximation of the delay, check the
% order of the states (1st position, 2nd velocity, 3rd pitch)
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
% linearize Systems
%--------------------------------------------------------------------------
[A_x_est, B_x_est, C_x_est, D_x_est] = ...
          linmod( 'SimulinkModel_hquad_lin_pitch_2ndOrd', output_lin, input_lin );
      
% use the position output for position control-> remove velocity and
% pitch
A_x=A_x_est;
B_x=B_x_est;
C_x=C_x_est(1,:);
D_x=D_x_est(1,:);
      
p = size(C_x,1);
[n,m]= size(B_x);


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
% Q_x = 1*diag([100,20,0.01*ones(1,delay_pade_order),0.1,5000]);      % states ( x, x_dot , ??, ??)
% R_x = 350;                       % inputs ( pitch )
% gamma_x = 60;                     % integral action



% % -----------------------------
% % version 3 - optimized for camera
% % -----------------------------
VERSION_NR = 3;
Q_x = 1*diag([100,40,0.01*ones(1,delay_pade_order),20,0.000001]);       % states ( x, x_dot , pitch, ...)
R_x = 250;                       % inputs ( pitch )
gamma_x = 30;                     % integral action

%--------------------------------------------------------------------------
% lqri controller discret
%--------------------------------------------------------------------------

Znm= zeros(n,m); Zmm=zeros(m,m);
Znn=zeros(n,n); Zmn= zeros(m,n);

% add integrator to the lqr controller for position
A = [A_x Znm; -C_x Zmm];
B = [B_x;-D_x];

Q_xint = [Q_x Znm; Zmn gamma_x*eye(m,m)];

% get discrete lqr gain
Kr=lqrd(A,B,Q_xint,R_x,Ts);


% split gain into integral and non integral part
K_lqri_x = Kr(1:m,1:n);
K_I_lqri_x = Kr(1:m,n+1:n+m);


%==========================================================================
%
% Save the Controller
%
%==========================================================================
PATH_CTRL_x = ['../Hquad_CTRL_OBSV_parameters/ctrl_lqri_x_v'...
                    num2str(VERSION_NR) '.mat'];
save(PATH_CTRL_x, 'K_lqri_x', 'K_I_lqri_x');


%==========================================================================
%
% Testing / Run the Simulation
%
%==========================================================================
% lqr_sim
% 
