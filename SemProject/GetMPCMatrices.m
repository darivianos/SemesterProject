function [H,K,F,G,Nc] = GetMPCMatrices(obj)

% Main Modification for support of PWA systems
tempnum = size(obj.feedback,2);
clear Pn;
Pn = [];
nr = 0;
nu = obj.nu;
for i = 1:tempnum
    Pn = [Pn;obj.feedback(i).Set];
    nr = nr + obj.feedback(i).Num;
end


% extract hyperplane representation
Hn = cell(nr,1);
Kn = cell(nr,1);
[Hn{:}]=deal(Pn.A);
[Kn{:}]=deal(Pn.b);
if ~iscell(Hn),
    Hn = {Hn};
    Kn = {Kn};
end

% extract control law
Fi = cell(nr,1);
Gi = Fi;
for i=1:nr
    Fi{i}=Pn(i).getFunction('primal').F(1:nu,:);
    Gi{i}=Pn(i).getFunction('primal').g(1:nu);
end

Nc = zeros(nr,1);
for i = 1:nr
    Nc(i) = size(Hn{i},1);
end

% count number of constraints
nctotal = 0;
for ii=1:nr,
    nctotal = nctotal + size(Pn(ii).H,1);
end

nx = obj.nx;
H = zeros(nctotal,nx);
K = zeros(nctotal,1);

F = zeros(nr*nu,nx);
G = zeros(nr*nu,1);

abspos = 1;
for i = 1:nr
    H(abspos:abspos+Nc(i)-1,:) = Hn{i};
    K(abspos:abspos+Nc(i)-1,:) = Kn{i};
    abspos = abspos + Nc(i);
    
    F((i-1)*nu+1:i*nu,:) = Fi{i};
    G((i-1)*nu+1:i*nu,:) = Gi{i};
end

return