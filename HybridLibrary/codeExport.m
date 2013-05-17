function codeExport(obj,Ts,type,fname,dirname)
% Generate explicit controller in c or in Matlab Embedded function
% codeExport(obj,Ts,fname,dirname,type)
% obj : explicit controller provided by mpt3 toolbox
% Ts : sampling time of the controller
% type : sting can be either 'matlab' or 'c'
% fname: name of the c code generator
% dirname : directory in which the c code will be stored
%
% Created by Darivianakis Georgios (gdarivia@student.ethz.ch)

if strcmp(type,'c')
    exportToC_MLD(obj,Ts,fname,dirname);
elseif strcmp(type,'matlab')
    [Hn,Kn,Fi,Gi,Nc] = GetMPCMatrices(obj);
else
    error('type can be only matlab or c');
end