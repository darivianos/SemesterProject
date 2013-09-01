function [H,K,Hobj,Fobj,Gobj,F,G,Nc,Qopt,Ropt,Ml,Mr] = GetMPCMatrices_vP(obj)

nx = obj.nx;
nu = obj.model.nu;

Qopt = obj.model.x.penalty.H;
if ~isempty(obj.model.u.penalty)
    Ropt = obj.model.u.penalty.H;
elseif ~isempty(obj.model.u.deltaPenalty)
    disp('WARNING: !!! Ropt := deltaPenalty !!!');
    Ropt = obj.model.u.deltaPenalty.H;
else
    error('ERROR: !!! No u or deltau Penalty !!!');
end

if isfield(struct(obj.model),'modes')
    %number of modes
    [~,nm] = size(struct(obj.model).modes);
    nineq = 0;
    for im = 1:nm
        %max number of Inequalities
        nineq = max( nineq , size(struct(struct(obj.model).modes(im)).domain.b) );
    end
    %mode inequalities right/left
    Ml = zeros(nineq,nx+nu,nm);
    Mr = zeros(nineq,1,nm);
    for im = 1:nm
        Ml(:,:,im) = [struct(struct(obj.model).modes(im)).domain.A;zeros(nineq-size(struct(struct(obj.model).modes(im)).domain.A),nx+nu)];
        Mr(:,:,im) = [struct(struct(obj.model).modes(im)).domain.b;zeros(nineq-size(struct(struct(obj.model).modes(im)).domain.b),1)];
    end
    disp(['!!! PWA system with ' nm+char('0') ' modes and ' nu+char('0') ' input(s) detected !!!']); %simple, works up to 9 modes
else
    nm = 1;
    nineq = 1;
    Ml = zeros(nineq,nx+nu,nm);
    Mr = zeros(nineq,1,nm);
    disp(['!!! LTI system with single mode and ' nu+char('0') ' input(s) detected !!!']);
end

% Main Modification for support of PWA systems
tempnum = size(obj.feedback,2);
clear Pn;
Pn = [];
On = [];
nr = 0;
for i = 1:tempnum
    Pn = [Pn;obj.feedback(i).Set];
    On = [On;obj.optimizer(i).Set];
    nr = nr + obj.feedback(i).Num;
end
if nr~=obj.nr;  error('err_nr!ctrl.nr=');  return;  end

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
Gi = cell(nr,1);
Hobji = cell(nr,1);
Fobji = cell(nr,1);
Gobji = cell(nr,1);
for i=1:nr
    %Frows=size(Pn(i).getFunction('primal').F,1); if find(any(Pn(i).getFunction('primal').F(nu+1:Frows,:))); disp(Pn(i).getFunction('primal').F); disp(i); error('shit1'); return; end;
    %grows=size(Pn(i).getFunction('primal').g,1); if find(any(Pn(i).getFunction('primal').g(nu+1:grows))); disp(Pn(i).getFunction('primal').g); disp(i); error('shit2'); return; end; 
    %if find(any(On(i).getFunction('primal').F-Pn(i).getFunction('primal').F)); disp(i); error('shit3'); return; end;
    Fi{i}=Pn(i).getFunction('primal').F(1:nu,:);
    Gi{i}=Pn(i).getFunction('primal').g(1:nu);
    Hobji{i}=On(i).getFunction('obj').H;
    Fobji{i}=On(i).getFunction('obj').F;
    Gobji{i}=On(i).getFunction('obj').g;
    % %SAME
    % struct( ctrl.optimizer(i1).Set(i2).Functions('primal') ).F
    % struct( ctrl.feedback(i1).Set(i2).Functions('primal') ).F
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

H = zeros(nctotal,nx);
K = zeros(nctotal,1);
Hobj = zeros(nx,nx,nr);
Fobj = zeros(1,nx,nr);
Gobj = zeros(1,1,nr);
F = zeros(nu,nx,nr);
G = zeros(nu,1,nr);

abspos = 1;
for i = 1:nr
    
    H(abspos:abspos+Nc(i)-1,:) = Hn{i};
    K(abspos:abspos+Nc(i)-1,:) = Kn{i};
    abspos = abspos + Nc(i);

    Hobj(:,:,i) = Hobji{i};
    Fobj(:,:,i) = Fobji{i};
    Gobj(:,:,i) = Gobji{i};
    
    F(:,:,i) = Fi{i};
    G(:,:,i) = Gi{i}; 
    
end

return