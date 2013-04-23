%==========================================================================
%
% Project:  IR control for the Hquad 
%
% Task:     LQR - Controlling decoupled SISO case
%
% function: calculate and design the LQR - controller for the distance to 
%           the front wall
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


%==========================================================================
%
% linearize the subsystem for the front direction 
%     (assume that roll, yaw are equal to zero and thrust constant)
%
%==========================================================================

%--------------------------------------------------------------------------
% linearize System
%   hovering in 0.40 m and at a distance of 0.40 m of the front and side
%   wall
%--------------------------------------------------------------------------


%--------------------------------------------------------------------------
% set point for the linarization: hovering
%--------------------------------------------------------------------------
output_lin = [0 0 0 0];
input_lin  = [0];


%--------------------------------------------------------------------------
% linearize Systems
%--------------------------------------------------------------------------
[A_x_est, B_x_est, C_x_est, D_x_est] = ...
          linmod( 'SimulinkModel_hquad_lin_pitch_kalman_SI', output_lin, input_lin );
      
[A_y_est, B_y_est, C_y_est, D_y_est] = ...
          linmod( 'SimulinkModel_hquad_lin_roll_kalman_SI', output_lin, input_lin );
      
% use the position output for position control-> remove velocity and
% pitch
A_x=A_x_est;
B_x=B_x_est;
C_x=C_x_est(1,:);
D_x=D_x_est(1,:);
      
A_y=A_y_est;
B_y=B_y_est;
C_y=C_y_est(1,:);
D_y=D_y_est(1,:);
      
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

% W_x= 1*diag([1,1,0.01*ones(1,delay_pade_order),1,1]); % Q kalman
% V_x = 1*diag([0.000707,0.0007,0.0001]);   % R kalman

% % -----------------------------
% % version 2 - optimized for vicon
% % -----------------------------
% VERSION_NR = 2;
% Q_x = 1*diag([100,20,0.01*ones(1,delay_pade_order),0.1,5000]);      % states ( x, x_dot , ??, ??)
% R_x = 350;                       % inputs ( pitch )
% gamma_x = 60;                     % integral action

% W_x= 1*diag([1,1,0.01*ones(1,delay_pade_order),1,1]); % Q kalman
% V_x = 1*diag([0.000707,0.0007,0.0001]);   % R kalman

% % -----------------------------
% % version 3 - optimized for camera
% % -----------------------------
VERSION_NR = 3;
Q_x = 1*diag([100,30,0.01*ones(1,delay_pade_order),1,0.001]);      % states ( x, x_dot , ??, ??)
R_x = 120;                       % inputs ( pitch )
gamma_x = 30;                     % integral action

W_x= 1*diag([0.007,0.007,0.01*ones(1,delay_pade_order),0.001,1]); % Q kalman
V_x = 1*diag([0.000707,0.007,0.001]);   % R kalman

% use same parameters for y controller

Q_y = Q_x;                        % states ( y, y_dot , ??, ??)
R_y = R_x;                       % inputs ( roll )
gamma_y = gamma_x;               % integral action

W_y= W_x;       % Q kalman
V_y = V_x;      % R kalman

                           
%--------------------------------------------------------------------------
% lqri controller discret
%--------------------------------------------------------------------------

Znm= zeros(n,m); Zmm=zeros(m,m);
Znn=zeros(n,n); Zmn= zeros(m,n);

% add integrator to the lqr controller for position
A = [A_x Znm; -C_x Zmm];
B = [B_x;-D_x];

sysLin_xint = ss(A,B,[C_x Zmm],D_x);
sysdLin_xint = c2d(sysLin_xint, Ts, 'zoh');

Q_xint = [Q_x Znm; Zmn gamma_x*eye(m,m)];

Kr=dlqr(sysdLin_xint.a,sysdLin_xint.b,Q_xint,R_x);

K_x_SI = Kr(1:m,1:n);
K_I_x_SI = Kr(1:m,n+1:n+m);

%--------------------------------------------------------------------------
% kalman estimator discret
%--------------------------------------------------------------------------


Bnoise =1*eye(n);

Estss_x = ss(A_x_est, [B_x_est Bnoise], C_x_est,0);
[kest_x_SI,L_y,P_y] = kalman(Estss_x,W_x,V_x);
kest_x_SI=c2d(kest_x_SI,Ts, 'zoh');

% Estssd_x = c2d(Estss_x, Ts, 'zoh');
% [kest_x_SI_d,L2,P2] = kalman(Estssd_x,W_x,V_x)


%==========================================================================
%
% Save the Controller
%
%==========================================================================
PATH_CTRL_x = ['../Hquad_CTRL_OBSV_parameters/ctrl_lqri_x_v'...
                    num2str(VERSION_NR) '.mat'];
save(PATH_CTRL_x, 'K_x_SI', 'K_I_x_SI', 'kest_x_SI');




%--------------------------------------------------------------------------
% lqri controller discret
%--------------------------------------------------------------------------

% add integrator to the lqr controller for position
A = [A_y Znm; -C_y Zmm];
B = [B_y;-D_y];

sysLin_yint = ss(A,B,[C_y Zmm],D_y);
sysdLin_yint = c2d(sysLin_yint, Ts, 'zoh');

Q_yint = [Q_y Znm; Zmn gamma_y*eye(m,m)];

Kr=dlqr(sysdLin_yint.a,sysdLin_yint.b,Q_yint,R_y);

K_y_SI = Kr(1:m,1:n);
K_I_y_SI = Kr(1:m,n+1:n+m);

%--------------------------------------------------------------------------
% kalman estimator discret
%--------------------------------------------------------------------------


Bnoise =1*eye(n);

Estss_y = ss(A_y_est, [B_y_est Bnoise], C_y_est,0);
[kest_y_SI,L,P] = kalman(Estss_y,W_y,V_y);
kest_y_SI=c2d(kest_y_SI,Ts, 'zoh');

%==========================================================================
%
% Save the Controller
%
%==========================================================================


PATH_CTRL_y = ['../Hquad_CTRL_OBSV_parameters/ctrl_lqri_y_v'...
     num2str(VERSION_NR) '.mat'];
save(PATH_CTRL_y, 'K_y_SI', 'K_I_y_SI', 'kest_y_SI');

%==========================================================================
%
% Testing / Run the Simulation
%
%==========================================================================
% lqr_sim
% 
