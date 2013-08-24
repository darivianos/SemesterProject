%==========================================================================
%
% Project:      AIR control for the Hquad    
%
% Task:         LQRI, LQR, MPC - Controlling decoupled SISO case
%
% function:     main file for design and derivation of the controllers

% Important:    If you change the pade approximation of the delay, check the
%               order of the states (1st position, 2nd velocity)
%
% Author:       Rueesch Andreas
%               Michael Burri
%
%--------------------------------------------------------------------------
% created:      09.04.2010  v0.1    arue
%               14.04.2010  v0.2    arue    cleaned up 
%               26.04.2010  v0.2    arue    extended for all subsystems
%               28.06.2011  v0.3    burrimi added output constraints
%==========================================================================
close all
clear all
clc

addpath(fullfile(fileparts(mfilename('fullpath')),'HquadTrajectories'));
addpath(fullfile(fileparts(mfilename('fullpath')),'MPC_FastGradient'));
addpath(fullfile(fileparts(mfilename('fullpath')),'MPC_FastGradient','tools'));


%--------------------------------------------------------------------------
% tabula rasa
%--------------------------------------------------------------------------
%clear all; clc; close all;
format compact

%--------------------------------------------------------------------------
% contants and model parameters
%--------------------------------------------------------------------------
Ts = .01*2;                       % Samplingtime 50Hz
Ts_slow = Ts;
load_PMModel                    % load point mass model parameters

% limits for lqri and mpc controller
MAX_ANGLE=15/180*pi; % maximum allowed angle for roll and pitch in rad
MAX_FORCE=2; % maximum allowed force in N (without gravity)
MAX_YAW_RATE=pi; % maximum allowed yaw rate in rad/s

% limits for kalman filter with bias extension
MAX_BIAS_ANGLE=5/180*pi;    % maximum bias on roll and pitch angle
MAX_BIAS_THRUST=0.5;        % maximum bias on thrust
MAX_BIAS_YAW_RATE=5/180*pi; % maximum bias on yaw rate


% set pade order for delay approximation (Not working with real Quadrotor)
delay_pade_order=0;

% x0=1.8;
% y0=-1;
% z0=-1;
% yaw0=-2.321;

x0=0;
y0=0;
z0=0;
yaw0=0;

%==========================================================================
%
% LQR / LQRI - controller and observation calculation
%
%==========================================================================

% -----------------------------
% CALCULATION
% -----------------------------
% lqr_alt_calc_ctrl_SI              % calc for the cont - altitude
% lqr_dist_calc_ctrl_SI             % calc for the cont - distance
% lqr_yaw_calc_ctrl_SI              % calc for the cont - yaw

% -----------------------------
% LOAD SAVED SYSTEMS
% -----------------------------

% load position controller lqri
load Hquad_CTRL_OBSV_parameters/ctrl_lqri_x_v3.mat
load Hquad_CTRL_OBSV_parameters/ctrl_lqri_y_v3.mat
load Hquad_CTRL_OBSV_parameters/ctrl_lqri_z_v4.mat
load Hquad_CTRL_OBSV_parameters/ctrl_lqri_yaw_v2.mat

% load position observer lqri
load Hquad_CTRL_OBSV_parameters/obsv_lqri_x_v1.mat
load Hquad_CTRL_OBSV_parameters/obsv_lqri_y_v1.mat
load Hquad_CTRL_OBSV_parameters/obsv_lqri_z_v1.mat
load Hquad_CTRL_OBSV_parameters/obsv_lqri_yaw_v1.mat

% load SIMULINK MPC controller (the one from matlab)
% load MPC_roll.mat
% load MPC_pitch.mat
% load MPC_thrust.mat

% load Fast Gradient controller
% load Hquad_CTRL_OBSV_parameters/ctrl_mpc_x_v1.mat
% load Hquad_CTRL_OBSV_parameters/ctrl_mpc_y_v1.mat
% load Hquad_CTRL_OBSV_parameters/ctrl_mpc_z_v1.mat
% load Hquad_CTRL_OBSV_parameters/ctrl_mpc_yaw_v1.mat

% load Fast Gradient controller (the fast one)
load Hquad_CTRL_OBSV_parameters/ctrl_mpc_x_v2.mat
load Hquad_CTRL_OBSV_parameters/ctrl_mpc_y_v2.mat
load Hquad_CTRL_OBSV_parameters/ctrl_mpc_z_v2.mat
load Hquad_CTRL_OBSV_parameters/ctrl_mpc_yaw_v2.mat

% load Fast Gradient observer
load Hquad_CTRL_OBSV_parameters/obsv_mpc_x_v1.mat
load Hquad_CTRL_OBSV_parameters/obsv_mpc_y_v1.mat
load Hquad_CTRL_OBSV_parameters/obsv_mpc_z_v1.mat
load Hquad_CTRL_OBSV_parameters/obsv_mpc_yaw_v1.mat

