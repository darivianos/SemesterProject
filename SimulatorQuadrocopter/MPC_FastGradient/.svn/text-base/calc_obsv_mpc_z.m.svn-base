%==========================================================================
%
% Project:  IR control for the Hquad
%
% function: calculate the kalman filter with bias extension for the
%           z - Axis
%
% Author:   Michael Burri
%
%--------------------------------------------------------------------------
% created:  17.08.2011  v0.1    burrimi 
%==========================================================================



%--------------------------------------------------------------------------
% observer : kalman filter
%--------------------------------------------------------------------------
Q_z =  1*diag([5e-4,1e-4,5e-7]); % Q kalman   
R_z =  1*diag([5.5e-5,5.5e-3]);   % R kalman  (Qd=Qc/Ts)
     
%--------------------------------------------------------------------------
% linearize System
%--------------------------------------------------------------------------
[A_z_est, B_z_est, C_z_est, D_z_est] = ...
          dlinmod( 'SimulinkModel_hquad_lin_thrust_0thOrd',Ts);
[n,m]=size(B_z_est);
[p,~]=size(C_z_est);

%--------------------------------------------------------------------------
% add bias to command u
% -> x[k+1]=A*x[k]+B*u+B*u_bias
%--------------------------------------------------------------------------
A_obsv_z=[A_z_est B_z_est; zeros(m,n) eye(m)];
B_obsv_z=[B_z_est; zeros(m)];
C_obsv_z=[C_z_est zeros(p,m)];
D_obsv_z=[D_z_est];


%--------------------------------------------------------------------------
% get kalman filter data
%--------------------------------------------------------------------------
[kalm_mpc_z, kalm_mpc_z_ss] = ...
    getKalmanFilter( A_obsv_z, B_obsv_z, C_obsv_z, D_obsv_z, Q_z, R_z, Ts);
  
  
%==========================================================================
%
% Save the Filter
%
%==========================================================================
PATH_CTRL_z = ['../Hquad_CTRL_OBSV_parameters/obsv_mpc_z_v'...
                    num2str(VERSION_NR) '.mat'];
save(PATH_CTRL_z, 'kalm_mpc_z', 'kalm_mpc_z_ss');


%==========================================================================
%
% Testing / Run the Simulation
%
%==========================================================================
% 
validate_kalm_bias_z
