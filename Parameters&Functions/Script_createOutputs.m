%% Setup
RunName='PID, Mplanned=0.5[kg], Mactual=0[kg], P0actualZ=0.35[cm] - UPDATED';

project=simulinkproject();
projectRoot=project.RootFolder;
OutputFolder=fullfile(projectRoot,'Outputs',RunName);
mkdir(OutputFolder); %create directory to planned figures in
subsystemName='RobotSimulation/Scopes/Submission Scopes';
%% Print Figures
 scopeNames={'q','qdot','x','tau_diff','Percentile_Error'};
for i=1:length(scopeNames)
    blockpath=[subsystemName,'/',scopeNames{i}];
    open_system(blockpath);
    fig=findall(0,'Name',scopeNames{i}); %open scope figure
    
    set(fig,'PaperPositionMode','auto'); %removes edges
    set(fig,'InvertHardCopy','off'); %if not, backgground turns white
    
    AxesInScope = findall(fig,'type','axes'); 
    axis(AxesInScope,'auto'); %auto limits on all axes
    for j=1:length(AxesInScope)
        legend(AxesInScope(j),'Location','best');
    end
    saveas(fig,fullfile(OutputFolder,scopeNames{i}),'svg');
    
    if strcmp(scopeNames{i},'Percentile_Error')
        AxesInScope.YLim=[0,0.2];
        legend(AxesInScope,'Location','best');
        saveas(fig,fullfile(OutputFolder,[scopeNames{i},'_focus']),'svg');
    end
    
    if strcmp(scopeNames{i},'tau_diff')
        for j=1:length(AxesInScope)
            AxesInScope(j).XLim=[0.2,2.5];
            legend(AxesInScope(j),'Location','best');
        end
        saveas(fig,fullfile(OutputFolder,[scopeNames{i},'_focus']),'svg');
    end
    
    delete(fig);
end

%% print M estimation if adaptive controller

ControllerBlock='RobotSimulation/High level Controllers';
Choice=get_param(ControllerBlock,'CompiledActiveChoiceControl');
if strcmp(Choice,'Choice5') %Adaptive control is on
    blockpath='RobotSimulation/High level Controllers/Adaptive Control/Predict M/Mestimation';
    open_system(blockpath);
    fig=findall(0,'Name','Mestimation'); %open scope figure
    
    set(fig,'PaperPositionMode','auto'); %removes edges
    set(fig,'InvertHardCopy','off'); %if not, backgground turns white
    
    AxesInScope = findall(fig,'type','axes');
    axis(AxesInScope,'auto'); %auto limits on all axes
    saveas(fig,fullfile(OutputFolder,'MEst'),'svg');
    
    delete(fig);
end