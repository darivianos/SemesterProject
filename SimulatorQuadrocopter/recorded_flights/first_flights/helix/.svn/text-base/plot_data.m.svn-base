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
plot([hquad_traj_FG(2,:)',...
    hquad_traj_FG(3,:)',hquad_traj_FG(5,:)']);
title('Position control with lqg');
legend('position','velocity','reference','Location','SouthEast');
ylabel('position (meter)');
xlabel('time (sec)');
% axis([0 40 -1.5 1.5]);



figure
plot([hquad_traj_FG(7,:)',...
    hquad_traj_FG(8,:)',hquad_traj_FG(10,:)']);
title('Position control with lqg');
legend('position','velocity','reference','Location','SouthEast');
ylabel('position (meter)');
xlabel('time (sec)');

figure
plot([hquad_traj_FG(12,:)',...
    hquad_traj_FG(13,:)',hquad_traj_FG(14,:)']);
title('Position control with lqg');
legend('position','velocity','reference','Location','SouthEast');
ylabel('position (meter)');
xlabel('time (sec)');


figure
plot([hquad_traj_FG(16,:)',...
    hquad_traj_FG(17,:)',hquad_traj_FG(19,:)']);
title('Position control with lqg');
legend('position','velocity','reference','Location','SouthEast');
ylabel('position (meter)');
xlabel('time (sec)');



figure
plot3(hquad_traj_FG(2,1:500)', hquad_traj_FG(7,1:500)',hquad_traj_FG(12,1:500)');
hold on
plot3(hquad_traj_FG(5,1:500)', hquad_traj_FG(10,1:500)',hquad_traj_FG(14,1:500)','-r');
