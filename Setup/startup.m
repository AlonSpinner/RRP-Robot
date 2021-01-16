project=simulinkproject();
projectRoot=project.RootFolder;

myCacheFolder = fullfile(projectRoot,'Cash');

Simulink.fileGenControl('set',...
    'CacheFolder',myCacheFolder,...
    'createDir',true);

clear project projectRoot myCacheFolder