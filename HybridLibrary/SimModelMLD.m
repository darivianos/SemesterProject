function [sys,x0,str,ts] = SimModelMLD(t,x,u,flag,model,x_init,Ts)
% Simulation Model of PWA systems for Simulink
%
% use: drag a simulink block of type 'S-function' in your simulink model
%      set the function name to hylink and the filename as parameter.
%      The optional parameter x0 sets the initial state.
%      Use multiplex/demultiplex to access all the inputs/outputs
%   
% Created by Darivianakis Georgios (MSc Robotics Systems and Control)
% email: gdarivia@student.ethz.ch

switch flag,
  % Initialization
  case 0,                                                
    [sys,str,ts] = mdlInitializeSizes(model,Ts);    
    if nargin > 5,
        x0 = x_init;
    else
        x0 = zeros(model.nx,1);
    end
  % Update 
  case 2,                                               
    model.initialize(x);
    [sys,~] = model.update(u);
    % Output
  case 3,                                                
  % Terminate 
    model.initialize(x);
    [~,sys] = model.update(u);
  case 9,                                               
    sys = [];

  otherwise
    error(['unhandled flag = ',num2str(flag)]);
end
return


%end hylink

% mdlInitializeSizes
% Return the sizes, initial conditions, and sample times for the S-function.
function [sys,str,ts]=mdlInitializeSizes(model,Ts)

S = model;

sizes = simsizes;

sizes.NumContStates  = 0;
sizes.NumDiscStates  = S.nx;
sizes.NumOutputs     = S.ny;
sizes.NumInputs      = S.nu;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 1;

sys = simsizes(sizes);

str = [];
ts  = [Ts 0]; % Sample period of 1 seconds (1Hz)
return
