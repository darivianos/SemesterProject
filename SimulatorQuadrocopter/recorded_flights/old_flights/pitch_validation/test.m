% Open-loop system parameters 

% True plant and true initial state
sys=ss(tf({1,1,1},{[1 .5 1],[1 1],[.7 .5 1]}));
x0=[0 0 0 0 0]';

% MPC object setup

Ts=.2;             % sampling time

% Define type of input signals
sys.InputGroup=struct('Manipulated',1,'Measured',2,'Unmeasured',3);

% Define constraints on manipulated variable
MV=struct('Min',0,'Max',1);

Model=[]; % Reset structure Model
Model.Plant=sys;
% Integrator driven by white noise with variance=1000
Model.Disturbance=tf(sqrt(1000),[1 0]); 

p=[];       % Prediction horizon (take default one)
m=3;        % Control horizon
weights=[]; % Default value for weights

MPCobj=mpc(Model,Ts,p,m,weights,MV);

% Simulate closed loop system using MPCMOVE

Tstop=30;  %Simulation time

xmpc=mpcstate(MPCobj); % Initial state of MPC controller
x=x0;                  % Initial state of Plant
r=1;                   % Output reference trajectory

% State-space matrices of Plant model
[A,B,C,D]=ssdata(c2d(sys,Ts));

YY=[];XX=[];RR=[];
for t=0:round(Tstop/Ts)-1,
    XX=[XX,x];
    
    % Define measured disturbance signal
    v=0;
    if t*Ts>=10, v=1; end
    
    % Define unmeasured disturbance signal
    d=0;
    if t*Ts>=20, d=-0.5; end
    
    % Plant equations: output update 
    % (note: no feedrthrough from MV to Y, D(:,1)=0)
    y=C*x+D(:,2)*v+D(:,3)*d;
    YY=[YY,y];
    
    % Compute MPC law
    u=mpcmove(MPCobj,xmpc,y,r,v);
        
    % Plant equations: state update
    x=A*x+B(:,1)*u+B(:,2)*v+B(:,3)*d;
end

% Plot results
plot(0:Ts:Tstop-Ts,YY);grid