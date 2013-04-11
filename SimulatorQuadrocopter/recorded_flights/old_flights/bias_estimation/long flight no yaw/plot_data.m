close all
%1: time
%2: x
%3: x_ref
%4: pitch_bias
%5: y
%6: y_ref
%7: roll_bias
%8: y_dot
%9: roll
%10: y_ref
%11: roll_cmd
%12: z
%13: z_dot
%14: z_ref
%15: thrust cmd

load hquad_bias_MPC1.mat
hquad_bias_mpc1=hquad_bias_mpc(:,20/Ts:size(hquad_bias_mpc,2));
load hquad_bias_MPC2.mat
hquad_bias_mpc2=hquad_bias_mpc(:,20/Ts:size(hquad_bias_mpc,2));
load hquad_bias_MPC3.mat
hquad_bias_mpc3=hquad_bias_mpc(:,20/Ts:size(hquad_bias_mpc,2));
load hquad_bias_MPC4.mat
hquad_bias_mpc4=hquad_bias_mpc(:,20/Ts:size(hquad_bias_mpc,2));

figure
plot(hquad_bias_mpc1(1,:)'-hquad_bias_mpc1(1,1),[hquad_bias_mpc1(2,:)'-hquad_bias_mpc1(3,:)',...
    hquad_bias_mpc1(4,:)',hquad_bias_mpc1(5,:)'-hquad_bias_mpc1(6,:)',hquad_bias_mpc1(7,:)']);
title('Position control with lqg');
legend('position','velocity','reference','Location','SouthEast');
ylabel('position (meter)');
xlabel('time (sec)');
% axis([0 40 -1.5 1.5]);

figure
plot(hquad_bias_mpc2(1,:)'-hquad_bias_mpc2(1,1),[hquad_bias_mpc2(2,:)'-hquad_bias_mpc2(3,:)',...
    hquad_bias_mpc2(4,:)',hquad_bias_mpc2(5,:)'-hquad_bias_mpc2(6,:)',hquad_bias_mpc2(7,:)']);
title('Position control with lqg');
legend('position','velocity','reference','Location','SouthEast');
ylabel('position (meter)');
xlabel('time (sec)');
% axis([0 40 -1.5 1.5]);

figure
plot(hquad_bias_mpc3(1,:)'-hquad_bias_mpc3(1,1),[hquad_bias_mpc3(2,:)'-hquad_bias_mpc3(3,:)',...
    hquad_bias_mpc3(4,:)',hquad_bias_mpc3(5,:)'-hquad_bias_mpc3(6,:)',hquad_bias_mpc3(7,:)']);
title('Position control with lqg');
legend('position','velocity','reference','Location','SouthEast');
ylabel('position (meter)');
xlabel('time (sec)');
% axis([0 40 -1.5 1.5]);

bias_pitch=hquad_bias_mpc1(4,:);
bias_pitch_mean=mean(bias_pitch)
bias_pitch_std=std(bias_pitch)
bias_roll=hquad_bias_mpc1(7,:);
bias_roll_mean=mean(bias_roll)
bias_roll_std=std(bias_roll)

bias_pitch=hquad_bias_mpc2(4,:);
bias_pitch_mean=mean(bias_pitch)
bias_pitch_std=std(bias_pitch)
bias_roll=hquad_bias_mpc2(7,:);
bias_roll_mean=mean(bias_roll)
bias_roll_std=std(bias_roll)

bias_pitch=hquad_bias_mpc3(4,:);
bias_pitch_mean=mean(bias_pitch)
bias_pitch_std=std(bias_pitch)
bias_roll=hquad_bias_mpc3(7,:);
bias_roll_mean=mean(bias_roll)
bias_roll_std=std(bias_roll)

bias_pitch=hquad_bias_mpc4(4,:);
bias_pitch_mean=mean(bias_pitch)
bias_pitch_std=std(bias_pitch)
bias_roll=hquad_bias_mpc4(7,:);
bias_roll_mean=mean(bias_roll)
bias_roll_std=std(bias_roll)
