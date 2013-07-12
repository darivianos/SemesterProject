posx = simout_data.signals.values(:,1);
pitch = simout_data.signals.values(:,3);
time = simout_data.time;

pitch = pitch/2/pi*180;

figure(1);
subplot(211)
plot(time,pitch);
ylabel('Pitch');
subplot(212);
plot(time,posx);
ylabel('Posx');
%%

z = simout_data.signals.values(:,11);

thrust_cmd = simout_data.signals.values(:,14)
plot(thrust_cmd);


mscohere(z,thrust_cmd)
