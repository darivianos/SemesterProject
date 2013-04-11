function [AA_delay, BB_delay] = ...
    getDelayMatrices(A, B, delay_steps)
%
% creates all necessary matrices for the delay of the states
%


[n,m] = size(B);

BB = [];

temp_last_row_BB = [];


for k=1:delay_steps
    if (k==1)
        BB = B;
        temp_last_row_BB = B;
    else
        new_row_BB = [A*temp_last_row_BB, B];
        temp_last_row_BB = new_row_BB;
        BB = [BB, zeros((k-1)*n, m); new_row_BB];
    end
end


if(delay_steps==0)
    BB_delay = zeros(1,m);
else
    BB_delay = temp_last_row_BB;
end

AA_delay = A^delay_steps;
