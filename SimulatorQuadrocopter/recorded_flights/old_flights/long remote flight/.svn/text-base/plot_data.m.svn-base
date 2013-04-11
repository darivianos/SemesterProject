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

load hquad_pos_controller_FG.mat




hquad_pos_simulation = hquad_pos_controller_FG(:,130/Ts:230/Ts);


figure
plot(hquad_pos_controller_FG(1,:)'-hquad_pos_controller_FG(1,1),[hquad_pos_controller_FG(12,:)',...
    hquad_pos_controller_FG(13,:)',hquad_pos_controller_FG(14,:)']);
title('Position control with lqg');
legend('position','velocity','reference','Location','SouthEast');
ylabel('position (meter)');
xlabel('time (sec)');
% axis([0 40 -1.5 1.5]);

