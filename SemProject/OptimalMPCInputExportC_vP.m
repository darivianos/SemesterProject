function [U,flag_oob,M] = OptimalMPCInputExportC_vP(X,Uprev,Mprev,nx,nu,Hn,Kn,Hobj,Fobj,Gobj,Fi,Gi,Nc,Qopt,Ropt,Ml,Mr)
%#codegen

% check fixed parameters - throw errors
[nuRoptr,nuRoptc] = size(Ropt);
if (nuRoptr ~= nuRoptc) || (nuRoptr == 0) || (nuRoptr ~= nu)
    error('expected Ropt[nu,nu] square matrix');
end
% TODO Check Gi
[nuUprevr,nuUprevc] = size(Uprev);
if (nuUprevr ~= nu) || (nuUprevc ~= 1) || (nuUprevr ~= nu)
    error('expected Uprev[nu,1]');
end

[nxQoptr,nxQoptc] = size(Qopt);
if (nxQoptr ~= nxQoptc) || (nxQoptr == 0) || (nxQoptr ~= nx)
    error('expected Qopt[nx,nx] square matrix');
end
[nxHobjr,nxHobjc,~] = size(Hobj);
if (nxHobjr ~= nxHobjc) || (nxHobjr == 0) || (nxHobjr ~= nx)
    error('expected Hobj[nx,nx] square matrix');
end
% THIS IS VALID ONLY IF TRACKING = 0 (Qopt:states optimizer , Hobj:explicit optimizer) 
if nxHobjr ~= nxQoptr
    error('inconsistent Hobj , Qopt sizes -for non-tracking controller-')
end
[nxFobjr,nxFobjc,~] = size(Fobj);
if (nxFobjr~=1) || (nxFobjc ~= nx)
    error('expected Fobj[1,nx,nr] matrix');
end
[nxGobjr,nxGobjc,~] = size(Gobj);
if (nxGobjr ~= 1) || (nxGobjc ~= 1)
    error('expected Gobj[1,1,nr] matrix');
end
% TODO Check Fi

[nmMprevr,nmMprevc] = size(Mprev);
if (nmMprevr ~= 1) || (nmMprevc ~= 1)
    error('expected Mprev non-array double');
end


% check dynamic parameters - return with flags
M = 0;
[~,~,nm] = size(Ml);
if (Mprev < 1)  ||  (Mprev > nm)
    %Mprev not within system modes envelope
    U = Uprev;
    flag_oob = -1;
    return;
end
if all( Ml(:,:,Mprev)*[X;Uprev]<=Mr(:,:,Mprev) , 1 )
    M = Mprev;
else
    for im=1:nm
        if all( Ml(:,:,im)*[X;Uprev]<=Mr(:,:,im) , 1 )
            M = im;
            break;
        end
    end
end
if M==0
    %X;Uprev not within controller state-input envelope
    U = Uprev;
    flag_oob = -1;
    return;
end


tolerance = 1;
nr  = size(Nc,1);
MPT_ABSTOL = 1e-8;
minreg = 0;
%X = round(10000*X)/10000;

flag_oob = 0;
%maxSize = max(Nc);

Hsz = size(Hn,2);  %=nx?
Hi = zeros(100,Hsz);
Ki = zeros(100,1);

UminJ = 10000*ones(nu,1);
minJ = 1e+08;

% Find the proper region
abspos = 1;
for ireg = 1:nr
    sumViol = 0;
    isinside = 1;
    

%    Hi(1:Nc(ireg),1:Hsz) = Hn(abspos:(abspos+Nc(ireg)-1),1:Hsz);
     for i = 1:Nc(ireg)
         for j = 1:Hsz
             Hi(i,j) = Hn(abspos + i - 1,j);
         end
     end
    
%    Ki(1:Nc(ireg),1) = Kn(abspos:(abspos+Nc(ireg)-1),1);
    for i = 1:Nc(ireg)
        Ki(i,1) = Kn(abspos + i - 1,1);
    end
    abspos = abspos + Nc(ireg);
    
    F = Fi(:,:,ireg);
    G = Gi(:,:,ireg);
    
    nc = Nc(ireg);
    
    for ic = 1:nc
        hx = Hi(ic,:)*X;
        if ((hx - Ki(ic)) > MPT_ABSTOL)
            isinside = 0;
            sumViol = sumViol + (hx - Ki(ic));
        end
    end
    
    if (sumViol < tolerance)
        tolerance = sumViol;
        minreg = ireg;
    end
    % extract the right control law
    if (isinside == 1)
        U = F*X + G;
        Jobj = X'*Hobj(:,:,ireg)*X + Fobj(:,:,ireg)*X + Gobj(:,:,ireg);
%       % compute cost in the best region of each feasible partition
% 		for i = feasible_idx
%             if isempty(J{i})
% 			    % no cost provided by tie-breaking, compute it
% 			    % manually
%                   %  The QuadFunction class represents quadratic functions of the form f(x) =
%                   %  x'*H*x + F*x + g  where H  is a real matrix, F  is a real matrix and g is a real
%                   %  column vector. Dimensions of H, F  and g  must coincide such that the output is a scalar.
% 			    J{i} = obj.optimizer(i).Set(idx{i}).Functions('obj').feval(xinit);
% 			end
% 		end
% 		Jmin = cat(2, J{feasible_idx});
% 		[J, best_partition] = min(Jmin);
% 		U = U{feasible_idx(best_partition)};
% 		opt_region = idx{feasible_idx(best_partition)};
% 		opt_partition = feasible_idx(best_partition);
       %[U1 U2 Jobj]
       if Jobj < minJ  
            minJ = Jobj;
            UminJ = U;
       elseif Jobj == minJ
            if U'*Ropt*U < UminJ'*Ropt*UminJ
               minJ = Jobj;
               UminJ = U;
            end
       end
       %return
    end
end
if minJ < 1e+08  
    U = UminJ;
    return;
end
if minreg > 0
    F = Fi(:,:,minreg);
    G = Gi(:,:,minreg);
    U = F*X + G;
    flag_oob = 1;
else
    U = Uprev;
    flag_oob = 1;
end

return;

%ctrl.optimizer = ctrl.optimizer.merge % !!! NOT WORKING !!!
% clc; x0=[10;0;10;0;0]; 
% ctrl.evaluate([x0])
% [U1,U2,flag_oob] = OptimalMPCInputExportC_vP([x0],H,K,F1,G1,W1,F2,G2,W2,Nc)
 