function [Aff,Bff,Cff,Dff,Add,Bdd,Cdd,Ddd] = linearizSimple(Theta,Ts)


% Linearization function that returns the discrete state space
% space matrix A and B in free flight and docking
% -------------------------------------------------------------
% [Aff,Bff,Cff,Add,Bdd,Cdd] = linearizSimple(Theta,Ts)
%
% Theta : Desired Angle for Force Control
% Ts : sampling time
% -------------------------------------------------------------



% Initialization
m = 0.65;
g = 9.8065;
l = 0.30;
gamma = 0;

% for the mass of inertia, we use the approximation of Thin, solid disk of radius r and mass m
J = m*l*l/4; % Inertia

% Equilibrium Position
la = l*sin(gamma+Theta)/J;
%DF = -0.9606;
DF = 0;

a1 = 59.71;
a0 = 491;
c0 = 491;

% Calculation of linearized Matrices around Theta
Af = zeros(4,4);
Bf = zeros(4,2);
Df = zeros(5,2);

Ad = zeros(4,4);
Bd = zeros(4,2);
Dd = zeros(5,2);

% Free Flight
Af(1,2) = 1; Af(2,1) = -a0; Af(2,2) = -a1; Af(3,4) = 1; 
Af(4,1) = -g; Af(4,4) = DF;
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
      -m*g,zeros(1,3)];

sysdc = ss(Ad,Bd,Cd,Dd);
sysdd = c2d(sysdc,Ts,'zoh');
Add = sysdd.a;
Bdd = sysdd.b;
Cdd = sysdd.c;
Ddd = sysdd.d;

return
