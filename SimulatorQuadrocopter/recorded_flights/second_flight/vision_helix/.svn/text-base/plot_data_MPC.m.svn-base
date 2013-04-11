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

load hquad_traj_FG.mat



figure
plot([hquad_traj_FG(12,:)',...
    hquad_traj_FG(13,:)',hquad_traj_FG(14,:)']);
title('Trajectory Control with MPC');
legend('position','velocity','reference','Location','SouthEast');
ylabel('position (meter)');
xlabel('time (sec)');



start_time=1001;
end_time=1501;

% get trajectory data
%hquad_traj_FG=hquad_traj_FG(:,start_time:end_time);

% move starting point to 0/0
hquad_traj_FG(2,:)=hquad_traj_FG(2,:)-0.5;
hquad_traj_FG(5,:)=hquad_traj_FG(5,:)-0.5;
hquad_traj_FG(7,:)=hquad_traj_FG(7,:)+0.5;
hquad_traj_FG(10,:)=hquad_traj_FG(10,:)+0.5;
hquad_traj_FG(12,:)=hquad_traj_FG(12,:)+1;
hquad_traj_FG(14,:)=hquad_traj_FG(14,:)+1;

% data is recorded with z-axis pointing down !!
% change this
hquad_traj_FG(7:19,:)=-1*hquad_traj_FG(7:19,:);



%% x - axis
figure
plot(hquad_traj_FG(1,:)'-hquad_traj_FG(1,1),[hquad_traj_FG(2,:)',...
    hquad_traj_FG(3,:)',hquad_traj_FG(5,:)']);
title('Trajectory Control with MPC');
legend('position','velocity','reference','Location','SouthEast');
ylabel('position (meter)');
xlabel('time (sec)');
axis([0 25 -1.2 1.2]);

%% y - axis
figure
plot(hquad_traj_FG(1,:)'-hquad_traj_FG(1,1),[hquad_traj_FG(7,:)',...
    hquad_traj_FG(8,:)',hquad_traj_FG(10,:)']);
title('Trajectory Control with MPC');
legend('position','velocity','reference','Location','SouthEast');
ylabel('position (meter)');
xlabel('time (sec)');
axis([0 25 -1.2 1.2]);

%% z - axis
figure
plot(hquad_traj_FG(1,:)'-hquad_traj_FG(1,1),[hquad_traj_FG(12,:)',...
    hquad_traj_FG(13,:)',hquad_traj_FG(14,:)']);
title('Trajectory Control with MPC');
legend('position','velocity','reference','Location','SouthEast');
ylabel('position (meter)');
xlabel('time (sec)');
axis([0 25 -1.2 1.2]);

%% yaw - angle
% figure
% plot(hquad_traj_FG(1,:)'-hquad_traj_FG(1,1),[hquad_traj_FG(16,:)',...
%     hquad_traj_FG(17,:)',hquad_traj_FG(18,:)']);
% title('Trajectory Control with MPC');
% legend('position','velocity','reference','Location','SouthEast');
% ylabel('position (meter)');
% xlabel('time (sec)');


%% 2D - Plot
figure
plot(hquad_traj_FG(2,:)', hquad_traj_FG(7,:)');
hold on
plot(hquad_traj_FG(5,:)', hquad_traj_FG(10,:)','-r');
axis([-0.6 0.6 -0.6 0.6]);

title('Trajectory Control with MPC');
legend('position','reference','Location','SouthEast');
xlabel('x');
ylabel('y');


% get trajectory data
%hquad_traj_FG=hquad_traj_FG(:,start_time:end_time);

%% 3D - Plot
figure
plot3(hquad_traj_FG(2,:)', hquad_traj_FG(7,:)',hquad_traj_FG(12,:)');
hold on
plot3(hquad_traj_FG(5,:)', hquad_traj_FG(10,:)',hquad_traj_FG(14,:)','-r');
axis([-0.6 0.6 -0.6 0.6 -0.1 1.1]);
%axis equal;

title('Trajectory Control with MPC');
legend('position','reference','Location','SouthEast');
xlabel('x');
ylabel('y');
zlabel('z');


