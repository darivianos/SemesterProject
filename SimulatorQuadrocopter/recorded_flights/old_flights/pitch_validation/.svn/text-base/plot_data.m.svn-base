close all

% %10 degree
% load hquad_pos_controller3.mat
% load hquad_pos_simulation.mat
% 
% figure
% 
% plot(hquad_pos_controller(1,:)',[hquad_pos_controller(2,:)'-1,...
%     hquad_pos_controller(3,:)',hquad_pos_controller(5,:)'-1]);
% 
% figure
% hquad_pos_simulation=hquad_pos_simulation(:,1:2223);
% hquad_pos_controller=hquad_pos_controller(:,10133-555:10133-555+2222);
% plot(hquad_pos_controller(1,:)'-162.92,[hquad_pos_controller(2,:)'-1,hquad_pos_simulation(2,:)',...
%     hquad_pos_controller(4,:)',hquad_pos_simulation(4,:)',...
%     hquad_pos_controller(6,:)',hquad_pos_simulation(6,:)']);
% axis([0 20 -0.2 1.2])
% 
% 
% load hquad_pos_controller4.mat
% figure



load hquad_pos_simulation.mat
load hquad_pos_controller5.mat


plot(hquad_pos_controller(1,:)',[hquad_pos_controller(2,:)'-1,...
    hquad_pos_controller(3,:)',hquad_pos_controller(5,:)'-1]);


figure

[~,offset_simulation] = max(diff(hquad_pos_simulation(5,:)'));

step_counter=2;
ref_dot=diff(hquad_pos_controller(5,:)');
ref_counter=0;
for i = 1:size(hquad_pos_controller,2)-1
    if ref_dot(i)>0.9
        ref_counter=ref_counter+1;
        if ref_counter==step_counter
            offset_controller=i;
        end
    end
end

hquad_pos_simulation=hquad_pos_simulation(:,1:offset_simulation+floor(10/Ts));
hquad_pos_controller=hquad_pos_controller(:,offset_controller-offset_simulation+1:offset_controller+floor(10/Ts));

plot(hquad_pos_simulation(1,:)',...
    [hquad_pos_controller(2,:)'-1,hquad_pos_simulation(2,:)',...
    hquad_pos_controller(3,:)',hquad_pos_simulation(3,:)',...
    hquad_pos_controller(4,:)',hquad_pos_simulation(4,:)',...
    hquad_pos_controller(6,:)',hquad_pos_simulation(6,:)']);
axis([0 15 -0.2 1.2])

% %5 degree
% load hquad_traj_controller2.mat
% 
% figure
% plot(pose_traj_controller(1,:),[pose_traj_controller(4,:)',pose_traj_controller(5,:)']);
% pitch_ident2=pose_traj_controller(:,20*1/Ts:50*1/Ts);
% 
% %15 degree
% load hquad_traj_controller3.mat
% 
% figure
% plot(pose_traj_controller(1,:),[pose_traj_controller(4,:)',pose_traj_controller(5,:)']);


load hquad_pos_controller_mpc.mat
load hquad_pos_simulation.mat

figure

plot(hquad_pos_controller(1,:)',[hquad_pos_controller(2,:)'-1,hquad_pos_controller(5,:)'-1]);
title('Position control with MPC');
legend('position','reference');
ylabel('position');
xlabel('time');

