function exportToC_MLD(obj,Ts)
%
%  EXPORTTOC: Export the explicit controller to C-code of MLD systems,
%  otherwise use the controller.exportToC(); of the explicit controller.
%  The function was modified to compensate for the definition of Ts.
%  ====================================================
%  
%  
%  SYNTAX
%  ------
%     
%      exportToC_MLD(expmpc,Ts)
%    
%  
%  DESCRIPTION
%  -----------
%     The routine exportToC generates C-code from the explicit controller. A new
%  directory is always created with the generated code. If no name of the directory
%  is provided in the second argument, the default name for the directory is
%  mpt_explicit_controller. The directory contains three files: 
%    
%     - mpt_getInput.h - The header files with PWA control law. 
%     - mpt_getInput.c - The routine for sequential evaluation of PWA control law. 
%     - mpt_getInput_sfunc.c - The Simulink interface for calling using the mpt_sim
%     library. 
%    The generated code can be used for fast execution of MPC control. An example
%  of Simulink interface to generated code is given in mpt_getInput_sfunc.c that
%  can be tested from Matlab. The prerequisite is to have C-compiler installed and
%  recognized from Matlab. To test the Simulink interface, compile the
%  mpt_getInput_sfunc.c first by typing
%     mex mpt_getInput_sfunc.c.
%    When compiled, connect the block of explicit controller from MPT Simulink
%  library mpt_sim with your scheme and run the simulation.
%  
%  INPUT
%  -----
%     
%        
%          filename Name of the header file to be generated. 
%                                                            
%                   Class: char                              
%          dirname  Name of the directory to be generated.   
%                   Class: char                              
%                     
%  
%  

%  AUTHOR(s)
%  ---------
%     
%    
%   (c) 2010-2012  Martin Herceg: ETH Zurich
%   mailto:herceg@control.ee.ethz.ch 
%     
%    
%   (c) 2003-2012  Michal Kvasnica: STU Bratislava
%   mailto:michal.kvasnica@stuba.sk 
%  
%  

%  LICENSE
%  -------
%    
%    This program is free software; you can redistribute it and/or modify it under
%  the terms of the GNU General Public License as published by the Free Software
%  Foundation; either version 2.1 of the License, or (at your option) any later
%  version.
%    This program is distributed in the hope that it will be useful, but WITHOUT
%  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
%  FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
%    You should have received a copy of the GNU General Public License along with
%  this library; if not, write to the  Free Software Foundation, Inc.,  59 Temple
%  Place, Suite 330,  Boston, MA 02111-1307 USA
 
 
global MPTOPTIONS

if isempty(MPTOPTIONS)
    MPTOPTIONS = mptopt;
end


fname = 'mpt_getInput';
dirname = 'mpt_explicit_controller';
% append the dirname to a current directory
dirname = [pwd, filesep, dirname];

% generate the files inside given directory
if ~mkdir(dirname)
    error('Could not create directory "%s".',dirname);
end
% add extension
fullfilename = [dirname, filesep, fname,'.h'];

% extract polyhedra with control law
tempnum = size(obj.feedback,2);
clear Pn;
Pn = [];
nr = 0;
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

% count number of constraints
nctotal = 0;
for ii=1:nr,
    nctotal = nctotal + size(Pn(ii).H,1);
end


% extract dimensions
nx = obj.nx;
nu = obj.nu;
ny = nx;
nref = 0;
nxt = nx;

% extract control law
Fi = cell(nr,1);
Gi = Fi;
for i=1:nr
    Fi{i}=Pn(i).getFunction('primal').F(1:nu,:);
    Gi{i}=Pn(i).getFunction('primal').g(1:nu);
end

% TO DO: TRACKING AND DELTA U FORMULATION 
deltau = 0;
tracking = 0;
if tracking==1,
    nxt = obj.model.nx;
    if isfield(obj.model.y,'reference'),
        nref = obj.model.ny;
    else
        nref = obj.model.nx;
    end
elseif deltau,
    nxt = nx - nu;
end


% Ts = obj.model.Ts;
% if isempty(Ts)
%     Ts = 1;
% end

%% write the header file in the given directory

fid = fopen(fullfilename, 'w');
if fid<0,
    error('Cannot open file for writing!');
