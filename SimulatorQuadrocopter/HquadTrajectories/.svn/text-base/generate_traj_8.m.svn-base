N=30;
Ts=0.018;
time_per_circle=3; %time in seconds for one circle
R=0.5; %radius
x0=0;
y0=1.5;

delay_steps=3;

time=0:Ts:(time_per_circle);
%size(time)


x1=x0+R*cos(2*pi*time/time_per_circle);
y1=y0+R*sin(2*pi*time/time_per_circle);

v=2*pi*R/time_per_circle;

x1_dot=-v*sin(2*pi*time/time_per_circle);
y1_dot=v*cos(2*pi*time/time_per_circle);

x2=x0+2*R-R*cos(-2*pi*time/time_per_circle);
y2=y0-R*sin(-2*pi*time/time_per_circle);

v=2*pi*R/time_per_circle;

x2_dot=-v*sin(-2*pi*time/time_per_circle);
y2_dot=v*cos(-2*pi*time/time_per_circle);


x=[x1 x2 x1(1,1:delay_steps+N)];
x_dot=[x1_dot x2_dot x1_dot(1,1:delay_steps+N)];

y=[y1 y2 y1(1,1:delay_steps+N)];
y_dot=[y1_dot y2_dot y1_dot(1,1:delay_steps+N)];

% create X_ref
X_ref_x=[x; x_dot ; zeros(1,size(x,2))];
X_ref_y=[y; y_dot; zeros(1,size(y,2))];

% reshape reference vector for fg
traj_x=reshape(X_ref_x,1,[])';
traj_y=reshape(X_ref_y,1,[])';

traj_total_samples=round(time_per_circle/Ts*2);