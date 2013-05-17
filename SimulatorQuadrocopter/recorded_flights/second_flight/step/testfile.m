
close all
%1: time
%2: x
%3: x_dot
%4: pitch
%5: x_ref
%6: pitch_cmd
%7: y
%8: y_dot%9: roll
%10: y_ref
%11: roll_cmd
%12: z
%13: z_dot
%14: z_ref
%15: thrust cmd
%16: yaw
%17: ang vel z
%18: yaw ref
%19: yaw rate cmd

time = QUAD_DATALOG.time;
pitch_cmd = QUAD_DATALOG.signals.values(:,6); 
pitch = QUAD_DATALOG.signals.values(:,4);
x = QUAD_DATALOG.signals.values(:,2);

figure(1);
subplot(311)
plot(time,x);
subplot(312);
plot(time,pitch);
subplot(313)
plot(time,pitch_cmd);
