close all

%1: x
%2: x_dot
%3: pitch
%4: x_ref
%5: pitch_cmd
%6: y
%7: y_dot
%8: roll
%9: y_ref
%10: roll_cmd
%11: z
%12: z_dot
%13: z_ref
%14: thrust cmd
%15: yaw
%16: ang vel z
%17: yaw ref
%18: yaw rate cmd

% Plot x axis
figure(1);
plot(simout_data.time,simout_data.signals.values(:,1));
title('x axis');

% Plot y axis
figure(2);
plot(simout_data.time,simout_data.signals.values(:,6));
title('y axis')
x_ref_sig = traj_FG.X_ref_x(1,:) + simout_data.signals.values(1,1);
y_ref_sig = traj_FG.X_ref_y(1,:) + simout_data.signals.values(1,6);
z_ref_sig = - traj_FG.X_ref_z(1,:) + simout_data.signals.values(1,11);
% Plot x-y axis
figure(3)
plot3(simout_data.signals.values(:,1),simout_data.signals.values(:,6),-simout_data.signals.values(:,11));
hold on
plot3(x_ref_sig,y_ref_sig,z_ref_sig,'r');
title('x-y-z axis plot');
grid on;
axis equal
