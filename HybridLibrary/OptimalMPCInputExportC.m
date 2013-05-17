function [U,flag_oob] = OptimalMPCInputExportC(X,Hn,Kn,Fi,Gi,Nc)

tolerance = 1;
nr  = size(Nc,1);
MPT_ABSTOL = 1e-8;
minreg = 0;
X = round(10000*X)/10000;

flag_oob = 0;
%maxSize = max(Nc);

Hi = zeros(100,4);
Ki = zeros(100,1);

% Find the proper region
abspos = 1;
for ireg = 1:nr
    sumViol = 0;
    isinside = 1;
    

  %  Hi(1:Nc(ireg),1:4) = Hn(abspos:(abspos+Nc(ireg)-1),1:4);
    for i = 1:Nc(ireg)
        for j = 1:4
            Hi(i,j) = Hn(abspos + i - 1,j);
        end
    end
    
%    Ki(1:Nc(ireg),1) = Kn(abspos:(abspos+Nc(ireg)-1),1);
    for i = 1:Nc(ireg)
        Ki(i,1) = Kn(abspos + i - 1,1);
    end
    abspos = abspos + Nc(ireg);
    
    F = Fi(ireg,:);
    G = Gi(ireg,:);
    
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
        return
    end
end
F = Fi(minreg,:);
G = Gi(minreg,:);
U = F*X + G;
flag_oob = 1;
%U = U_prev;
return
    
    
 