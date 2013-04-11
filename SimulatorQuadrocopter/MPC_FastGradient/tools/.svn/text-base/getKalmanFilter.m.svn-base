%==========================================================================
%
% Project:      IR control for the Hquad
%
% function:     calculate the discrete kalman filter 
%
% inputs :      Ad,Bd,Cd,Dd - discrete time model
%               Qd          - discrete process noise covariance matrix 
%               Rd          - discrete measurement noise covariance matrix  
%               Ts          - Sampling time
%
% outputs :     kalm_struct - kalman filter struct
%               kalm_obj    - matlab ss kalman filter
%
%
% Author:       Michael Burri
%
%--------------------------------------------------------------------------
% created:  18.08.2011  v0.1    burrimi 
%==========================================================================

function [kalm_struct, kalm_obj] = getKalmanFilter( Ad, Bd, Cd, Dd, Qd, Rd, Ts)

[n,m]=size(Bd);
[p,~]=size(Cd);

% add noise to all states
Gd = [eye(n)];
Hd = zeros(p,n);

% prepare data for the discrete kalman filter
Estss_d = ss(Ad, [Bd Gd], Cd, [Dd Hd],Ts);

% get kalman filter data
[kalm_obj,L_kalm,P_kalm,M_kalm,Z_kalm] = kalman(Estss_d,Qd,Rd);


% create kalman filter struct
kalm_struct=struct();
kalm_struct.A=Ad;
kalm_struct.B=Bd;
kalm_struct.C=Cd;
kalm_struct.D=Dd;
kalm_struct.Q=Qd;
kalm_struct.R=Rd;
kalm_struct.M=M_kalm;
kalm_struct.L=L_kalm;
kalm_struct.P=P_kalm;
kalm_struct.Z=Z_kalm;
kalm_struct.Ts=Ts;

end

