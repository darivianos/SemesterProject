close all
clear all
clc

% Initialization
%Ts = 0.011;
Ts = 0.11;
m = 1.22;
g = 9.8065;
% free flight and docked dynamics linearization
Theta = -deg2rad(0);
[Aff,Bff,Cff,Dff,Add,Bdd,Cdd,Ddd] = linearizSimple(Theta,Ts);

% Free Flight set parameters
for i = 1:4
    for j = 1:4
        VarName = sprintf('Af%d%d',i,j);
        VarValue = sprintf('=Aff(%d,%d);',i,j);
        eval([VarName VarValue ]);
    end
end

for i = 1:4
    for j = 1:2
        VarName = sprintf('Bf%d%d',i,j);
        VarValue = sprintf('=Bff(%d,%d);',i,j);
        eval([VarName VarValue ]);
    end
end

for i = 1:5
    for j = 1:4
        VarName = sprintf('Cf%d%d',i,j);
        VarValue = sprintf('=Cff(%d,%d);',i,j);
        eval([VarName VarValue ]);
    end
end

% Docked Set parameters
for i = 1:4
    for j = 1:4
        VarName = sprintf('Ad%d%d',i,j);
        VarValue = sprintf('=Add(%d,%d);',i,j);
        eval([VarName VarValue ]);
    end
end

for i = 1:4
    for j = 1:2
        VarName = sprintf('Bd%d%d',i,j);
        VarValue = sprintf('=Bdd(%d,%d);',i,j);
        eval([VarName VarValue ]);
    end
end

for i = 1:5
    for j = 1:4
        VarName = sprintf('Cd%d%d',i,j);
        VarValue = sprintf('=Cdd(%d,%d);',i,j);
        eval([VarName VarValue ]);
    end
end
%%
% Initial structure with the disturbance as an aux variable to the system,
% zero movement at the switching of the hybrid system
sysStruct = mpt_sys('Coaxial');
sysStruct.Ts = Ts;
%%  Simulate Open Loop
x0 = [0 0 -0.5 0 0]';
inU = deg2rad(-7)*ones(50,1);
[X,U,Y,mode]=mpt_simSys(sysStruct,x0,inU);

figure(1);
subplot(3,1,1)
plot(X(:,3)); grid on;ylabel('position');
subplot(3,1,2)
plot(X(:,1)); grid on;ylabel('angle');
subplot(3,1,3)
plot(X(:,4)); grid on;ylabel('acceleration')

%% Optimization problem set up
clear probStruct;
probStruct.subopt_lev = 0;  % cost optimal solution
probStruct.norm = 2;
probStruct.N = 5;
probStruct.Q = zeros(5,5); % we don't penalize the states(output reference)
probStruct.R = 0.001;
probStruct.tracking = 0;
% We only care about the position and the force. So, we make output
% reference with position zero(wall) and desired force
probStruct.yref = [-deg2rad(3);0;0;0;m*g*sin(deg2rad(3))];
probStruct.Qy = zeros(5,5);
probStruct.Qy(5,5) = 1; % we want to be smooth the change of angle in the wall.
probStruct.Qy(3,3) = 1000; %when we have the switching this cost will be zero.
probStruct.Qy(4,4) = 100;
probStruct.Tconstraint = 1;
probStruct.y0bounds = 0; 

%%
ctrl = mpt_control(sysStruct,probStruct);
%%
clc
opts_sim.reference = [-deg2rad(3);0;0;0;m*g*sin(deg2rad(3))];
xinits = [0 0 -1 0 0]';
figure(2);
[Xsim, Usim, Ysim, cost_traj, trajectory]=mpt_plotTimeTrajectory(ctrl, xinits , 50,opts_sim);
