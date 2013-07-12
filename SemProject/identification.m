phi_ref = simout_data12.signals.values(:,1);
phi = simout_data12.signals.values(:,3);
time_vec = simout_data12.time;

plot(time_vec,phi_ref,'b'); hold on;
plot(time_vec,phi,'r'); grid on;

data_roll = iddata(phi,phi_ref,time_vec(2)-time_vec(1));

data_roll = detrend(data_roll);
plot(data_roll);
%%
plot(fft(data_roll));
%%

roll_tf = idproc('P2')
%%
roll_tf = pem(fft(data_roll),roll_tf,'focus',[0.05 25],'InitialState','Backcast');

%%
compare(data_roll,roll_tf)

%%
time_vec = time_vec - time_vec(1);
phi_ref = phi_ref - mean(phi_ref);
phi = phi - mean(phi);
phi_ref = lsim(tf(20,[1 20]),phi_ref,time_vec,phi_ref(1));
phi = lsim(tf(20,[1 20]),phi,time_vec,phi(1));

mscohere(phi_ref,phi,8092,8092/2,1024,1/0.02)
%%

phi_ss = idss(roll_tf)
phi_ss.SSParameterization = 'canonical'