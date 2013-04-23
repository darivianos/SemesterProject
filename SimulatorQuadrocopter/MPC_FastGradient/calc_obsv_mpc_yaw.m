%==========================================================================
%
% Project:  IR control for the Hquad
%
% function: calculate the kalman filter with bias extension for the
%           yaw rate
%
% Author:   Michael Burri
%
%--------------------------------------------------------------------------
% created:  17.08.2011  v0.1    burrimi 
%==========================================================================



%--------------------------------------------------------------------------
% observer : kalman filter
%--------------------------------------------------------------------------
Q_yaw =  1*diag([1e-4,5e-2,1e-8]); % Q kalman   
R_yaw = 1*diag([5.6e-4,5.6e-2]);   % R kalman

%--------------------------------------------------------------------------
% linearize System
%--------------------------------------------------------------------------
[A_yaw_est, B_yaw_est, C_yaw_est, D_yaw_est] = ...
          dlinmod( 'SimulinkModel_hquad_lin_yaw_1stOrd',Ts);
[n,m]=size(B_yaw_est);
[p,~]=size(C_yaw_est);

%--------------------------------------------------------------------------
% add bias to command u
% -> x[k+1]=A*x[k]+B*u+B*u_bias
%--------------------------------------------------------------------------
A_obsv_yaw=[A_yaw_est B_yaw_est; zeros(m,n) eye(m)];
B_obsv_yaw=[B_yaw_est; zeros(m)];
C_obsv_yaw=[C_yaw_est zeros(p,m)];
D_obsv_yaw=[D_yaw_est];


%--------------------------------------------------------------------------
% get kalman filter data
%--------------------------------------------------------------------------
[kalm_mpc_yaw, kalm_mpc_yaw_ss] = ...
    getKalmanFilter( A_obsv_yaw, B_obsv_yaw, C_obsv_yaw, D_obsv_yaw, Q_yaw, R_yaw, Ts);
  
  
%==========================================================================
%
% Save the Filter
%
%==========================================================================
PATH_CTRL_yaw = ['../Hquad_CTRL_OBSV_parameters/obsv_mpc_yaw_v'...
                    num2str(VERSION_NR) '.mat'];
save(PATH_CTRL_yaw, 'kalm_mpc_yaw', 'kalm_mpc_yaw_ss');


%==========================================================================
%
% Testing / Run the Simulation
%
%==========================================================================
% 
validate_kalm_bias_yaw
