%==========================================================================
%
% Project:  AIR control for the Hquad 
%
%
% Function: Compare first order and second order approximation of the pitch
%           angle
%
% Author:   Michael Burri
%
%--------------------------------------------------------------------------
% created:  10.08.2011  v0.1    burrimi
%==========================================================================

sys = ss(dynamics_pitch_1stOrd)
% di = ss(A_x_est, B_x_est, C_x_est, D_x_est);
pitch_delayed_1=ss(sys.a, sys.b, sys.c, 0, 'Inputdelay', Td_pitch_1stOrd);

sys = ss(dynamics_pitch_SI)
% di = ss(A_x_est, B_x_est, C_x_est, D_x_est);
pitch_delayed_2=ss(sys.a, sys.b, sys.c, 0, 'Inputdelay', Td_pitch_SI);

step(pitch_delayed_1,pitch_delayed_2)
legend('1stOrd','2ndOrd');
xlabel('time')
