function U = OptimalMPCInput(X,Hn,Kn,Fi,Gi,Nc)

tolerance = 1;
nr  = size(Nc,1);
MPT_ABSTOL = 1e-8;

X = round(10000*X)/10000;

% Find the proper region
abspos = 1;
for ireg = 1:nr
    sumViol = 0;
    isinside = 1;
    
    Hi = Hn(abspos:abspos+Nc(ireg)-1,:);
    Ki = Kn(abspos:abspos+Nc(ireg)-1,:);
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
return
    
    
 