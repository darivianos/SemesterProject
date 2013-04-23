%==========================================================================
%
% Project:  IR control for the Hquad 
%
% Task:     MPC - Controlling decoupled SISO case
%
% function:	calculate and design the MPC (fast gradient) - controller in 
%           the x axis
%
% Author:	Michael Burri
%
%--------------------------------------------------------------------------
% created:  01.07.2011  v0.1    burrimi
%           20.08.2011  v0.2    burrimi     Cleaned up 
%==========================================================================

% close all; 

%% load model parameters

[AA, BB, CC, DD] = dlinmod('SimulinkModel_hquad_lin_pitch_1stOrd',Ts);

A = AA;
B = BB;
C = CC;
D = DD;

%--------------------------------------------------------------------------
% tuning parameters
%--------------------------------------------------------------------------
Q = diag([100,30,20]);  % states (x,x_dot,pitch)
R = diag(120);          % command (pitch_cmd)
N = 30; % prediction horizon
u_max = MAX_ANGLE;
delay = Td_pitch_1stOrd; % in seconds


% determine epsilon (how accurate the fast gradient result is in the worst case) 
%epsilon = 1e-1;
epsilon = 1e2;

% only for simulation
simulation_time=10; % simulation time in seconds

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
FG_obj_x=struct();
FG_ctrl_x.A=A;
FG_ctrl_x.B=B;
FG_ctrl_x.C=C;
FG_ctrl_x.D=D;
FG_ctrl_x.TT_PP=TT_PP;
FG_ctrl_x.LL_PP=LL_PP;
FG_ctrl_x.LL_ref_PP=LL_ref_PP;
FG_ctrl_x.LL_U_ref_PP=LL_U_ref_PP;
FG_ctrl_x.MM=MM;
FG_ctrl_x.PP=PP;
FG_ctrl_x.AA_delay=AA_delay;
FG_ctrl_x.BB_delay=BB_delay;
FG_ctrl_x.V_max=V_max;
FG_ctrl_x.i_min=i_min_cs_pre_rough;
FG_ctrl_x.betas=betas;
FG_ctrl_x.L=L;
FG_ctrl_x.pred_horizon=N;
FG_ctrl_x.delay_steps=delay_steps;



%% start simulation

% create step after 1 second
X_ref = [zeros(n,round(1/Ts)) , [1*ones(1,num_of_steps+delay_steps); zeros(n-1,num_of_steps+delay_steps)]];
U_ref = [zeros(m,num_of_steps + 2*delay_steps + N)];


% set initial state
x0 = zeros(n,1);

%--------------------------------------------------------------------------
% simulate system
%--------------------------------------------------------------------------
[x_state, u_opt] = simulate_MPC_FG(FG_ctrl_x, X_ref, U_ref, x0);

% plot system
hold on
plot(0:Ts:(simulation_time+delay_steps*Ts),[x_state(1,:)',X_ref(1,1:num_of_steps+delay_steps+1)',x_state(2,:)',u_opt(1,:)']);
axis([0 10 -1 4]);

%% save all precalculated values for simulink
PATH_CTRL = ['../Hquad_CTRL_OBSV_parameters/ctrl_mpc_x_v'...
                    num2str(VERSION_NR) '.mat'];
save(PATH_CTRL, 'FG_ctrl_x');

