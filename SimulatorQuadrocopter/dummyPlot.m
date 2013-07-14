%%

y_ref_wall = RecordYZ.signals(1).values(:,2);
y_wall = RecordYZ.signals(1).values(:,1);

z_ref_wall = RecordYZ.signals(2).values(:,2);
z_wall = RecordYZ.signals(2).values(:,1);

close all;
figure;
plot(y_ref_wall,z_ref_wall,'b','LineWidth',2); hold on;
plot(y_wall,z_wall,'r','LineWidth',2); grid on;
axis equal;

%%
time_yz = RecordYZ.time;

subplot(2,1,1);
plot(time_yz,y_ref_wall,'b'); hold on;
plot(time_yz,y_wall,'r'); grid on;
subplot(2,1,2)
plot(time_yz,z_ref_wall,'b'); hold on;
plot(time_yz,z_wall,'r'); grid on;
%%
vel = sqrt( (0*diff(y_wall)/(time_yz(2)-time_yz(1))).^2 + (diff(z_wall)/(time_yz(2)-time_yz(1))).^2) 
plot(vel)

%%
close all;
plot(traj_FG.X_ref_y(1,:),-traj_FG.X_ref_z(1,:),'o-'); grid on; axis equal;

%%
YY_REF = [-0.65 -0.55 -0.45 -0.35 -0.25 -0.1 0.4  0.65  0.4 0.15 -0.05   0.15 0.65 0.9 0.9  1.3];
ZZ_REF = [-0.4   0.3   0.4   0.3  -0.4  -0.4 -0.4 -0.2 0.0 0.0  0.2 0.4  0.4       0.4 -0.4 -0.4];
Coarsity = 50; 
[YY_WPTS_S,ZZ_WPTS_S,SOUT,EXITFLAGS] = ACX_Smooth_Trajectory(YY_REF,ZZ_REF,Coarsity,1);
% 
% figure;
% plot(YY_REF,ZZ_REF,'o-');

%%
/home/burrimi/Downloads/acx_traj_smooth
%%
zz_vec = spline(YY_REF,ZZ_REF,yy_vec);
figure;
plot(yy_vec,zz_vec,'o-'); grid on; axis equal;
%%

y_ref_wall = RecordYZ.signals(1).values(:,2);
y_wall = RecordYZ.signals(1).values(:,1);

z_ref_wall = RecordYZ.signals(2).values(:,2);
z_wall = RecordYZ.signals(2).values(:,1);

close all;
figure;
plot(y_ref_wall,z_ref_wall,'b','LineWidth',2); hold on;
plot(y_wall,z_wall,'r','LineWidth',2); grid on;
plot(traj_FG.X_ref_y_real(1,:),-traj_FG.X_ref_z_real(1,:),'o-g'); 
axis equal;

