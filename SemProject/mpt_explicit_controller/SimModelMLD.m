function [sys,x0,str,ts] = SimModelMLD(t,x,u,flag,model,x_init)
% Simulation Model of PWA systems for Simulink
%
% use: drag a simulink block of type 'S-function' in your simulink model
%      set the function name to hylink and the filename as parameter.
%      The optional parameter x0 sets the initial state.
%      Use multiplex/demultiplex to access all the inputs/outputs
%   
% Created by Darivianakis Georgios (MSc Robotics Systems and Control)
% email: darivianos@gmail.com

switch flag,
  % Initialization
  case 0,                                                
    [sys,str,ts] = mdlInitializeSizes(model);    
    if nargin > 5,
        x0 = x_init;
    else
        x0 = [0;0;0;0];
    end
  % Update 
  case 2,                                               
    sys = mdlUpdate(t,x,u,model);
  % Output
  case 3,                                               
    sys = mdlOutputs(t,x,u,model);    
  % Terminate 
  case 9,                                               
    sys = [];

  otherwise
    error(['unhandled flag = ',num2str(flag)]);
end

%end hylink

% mdlInitializeSizes
% Return the sizes, initial conditions, and sample times for the S-function.
function [sys,str,ts]=mdlInitializeSizes(model)

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
ts  = [-1 0]; % Sample period of 1 seconds (1Hz)

% mdlUpdate
% Handle discrete state updates, sample time hits, and major time step
% requirements.
function sys = mdlUpdate(t,x,u,model)
model.initialize(x);
sys = model.update(u);    

% mdlOutputs
% Return the output vector for the S-function
function sys = mdlOutputs(t,x,u,model)
model.initialize(x);
[~,sys] = model.update(u);

%end mdlOutputs

