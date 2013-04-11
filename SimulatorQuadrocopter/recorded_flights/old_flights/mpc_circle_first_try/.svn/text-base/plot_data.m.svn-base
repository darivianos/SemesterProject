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

load hquad_traj.mat



figure
plot([hquad_traj(2,1340:1680)',...
    hquad_traj(3,1340:1680)',hquad_traj(5,1340:1680)']);
title('Position control with lqg');
legend('position','velocity','reference','Location','SouthEast');
ylabel('position (meter)');
xlabel('time (sec)');
% axis([0 40 -1.5 1.5]);
figure
plot(hquad_traj(2,1340:1680)', hquad_traj(7,1340:1680)');
hold on
plot(hquad_traj(5,1340:1680)', hquad_traj(10,1340:1680)','-r');
