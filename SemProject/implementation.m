% Main implementation
%%
close all
clear all
clear classes
clc
%% Initialization
% Define Parameters
m = 0.650;
g = 9.8065;
Theta = -deg2rad(3);
% Controller Sampling Time
Ts = 0.08;
model = GenerateModel('QuadXDirection',Theta,Ts);
% Simulation Sampling Time (50 Hz)
TsReal = 0.02;
modelReal = GenerateModel('QuadXDirectionSimulink',Theta,TsReal);

%%

% %%  Simulate Open Loop
% x0 = [0 0 -0.1 0 ]';
% model.initialize(x0);
% 
% U = -deg2rad(5)*ones(1,50);
% data = model.simulate(U);
% 
% time = [0:Ts:49*Ts];
% figure(1);
% subplot(5,1,1)
% plot(time,data.Y(1,:)); grid on;ylabel('angle');
% subplot(5,1,2)
% plot(time,data.Y(2,:)); grid on;ylabel('omega');
% subplot(5,1,3)
% plot(time,data.Y(3,:)); grid on;ylabel('position')
% subplot(5,1,4)
% plot(time,data.Y(4,:)); grid on;ylabel('velocity')
% subplot(5,1,5)
% plot(time,data.Y(5,:)); grid on;ylabel('Force')

%% Optimization problem set up
Qy = zeros(5,5);
Qy(3,3) = 100; % when we have the switching this cost will be zero.
Qy(4,4) = 10;
Qy(5,5) = 1; % when in free flight this error doesn't affect optimization
R = 1;
Q = zeros(4,4);
% reference signals calculation Xss = A*Xss+B*Uref
yref = [Theta;0;0;0;-m*g*Theta]; % ensure that the angle of arrival is not positive 
xref = [Theta;0;0;0];
B = model.B{1};
A = model.A{1};
uref = (B'*B)\B'*(eye(4) - A)*xref;


N = 5;
norm = 2;

ctrl = MPCController(model);
ctrl.N = N;

% add quadratic penalty on the inputs
ctrl.model.u.penalty = Penalty(R, norm);
% add quadratic penalty on the states
ctrl.model.x.penalty = Penalty(Q, norm);
% add quadratic penalty on the output
ctrl.model.y.penalty = Penalty(Qy, norm);

% Define output reference signal
ctrl.model.y.with('reference');
ctrl.model.y.reference = yref;
ctrl.model.u.with('reference');
ctrl.model.u.reference = uref;

% Define Terminal Set
% ctrl.model.x.with('terminalSet');
% ctrl.model.x.terminalSet = Polyhedron('Ae',Ae,'be',be);
expmpc = ctrl.toExplicit();
save;
% Create Look Up Table, code in C
exportToC_MLD(expmpc,Ts);
cd mpt_explicit_controller
mex mpt_getInput_sfunc.c;
x0 = [0;0;-1;0];
% Open Loop Simulation
%% Simulate the closed loop
% N_sim = 50;
% 
% % Create the closed-loop system:
% loop = ClosedLoop(expmpc, model);
% ClosedData = loop.simulate(x0, N_sim);
% 
% N = size(ClosedData.Y(1,:),2);
% time = zeros(N,1);
% Fref = zeros(N,1);
% thetaref = zeros(N,1);
% k=1;
% for i = 0:Ts:(N-1)*Ts
%     time(k) =i;
%     Fref(k) = yref(5);
%     thetaref(k) = yref(1);
%     k = k+1;
% end
% 
% 
% % plot the output
% figure(2);
% subplot(6,1,1)
% plot(time,ClosedData.Y(1,:),time,thetaref,'-g'); grid on;ylabel('angle');
% subplot(6,1,2)
% plot(time,ClosedData.Y(2,:)); grid on;ylabel('omega');
% subplot(6,1,3)
% plot(time,ClosedData.Y(3,:)); grid on;ylabel('position')
% subplot(6,1,4)
% plot(time,ClosedData.Y(4,:)); grid on;ylabel('velocity')
% subplot(6,1,5)
% plot(time,ClosedData.Y(5,:),time,Fref,'-g'); grid on;ylabel('Force')
% subplot(6,1,6)
% plot(time,ClosedData.U(:)); grid on;ylabel('Input')
