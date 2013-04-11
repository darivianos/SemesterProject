%==========================================================================
%
% Project:  IR control for the Hquad 
%
% Task:     LQR - Controlling
%
% function: loading the point mass model
%
% Author:   Rueesch Andreas
%
%--------------------------------------------------------------------------
% created:  06.04.2010  v0.1    arue
%==========================================================================

%--------------------------------------------------------------------------
% physical constants
%--------------------------------------------------------------------------
%mass = 0.640;       % mass Andreas Rueesch
%mass = 0.550;     % mass without camera, with battery
% THRUST_CMD_GAIN= -0.0943;

mass_quad=0.537;
mass_batt=0.153;
mass_camera=0.102;
mass_weight=0.0967;
mass_camera_new=0.150;

mass = mass_quad+mass_camera_new;     % mass with weight and battery
THRUST_CMD_GAIN= -0.0835;   %  with cable and camera
% THRUST_CMD_GAIN= -0.0806; % without cable and mass_weight (no camera)

% mass = 0.790-0.1;     % mass with some parts of camera and battery
% THRUST_CMD_GAIN= -0.0850;

%mass = 0.660;       % FAKE mass with camera and battery
%mass=0.65;        % mass with camera without battery
m=mass;
g = 9.81;        % gravity constant


%--------------------------------------------------------------------------
% LTI blocks for the rotational and thrust dynamics (incl. delay)
%--------------------------------------------------------------------------
load('HquadModel/dynamics_pitch.mat')
load('HquadModel/dynamics_roll.mat')
load('HquadModel/dynamics_yaw.mat')
load('HquadModel/dynamics_thrust.mat')

