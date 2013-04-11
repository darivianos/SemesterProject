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

plot([hquad_pos_FG(2,:)',...
    hquad_pos_FG(5,:)']);

start_time=1;
end_time=5519;

start_time_camera=3302;
end_time_camera=4612;


% move starting point to 0/0
hquad_pos_FG(2,:)=hquad_pos_FG(2,:)-2;
hquad_pos_FG(5,:)=hquad_pos_FG(5,:)-2;
hquad_pos_FG(7,:)=hquad_pos_FG(7,:)+0.4;
hquad_pos_FG(10,:)=hquad_pos_FG(10,:)+0.4;
hquad_pos_FG(12,:)=hquad_pos_FG(12,:)+1;
hquad_pos_FG(14,:)=hquad_pos_FG(14,:)+1;

% data is recorded with z-axis pointing down !!
% change this
hquad_pos_FG(7:19,:)=-1*hquad_pos_FG(7:19,:);

% get trajectory data
hovering_vicon=hquad_pos_FG(:,start_time:end_time);
hovering_camera=hquad_pos_FG(:,start_time_camera:end_time_camera);

%% x - axis
figure
plot(hovering_vicon(1,:)'-hovering_vicon(1,1),[hovering_vicon(2,:)',...
    hovering_vicon(5,:)']);
title('Position Control with LQRI');
legend('position','reference','Location','SouthEast');
ylabel('position (m)');
xlabel('time (sec)');
% axis([0 25 -1.2 1.2]);
x=hovering_vicon(2,:)'-hovering_vicon(5,:)';
rms_vicon_x = norm(x)/sqrt(length(x))  


%% y - axis
figure
plot(hovering_vicon(1,:)'-hovering_vicon(1,1),[hovering_vicon(7,:)',...
    hovering_vicon(10,:)']);
title('Position Control with LQRI');
legend('position','reference','Location','SouthEast');
ylabel('position (m)');
xlabel('time (sec)');
% axis([0 25 -1.2 1.2]);
y=hovering_vicon(7,:)'-hovering_vicon(10,:)';
rms_vicon_y = norm(y)/sqrt(length(y))  


%% z - axis
figure
plot(hovering_vicon(1,:)'-hovering_vicon(1,1),[hovering_vicon(12,:)',...
    hovering_vicon(14,:)']);
title('Position Control with LQRI');
legend('position','reference','Location','SouthEast');
ylabel('position (m)');
xlabel('time (sec)');
% axis([0 25 -1.2 1.2]);
z=hovering_vicon(12,:)'-hovering_vicon(14,:)';
rms_vicon_z = norm(z)/sqrt(length(z))  


%% yaw - angle
% figure
% plot(hquad_pos_FG(1,:)'-hquad_pos_FG(1,1),[hquad_pos_FG(16,:)',...
%     hquad_pos_FG(17,:)',hquad_pos_FG(18,:)']);
% title('Trajectory Control with MPC');
% legend('position','velocity','reference','Location','SouthEast');
% ylabel('position (meter)');
% xlabel('time (sec)');


%% x - axis
figure
plot(hovering_camera(1,:)'-hovering_camera(1,1),[hovering_camera(2,:)',...
    hovering_camera(5,:)']);
title('Position Control with LQRI');
legend('position','reference','Location','SouthEast');
ylabel('position (m)');
xlabel('time (sec)');
% axis([0 25 -1.2 1.2]);
x=hovering_camera(2,:)'-hovering_camera(5,:)';
rms_cam_x = norm(x)/sqrt(length(x))  


%% y - axis
figure
plot(hovering_camera(1,:)'-hovering_camera(1,1),[hovering_camera(7,:)',...
    hovering_camera(10,:)']);
title('Position Control with LQRI');
legend('position','reference','Location','SouthEast');
ylabel('position (m)');
xlabel('time (sec)');
% axis([0 25 -1.2 1.2]);
y=hovering_camera(7,:)'-hovering_camera(10,:)';
rms_cam_y = norm(y)/sqrt(length(y))  


%% z - axis
figure
plot(hovering_camera(1,:)'-hovering_camera(1,1),[hovering_camera(12,:)',...
    hovering_camera(14,:)']);
title('Position Control with LQRI');
legend('position','reference','Location','SouthEast');
ylabel('position (m)');
xlabel('time (sec)');
% axis([0 25 -1.2 1.2]);
z=hovering_camera(12,:)'-hovering_camera(14,:)';
rms_cam_z = norm(z)/sqrt(length(z))  




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

% title('Trajectory Control with MPC');
% legend('position','reference','Location','SouthEast');
% xlabel('x');
% ylabel('y');
% zlabel('z');
