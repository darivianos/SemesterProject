N=30;
Ts=0.018;

delay_steps_max=11;

speed=0.5;
yaw=-2.35619449;
%yaw=0;

waypoints = [2, -0.4, -1, yaw, speed;
    2, -1.4, -1, yaw, speed;
    1, -1.4, -1, yaw, speed;
    1, -0.4, -1, yaw, speed;
    2, -0.4, -1, yaw, speed;
    2, -1.4, -1, yaw, speed;
    1, -1.4, -1, yaw, speed;
    1, -0.4, -1, yaw, speed;
    2, -0.4, -1, yaw, speed;
    ];

% points square
% waypoints = [0, 0, -1, yaw, speed;
%     0, -1, -1, yaw, speed;
%     1, -1, -1, yaw, speed;
%     1, 0, -1, yaw, speed;
%     0, 0, -1, yaw, speed;
%     0, -1, -1, yaw, speed;
%     1, -1, -1, yaw, speed;
%     1, 0, -1, yaw, speed;
%     0, 0, -1, yaw, speed;
%     ];

% 
% waypoints = [0.8, -0.7, -1, yaw, speed;
%     0.8, -1.7, -1, yaw, speed;
%     1.8, -1.7, -1, yaw, speed;
%     1.8, -0.7, -1, yaw, speed;
%     0.8, -0.7, -1, yaw, speed;
%     0.8, -1.7, -1, yaw, speed;
%     1.8, -1.7, -1, yaw, speed;
%     1.8, -0.7, -1, yaw, speed;
%     0.8, -0.7, -1, yaw, speed;
%     ];


% waypoints = [2, 0, -1, yaw, speed;
%     2.3, -0.65, -1, yaw, speed;
%     2.3, -1.23, -1, yaw, speed;
%     2, -1.75, -1, yaw, speed;
%     2, -1.75, -1.2, yaw, speed;
%     2.3, -1.23, -1.2, yaw, speed;
%     2.3, -0.65, -1.2, yaw, speed;
%     2, 0, -1.2, yaw, speed;
%     2, 0, -1.4, yaw, speed;
%     2.3, -0.65, -1.4, yaw, speed;
%     2.3, -1.23, -1.4, yaw, speed;
%     2, -1.75, -1.4, yaw, speed;
%     2, -1.75, -1.6, yaw, speed;
%     2.3, -1.23, -1.6, yaw, speed;
%     2.3, -0.65, -1.6, yaw, speed;
%     2, 0, -1.6, yaw, speed;
%     2, 0, -1, yaw, speed;
%     ];


num_waypoints=size(waypoints,1);
    
counter=1;

for waypoint_id=1:num_waypoints-1

    P1 = waypoints(waypoint_id,1:3)';
    yaw1 = waypoints(waypoint_id,4);
    speed=waypoints(waypoint_id+1,5);


    P2=waypoints(waypoint_id+1,1:3)';
    yaw2 = waypoints(waypoint_id+1,4);
    vect=(P2-P1);
    if norm(vect)~=0   %if 2 waypoints are equal just skip to next waypoint_id
        num_of_points = norm(vect)/(Ts*speed);
        for i=1:num_of_points
            t=i/num_of_points;
            pos_ref(:,counter)=P1+t*vect;
            yaw_ref(:,counter)=yaw1+t*(yaw2-yaw1);
            counter=counter+1;
        end
    end
end

for i=1:N+delay_steps_max
    pos_ref(:,counter+i-1)=P2;
    yaw_ref(:,counter+i-1)=yaw2;
end
total_size=size(pos_ref,2);
% create X_ref
% X_ref_x=[x; x_dot; zeros(1,size(x,2))];
X_ref_x=[pos_ref(1,:); [diff(pos_ref(1,:)),0]/Ts; zeros(1,total_size)];
% X_ref_y=[y; y_dot; zeros(1,size(y,2))];
X_ref_y=[pos_ref(2,:); [diff(pos_ref(2,:)),0]/Ts; zeros(1,total_size)];
X_ref_z=[pos_ref(3,:); [diff(pos_ref(3,:)),0]/Ts];
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
traj_FG.total_samples=counter-1;

save('traj_points.mat', 'traj_FG');

