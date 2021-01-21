function q=inverse_kin(x,elbows)
%Input:
%x - 3XN matrix of [x,y,z]' tool position in world units
%elbows - [t2_elbow,d3_eblow]: accepts -1 or 1 values

%Output:
%q - 3XN matrix of [t1,t2,d3]' joint locations in [radians/m]

load('Parameters.mat');
H=prm.H;
L=prm.L;

t2_elbow=elbows(1);
d3_elbow=elbows(2);
q=zeros(3,size(x,2));
for i=1:size(x,2)
    %Parse
    Px=x(1,i);
    Py=x(2,i);
    Pz=x(3,i);
    %Compute d3
    d3=d3_elbow*sqrt(Px^2+Py^2+(Pz-H)^2-L^2);
    %compute theta2
    c2=(Pz-H)/(d3+eps); %<------------Added eps
    s2=t2_elbow*sqrt(1-c2^2);
    t2=atan2(s2,c2);
    %compute theta1
    a=d3*s2;
    b=L;
    c=-Py;
    d=Px;
    t1=atan2(a*d-b*c,a*c+b*d);
    %create joint vector
    q(:,i)=[t1,t2,d3]';
end
end