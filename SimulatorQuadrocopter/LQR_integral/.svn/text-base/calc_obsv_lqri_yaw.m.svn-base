%==========================================================================
%
% Project:  IR control for the Hquad
%
% function: calculate the kalman filter for the yaw - Axis
%
% Author:   Michael Burri
%
%--------------------------------------------------------------------------
% created:  17.08.2011  v0.1    burrimi 
%==========================================================================


%--------------------------------------------------------------------------
% linearize System
%--------------------------------------------------------------------------
[A_yaw, B_yaw, C_yaw, D_yaw] = ...
          linmod( 'SimulinkModel_hquad_lin_yaw_1stOrd');
      
[n,m]= size(B_yaw);
p = size(C_yaw,1);


%--------------------------------------------------------------------------
% tuning parameters
%--------------------------------------------------------------------------


% % -----------------------------
% % version 1 - optimized for vicon
% % -----------------------------
VERSION_NR = 1;

Q_yaw = 1*diag([1e-2,1e-1,0.01*ones(1,delay_pade_order)]); % Q kalman
R_yaw = 1*diag([1e-5,1e-3]);   % R kalman

%--------------------------------------------------------------------------
% kalman estimator discret
%--------------------------------------------------------------------------

[kalm_lqri_yaw, kalm_lqri_yaw_ss] = ...
    getKalmanFilterFromContinuous( A_yaw, B_yaw, C_yaw, D_yaw, Q_yaw, R_yaw, Ts);

%==========================================================================
%
% Save the Filter
%
%==========================================================================
PATH_CTRL_yaw = ['../Hquad_CTRL_OBSV_parameters/obsv_lqri_yaw_v'...
                    num2str(VERSION_NR) '.mat'];
save(PATH_CTRL_yaw, 'kalm_lqri_yaw' , 'kalm_lqri_yaw_ss');


%==========================================================================
%
% Testing / Run the Simulation
%
%==========================================================================
%
validate_kalman_yaw
