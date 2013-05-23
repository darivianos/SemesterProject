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
title('y axis');