% load trajectory
%load HquadTrajectories/traj_wall_docking.mat
%load HquadTrajectories/traj_wall_square.mat
%load HquadTrajectories/traj_circle.mat
% load HquadTrajectories/traj_helix.mat

%% Drawing Tool for wall reference (comment for free flight)
maxdisty = 1.25;
maxdistz = 0.6;

scale_y = 1.1;
scale_z = 1.2;


traj_FG = ReferenceCreator(maxdisty,maxdistz,scale_y,scale_z);

% %%
% hold on;
% plot(traj_FG.X_ref_y(1,:),-traj_FG.X_ref_z(1,:),'o-g');
%%
% hold on;
% plot(traj_FG.X_ref_y_real(1,:),-traj_FG.X_ref_z_real(1,:),'o-g'); 
%%


load Hquad_CTRL_OBSV_parameters/ctrl_lqr_x_v1.mat
load Hquad_CTRL_OBSV_parameters/ctrl_lqr_y_v1.mat
load Hquad_CTRL_OBSV_parameters/ctrl_lqr_z_v1.mat
load Hquad_CTRL_OBSV_parameters/ctrl_lqr_yaw_v1.mat


%==========================================================================
%
% Simulation, testing
%
%==========================================================================
% lqr_sim


%% Darivianakis Controller Parameters load


%% Parameters Initialization
addpath(genpath('/home/burrimi/git/darivianakis/SemProject/'));
DF = 0;
m = 0.66;
g = 9.8065;
l = 0.30;
gamma = 0;
J = m*l*l/4; % Inertia, we use the approximation of Thin, solid disk of radius r and mass m
Theta = -deg2rad(3); % Docking angle
TsCtrl = 0.08;
Tsz = 0.04;

DF_roll = 0;
a1_roll = 54.9;
a0_roll = 419.1;
c0_roll = 419.1;
Td_roll = Td_roll_2ndOrd;
[Aff_roll,Bff_roll,Cff_roll,Dff_roll,~,~,~,~] = linearizSimple(Theta,Td_roll,m,l,gamma,J,a1_roll,a0_roll,c0_roll,DF);

Aff_roll = [Aff_roll,zeros(size(Aff_roll,1),1);zeros(1,size(Aff_roll,1)),1];
Bff_roll = [Bff_roll;zeros(1,size(Bff_roll,2))];


DF_pitch = 0;
DF_pitch_mp = -2.35;
a1_pitch = 59.71;
a0_pitch = 491;
c0_pitch = 491;
Td_pitch = Td_pitch_2ndOrd;

[Aff_pitch_mp,Bff_pitch_mp,Cff_pitch_mp,Dff_pitch_mp,Add_pitch_mp,Bdd_pitch_mp,Cdd_pitch_mp,Ddd_pitch_mp] = linearizSimple(Theta,Td_pitch,m,l,gamma,J,a1_pitch,a0_pitch,c0_pitch,DF_pitch_mp);

% Af = zeros(4,4);
% Bf = zeros(4,2);
% 
% % Free Flight
% Af(1,2) = 1; Af(2,1) = -a0_pitch; Af(2,2) = -a1_pitch; Af(3,4) = 1; 
% Af(4,1) = -g; Af(4,4) = DF_pitch_mp;
% 
% Bf(2,1) = c0_pitch;
% Cf = [eye(4);zeros(1,4)];

[Aff_pitch,Bff_pitch,Cff_pitch,Dff_pitch,Add_pitch,Bdd_pitch,Cdd_pitch,Ddd_pitch] = linearizSimple(Theta,Td_pitch,m,l,gamma,J,a1_pitch,a0_pitch,c0_pitch,DF);

a0_yaw = 5.9;
c0_yaw = 5.9;
Td_yaw = Td_yaw_1stOrd;

sysfd_yaw = c2d(dynamics_yaw_1stOrd,Td_yaw,'zoh');
Aff_yaw = sysfd_yaw.a;
Bff_yaw = sysfd_yaw.b;
Cff_yaw = sysfd_yaw.c;
Dff_yaw = sysfd_yaw.d;



WallPos = 2.9;

% Load Controllers parameters
load Xdirection.mat
load XdirectionFF.mat
load Ydirection.mat
load Zdirection.mat
load Yawdirection.mat

mass = 0.66;
% %% simulation step
% load hquad_pos_FG_square.mat
% startIndex = 1;
% endIndex = 1700;
% [RecordedData,RefX,RefY,RefZ,RefYaw] = loadSimulationData(hquad_pos_FG,startIndex,endIndex);

%% Kalman Filter Parameters
Ax = Aff_pitch_mp;
Bx = Bff_pitch_mp(:,1);
Cx = eye(4);

disp('### MAIN FILE LOADED!');