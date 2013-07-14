function [X_WPTS_S,Y_WPTS_S,SOUT,EXITFLAGS] = Smooth_Trajectory(X_WPTS,Y_WPTS,Coarsity,plot_flag)

if(length(X_WPTS)~=length(Y_WPTS))
    disp('### WRONG! The number of X - Y Waypoint Coordinates must be the same!');
else
    
num_samples = length(X_WPTS);
mul_factor = ceil(Coarsity/num_samples);
if(Coarsity<=num_samples)
    mul_factor = 1;
end

ind_wpts = 1:num_samples;
step_size = ind_wpts(end)/(mul_factor*num_samples);
ind_wpts_many = 1:step_size:ind_wpts(end);
if(ind_wpts_many(end)<ind_wpts(end))
    ind_wpts_many(end+1) = ind_wpts(end);
end

Smoothing_Factor = 5;
if(length(ind_wpts_many)<=10)
    Smoothing_Factor = 3;
end
if((length(ind_wpts_many)>10)&&(length(ind_wpts_many)<100))
    Smoothing_Factor = 5;
end
if((length(ind_wpts_many)>100)&&(length(ind_wpts_many)<1000))
    Smoothing_Factor = 500;
end
if((length(ind_wpts_many)>1000)&&(length(ind_wpts_many)<10000))
    Smoothing_Factor = 5000;
end

X_WPTS_MANY = interp1(ind_wpts,X_WPTS,ind_wpts_many);
Y_WPTS_MANY = interp1(ind_wpts,Y_WPTS,ind_wpts_many);

[X_WPTS_S,SSX,EXITFLAG_X] = smoothn(X_WPTS_MANY,Smoothing_Factor);
[Y_WPTS_S,SSY,EXITFLAG_Y] = smoothn(Y_WPTS_MANY,Smoothing_Factor);

if((X_WPTS_S(1)~=X_WPTS(1))||(Y_WPTS_S(1)~=Y_WPTS(1)))
    TEMP_V = X_WPTS_S;
    X_WPTS_S(1) = X_WPTS(1);
    X_WPTS_S(2:(length(TEMP_V)+1)) = TEMP_V;
    TEMP_V = Y_WPTS_S;
    Y_WPTS_S(1) = Y_WPTS(1);
    Y_WPTS_S(2:(length(TEMP_V)+1)) = TEMP_V;
end

if((X_WPTS_S(end)~=X_WPTS(end))||(Y_WPTS_S(end)~=Y_WPTS(end)))
    X_WPTS_S(end+1) = X_WPTS(end);
    Y_WPTS_S(end+1) = Y_WPTS(end);
end

EXITFLAGS.X = EXITFLAG_X;
EXITFLAGS.Y = EXITFLAG_Y;
SOUT.X = SSX;
SOUT.Y = SSY;

if(isempty(plot_flag)==1)
else
plot(X_WPTS,Y_WPTS,'o-b','LineWidth',2);
hold on
plot(X_WPTS_S,Y_WPTS_S,'o-r','LineWidth',2)
grid on; axis equal; xlabel('X'); ylabel('Y');
end
end

end