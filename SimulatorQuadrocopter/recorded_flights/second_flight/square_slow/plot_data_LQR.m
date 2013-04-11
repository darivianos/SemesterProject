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

load hquad_traj_LQR.mat


start_time=1;
end_time=1311;

% get trajectory data
hquad_traj_LQR=hquad_traj_LQR(:,start_time:end_time);

% move starting point to 0/0
hquad_traj_LQR(2,:)=hquad_traj_LQR(2,:)-0.8;
hquad_traj_LQR(5,:)=hquad_traj_LQR(5,:)-0.8;
hquad_traj_LQR(7,:)=hquad_traj_LQR(7,:)+0.7;
hquad_traj_LQR(10,:)=hquad_traj_LQR(10,:)+0.7;
hquad_traj_LQR(12,:)=hquad_traj_LQR(12,:)+1;
hquad_traj_LQR(14,:)=hquad_traj_LQR(14,:)+1;

% data is recorded with z-axis pointing down !!
% change this
hquad_traj_LQR(7:19,:)=-1*hquad_traj_LQR(7:19,:);



%% x - axis
figure
plot(hquad_traj_LQR(1,:)'-hquad_traj_LQR(1,1),[hquad_traj_LQR(2,:)',...
    hquad_traj_LQR(3,:)',hquad_traj_LQR(5,:)']);
title('Trajectory Control with LQR');
legend('position','velocity','reference','Location','SouthEast');
ylabel('position (meter)');
xlabel('time (sec)');
axis([0 25 -1.2 1.2]);


%% y - axis
figure
plot(hquad_traj_LQR(1,:)'-hquad_traj_LQR(1,1),[hquad_traj_LQR(7,:)',...
    hquad_traj_LQR(8,:)',hquad_traj_LQR(10,:)']);
title('Trajectory Control with LQR');
legend('position','velocity','reference','Location','SouthEast');
ylabel('position (meter)');
xlabel('time (sec)');
axis([0 25 -1.2 1.2]);


%% z - axis
figure
plot(hquad_traj_LQR(1,:)'-hquad_traj_LQR(1,1),[hquad_traj_LQR(12,:)',...
    hquad_traj_LQR(13,:)',hquad_traj_LQR(14,:)']);
title('Trajectory Control with LQR');
legend('position','velocity','reference','Location','SouthEast');
ylabel('position (meter)');
xlabel('time (sec)');
axis([0 25 -1.2 1.2]);

%% yaw - angle
% figure
% plot(hquad_traj_LQR(1,:)'-hquad_traj_LQR(1,1),[hquad_traj_LQR(16,:)',...
%     hquad_traj_LQR(17,:)',hquad_traj_LQR(18,:)']);
% title('Trajectory Control with LQR');
% legend('position','velocity','reference','Location','SouthEast');
% ylabel('position (meter)');
% xlabel('time (sec)');


%% 2D - Plot
figure
plot(hquad_traj_LQR(2,:)', hquad_traj_LQR(7,:)');
hold on
plot(hquad_traj_LQR(5,:)', hquad_traj_LQR(10,:)','-r');

axis([-0.2 1.2 -0.2 1.2]);
title('Trajectory Control with LQR');
legend('position','reference','Location','SouthEast');
xlabel('x');
ylabel('y');

%% 3D - Plot
figure
plot3(hquad_traj_LQR(2,:)', hquad_traj_LQR(7,:)',hquad_traj_LQR(12,:)');
hold on
plot3(hquad_traj_LQR(5,:)', hquad_traj_LQR(10,:)',hquad_traj_LQR(14,:)','-r');
axis([-0.2 1.2 -0.2 1.2 -0.2 1.2]);
%axis equal;

title('Trajectory Control with LQR');
legend('position','reference','Location','SouthEast');
xlabel('x');
ylabel('y');
zlabel('z');


