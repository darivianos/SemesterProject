function [i_min, i_min_lin, i_min_sublin] = ...
    getLowerIterBound(TT, PP, epsilon, rho)
% 
% computes the lower iteration bound and gives both linear and sublinear
% bound acc. to the journal paper.
%
% (c) by Stefan Richter

eigs = eig(PP' * TT * PP);
mu = min(eigs);
L = max(eigs);

i_min_lin = ceil((log(epsilon) - log(rho)) / log(1 - sqrt(mu/L)));
i_min_sublin = ceil(2*(sqrt(rho/epsilon) - 1));
i_min = max(0, min(i_min_lin, i_min_sublin));