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

load hquad_pos_controller_lqr.mat

load hquad_pos_controller_mpc.mat

load hquad_pos_simulation.mat

%hquad_pos_controller_lqr = hquad_pos_controller_lqr(:,1000:3300);
hquad_pos_controller_lqr = hquad_pos_controller_lqr(:,3700:7000);

figure
plot(hquad_pos_controller_lqr(1,:)'-hquad_pos_controller_lqr(1,1),[hquad_pos_controller_lqr(2,:)',...
    hquad_pos_controller_lqr(3,:)',hquad_pos_controller_lqr(5,:)']);
title('Step Response with LQRI in x-Axis');
legend('position','velocity','reference','Location','SouthEast');
ylabel('position (m)');
xlabel('time (sec)');
axis([0 40 -1.5 1.5]);

hquad_pos_controller_mpc=hquad_pos_controller_mpc(:,4444:6670);

figure
plot(hquad_pos_controller_mpc(1,:)'-hquad_pos_controller_mpc(1,1),[hquad_pos_controller_mpc(2,:)',...
    hquad_pos_controller_mpc(3,:)',hquad_pos_controller_mpc(5,:)']);
title('Step Response with MPC in x-Axis');
legend('position','velocity','reference','Location','SouthEast');
ylabel('position (m)');
xlabel('time (sec)');
axis([0 40 -1.5 1.5]);

figure
plot(hquad_pos_simulation(1,:)'-hquad_pos_simulation(1,1),[hquad_pos_simulation(2,:)',...
    hquad_pos_simulation(3,:)',hquad_pos_simulation(5,:)']);
title('Position control with mpc');
legend('position','velocity','reference','Location','SouthEast');
ylabel('position (m)');
xlabel('time (sec)');

% axis([80 120 -1.5 1.5]);

%% sync steps of simulation and real model
figure
[~,offset_simulation] = max(diff(hquad_pos_simulation(5,:)'));

step_counter=2;
ref_dot=diff(hquad_pos_controller_lqr(5,:)');
ref_counter=0;
for i = 1:size(hquad_pos_controller_lqr,2)-1
    if ref_dot(i)>0.9
        ref_counter=ref_counter+1;
        if ref_counter==step_counter
            offset_controller=i
        end
    end
end

% hquad_pos_simulation=hquad_pos_simulation(:,1:offset_simulation+floor(10/Ts));
hquad_pos_controller_lqr=hquad_pos_controller_lqr(:,offset_controller-offset_simulation+2:offset_controller+floor(10/Ts));

plot(hquad_pos_simulation(1,:)',...
    [hquad_pos_simulation(2,:)',...
    hquad_pos_simulation(3,:)'],'--');

% plot(hquad_pos_simulation(1,:)',...
%     [hquad_pos_controller_lqr(2,:)',hquad_pos_simulation(2,:)',...
%     hquad_pos_controller_lqr(3,:)',hquad_pos_simulation(3,:)',...
%     hquad_pos_controller_lqr(5,:)',hquad_pos_simulation(5,:)']);
axis([0 15 -0.2 1.2])

hold on
plot(hquad_pos_controller_lqr(1,:)'-hquad_pos_controller_lqr(1,1),...
    [hquad_pos_controller_lqr(2,:)',...
    hquad_pos_controller_lqr(3,:)',...
    hquad_pos_controller_lqr(5,:)']);

axis([0 15 -0.3 1.3])

title('Step response LQG in x-direction');
legend('position model','velocity model','position vicon','velocity vicon','reference','Location','SouthEast');
ylabel('position (meter)');
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
