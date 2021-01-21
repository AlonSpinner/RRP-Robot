function [JLdot,JAdot,Jdot]=jacobian_dot_mat(q,qdot)
%---input
%q - 3xN [t1,t2,d3]' 
%qdot - 3xN [t1,t2,d3]' 

%---output
%Jacobians in world system
%JLdot -(3x3 matrix) diff(JL,t)
%JAdot -(3x3 matrix) diff(JA,t)

load('Parameters.mat');
[JLdot,JAdot]=deal(zeros(3,3,size(q,2)));
for i=1:size(q,2)
    JLdot(:,:,i)=prm.f_JLdot([q(:,i);qdot(:,i)]);
    JAdot(:,:,i)=prm.f_JAdot([q(:,i);qdot(:,i)]);
end
Jdot=[JLdot;JAdot];
end