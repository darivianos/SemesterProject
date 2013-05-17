N=30;
Ts=0.02;
time_per_circle=6; %time in seconds for one circle
num_of_circles=3;
R=0.5; %radius
x0=1.3;
y0=-1.2;
z0=-1;

time=0:Ts:(num_of_circles*time_per_circle+(N+1)*Ts);
%size(time)


x=x0+R*cos(2*pi*time/time_per_circle);
y=y0+R*sin(2*pi*time/time_per_circle);

yaw=zeros(size(time));
%yaw=time/time_per_circle*2*pi;

v=2*pi*R/time_per_circle;

x_dot=-v*sin(2*pi*time/time_per_circle);
y_dot=v*cos(2*pi*time/time_per_circle);

yaw_dot=zeros(size(time));
%yaw_dot=2*pi/time_per_circle*ones(1,size(time,2));

z=z0*ones(1,size(time,2));


% create X_ref
X_ref_x=[x; x_dot; zeros(1,size(x,2))];
% X_ref_x=[x; x_dot; [0 diff(x_dot)/g]];
X_ref_y=[y; y_dot; zeros(1,size(y,2))];
% X_ref_y=[y; y_dot; [0 diff(y_dot)/g]];
X_ref_z=[z; [diff(z),0]/Ts];

X_ref_yaw=[yaw;yaw_dot];



traj_total_samples=round(num_of_circles*time_per_circle/Ts);

traj_FG = struct();
traj_FG.X_ref_x=X_ref_x;
traj_FG.X_ref_y=X_ref_y;
traj_FG.X_ref_z=X_ref_z;
traj_FG.X_ref_yaw=X_ref_yaw;
traj_FG.total_samples=traj_total_samples;

save('traj_circle.mat', 'traj_FG');

