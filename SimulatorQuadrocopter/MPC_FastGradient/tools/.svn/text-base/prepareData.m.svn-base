function [TT_PP, LL_PP, LL_ref_PP, LL_U_ref_PP, V_min, V_max, betas, L] = ...
    prepareData(TT, LL, LL_ref, LL_U_ref, PP, N, u_min, u_max, i_min)
% 
% Prepares all necessary data for the fast gradient method, where TT is the
% original Hessian, PP is a diagonal preconditioner.
%
% (c) by Stefan Richter

if (abs(PP - diag(diag(PP))) > 1e-10)
    error('In the current implementation only diagonal preconditioners PP are allowed.')
end

[TT_PP, LL_PP, LL_ref_PP, LL_U_ref_PP, ~, ~] = ...
    getPreCondMatrices(TT, LL, LL_ref, LL_U_ref, PP, N, u_min, u_max);
V_min = inv(PP) * kron(ones(N,1), u_min);
V_max = inv(PP) * kron(ones(N,1), u_max);
eigs = eig(TT_PP);
mu = min(eigs)
L = max(eigs)
cond_number=L/mu
% compute beta's:
alpha_i = -0.5*(1-mu/L) + sqrt((1-mu/L)^2 / 4 + 1); % initialization
betas = zeros(i_min,1);

for i = 1:i_min
    alpha_ip1_1 = -0.5*(alpha_i^2 - mu/L) + sqrt(1/4 * (alpha_i^2 - mu/L)^2 + alpha_i^2);
    alpha_ip1_2 = -0.5*(alpha_i^2 - mu/L) - sqrt(1/4 * (alpha_i^2 - mu/L)^2 + alpha_i^2);
    alpha_ip1 = inf;
    if (alpha_ip1_1 < 1) && (alpha_ip1_1 > 0)
        alpha_ip1 = alpha_ip1_1;
    elseif (alpha_ip1_2 < 1) && (alpha_ip1_2 > 0)
        alpha_ip1 = alpha_ip1_2;
    else
        disp(alpha_ip1_1), disp(alpha_ip1_2)
        error('alpha_ip1 must be in (0,1)!')
    end
    betas(i) = alpha_i * (1 - alpha_i) / (alpha_i^2 + alpha_ip1);
    alpha_i = alpha_ip1;
end