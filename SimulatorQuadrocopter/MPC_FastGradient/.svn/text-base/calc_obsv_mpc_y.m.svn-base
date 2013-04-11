%==========================================================================
%
% Project:  IR control for the Hquad
%
% function: calculate the kalman filter with bias extension for the
%           y - Axis
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
Q_y =  1*diag([1e-4,1e-4,1e-3,5e-8]); % Q kalman   
R_y =  1*diag([5.5e-5,5.5e-3,5.5e-4]);   % R kalman  (Qd=Qc/Ts)


%--------------------------------------------------------------------------
% linearize System
%--------------------------------------------------------------------------
[A_y_est, B_y_est, C_y_est, D_y_est] = ...
          dlinmod( 'SimulinkModel_hquad_lin_roll_1stOrd',Ts);
[n,m]=size(B_y_est);
[p,~]=size(C_y_est);

%--------------------------------------------------------------------------
% add bias to command u
% -> x[k+1]=A*x[k]+B*u+B*u_bias
%--------------------------------------------------------------------------
A_obsv_y=[A_y_est B_y_est; zeros(m,n) eye(m)];
B_obsv_y=[B_y_est; zeros(m)];
C_obsv_y=[C_y_est zeros(p,m)];
D_obsv_y=[D_y_est];


%--------------------------------------------------------------------------
% get kalman filter data
%--------------------------------------------------------------------------
[kalm_mpc_y, kalm_mpc_y_ss] = ...
    getKalmanFilter( A_obsv_y, B_obsv_y, C_obsv_y, D_obsv_y, Q_y, R_y, Ts);
  
  
%==========================================================================
%
% Save the Filter
%
%==========================================================================
PATH_CTRL_y = ['../Hquad_CTRL_OBSV_parameters/obsv_mpc_y_v'...
                    num2str(VERSION_NR) '.mat'];
save(PATH_CTRL_y, 'kalm_mpc_y', 'kalm_mpc_y_ss');


%==========================================================================
%
% Testing / Run the Simulation
%
%==========================================================================
% 
validate_kalm_bias_y
