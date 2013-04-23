close all
%1: time
%2: x
%3: x_dot
%4: pitch
%5: x_ref
%6: pitch_cmd
%7: y
%8: y_dot
%9: roll
%10: y_ref
%11: roll_cmd
%12: z
%13: z_dot
%14: z_ref
%15: thrust cmd
%16: yaw
%17: ang vel z
%18: yaw ref
%19: yaw rate cmd

load hquad_pos_FG.mat
load simulation_pos_FG.mat

plot([hquad_pos_FG(2,:)',...
    hquad_pos_FG(3,:)',hquad_pos_FG(5,:)']);

start_time=3250;
end_time=start_time+40/Ts;

% get trajectory data
hquad_pos_FG=hquad_pos_FG(:,start_time:end_time);

% move starting point to 0/0
hquad_pos_FG(2,:)=hquad_pos_FG(2,:)-0;
hquad_pos_FG(5,:)=hquad_pos_FG(5,:)-0;
hquad_pos_FG(7,:)=hquad_pos_FG(7,:)+0;
hquad_pos_FG(10,:)=hquad_pos_FG(10,:)+0;
hquad_pos_FG(12,:)=hquad_pos_FG(12,:)+1;
hquad_pos_FG(14,:)=hquad_pos_FG(14,:)+1;

% data is recorded with z-axis pointing down !!
% change this
hquad_pos_FG(7:19,:)=-1*hquad_pos_FG(7:19,:);



%% x - axis
figure
plot(hquad_pos_FG(1,:)'-hquad_pos_FG(1,1),[hquad_pos_FG(2,:)',...
    hquad_pos_FG(3,:)',hquad_pos_FG(5,:)']);
title('Step Response with MPC in x-Axis');
legend('position','velocity','reference','Location','SouthEast');
ylabel('position (meter)');
xlabel('time (sec)');
% axis([0 25 -1.2 1.2]);

%% y - axis
figure
plot(hquad_pos_FG(1,:)'-hquad_pos_FG(1,1),[hquad_pos_FG(7,:)',...
    hquad_pos_FG(8,:)',hquad_pos_FG(10,:)']);
title('Trajectory Control with MPC');
legend('position','velocity','reference','Location','SouthEast');
ylabel('position (meter)');
xlabel('time (sec)');
% axis([0 25 -1.2 1.2]);

% %% z - axis
% figure
% plot(hquad_pos_FG(1,:)'-hquad_pos_FG(1,1),[hquad_pos_FG(12,:)',...
%     hquad_pos_FG(13,:)',hquad_pos_FG(14,:)']);
% title('Trajectory Control with MPC');
% legend('position','velocity','reference','Location','SouthEast');
% ylabel('position (meter)');
% xlabel('time (sec)');
% % axis([0 25 -1.2 1.2]);

%% yaw - angle
% figure
% plot(hquad_pos_FG(1,:)'-hquad_pos_FG(1,1),[hquad_pos_FG(16,:)',...
%     hquad_pos_FG(17,:)',hquad_pos_FG(18,:)']);
% title('Trajectory Control with MPC');
% legend('position','velocity','reference','Location','SouthEast');
% ylabel('position (meter)');
% xlabel('time (sec)');


