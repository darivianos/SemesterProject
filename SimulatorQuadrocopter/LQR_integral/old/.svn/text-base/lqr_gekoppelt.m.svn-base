Ts = 0.01; % sampling time
mass = 0.55;
g = 9.81; % gravity constant

% LQR gains
QQ = diag([100,100,100,20,20,10,0.1,5000,0.1,5000,1]);
RR = diag([350,350,20]);

% Kalman Filter gains
Q_K= 1*diag([1,1,1,1,1,1,1,1,1,1,1]); % Q kalman
R_K = 1*diag([0.000707,0.0001,0.0001, 0.000707,0.0001,0.0001, 1,1]);   % R kalman      

% linearize model
[AA, BB, CC, DD] = dlinmod( 'SimulinkModel_gekoppelt',Ts);
     
% calculate lqr gain
Kr=dlqr(AA,BB,QQ,RR);

% calculate kalman filter 
Bnoise=eye(11);
Estss = ss(AA, [BB Bnoise], CC,0,Ts);
[kest,L,P] = kalman(Estss,Q_K,R_K);

% form lqg controller
rlqg = lqgreg(kest,Kr);

% save data
save('MPC_data', 'AA', 'BB', 'CC', 'DD','QQ','RR','P');