function [JL,JA,J]=jacobian_mat(q)
%---input
%q - 3xN [t1,t2,d3]' 

%---output
%Jacobians in world system
%J - full Jacobian Matrix
%JL -(3x3 matrix) v=JL*qdot
%JA -(3x3 matrix) omega=JA*qdot

load('Parameters.mat');
[JL,JA]=deal(zeros(3,3,size(q,2)));
for i=1:size(q,2)
    JL(:,:,i)=prm.f_JL(q(:,i));
    JA(:,:,i)=prm.f_JA(q(:,i));
end
J=[JL;JA];
end