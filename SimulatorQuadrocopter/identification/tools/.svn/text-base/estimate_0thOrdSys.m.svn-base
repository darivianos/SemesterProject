function [ k, Td, est_mod ] = estimate_0thOrdSys( input, output, Ts, delay)
% ESTIMATE_0THORDSYS 
% 
% function :    estimates a 0th order system, of the form
%                          
%                 P(s) = k * exp(-s*Td)
%                         
%
% inputs :      input_data  - measured data to the model
%               output_data - measured data from the model
%               Ts          - sampling time of the data
%               delay       - fixed delay (or -1 for estimation of the 
%                             delay)
%
% outputs :     k       - gain
%               Td      - Delay
%               est_mod - estimated model
% 
% Author:   Rueesch Andreas
%           Michael Burri
% 
% --------------------------------------------------------------------

% transfer the data for the Identification Toolbox
data_est = iddata(double(output),double(input),Ts);

% Estimate model with konstant gain and a delay 
if ( delay > 0 )
    est_mod = pem(data_est, 'P0D', 'Td', 'fix', 'Td', delay);
else
     est_mod = pem(data_est, 'P0D');
end

Td = est_mod.Td.value;
k = est_mod.Kp.value;

end

