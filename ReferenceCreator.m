function traj_FG = ReferenceCreator(maxdisty,maxdistz,interpy,interpz)
% Simple GUI for drawing trajectories on the wall
% 
% traj_FG = ReferenceCreator(maxdisty,maxdistz,interpy,interpz)
% maxdisty : borders in y direction from center
% maxdistz : borders in z direction from center
% interpy : Distance between interpolated points in y direction
% interpz : Distance between interpolated points in z direction
%
% Created by Darivianakis Georgios (gdarivia@student.ethz.ch)
% Date: 7/7/2013

maxdisty = abs(maxdisty);
maxdistz = abs(maxdistz);
interpy = abs(interpy);
interpz = abs(interpz);

h = figure;
axis([-maxdisty,maxdisty,-maxdistz,maxdistz]);

yvec = zeros(1,1000);
zvec = zeros(1,1000);

disp('Central point (0,0)');
disp('Left mouse button, new point');
disp('Right mouse button for final point');

[yvec(1),zvec(1)] = ginput(1);

counter = 1;
while ~strcmp(get(gcf,'SelectionType'),'alt')
    counter = counter + 1;    
    [yvec(counter),zvec(counter)] = ginput(1);
    plot(yvec(1:counter),zvec(1:counter));
    axis([-maxdisty,maxdisty,-maxdistz,maxdistz]);
end

y = yvec(1:counter);
z = -1*zvec(1:counter);

deltay = zeros(1,counter-1);
deltaz = zeros(1,counter-1);
for ii = 2:counter
    deltay = floor((y(ii) - y(ii-1))/interpy);   % Number of intermediate points
    deltaz = floor((z(ii) - z(ii-1))/interpz);   % Number of intermediate points
    delta(ii-1) = max(abs(deltay),abs(deltaz));    % same number of intermediate points, maximum absolute value
end

cnew = 0;
y_new = zeros(1,sum(delta)+1);
z_new = zeros(1,sum(delta)+1);
for ii = 1:counter-1
    for jj = 1:delta(ii)
        cnew = cnew + 1;
        if y(ii) > y(ii+1)
            y_new(cnew) = y(ii) - (jj-1)*interpy;
            if y_new(cnew) < y(ii+1)
                y_new(cnew) = y_new(cnew-1);
            end
        else
            y_new(cnew) = y(ii) + (jj-1)*interpy;
            if y_new(cnew) > y(ii+1)
                y_new(cnew) = y_new(cnew-1);
            end
        end
        if z(ii) > z(ii+1)
            z_new(cnew) = z(ii) - (jj-1)*interpz;
            if z_new(cnew) < z(ii+1)
                z_new(cnew) = z_new(cnew-1);
            end
        else
            z_new(cnew) = z(ii) + (jj-1)*interpz;
            if z_new(cnew) > z(ii+1)
                z_new(cnew) = z_new(cnew-1);
            end
        end
    end
end
cnew = cnew + 1;
y_new(cnew) = y(counter);
z_new(cnew) = z(counter);

counter = cnew;
y = y_new;
z = z_new;

% create X_ref 
X_ref_x=[zeros(1,counter); zeros(1,counter);zeros(1,counter)]; % In x axis the wall position is at zero
X_ref_y=[y; zeros(1,counter);zeros(1,counter)]; % No velocity references, controller does all the job...
X_ref_z=[z; zeros(1,counter)];
X_ref_yaw=[zeros(1,counter);zeros(1,counter)];  % No yaw


traj_FG = struct();
traj_FG.X_ref_x=X_ref_x;
traj_FG.X_ref_y=X_ref_y;
traj_FG.X_ref_z=X_ref_z;
traj_FG.X_ref_yaw=X_ref_yaw;
traj_FG.total_samples=counter;

return
