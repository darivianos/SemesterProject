%==========================================================================
%
% Project:  IR control for the Hquad 
%
% Task:     LQR - Controlling decoupled SISO case
%
% function:	calculate and design the LQR - controller in 
%           the z axis
%
% Author:	Michael Burri
%
%--------------------------------------------------------------------------
% created:  09.09.2011  v0.1    burrimi
%==========================================================================

%% load model parameters

[AA, BB, CC, DD] = dlinmod('SimulinkModel_hquad_lin_thrust_0thOrd',Ts);

A = AA;
B = BB;
C = CC;
D = DD;

%--------------------------------------------------------------------------
% tuning parameters
%--------------------------------------------------------------------------
Q = diag([100,30]);         % states (z,z_dot)
R = diag(15);               % command (thrust_cmd)
u_max = MAX_FORCE;
delay = Td_thrust_0thOrd; % in seconds


% only for simulation
simulation_time=10;

% only for storing the data
VERSION_NR=1;

%--------------------------------------------------------------------------
% get optimal lqr gain
%--------------------------------------------------------------------------
K_lqr_z=dlqr(A,B,Q,R);

%% start simulation

[n, m] = size(B);
delay_steps=round(delay/Ts);
num_of_steps=floor(simulation_time/Ts);

% create step after 1 second
X_ref=[zeros(1,round(1/Ts)) , 1*ones(1,num_of_steps+delay_steps)];

% set initial state
x0 = zeros(n,1);

% init variables
x_state=zeros(n,num_of_steps+1+delay_steps);
u_opt=zeros(m,num_of_steps+1+delay_steps);
x_state(:,1:delay_steps+1)=x0*ones(1,delay_steps+1);

tic
for i=1+delay_steps:num_of_steps+delay_steps
    

    uu=-K_lqr_z*([x_state(1,i)-X_ref(i);x_state(2:n,i)]);
    
    if uu>u_max
        uu=u_max;
    elseif uu<-u_max
        uu=-u_max;
    end
    
    % update state with delayed optimal command
    x_state(:,i+1)=A*x_state(:,i)+B*uu;
    
 
    u_opt(:,i)=uu;
    
end
time_per_timestep=toc/num_of_steps
hold on
plot(0:Ts:(simulation_time+delay_steps*Ts),[x_state(1,:)',X_ref(1,1:num_of_steps+delay_steps+1)',x_state(2,:)',u_opt(1,:)']);
axis([0 10 -1 4]);

%% save all precalculated values for simulink


PATH_CTRL = ['../Hquad_CTRL_OBSV_parameters/ctrl_lqr_z_v'...
                    num2str(VERSION_NR) '.mat'];
save(PATH_CTRL, 'K_lqr_z')
