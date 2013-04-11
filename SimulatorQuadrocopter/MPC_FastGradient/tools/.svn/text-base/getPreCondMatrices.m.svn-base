function [TT_PP, LL_PP, LL_ref_PP, LL_U_ref_PP HH_PP, KK] = ...
    getPreCondMatrices(TT, LL, LL_ref, LL_U_ref, PP, N, u_min, u_max)
%
% create problem matrices for preconditioned problem 
% (see notes from 9.6.2010)
%
% (c) by Stefan Richter
%
% 05.07.11
% modified for reference tracking by Michael Burri

TT_PP = PP' * TT * PP;
LL_PP = LL * PP;
LL_ref_PP = LL_ref * PP;
LL_U_ref_PP = LL_U_ref * PP;

m = length(u_min);
HH = kron(eye(N), [eye(m); -eye(m)]);
HH_PP = HH * PP;
KK = kron(ones(N,1), [u_max; -u_min]);

