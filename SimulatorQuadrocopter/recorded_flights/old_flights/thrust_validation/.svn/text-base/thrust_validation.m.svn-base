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

load hquad_pos.mat

hquad_pos(12,:)=hquad_pos(12,:)+0.7;
hquad_pos(14,:)=hquad_pos(14,:)+0.7;

load hquad_pos_simulation.mat

%hquad_pos_controller_lqr = hquad_pos_controller_lqr(:,1000:3300);


figure
plot(hquad_pos(1,:)'-hquad_pos(1,1),[hquad_pos(12,:)',...
    hquad_pos(13,:)',hquad_pos(14,:)']);
title('Position control with lqg');
legend('position','velocity','reference','Location','SouthEast');
ylabel('position (meter)');
xlabel('time (sec)');
% axis([0 40 -1.5 1.5]);



figure
plot(hquad_pos_simulation(1,:)'-hquad_pos_simulation(1,1),[hquad_pos_simulation(12,:)',...
    hquad_pos_simulation(13,:)',hquad_pos_simulation(14,:)']);
title('Position control with mpc');
legend('position','velocity','reference','Location','SouthEast');
ylabel('position (meter)');
xlabel('time (sec)');

% axis([80 120 -1.5 1.5]);

%% sync steps of simulation and real model
figure
[~,offset_simulation] = max(diff(hquad_pos_simulation(14,:)'));

step_counter=4;
ref_dot=diff(hquad_pos(14,:)');
ref_counter=0;
for i = 1:size(hquad_pos,2)-1
    if ref_dot(i)<-0.9
        ref_counter=ref_counter+1;
        if ref_counter==step_counter
            offset_controller=i
        end
    end
end

hquad_pos_simulation=hquad_pos_simulation(:,offset_simulation-floor(8/Ts):offset_simulation+floor(10/Ts));
hquad_pos=hquad_pos(:,offset_controller+2-floor(8/Ts):offset_controller+floor(10/Ts));

plot(hquad_pos_simulation(1,:)'-hquad_pos_simulation(1,1),...
    [hquad_pos_simulation(12,:)',...
    hquad_pos_simulation(13,:)'],'--');

% plot(hquad_pos_simulation(1,:)',...
%     [hquad_pos_controller_lqr(2,:)',hquad_pos_simulation(2,:)',...
%     hquad_pos_controller_lqr(3,:)',hquad_pos_simulation(3,:)',...
%     hquad_pos_controller_lqr(5,:)',hquad_pos_simulation(5,:)']);
axis([0 15 -0.2 1.2])

hold on
plot(hquad_pos(1,:)'-hquad_pos(1,1),...
    [-1*hquad_pos(12,:)',...
    -1*hquad_pos(13,:)',...
    -1*hquad_pos(14,:)']);

axis([0 15 -0.2 1.2])

title('Step Response in z-Direction Model and Measured');
legend('position model','velocity model','position vicon','velocity vicon','reference','Location','NorthWest');
ylabel('position (m)');
xlabel('time (sec)');


% 
% %% plot MPC flight
% load hquad_pos_controller_mpc.mat
% load hquad_pos_simulation.mat
% 
% figure
% 
% plot(hquad_pos_controller(1,:)',[hquad_pos_controller(2,:)'-1,hquad_pos_controller(5,:)'-1]);
% title('Position control with MPC');
% legend('position','reference');
% ylabel('position');
% xlabel('time');
% 