% %% 2D - Plot
% figure
% plot(hquad_pos_FG(2,:)', hquad_pos_FG(7,:)');
% hold on
% plot(hquad_pos_FG(5,:)', hquad_pos_FG(10,:)','-r');
% axis([-0.2 1.2 -0.2 1.2]);
% 
% title('Trajectory Control with MPC');
% legend('position','reference','Location','SouthEast');
% xlabel('x');
% ylabel('y');
% 
% %% 3D - Plot
% figure
% plot3(hquad_pos_FG(2,:)', hquad_pos_FG(7,:)',hquad_pos_FG(12,:)');
% hold on
% plot3(hquad_pos_FG(5,:)', hquad_pos_FG(10,:)',hquad_pos_FG(14,:)','-r');
% axis([-0.2 1.2 -0.2 1.2 -0.2 1.2]);
% %axis equal;

title('Trajectory Control with MPC');
legend('position','reference','Location','SouthEast');
xlabel('x');
ylabel('y');
zlabel('z');

load hquad_pos_FG.mat
load simulation_pos_FG.mat

%% sync steps of simulation and real model
figure
[~,offset_simulation] = max(diff(simulation_pos_FG(5,:)'))

step_counter=1;
ref_dot=diff(hquad_pos_FG(5,:)');
ref_counter=0;
for i = 1:size(hquad_pos_FG,2)-1
    if ref_dot(i)>0.9
        ref_counter=ref_counter+1;
        if ref_counter==step_counter
            offset_controller=i
        end
    end
end

simulation_pos_FG_sync=simulation_pos_FG(:,offset_simulation-floor(8/Ts):offset_simulation+floor(10/Ts));
hquad_pos_FG_sync=hquad_pos_FG(:,offset_controller-floor(8/Ts):offset_controller+floor(10/Ts));

plot(simulation_pos_FG_sync(1,:)'-simulation_pos_FG_sync(1,1),...
    [simulation_pos_FG_sync(2,:)',...
    simulation_pos_FG_sync(3,:)'],'--');

% plot(hquad_pos_simulation(1,:)',...
%     [hquad_pos_controller_lqr(2,:)',hquad_pos_simulation(2,:)',...
%     hquad_pos_controller_lqr(3,:)',hquad_pos_simulation(3,:)',...
%     hquad_pos_controller_lqr(5,:)',hquad_pos_simulation(5,:)']);
axis([0 15 -0.2 1.2])

hold on
plot(hquad_pos_FG_sync(1,:)'-hquad_pos_FG_sync(1,1),...
    [hquad_pos_FG_sync(2,:)',...
    hquad_pos_FG_sync(3,:)',...
    hquad_pos_FG_sync(5,:)']);

axis([0 15 -0.3 1.3])

title('Step Response in x-Direction Model and Measured');
legend('position model','velocity model','position vicon','velocity vicon','reference','Location','NorthWest');
ylabel('position (m)');
xlabel('time (sec)');






%% sync steps of simulation and real model
figure
[~,offset_simulation] = max(diff(simulation_pos_FG(10,:)'))

step_counter=2;
ref_dot=diff(hquad_pos_FG(10,:)');
ref_counter=0;
for i = 1:size(hquad_pos_FG,2)-1
    if ref_dot(i)>0.9
        ref_counter=ref_counter+1;
        if ref_counter==step_counter
            offset_controller=i
        end
    end
end

simulation_pos_FG_sync=simulation_pos_FG(:,offset_simulation-floor(8/Ts):offset_simulation+floor(10/Ts));
hquad_pos_FG_sync=hquad_pos_FG(:,offset_controller-floor(8/Ts):offset_controller+floor(10/Ts));

plot(simulation_pos_FG_sync(1,:)'-simulation_pos_FG_sync(1,1),...
    [simulation_pos_FG_sync(7,:)',...
    simulation_pos_FG_sync(8,:)'],'--');

% plot(hquad_pos_simulation(1,:)',...
%     [hquad_pos_controller_lqr(2,:)',hquad_pos_simulation(2,:)',...
%     hquad_pos_controller_lqr(3,:)',hquad_pos_simulation(3,:)',...
%     hquad_pos_controller_lqr(5,:)',hquad_pos_simulation(5,:)']);
axis([0 15 -0.2 1.2])

hold on
plot(hquad_pos_FG_sync(1,:)'-hquad_pos_FG_sync(1,1),...
    [hquad_pos_FG_sync(7,:)',...
    hquad_pos_FG_sync(8,:)',...
    hquad_pos_FG_sync(10,:)']);

axis([0 15 -0.3 1.3])

title('Step Response in y-Direction Model and Measured');
legend('position model','velocity model','position vicon','velocity vicon','reference','Location','NorthWest');
ylabel('position (m)');
xlabel('time (sec)');


