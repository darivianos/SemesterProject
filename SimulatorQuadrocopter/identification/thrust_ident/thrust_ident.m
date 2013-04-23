%==========================================================================
%
% Project:  AIR control for the Hquad 
%
%
% Function: Identifie the thrust dynamics of the attitude controller
%
% Author:   Michael Burri
%
%--------------------------------------------------------------------------
% created:  10.08.2011  v0.1    burrimi
%==========================================================================


close all
Ts=0.02;
% NOTE: Time constant is Ts= 0.02 !!! 

%% prepare data for the identification toolbox

% step of 1 meter with mpc controller
load thrust_1m_camera.mat

% prepare data for identification toolbox
thrust_ident_1m = iddata(thrust',control_thrust_scaled',Ts);

figure
plot(udp_xmit_time_sec,[control_thrust_scaled;thrust]);


% force cmd = 1.5 N
load thrust_1.5N_camera.mat

% prepare data for identification toolbox
thrust_ident_1N5 = iddata(thrust',control_thrust_scaled',Ts);


figure
plot(udp_xmit_time_sec,[control_thrust_scaled',thrust'*thrust_cmd2thrust]);

% force cmd = 1 N
load thrust_1N_camera.mat

% prepare data for identification toolbox
thrust_ident_1N = iddata(thrust',control_thrust_scaled',Ts);

figure
plot(udp_xmit_time_sec,[control_thrust_scaled',thrust'*thrust_cmd2thrust]);

% force cmd = 0.5 N
load thrust_0.5N_camera.mat

% prepare data for identification toolbox
thrust_ident_N5 = iddata(thrust',control_thrust_scaled',Ts);
figure
plot(udp_xmit_time_sec,[control_thrust_scaled',thrust'*thrust_cmd2thrust]);

%% do the identification with dataset 1N5

% 
% [k_thrust, omega_thrust, Td_thrust, est_mod] = estimate_1stOrdSys...
%             (control_thrust_scaled', thrust', Ts, -1 )
% 
% % NOTE: numerator should be  tf( [ 0, k_thrust*omega_thrust ],...
% % but we want SI units as inputs and as outputs -> we remove the scaling 
% % factor from the TF and instead multiply the input of the plant with this
% % scaling factor
% dynamics_thrust_1stOrd_tf = tf( [ 0, omega_thrust ],[ 1, omega_thrust ] );
% 
% % to avoid strange state scaling behaviour of simulink store the model in
% % observable canonical form. This should guarantee, that the first state is
% % always the thrust.
% dynamics_thrust_1stOrd = ss(-omega_roll,omega_roll,1,0);
% 
% thrust_cmd2thrust=1/k_thrust

[k_thrust, Td_thrust, est_mod] = estimate_0thOrdSys...
            (thrust_ident_1N5.InputData, thrust_ident_1N5.OutputData , Ts, -1 )

% NOTE: dynmics should be tf(k_thrust) but we remove scaling from the TF
% and instead multiply the input of the plant with this scaling factor
dynamics_thrust_0thOrd_tf = tf(1);

dynamics_thrust_0thOrd = ss(1);

thrust_cmd2thrust_0thOrd=1/k_thrust
Td_thrust_0thOrd=Td_thrust;

PATH_CTRL = ['dynamics_thrust.mat'];
save(PATH_CTRL, 'thrust_cmd2thrust_0thOrd', 'Td_thrust_0thOrd', 'dynamics_thrust_0thOrd', 'dynamics_thrust_0thOrd_tf');
