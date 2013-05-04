function [RecordedData,RefX,RefY,RefZ,RefYaw] = loadSimulationData(hquad_pos_FG,startIndex,endIndex)


% x direction simulation results
RecordedData.time = hquad_pos_FG(1,startIndex:endIndex);
RecordedData.time = RecordedData.time - RecordedData.time(1);
RecordedData.signals.values(:,1) = hquad_pos_FG(2,startIndex:endIndex);
RecordedData.signals.values(:,2) = hquad_pos_FG(3,startIndex:endIndex);
RecordedData.signals.values(:,3) = hquad_pos_FG(4,startIndex:endIndex);
RecordedData.signals.values(:,4) = 1*lsim(tf([1 0],[1 1]),hquad_pos_FG(4,startIndex:endIndex),RecordedData.time,0);
RecordedData.signals.values(:,5) = hquad_pos_FG(5,startIndex:endIndex);

% y direction simulation results
RecordedData.signals.values(:,6) = hquad_pos_FG(7,startIndex:endIndex);
RecordedData.signals.values(:,7) = hquad_pos_FG(8,startIndex:endIndex);
RecordedData.signals.values(:,8) = hquad_pos_FG(9,startIndex:endIndex);
RecordedData.signals.values(:,9) = 1*lsim(tf([1 0],[1 1]),hquad_pos_FG(9,startIndex:endIndex),RecordedData.time,0);
RecordedData.signals.values(:,10) = hquad_pos_FG(10,startIndex:endIndex);

% z direction simulation results
RecordedData.signals.values(:,11) = hquad_pos_FG(12,startIndex:endIndex);
RecordedData.signals.values(:,12) = hquad_pos_FG(13,startIndex:endIndex);
RecordedData.signals.values(:,13) = hquad_pos_FG(14,startIndex:endIndex);

% yaw direction simulation results
RecordedData.signals.values(:,14) = hquad_pos_FG(16,startIndex:endIndex);
RecordedData.signals.values(:,15) = hquad_pos_FG(18,startIndex:endIndex);

RefX.time = RecordedData.time;
RefX.signals.values = RecordedData.signals.values(:,5);
RefY.time = RecordedData.time;
RefY.signals.values = RecordedData.signals.values(:,10);
RefZ.time = RecordedData.time;
RefZ.signals.values = RecordedData.signals.values(:,13);
RefYaw.time = RecordedData.time;
RefYaw.signals.values = RecordedData.signals.values(:,15);

% x-direction plot
figure(1)
subplot(511)
plot(RecordedData.signals.values(:,1));
subplot(512)
plot(RecordedData.signals.values(:,2));
subplot(513)
plot(RecordedData.signals.values(:,3));
subplot(514)
plot(RecordedData.signals.values(:,4));
subplot(515)
plot(RecordedData.signals.values(:,5));

% y-direction plot
figure(2)
subplot(511)
plot(RecordedData.signals.values(:,6));
subplot(512)
plot(RecordedData.signals.values(:,7));
subplot(513)
plot(RecordedData.signals.values(:,8));
subplot(514)
plot(RecordedData.signals.values(:,9));
subplot(515)
plot(RecordedData.signals.values(:,10));

% z-direction plot
figure(3)
subplot(311)
plot(RecordedData.signals.values(:,11));
subplot(312)
plot(RecordedData.signals.values(:,12));
subplot(313)
plot(RecordedData.signals.values(:,13));

% yaw-direction plot
figure(4)
subplot(211)
plot(RecordedData.signals.values(:,14));
subplot(212)
plot(RecordedData.signals.values(:,15));


return