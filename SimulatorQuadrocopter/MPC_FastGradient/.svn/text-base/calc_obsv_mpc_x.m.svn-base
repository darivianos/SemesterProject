%==========================================================================
%
% Project:  IR control for the Hquad
%
% function: calculate the kalman filter with bias extension for the
%           x - Axis
%
% Author:   Michael Burri
%
%--------------------------------------------------------------------------
% created:  17.08.2011  v0.1    burrimi 
%==========================================================================



%--------------------------------------------------------------------------
% observer : kalman filter
%--------------------------------------------------------------------------
VERSION_NR=1;
Q_x =  1*diag([1e-4,1e-4,1e-3,5e-8]); % Q kalman   
R_x =  1*diag([5.5e-5,5.5e-3,5.5e-4]);   % R kalman  (Qd=Qc/Ts)


%--------------------------------------------------------------------------
% linearize System
%--------------------------------------------------------------------------
[A_x_est, B_x_est, C_x_est, D_x_est] = ...
          dlinmod( 'SimulinkModel_hquad_lin_pitch_1stOrd',Ts);
[n,m]=size(B_x_est);
[p,~]=size(C_x_est);

%--------------------------------------------------------------------------
% add bias to command u
% -> x[k+1]=A*x[k]+B*u+B*u_bias
%--------------------------------------------------------------------------
A_obsv_x=[A_x_est B_x_est; zeros(m,n) eye(m)];
B_obsv_x=[B_x_est; zeros(m)];
C_obsv_x=[C_x_est zeros(p,m)];
D_obsv_x=[D_x_est];


%--------------------------------------------------------------------------
% get kalman filter data
%--------------------------------------------------------------------------
[kalm_mpc_x, kalm_mpc_x_ss] = ...
    getKalmanFilter( A_obsv_x, B_obsv_x, C_obsv_x, D_obsv_x, Q_x, R_x, Ts);
  
%==========================================================================
%
% Save the Filter
%
%==========================================================================
PATH_CTRL_x = ['../Hquad_CTRL_OBSV_parameters/obsv_mpc_x_v'...
                    num2str(VERSION_NR) '.mat'];
save(PATH_CTRL_x, 'kalm_mpc_x', 'kalm_mpc_x_ss');


%==========================================================================
%
% Testing / Run the Simulation
%
%==========================================================================
% 
validate_kalm_bias_x
