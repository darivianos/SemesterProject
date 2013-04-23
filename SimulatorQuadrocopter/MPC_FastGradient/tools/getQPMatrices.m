function [TT, LL, LL_ref, LL_U_ref, MM] = ...
    getQPMatrices(A, B, B_w, Q, R, P, N)
%
% creates all necessary matrices for the dense QP formulation
% of the input-constrained MPC problem (see journal 2010 for definitions)
%
% (c) by Stefan Richter

QQ = blkdiag(kron(speye(N), Q), P);
RR = kron(speye(N), R);

[n,m] = size(B);
[temp, m_w] = size(B_w);
AA = [];
BB = [];
BB_w = [];

temp_last_row_BB = [];
temp_last_row_BB_w = [];
temp_last_row_AA = [];
for k=1:N
    if (k==1)
        BB = B;
        temp_last_row_BB = B;
        
        BB_w = B_w;
        temp_last_row_BB_w = B_w;
        
        AA = A;
        temp_last_row_AA = A;
    else
        new_row_BB = [A*temp_last_row_BB, B];
        temp_last_row_BB = new_row_BB;
        BB = [BB, zeros((k-1)*n, m); new_row_BB];
        
        new_row_BB_w = [A*temp_last_row_BB_w, B_w];
        temp_last_row_BB_w = new_row_BB_w;
        BB_w = [BB_w, zeros((k-1)*n, m_w); new_row_BB_w]; %#ok<*AGROW>
        
        new_row_AA = A*temp_last_row_AA;
        temp_last_row_AA = new_row_AA;
        AA = [AA; new_row_AA];
    end
end
% append a row at the beginning:
AA = [speye(n); AA];
BB = [zeros(n, N*m); BB];
BB_w = [zeros(n, N*m_w); BB_w]; % Note: this is not used yet in any computations.

% now we are ready to define the QP matrices:
TT = full(BB' * QQ * BB + RR);
TT = TT/2 + TT'/2; % to improve numerical robustness
LL = full(AA' * QQ * BB);
LL_ref = full(QQ * BB);
LL_U_ref = full( RR );
MM = full(AA' * QQ * AA);
MM = MM/2 + MM'/2; % to improve numerical robustness
