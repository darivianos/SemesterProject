%==========================================================================
%
% Project:      IR control for the Hquad
%
% function:     simulate the discrete kalman filter 
%
% inputs :      kalm_struct - discrete kalman filter
%               u           - commands
%               y           - measurements
%               x_init      - initial state
%
% outputs :     x_state     - estimated states
%
%
% Author:       Michael Burri
%
%--------------------------------------------------------------------------
% created:  19.08.2011  v0.1    burrimi 
%==========================================================================

function [ x_state ] = simulate_kalman( kalm_struct, u, y, x_init)

num_of_steps=size(u,2);
n=size(x_init,1);

% load parameters for kalman filter
A=kalm_struct.A;
B=kalm_struct.B;
C=kalm_struct.C;
Q=kalm_struct.Q;
R=kalm_struct.R;

%init filter
x_state(:,1)=x_init;
P=kalm_struct.Z;

tic
for i=2:num_of_steps
    % Time update
    x_=A*x_state(:,i-1)+B*u(:,i-1);
    P_=A*P*A'+Q;
    
  
    %measurement update
    Kk=P_*C'*(C*P_*C'+R)^-1;
    x_state(:,i)=x_+Kk*(y(:,i)-C*x_);
    P=(eye(n)-Kk*C)*P_;
end



end

