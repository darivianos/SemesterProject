%==========================================================================
%
% Project:      AIR control for the Hquad    
%
% Task:         LQRI, LQR, MPC - Controlling decoupled SISO case
%
% function:     main file for design and derivation of the controllers
%
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
load HquadTrajectories/traj_circle.mat
% load HquadTrajectories/traj_helix.mat
% load HquadTrajectories/traj_points.mat

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

m = 0.65;
g = 9.8065;
l = 0.30;
gamma = 0;
Theta = -deg2rad(3);

% for the mass of inertia, we use the approximation of Thin, solid disk of radius r and mass m
J = m*l*l/4; % Inertia
la = l*sin(gamma+Theta)/J;
WallPos = 2.9;

% Load Controllers parameters
load Xdirection.mat
load XdirectionFF.mat
load Ydirection.mat
load Zdirection.mat
load Yawdirection.mat


%% simulation step
load hquad_pos_FG_circle.mat
startIndex = 1;
endIndex = 1800;
[RecordedData,RefX,RefY,RefZ,RefYaw] = loadSimulationData(hquad_pos_FG,startIndex,endIndex);
