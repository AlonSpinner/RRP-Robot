project=simulinkproject();
projectRoot=project.RootFolder;

%% Set Cache Folder
Simulink.fileGenControl('set',...
    'CacheFolder',fullfile(projectRoot,'Cash'),...
    'createDir',true);

%% Enable library in browser
% set_param('RRProbotLibrary','EnableLBRepository','on');
slblocks();
%% clear variables used
clear project projectRoot