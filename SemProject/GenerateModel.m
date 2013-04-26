function model = GenerateModel(fname,Theta,Ts)
% Creates the discrete Model of the system for
% different sampling times Ts and desired angles Theta
%
% model = SimulateModel(Theta,Ts)
%
% Created by Darivianakis Georgios (gdarivia@student.ethz.ch)


[Aff,Bff,Cff,Dff,Add,Bdd,Cdd,Ddd] = linearizSimple(Theta,Ts);

% Free Flight set parameters
for i = 1:4
    for j = 1:4
        VarName = sprintf('parameters.Af%d%d',i,j);
        VarValue = sprintf('=Aff(%d,%d);',i,j);
        eval([VarName VarValue ]);
    end
end

for i = 1:4
    for j = 1:2
        VarName = sprintf('parameters.Bf%d%d',i,j);
        VarValue = sprintf('=Bff(%d,%d);',i,j);
        eval([VarName VarValue ]);
    end
end

for i = 1:5
    for j = 1:4
        VarName = sprintf('parameters.Cf%d%d',i,j);
        VarValue = sprintf('=Cff(%d,%d);',i,j);
        eval([VarName VarValue ]);
    end
end

% Docked Set parameters
for i = 1:4
    for j = 1:4
        VarName = sprintf('parameters.Ad%d%d',i,j);
        VarValue = sprintf('=Add(%d,%d);',i,j);
        eval([VarName VarValue ]);
    end
end

for i = 1:4
    for j = 1:2
        VarName = sprintf('parameters.Bd%d%d',i,j);
        VarValue = sprintf('=Bdd(%d,%d);',i,j);
        eval([VarName VarValue ]);
    end
end

for i = 1:5
    for j = 1:4
        VarName = sprintf('parameters.Cd%d%d',i,j);
        VarValue = sprintf('=Cdd(%d,%d);',i,j);
        eval([VarName VarValue ]);
    end
end
% Initial structure with the disturbance as an aux variable to the system,
% zero position and velocity at the switching of the hybrid system
modelMLD = MLDSystem(fname,parameters);
model = modelMLD.toPWA();

return