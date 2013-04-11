function num_flops = getNumFlops(N,m,n,i_min)
%
% computes the number of expected floating point operations assuming:
% - no memory ops
% - upper/lower constraints
% - N...horizon length, m... number of inputs, n... number of states, 
%   i_min... number of iterations
%
% (c) by Stefan Richter

num_flops_per_iter = 2*(N*m)^2 + 2*N*m*n + 5*N*m;
num_flops = i_min * num_flops_per_iter;