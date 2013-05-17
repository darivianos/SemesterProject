function [Aff,Bff,Cff,Dff,Add,Bdd,Cdd,Ddd] = linearizSimple(Theta,Ts,m,l,gamma,J,a1,a0,c0,DF)


% Linearization function that returns the discrete state space
% space matrix A and B in free flight and docking
% -------------------------------------------------------------
% [Aff,Bff,Cff,Add,Bdd,Cdd] = linearizSimple(Theta,Ts)
%
% Theta : Desired Angle for Force Control
% Ts : sampling time
% -------------------------------------------------------------

% Equilibrium Position
g = 9.8065;
la = l*sin(gamma+Theta)/J;



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
Add(3,3) = 0; Add(3,4) = 0; Add(4,4) = 0;
Bdd = sysdd.b;
Cdd = sysdd.c;
Ddd = sysdd.d;

return
