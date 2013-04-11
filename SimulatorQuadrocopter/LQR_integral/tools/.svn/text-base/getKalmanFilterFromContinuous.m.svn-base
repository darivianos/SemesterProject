%==========================================================================
%
% Project:      IR control for the Hquad
%
% function:     calculate the discrete kalman filter from continuous data
%               This function does the same as kalmd, except that it
%               returns the discretized noise covariance matrixes
%
% inputs :      Ac,Bc,Cc,Dc - discrete time model
%               Qc          - discrete process noise covariance matrix 
%               Rc          - discrete measurement noise covariance matrix  
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

function [kalm_struct, kalm_obj] = getKalmanFilterFromContinuous( Ac, Bc, Cc, Dc, Qc, Rc, Ts)

[n,m]=size(Bc);
[p,~]=size(Cc);

%--------------------------------------------------------------------------
% kalman estimator discret
%--------------------------------------------------------------------------

% add noise to all states
G = 1*eye(n);
H = zeros(p,n);

% copied from kalmd.m and modified to suit my notation --------------------

    % Form G*Q*G', enforce symmetry and check positivity
    qn = G * Qc *G';
    qn = (qn+qn')/2;

    % Compute discrete equivalent of continuous noise
    M = [-Ac  qn ; zeros(n) Ac'];
    phi = expm(M*Ts);
    phi12 = phi(1:n,n+1:2*n);
    phi22 = phi(n+1:2*n,n+1:2*n);
    Qd = phi22'*phi12;
    Qd = (Qd+Qd')/2; % Make sure Qd is symmetric
    Rd = Rc/Ts;

% end copy ================================================================
    
% get discrete time system
[Ad, Bd] = c2d(Ac, Bc, Ts);

% prepare data for the discrete kalman filter
Estss_d = ss(Ad, [Bd G], Cc, [Dc H],Ts);
[kalm_obj,L_kalm,P_kalm,M_kalm, Z_kalm] = kalman(Estss_d,Qd,Rd);
      

% create kalman filter struct
kalm_struct=struct();
kalm_struct.A=Ad;
kalm_struct.B=Bd;
kalm_struct.C=Cc;
kalm_struct.D=Dc;
kalm_struct.Q=Qd;
kalm_struct.R=Rd;
kalm_struct.M=M_kalm;
kalm_struct.L=L_kalm;
kalm_struct.P=P_kalm;
kalm_struct.Z=Z_kalm;
kalm_struct.Ts=Ts;


end

