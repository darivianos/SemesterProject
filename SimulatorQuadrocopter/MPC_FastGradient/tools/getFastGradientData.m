function [TT_PP,LL_PP, LL_ref_PP, LL_U_ref_PP MM, V_min, V_max, i_min_cs_pre_rough, betas, L, PP]...
    = getFastGradientData(A,B,Q,R,N,u_max,epsilon)
% Fast gradient method for quadrocopter
% 
% Note: Gives matrices according to tech report 2010 for implementation of the
% fast gradient method. Assumes regulation to origin and no penalties on
% the change of inputs.
%
% by Stefan Richter, June 2011

% clear all, clc
%close all;


[~,P,~] = dlqr(A,B,Q,R);

[n, m] = size(B);

u_min = -u_max;

% get matrices
[TT, LL, LL_ref, LL_U_ref, MM] = ...
    getQPMatrices(A, B, zeros(size(B)), Q, R, P, N);

%PP = diag(sqrt(1./diag(TT))); % heuristic preconditioner that often works well
PP = eye(N);

% compute feasible set radius
% NOTE: Only correct if bounds on u are symmetric around the origin!!!
r_min_squ_cs_pre_rough = ...
    max(eig((PP') * TT * PP))/2 * norm(inv(PP) * kron(ones(N,1), u_max), 2)^2;


% rough lower iteration bound bound
[i_min_cs_pre_rough, i_min_lin_rough, i_min_sublin_rough] = ...
    getLowerIterBound(TT, PP, epsilon, r_min_squ_cs_pre_rough);

% rough bound on flops
flops_cs_pre_rough = getNumFlops(N,m,n,i_min_cs_pre_rough)

% estimated solution time
time_per_flop = 1/1e9;
est_time = flops_cs_pre_rough * time_per_flop;
disp(['Estimated solution time (', num2str(i_min_cs_pre_rough), ' iterations): ', ...
    num2str(est_time), ' sec'])


% get data for fast gradient method (preconditioned with PP!)
[TT_PP, LL_PP, LL_ref_PP, LL_U_ref_PP, V_min, V_max, betas, L] = ...
    prepareData(TT, LL, LL_ref, LL_U_ref, PP, N, u_min, u_max, i_min_cs_pre_rough);

