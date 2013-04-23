% Es wird eifach die aktuell grafik wo als letschts gad offe hesch abgspeichered

% here we select which output file extension we want
bPrintOnFile_Pdf = 1; % [0 (false) 1 (true)]
bPrintOnFile_Eps = 1; % [0 (false) 1 (true)]
% we select the file path
%
% NOTE: do NOT insert extensions!
%strFilePath = '../images/my_figure';
strFilePath = 'traj_square_mpc1';
% we select the printing resolution
iResolution = 300;
% we select to crop or not the figure
bCropTheFigure = 1; % [0 (false) 1 (true)]
% ATTENTION: if PaperPositionMode is not 'auto' the saved file
% could have different dimensions from the one shown on the screen!
set(gcf, 'PaperPositionMode', 'auto');
% saving on file: requires some checks
if( bPrintOnFile_Pdf || bPrintOnFile_Eps )
    %
    % NOTE: if you want a .pdf with encapsulated fonts you need to save an
    % .eps and then convert it => it is always necessary to produce the .eps
    %
    % if we want to crop the figure we do it
    if( bCropTheFigure )
        print('-depsc2', sprintf('-r%d', iResolution), strcat(strFilePath, '.eps'));
    else
        print('-depsc2', '-loose', sprintf('-r%d', iResolution), strcat(strFilePath, '.eps'));
    end;
    % if we want the .pdf we produce it
    if( bPrintOnFile_Pdf )
    %
    % here we convert the .eps encapsulating the fonts
    system( ...
    sprintf(    ...
    'epstopdf --gsopt=-dPDFSETTINGS=/prepress --outfile=%s.pdf %s.eps', ...
    strFilePath,...
    strFilePath));
    %
    end;
    %
    % if we do not want the .eps we remove it
    if( ~bPrintOnFile_Eps )
    delete(sprintf('%s.eps', strFilePath));
    end;
%
end;% saving on file
