function x=forward_kin(q)
%---input
%q - 3xN [t1,t2,d3]' 

%---output
%x - [xx,xy,xz]' (3xN matrix) location of tip

load('Parameters.mat');
x=zeros(3,size(q,2));
for i=1:size(q,2)
    Ai=prm.f_A3t0(q(:,i)); %returns transformation matrix
    x(:,i)=Ai(1:3,4);
end
end