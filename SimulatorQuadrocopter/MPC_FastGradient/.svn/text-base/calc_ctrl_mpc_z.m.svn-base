%==========================================================================
%
% Project:  IR control for the Hquad 
%
% Task:     MPC - Controlling decoupled SISO case
%
% function:	calculate and design the MPC (fast gradient) - controller in 
%           the z axis
%
% Author:	Michael Burri
%
%--------------------------------------------------------------------------
% created:  01.07.2011  v0.1    burrimi
%           20.08.2011  v0.2    burrimi     Cleaned up 
%==========================================================================

% close all; 

%% load model parameters

[AA, BB, CC, DD] = dlinmod('SimulinkModel_hquad_lin_thrust_0thOrd',Ts);

A = AA;
B = BB;
C = CC;
D = DD;

%--------------------------------------------------------------------------
% tuning parameters
%--------------------------------------------------------------------------
Q = diag([100,30]);         % states (z,z_dot)
R = diag(15);               % command (thrust_cmd)
N = 30;                     % prediction horizon
u_max = MAX_FORCE;          % max command
delay = Td_thrust_0thOrd;   % delay in seconds


% determine epsilon (how accurate the fast gradient result is in the worst case) 
%epsilon = 1e-2;
epsilon = 1e2;

% only for simulation
simulation_time=10;

% only for storing the data
VERSION_NR=2;

%% get all data for fast gradient method

[n, m] = size(B);
delay_steps=round(delay/Ts);
num_of_steps=floor(simulation_time/Ts);


% get all data needed for the fast gradient method
[TT_PP,LL_PP, LL_ref_PP, LL_U_ref_PP, MM, V_min, V_max, i_min_cs_pre_rough, betas, L, PP] = ...
    getFastGradientData(A,B,Q,R,N,u_max,epsilon);


% Matrices to predict actual non-delayed state
[AA_delay, BB_delay] = getDelayMatrices(A, B, delay_steps);

% create FG controller struct
FG_obj_z=struct();
FG_ctrl_z.A=A;
FG_ctrl_z.B=B;
FG_ctrl_z.C=C;
FG_ctrl_z.D=D;
FG_ctrl_z.TT_PP=TT_PP;
FG_ctrl_z.LL_PP=LL_PP;
FG_ctrl_z.LL_ref_PP=LL_ref_PP;
FG_ctrl_z.LL_U_ref_PP=LL_U_ref_PP;
FG_ctrl_z.MM=MM;
FG_ctrl_z.PP=PP;
FG_ctrl_z.AA_delay=AA_delay;
FG_ctrl_z.BB_delay=BB_delay;
FG_ctrl_z.V_max=V_max;
FG_ctrl_z.i_min=i_min_cs_pre_rough;
FG_ctrl_z.betas=betas;
FG_ctrl_z.L=L;
FG_ctrl_z.pred_horizon=N;
FG_ctrl_z.delay_steps=delay_steps;

%% start simulation

% create step after 1 second
X_ref = [zeros(n,round(1/Ts)) , [1*ones(1,num_of_steps+delay_steps); zeros(n-1,num_of_steps+delay_steps)]];
U_ref = [zeros(m,num_of_steps + 2*delay_steps + N)];

% set initial state
x0 = zeros(n,1);

%--------------------------------------------------------------------------
% simulate system
%--------------------------------------------------------------------------
[x_state, u_opt] = simulate_MPC_FG(FG_ctrl_z, X_ref, U_ref, x0);

% plot systems
hold on
plot(0:Ts:(simulation_time+delay_steps*Ts),[x_state(1,:)',X_ref(1,1:num_of_steps+delay_steps+1)',x_state(2,:)',u_opt(1,:)']);
axis([0 10 -2 2]);

%% save all precalculated values for simulink
TT_PP_z=TT_PP;
LL_PP_z=LL_PP;
LL_ref_PP_z=LL_ref_PP;
MM_z=MM;
PP_z=PP;
AA_delay_z=AA_delay;
BB_delay_z=BB_delay;
V_max_z=V_max;
i_min_cs_pre_rough_z=i_min_cs_pre_rough;
betas_z=betas;
L_z=L;
pred_horizon_z=N;

delay_steps_z=delay_steps;

PATH_CTRL = ['../Hquad_CTRL_OBSV_parameters/ctrl_mpc_z_v'...
                    num2str(VERSION_NR) '.mat'];
save(PATH_CTRL, 'FG_ctrl_z');

