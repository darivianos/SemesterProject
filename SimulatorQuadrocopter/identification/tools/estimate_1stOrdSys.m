function [ k, omega, Td, est_mod ] = estimate_1stOrdSys( input, output, Ts, delay)
% ESTIMATE_1STORDSYS 
% 
% function :    estimates a 1nd order system, of the form
%                              1
%                 P(s) = k ---------
%                          s + omega 
%
% inputs :      input_data  - measured data to the model
%               output_data - measured data from the model
%               Ts          - sampling time of the data
%               delay       - fixed delay (or -1 for estimation of the 
%                             delay)
%
% outputs :     k       - gain
%               omega   - (-1)pole
%               Td      - Delay
%               est_mod - estimated model
% 
% Author:   Rueesch Andreas
%           Michael Burri
% 
% --------------------------------------------------------------------

% transfer the data for the Identification Toolbox
data_est = iddata(double(output),double(input),Ts);

% Estimate model with one pole1 and a delay 
if ( delay > 0 )
    est_mod = pem(data_est, 'P1D', 'Td', 'fix', 'Td', delay);
else
     est_mod = pem(data_est, 'P1D');
end

Td = est_mod.Td.value;
k = est_mod.Kp.value;
omega = 1/est_mod.Tp1.value;

end

