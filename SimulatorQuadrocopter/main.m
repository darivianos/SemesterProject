close all
clear all
clc
%--------------------------------------------------------------------------
% contants and model parameters
%--------------------------------------------------------------------------
Ts = .01*2;                       % Samplingtime 50Hz

load_PMModel                    % load point mass model parameters
m = 0.65;
g = 9.8065;
l = 0.30;
gamma = 0;
Theta = -deg2rad(3);

% for the mass of inertia, we use the approximation of Thin, solid disk of radius r and mass m
J = m*l*l/4; % Inertia
la = l*sin(gamma+Theta)/J;
WallPos = 1;

% set pade order for delay approximation (Not working with real Quadrotor)
delay_pade_order=0;