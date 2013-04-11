%==========================================================================
%
% Project:      IR control for the Hquad
%
% function:     simulate the mpc model, by using the fast gradient method 
%
% inputs :      FG_struct   - Precalculated Fast Gradient data
%               X_ref       - reference trajectory (states)
%               U_ref       - reference trajectory (commands)
%               x_init      - initial state
%
% outputs :     x_state     - simulated states
%
%
% Author:       Michael Burri
%
%--------------------------------------------------------------------------
% created:  19.08.2011  v0.1    burrimi 
%==========================================================================

function [ x_state, u_opt ] = simulate_MPC_FG( FG_struct, X_ref, U_ref , x_init )


% load all parameters from FG_struct (for readability)
A = FG_struct.A;
B = FG_struct.B;
C = FG_struct.C;
D = FG_struct.D;
TT_PP = FG_struct.TT_PP;
LL_PP = FG_struct.LL_PP;
LL_ref_PP = FG_struct.LL_ref_PP;
LL_U_ref_PP = FG_struct.LL_U_ref_PP;
MM = FG_struct.MM;
PP = FG_struct.PP;
AA_delay = FG_struct.AA_delay;
BB_delay = FG_struct.BB_delay;
V_max = FG_struct.V_max;
V_min = -V_max;
i_min = FG_struct.i_min;
betas = FG_struct.betas;
L = FG_struct.L;
N = FG_struct.pred_horizon;
delay_steps = FG_struct.delay_steps;


% get problem size
num_of_steps=size(U_ref,2) - 2*delay_steps - N;
n=size(x_init,1);
m=size(U_ref,1);


% reshape reference vector for fg
X_ref_shaped=reshape(X_ref,1,[])';
U_ref_shaped=reshape(U_ref,1,[])';


%% start simulation

% init variables
x_state=zeros(n,num_of_steps+1+delay_steps);
u_opt=zeros(m,num_of_steps+1+delay_steps);
u_pref=zeros(m*delay_steps,1);
x_state(:,1:delay_steps+1)=x_init*ones(1,delay_steps+1);
V_init=(V_min + V_max)/2;

tic
for i=1+delay_steps:num_of_steps+delay_steps

    % predict non-delayed state
    if(delay_steps==0)
        x_predicted=x_state(:,i);
    else
        x_predicted=AA_delay*x_state(:,i)+BB_delay*u_pref;
    end

    % get predicted reference trajectory
    X_ref_delayed = X_ref_shaped((i+delay_steps-1)*n+1:(i+N+delay_steps)*n,1);
    U_ref_delayed = U_ref_shaped((i+delay_steps-1)*m+1:(i+N+delay_steps-1)*m,1);
    
    % set optimization variables
    LL_PP_ref=x_predicted'*LL_PP - X_ref_delayed'*LL_ref_PP - U_ref_delayed' * LL_U_ref_PP;
    MM_ref = x_predicted' * MM * x_predicted; % TODO expand to X_ref, U_ref
    
    % run fast gradient method
    [J_star, V_star, actual_num_iters] = ...
        runFastGradient(TT_PP, LL_PP_ref, MM_ref, V_min, V_max, V_init, ...
        i_min, betas, L, []);

    % Note: Fast gradient method is implemented in variable V where U = PP * V,
    % so don't forget to backtransform after termination:
    U_star = PP * V_star;

    % get optimal command
    if(delay_steps==0)
        uu=U_star(1:m,1);
    else
        uu=u_pref(1:m,1);
        u_pref=[u_pref(2:delay_steps,:); U_star(1:m,1)];
    end
    % update state with delayed optimal command
    x_state(:,i+1)=A*x_state(:,i)+B*uu;
    
    
    % set new initial guess
    V_init=[V_star(2:N);0];
    
    % store optimal control output
    u_opt(:,i)=U_star(1:m,1);

   
end
time_per_timestep=toc/num_of_steps