end
fprintf(fid, '#define mpt_getInput_h\n\n');
fprintf(fid, '#define MPT_NR %d\n', nr);
fprintf(fid, '#define MPT_NX %d\n', nx);
fprintf(fid, '#define MPT_NU %d\n', nu);
fprintf(fid, '#define MPT_NY %d\n', ny);
fprintf(fid, '#define MPT_NXT %d\n', nxt);
fprintf(fid, '#define MPT_NREF %d\n', nref);
fprintf(fid, '#define MPT_TS %f\n', Ts);
fprintf(fid, '#define MPT_DUMODE %d\n', deltau);
fprintf(fid, '#define MPT_TRACKING %d\n', tracking);
%fprintf(fid, '#define MPT_ABSTOL %e\n', MPTOPTIONS.abs_tol);
fprintf(fid, '#define MPT_ABSTOL %e\n', 1e-6);

ctr = 0;
fprintf(fid, '\nstatic float MPT_H[] = {\n');
for ii = 1:nr,
    Hi = Hn{ii};
    nc = size(Hi, 1);
    for jj = 1:nc,
        h = Hi(jj, :);
        for kk = 1:length(h),
            ctr = ctr + 1;
            if ctr<nctotal*nx,
                fprintf(fid, '%e,\t', h(kk));
            else
                fprintf(fid, '%e ', h(kk));
            end
            if mod(ctr, 5)==0,
                fprintf(fid, '\n');
            end
        end
    end
end
fprintf(fid, '};\n\n');

ctr = 0;
fprintf(fid, 'static float MPT_K[] = {\n');
for ii = 1:nr,
    Ki = Kn{ii};
    nc = size(Ki, 1);
    for jj = 1:nc,
        ctr = ctr + 1;
        if ctr<nctotal,
            fprintf(fid, '%e,\t', Ki(jj));
        else
            fprintf(fid, '%e ', Ki(jj));
        end
        if mod(ctr, 5)==0,
            fprintf(fid, '\n');
        end
    end
end
fprintf(fid, '};\n\n');

fprintf(fid, 'static int MPT_NC[] = {\n');
for ii = 1:nr,
    if ii < nr,
        fprintf(fid, '%d,\t', size(Pn(ii).H,1));
    else
        fprintf(fid, '%d ', size(Pn(ii).H,1));
    end
    if mod(ii, 5)==0,
        fprintf(fid, '\n');
    end
end
fprintf(fid, '};\n\n');

nctotal = nx*nu*nr;
ctr = 0;
fprintf(fid, 'static float MPT_F[] = {\n');
for ii = 1:nr,
    F = Fi{ii};
    for jj = 1:nu,
        f = F(jj, :);
        for kk = 1:nx,
            ctr = ctr + 1;
            if ctr<nctotal,
                fprintf(fid, '%e,\t', f(kk));
            else
                fprintf(fid, '%e ', f(kk));
            end
            if mod(ctr, 5)==0,
                fprintf(fid, '\n');
            end
        end
    end
end
fprintf(fid, '};\n\n');

ctr = 0;
fprintf(fid, 'static float MPT_G[] = {\n');
for ii = 1:nr,
    G = Gi{ii};
    for jj = 1:nu,
        ctr = ctr + 1;
        if ctr<nctotal,
            fprintf(fid, '%e,\t', G(jj));
        else
            fprintf(fid, '%e ', G(jj));
        end
        if mod(ctr, 5)==0,
            fprintf(fid, '\n');
        end
    end
end
fprintf(fid, '};\n');

fclose(fid);




%% write mpt_getInput.c

f2 = fopen([dirname, filesep, 'mpt_getInput.c'], 'w');
if f2<0,
    error('Cannot open file for writing!');
end

header = {''
'/*  mpt_getInput.c,'
''
'  Identifies a control law associated to a given state X'
''  
'  Requires the explicit controller to be described in a header file called'
'  mpt_getInput.h (see ''help mpt_exportc'' for more details).'
''
'  Usage:'
'    region = mpt_getInput(*X, *U)'
''    
'    if ''region'' is smaller 1 (region < 1), there is no control law associated to'
'    a given state.'
''
'   Please note that all code in this file is provided under the terms of the'
'   GNU General Public License, which implies that if you include it directly'
'   into your commercial application, you will need to comply with the license.'
'   If you feel this is not a good solution for you or your company, feel free '
'   to contact the author:'
'       michal.kvasnica@stuba.sk'
'    to re-license this specific piece of code to you free of charge.'
'*/'
''
'/* Copyright (C) 2005 by Michal Kvasnica (michal.kvasnica@stuba.sk) '
'   Revised in 2012 by Martin Herceg (herceg@control.ee.ethz.ch)    '
'*/'
''
''
'/*  This program is free software; you can redistribute it and/or modify'
'    it under the terms of the GNU General Public License as published by'
'    the Free Software Foundation; either version 2 of the License, or'
'    (at your option) any later version.'
''
'    This program is distributed in the hope that it will be useful,'
'    but WITHOUT ANY WARRANTY; without even the implied warranty of'
'    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the'
'    GNU General Public License for more details.'
''
'    You should have received a copy of the GNU General Public License'
'    along with this program; if not, write to the Free Software'
'    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.'
'*/ '
''};

