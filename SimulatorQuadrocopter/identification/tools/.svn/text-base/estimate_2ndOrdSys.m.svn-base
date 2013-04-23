function [ k, omega, d, Td, est_mod ] = estimate_2ndOrdSys( input, output, Ts, delay)
% ESTIMATE_2NDORDSYS 
% 
% function :    estimates a 2nd order system, of the form
%                              omega²
%                 P(s) = k -----------------------
%                          s² + 2d*omega*s + omega² 
%
% inputs :      input_data  - measured data to the model
%               output_data - measured data from the model
%               Ts          - sampling time of the data
%               delay       - fixed delay 
%
% outputs :     k       - gain
%               omega   - critical frequencey
%               d       - damping
%               Td      - Delay
%               est_mod - estimated model
% 
% Author:   Rueesch Andreas
%           Michael Burri
% 
% --------------------------------------------------------------------

% transfer the data for the Identification Toolbox
data_est = iddata(double(output),double(input),Ts);

% Estimate model with two poles and a delay 
% delay bounded between 20 and 90 ms


% Estimate model with one pole1 and a delay 
if ( delay > 0 )
    est_mod = pem(data_est, 'P2D', 'Td', 'fix', 'Td', delay)
else
     est_mod = pem(data_est, 'P2D');
end



Td = est_mod.Td.value;
k = est_mod.Kp.value;
omega = sqrt(1/(est_mod.Tp1.value*est_mod.Tp2.value));
d =( est_mod.Tp1.value+est_mod.Tp2.value )/ ...
    ( 2 * sqrt(est_mod.Tp1.value*est_mod.Tp2.value) );

end

