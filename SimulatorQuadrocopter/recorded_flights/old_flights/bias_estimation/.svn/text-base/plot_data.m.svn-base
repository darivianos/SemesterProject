close all
%1: time
%2: x
%3: x_ref
%4: pitch_bias
%5: y
%6: y_ref
%7: roll_bias
%8: z
%9: z_ref
%10: thrust_bias
%11: yaw
%12: yaw_ref
%13: yaw_rate_bias

load hquad_bias_MPC.mat







figure
plot(hquad_bias_mpc(1,:)'-hquad_bias_mpc(1,1),[hquad_bias_mpc(8,:)'-hquad_bias_mpc(9,:)',...
    hquad_bias_mpc(4,:)',hquad_bias_mpc(7,:)',hquad_bias_mpc(10,:)']);
title('Position control with lqg');
legend('position','velocity','reference','Location','SouthEast');
ylabel('position (meter)');
xlabel('time (sec)');
% axis([0 40 -1.5 1.5]);