% write the header
for i=1:numel(header)
    fprintf(f2,[header{i},'\n']);
end

% insert the name of the file
fprintf(f2,'#ifndef mpt_getInput_h \n');
fprintf(f2,'#include "%s.h" \n',fname);
fprintf(f2,'#endif\n');

core = {''
'static float mpt_getInput(float *X, float *U)'
'{'
'    int ix, iu, ic, nc, isinside;'
'    unsigned long ireg, abspos;'
'    float hx, region;'
''    
'    abspos = 0;'
'    region = 0;'
''    
'    /* initialize U to zero*/'
'    for (iu=0; iu<MPT_NU; iu++) {'
'        U[iu] = 0;'
'    }'
''    
'    for (ireg=0; ireg<MPT_NR; ireg++) {'
''        
'        isinside = 1;'
'        nc = MPT_NC[ireg];'
'        for (ic=0; ic<nc; ic++) {'
'            hx = 0;'
'            for (ix=0; ix<MPT_NX; ix++) {'
'                hx = hx + MPT_H[abspos*MPT_NX+ic*MPT_NX+ix]*X[ix];'
'            }'
'            if ((hx - MPT_K[abspos+ic]) > MPT_ABSTOL) {'
'                /* constraint is violated, continue with next region */'
'                isinside = 0;'
'                break;'
'            } '
'        }'
'        if (isinside==1) {'
'            /* state belongs to this region, extract control law and exit */'
'            region = ireg + 1;'
'            for (iu=0; iu<MPT_NU; iu++) {'
'                for (ix=0; ix<MPT_NX; ix++) {'
'                    U[iu] = U[iu] + MPT_F[ireg*MPT_NX*MPT_NU + iu*MPT_NX + ix]*X[ix];'
'                }'
'                U[iu] = U[iu] + MPT_G[ireg*MPT_NU + iu];'
'            }'
'            return region;'
'        }'
'        abspos = abspos + MPT_NC[ireg];'
'    }'
'    return region;'
'}'
''
'static void mpt_augmentState(float *Xaug, float *X, float *Uprev, float *reference)'
'{'
'    /* augments states vector for tracking / deltaU formulation */'
'    int i;'
'    if (MPT_TRACKING==1) {'
'        /* Xaug = [X; U(k-1); reference] */'
'        for (i=0; i<MPT_NXT; i++)'
'            Xaug[i] = X[i];'
'        for (i=0; i<MPT_NU; i++)'
'            Xaug[MPT_NXT + i] = Uprev[i];'
'        for (i=0; i<MPT_NREF; i++)'
'            Xaug[MPT_NXT + MPT_NU + i] = reference[i];'
'    } else if (MPT_TRACKING==2) {'
'        /* X = [X; reference] */'
'        for (i=0; i<MPT_NXT; i++)'
'            Xaug[i] = X[i];'
'        for (i=0; i<MPT_NREF; i++)'
'            Xaug[MPT_NXT + i] = reference[i];'
'    } else if (MPT_DUMODE==1) {'
'        /* X = [Xin; U(k-1)] */'
'        for (i=0; i<MPT_NXT; i++)'
'            Xaug[i] = X[i];'
'        for (i=0; i<MPT_NU; i++)'
'            Xaug[MPT_NXT + i] = Uprev[i];'
'    } else {'
'        /* no augmentation necessary, just copy states */'
'        for (i=0; i<MPT_NX; i++) {'
'            Xaug[i] = X[i];'
'        }'
'    }'
'}'
''
''
'static void mpt_augmentInput(float *U, const float *Uprev)'
'{'
'    int i;'
'    if ((MPT_TRACKING==1) || (MPT_DUMODE>0))'
'    {'
'        /* controllers with MPT_TRACKING=1 or MPT_DUMODE=1 generate'
'         * deltaU instead of U, therefore to obtain the "true" control action,'
'         * we need to add previous input at this point'
'         */'
'        for (i=0; i<MPT_NU; i++)'
'        {'
'            U[i] = U[i] + Uprev[i];'
'        }'
'    } '
'}'
''};

% write the core
for i=1:numel(core)
    fprintf(f2,[core{i},'\n']);
end

fclose(f2);

%% copy remaining files

p = fileparts(which('EMPCController'));
copyfile([p,filesep,'mpt_getInput_sfunc.c'],dirname);

