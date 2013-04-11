close all
load hquad_identification_pitch.mat
Ts=0.018;

% command was +-15deg
figure
plot(hquad_identification(1,:),[hquad_identification(2,:)'-0.02,hquad_identification(3,:)']);
pitch_ident1=hquad_identification(:,86*1/Ts:117*1/Ts);
pitch_ident_cam = iddata(pitch_ident1(2,:)'-0.02,pitch_ident1(3,:)',Ts);
