N=30;
Ts=0.02;

delay_steps_max=11;

speed=0.01;
yaw=0;

% % simple docking
% waypoints = [
%     0, 0, 0, yaw, speed;];

% points square on the wall
waypoints = [
    0, 0, 0, yaw, speed;
    0, 0, -0.5, yaw, speed;
    0, -0.5, -0.5, yaw, speed;
    0, -0.5, 0, yaw, speed;
    0, -0.5, 0.5, yaw, speed;
    0, 0, 0.5, yaw, speed;
    0, 0.5, 0.5, yaw, speed;
    0, 0.5, 0, yaw, speed;
    0, 0.5, -0.5, yaw, speed;
    0, 0, -0.5, yaw, speed;
    ];


num_waypoints=size(waypoints,1);
    
counter=1;

for waypoint_id=1:num_waypoints

    P1 = waypoints(waypoint_id,1:3)';
    yaw1 = waypoints(waypoint_id,4);
    speed=waypoints(waypoint_id,5);

    pos_ref(:,waypoint_id) = P1;
    yaw_ref(:,waypoint_id) = yaw1;
end

total_size=size(pos_ref,2);
% create X_ref
% X_ref_x=[x; x_dot; zeros(1,size(x,2))];
X_ref_x=[pos_ref(1,:); zeros(1,total_size); zeros(1,total_size)];
% X_ref_y=[y; y_dot; zeros(1,size(y,2))];
X_ref_y=[pos_ref(2,:); zeros(1,total_size); zeros(1,total_size)];
X_ref_z=[pos_ref(3,:); zeros(1,total_size)];
X_ref_yaw=[yaw_ref;zeros(1,total_size)];



% reshape reference vector for fg
traj_x=reshape(X_ref_x,1,[])';
traj_y=reshape(X_ref_y,1,[])';
traj_yaw=X_ref_yaw;

traj_total_samples=counter-1;


traj_FG = struct();
traj_FG.X_ref_x=X_ref_x;
traj_FG.X_ref_y=X_ref_y;
traj_FG.X_ref_z=X_ref_z;
traj_FG.X_ref_yaw=X_ref_yaw;
traj_FG.total_samples=traj_total_samples;

save('traj_wall_square.mat', 'traj_FG');
