function  plot_nicely( recorded_data, start_idx, end_idx, name )
    
    recorded_data=recorded_data(:,start_idx:end_idx);

    figure('Name',name,'Position',[1 1 800 400])
    
    
    %% x - axis
subplot(3,1,1)
plot(recorded_data(1,:)'-recorded_data(1,1),recorded_data(2,:)','b',...
    recorded_data(1,:)'-recorded_data(1,1),recorded_data(5,:)','r');
% title('Position Control with LQRI');
legend('x','x ref','Location','NorthEastOutside');
ylabel('position(m)');
xlabel('time (sec)');
axis([0 23 -0.1 0.1]);



%% y - axis
subplot(3,1,2)
plot(recorded_data(1,:)'-recorded_data(1,1),recorded_data(7,:)','b',...
    recorded_data(1,:)'-recorded_data(1,1),recorded_data(10,:)','r');
% title('Position Control with LQRI');
legend('y','y ref','Location','NorthEastOutside');
ylabel('position(m)');
xlabel('time (sec)');
axis([0 23 -0.1 0.1]);


%% z - axis
subplot(3,1,3)
plot(recorded_data(1,:)'-recorded_data(1,1),recorded_data(12,:)','b',...
    recorded_data(1,:)'-recorded_data(1,1),recorded_data(14,:)','r');
% title('Position Control with LQRI');
legend('z','z ref','Location','NorthEastOutside');
ylabel('position(m)');
xlabel('time (sec)');
axis([0 23 -0.1 0.1]);


end

