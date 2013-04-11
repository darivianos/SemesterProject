close all


load hquad_pos_controller_lqg.mat
hquad_pos_controller_lqg=hquad_pos_controller;
load hquad_pos_controller_MPC.mat
hquad_pos_controller_mpc=hquad_pos_controller;

hquad_pos_controller_lqg = hquad_pos_controller_lqg(:,1000:3300);

close all
figure
plot(hquad_pos_controller_lqg(1,:)'-hquad_pos_controller_lqg(1,1),[hquad_pos_controller_lqg(2,:)'-1,...
    hquad_pos_controller_lqg(3,:)',hquad_pos_controller_lqg(5,:)'-1,...
    hquad_pos_controller_lqg(12,:)',hquad_pos_controller_lqg(14,:)']);
title('Position control with lqg');
legend('position','velocity','reference','Location','SouthEast');
ylabel('position (meter)');
xlabel('time (sec)');
axis([0 40 -1.5 1.5]);


hquad_pos_controller_mpc = hquad_pos_controller_mpc(:,9600:11900);

figure
plot(hquad_pos_controller_mpc(1,:)'-hquad_pos_controller_mpc(1,1),[hquad_pos_controller_mpc(2,:)'-1,...
    hquad_pos_controller_mpc(3,:)',hquad_pos_controller_mpc(5,:)'-1,...
    hquad_pos_controller_mpc(12,:)',hquad_pos_controller_mpc(14,:)']);
title('Position control with MPC');
legend('position','velocity','reference','Location','SouthEast');
ylabel('position (meter)');
xlabel('time (sec)');
axis([0 40 -1.5 1.5]);

% 
% %% sync steps of simulation and real model
% figure
% [~,offset_simulation] = max(diff(hquad_pos_simulation(5,:)'));
% 
% step_counter=2;
% ref_dot=diff(hquad_pos_controller(5,:)');
% ref_counter=0;
% for i = 1:size(hquad_pos_controller,2)-1
%     if ref_dot(i)>0.9
%         ref_counter=ref_counter+1;
%         if ref_counter==step_counter
%             offset_controller=i;
%         end
%     end
% end
% 
% hquad_pos_simulation=hquad_pos_simulation(:,1:offset_simulation+floor(10/Ts));
% hquad_pos_controller=hquad_pos_controller(:,offset_controller-offset_simulation+1:offset_controller+floor(10/Ts));
% 
% plot(hquad_pos_simulation(1,:)',...
%     [hquad_pos_controller(2,:)'-1,hquad_pos_simulation(2,:)',...
%     hquad_pos_controller(3,:)',hquad_pos_simulation(3,:)',...
%     hquad_pos_controller(4,:)',hquad_pos_simulation(4,:)',...
%     hquad_pos_controller(6,:)',hquad_pos_simulation(6,:)']);
% axis([0 15 -0.2 1.2])
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
