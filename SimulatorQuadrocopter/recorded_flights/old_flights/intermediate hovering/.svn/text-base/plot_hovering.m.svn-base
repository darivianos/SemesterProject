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
%14: thrust cmd

load hovering_lqr.mat



hquad_pos_controller_lqr_vicon = hquad_pos_controller_lqr(:,1000:4047);
hquad_pos_controller_lqr_vision = hquad_pos_controller_lqr(:,4048:5700);

rms_x_vicon=norm(hquad_pos_controller_lqr_vicon(2,:)-hquad_pos_controller_lqr_vicon(5,:))/sqrt(size(hquad_pos_controller_lqr_vicon,2))
rms_x_vision=norm(hquad_pos_controller_lqr_vision(2,:)-hquad_pos_controller_lqr_vision(5,:))/sqrt(size(hquad_pos_controller_lqr_vision,2))

rms_y_vicon=norm(hquad_pos_controller_lqr_vicon(7,:)-hquad_pos_controller_lqr_vicon(10,:))/sqrt(size(hquad_pos_controller_lqr_vicon,2))
rms_y_vision=norm(hquad_pos_controller_lqr_vision(7,:)-hquad_pos_controller_lqr_vision(10,:))/sqrt(size(hquad_pos_controller_lqr_vision,2))

rms_z_vicon=norm(hquad_pos_controller_lqr_vicon(12,:)-hquad_pos_controller_lqr_vicon(14,:))/sqrt(size(hquad_pos_controller_lqr_vicon,2))
rms_z_vision=norm(hquad_pos_controller_lqr_vision(12,:)-hquad_pos_controller_lqr_vision(14,:))/sqrt(size(hquad_pos_controller_lqr_vision,2))



figure
plot(hquad_pos_controller_lqr_vicon(1,:)'-hquad_pos_controller_lqr_vicon(1,1),[hquad_pos_controller_lqr_vicon(2,:)',...
    hquad_pos_controller_lqr_vicon(3,:)',hquad_pos_controller_lqr_vicon(5,:)']);
title('Position control with lqg');
legend('position','velocity','reference','Location','SouthEast');
ylabel('position (meter)');
xlabel('time (sec)');
% axis([0 40 -1.5 1.5]);

figure
plot(hquad_pos_controller_lqr_vision(1,:)'-hquad_pos_controller_lqr_vision(1,1),[hquad_pos_controller_lqr_vision(2,:)',...
    hquad_pos_controller_lqr_vision(3,:)',hquad_pos_controller_lqr_vision(5,:)']);
title('Position control with lqg');
legend('position','velocity','reference','Location','SouthEast');
ylabel('position (meter)');
xlabel('time (sec)');
