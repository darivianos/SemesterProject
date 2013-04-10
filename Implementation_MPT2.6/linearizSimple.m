function [Aff,Bff,Cff,Dff,Add,Bdd,Cdd,Ddd] = linearizSimple(Theta,Ts)


% Linearization function that returns the discrete state space
% space matrix A and B in free flight and docking
% -------------------------------------------------------------
% [Aff,Bff,Cff,Add,Bdd,Cdd] = linearizSimple(Theta,Ts)
%
% Theta : angle in rad
% Ts : sampling time
% -------------------------------------------------------------



% Initialization
m = 1.22;
g = 9.8065;
l = sqrt(0.301^2 + 0.483^2);
gamma = atan(0.301/0.483);
J = 0.0319; % Inertia

% Equilibrium Position
la = l*sin(gamma+Theta)/J;
DF = -0.9606;
a1 = 11.51;
a0 = 33.1;
c0 = 39.55;

% Calculation of linearized Matrices around Theta
Af = zeros(4,4);
Bf = zeros(4,2);
Df = zeros(5,2);

Ad = zeros(4,4);
Bd = zeros(4,2);
Dd = zeros(5,2);

% Free Flight
Af(1,2) = 1; Af(2,1) = -a0; Af(2,2) = -a1; Af(3,4) = 1; 
Af(4,1) = -g*cos(Theta); Af(4,4) = DF;
Bf(2,1) = c0;
Cf = [eye(4);zeros(1,4)];

sysfc = ss(Af,Bf,Cf,Df);
sysfd = c2d(sysfc,Ts,'zoh');
Aff = sysfd.a;
Bff = sysfd.b;
Cff = sysfd.c;
Dff = sysfd.d;

% Docked Dynamics
Ad(1,2) = 1; Ad(2,1) = -a0; Ad(2,2) = -a1; Ad(3,4) = 1; 
Bd(2,1) = c0; Bd(2,2) = la;
Cd = [eye(4);
      -m*g*cos(Theta),zeros(1,3)];

sysdc = ss(Ad,Bd,Cd,Dd);
sysdd = c2d(sysdc,Ts,'zoh');
Add = sysdd.a;
Bdd = sysdd.b;
Cdd = sysdd.c;
Ddd = sysdd.d;

return
