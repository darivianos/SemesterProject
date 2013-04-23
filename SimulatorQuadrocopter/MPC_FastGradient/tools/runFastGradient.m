function [J, V, actual_num_iters] = ...
    runFastGradient(TT_PP, LL_PP, MM, V_min, V_max, V_init, i_min, betas, L, sol)
%#eml

% Implementation of the fast gradient method for problem:
% J_star = min 0.5 V' TT_PP V + LL_PP V + MM 
% s.t. V_min <= V <= V_max
%
% Note: We do not assume V_min + V_max = 0!
% NOTE 2: LL_PP_t=LL_PP' is the transpose of LL_PP, this is done to
% optimize for speed
%
% The return value V is a feasible solution candidate and J is the associated cost.
% i_min is the number of iterations to be performed after initialization from
% V_init, and betas
% contains the pre-computed step-lengths whereas L is the maximum eigenvalue
% of TT_PP.

% If sol is non-empty then the
% following structure is assumed:
% sol.opt_val ... pre-computed optimal value (by another method)
% sol.eps     ... required absolute solution accuracy
% If sol is given, then the algorithm will terminate whenever J -
% sol.opt_val < sol.eps and return the actual number of iterations in
% actual_num_iters. If after i_min iterations the epsilon solution could
% not be reached, actual_num_iters = inf is returned
%
% (c) by Stefan Richter

% residuals = []; just for testing new convergence result idea
 
% check if there is the sol argument
MONITOR = 0;
actual_num_iters = inf;
if ~isempty(sol)
    MONITOR = 1;
end

% Run fast gradient method
% initialization:
L_inv = 1/L;
LL_PP_t=LL_PP';

V_i = max( V_min, min ( V_max, V_init - L_inv * (TT_PP * V_init + LL_PP_t) ) );
W_i = V_i;

if MONITOR
    val_i =  0.5 * V_i' * TT_PP * V_i + LL_PP * V_i + MM;
    if (val_i - sol.opt_val) < sol.eps
        actual_num_iters = 0; % initialization step was sufficient
        V = V_i;
        J = val_i;
        return;
    end
end

% now run the fast gradient method:
for i=1:i_min
    V_ip1 = max( V_min, min ( V_max, W_i - L_inv * (TT_PP * W_i + LL_PP_t) ) );
%     residuals = [residuals, norm(V_ip1 - V_i)]; just for testing new
%     convergence result idea
    W_ip1 = V_ip1 + betas(i) * (V_ip1 - V_i);
    
    V_i = V_ip1;
    W_i = W_ip1;
    
    if MONITOR
        val_i =  0.5 * V_i' * TT_PP * V_i + LL_PP * V_i + MM;
        if (val_i - sol.opt_val) < sol.eps
            actual_num_iters = i;
            V = V_i;
            J = val_i;
            return;
        end
    end
end


% return values:
V = V_i;
J =  0.5 * V_i' * TT_PP * V_i + LL_PP * V_i + MM;
if ~MONITOR
    actual_num_iters = i_min;
end

% plot(residuals) just for testing new convergence result idea
