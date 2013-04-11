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
[A_yaw_est, B_yaw_est, C_yaw_est, D_yaw_est] = ...
          linmod( 'SimulinkModel_hquad_lin_yaw', output_lin, input_lin );      



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
% W_yaw= 1*diag([1,100,0.001*ones(1,delay_pade_order),0.001]); % Q kalman
% V_yaw = diag([0.005,0.005]);   % R kalman

% ------------------------
% version 2
% ------------------------
VERSION_NR = 2;
Q_yaw = 1*diag([9,3]);           % states ( yaw, yaw_rate )
R_yaw = 3.5;                         % inputs ( yaw_rate_cmd )
gamma_yaw = 0.5;

W_yaw= 1*diag([1,1,0.001*ones(1,delay_pade_order),1]); % Q kalman
V_yaw = diag([0.000707,0.001]);   % R kalman

%--------------------------------------------------------------------------
% lqr controller discret
%--------------------------------------------------------------------------

Znm= zeros(n,m); Zmm=zeros(m,m);
Znn=zeros(n,n); Zmn= zeros(m,n);

% add integrator to the lqr controller for position
A = [A_yaw Znm; -C_yaw Zmm];
B = [B_yaw;-D_yaw];

sysLin_yawint = ss(A,B,[C_yaw Zmm],D_yaw);
sysdLin_yawint = c2d(sysLin_yawint, Ts, 'zoh');

Q_yaw_int = [Q_yaw Znm; Zmn gamma_yaw*eye(m,m)];

Kr=dlqr(sysdLin_yawint.a,sysdLin_yawint.b,Q_yaw_int,R_yaw);

K_yaw_SI = Kr(1:m,1:n);
K_I_yaw_SI = Kr(1:m,n+1:n+m);

%--------------------------------------------------------------------------
% kalman estimator discret
%--------------------------------------------------------------------------

Bnoise =1*eye(n);

Estss = ss(A_yaw_est, [B_yaw_est Bnoise], C_yaw_est,0);
[kest_yaw_SI,L,P] = kalman(Estss,W_yaw,V_yaw);
kest_yaw_SI=c2d(kest_yaw_SI,Ts, 'zoh');


%==========================================================================
%
% Save the Controller
%
%==========================================================================
PATH_CTRL_alt = ['../Hquad_CTRL_OBSV_parameters/ctrl_lqri_yaw_v'...
                    num2str(VERSION_NR) '.mat'];
save(PATH_CTRL_alt, 'K_yaw_SI', 'K_I_yaw_SI', 'kest_yaw_SI');


%==========================================================================
%
% Testing / Run the Simulation
%
%==========================================================================
% lqr_sim