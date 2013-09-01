function U = OptimalMPCInput(X,Hn,Kn,Fi,Gi,Nc,Hobj,Fobj,Gobj)

tolerance = 1;
nr  = size(Nc,1);
nu = size(Gi,1)/nr;
MPT_ABSTOL = 1e-8;
UminJ = 10000*ones(nu,1);
minJ = 1e+08;

X = round(10000*X)/10000;

% Find the proper region
abspos = 1;
for ireg = 1:nr
    sumViol = 0;
    isinside = 1;
    
    Hi = Hn(abspos:abspos+Nc(ireg)-1,:);
    Ki = Kn(abspos:abspos+Nc(ireg)-1,:);
    abspos = abspos + Nc(ireg);
    
    F = Fi((ireg-1)*nu+1:ireg*nu,:);
    G = Gi((ireg-1)*nu+1:ireg*nu,:);
    
    Ho = Hobj((ireg-1)*nx+1:ireg*nx,:);
    Fo = Fobj(ireg,:);
    Go = Gobj(ireg);
    
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
        
       Jobj = X'*Ho*X + Fo*X + Go;
       if Jobj < minJ  
            minJ = Jobj;
            UminJ = U;
       end
    end
end

if UminJ == 10000*ones(nu,1)
    F = Fi((minreg-1)*nu:minreg*nu,:);
    G = Gi((minreg-1)*nu:minreg*nu,:);
    U = F*X + G;
else
    U = UminJ;
end
return