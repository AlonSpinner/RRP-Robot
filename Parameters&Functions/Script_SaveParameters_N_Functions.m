%% Instructions
%There is no garuntee that variale names will be kept save between segments
%Use the struct prm.variable to 'pass' values between sections

clear('prm'); %clear varaible if exists in workspace as not to add to it
proj=simulinkproject;
FunctionFolder=fullfile(proj.RootFolder,'Parameters&Functions','Functions');
delete(fullfile(FunctionFolder,'*.m')); %delete previous functions
%% Parameters
prm.H=0.2;
prm.L=0.1;
prm.L1=0.1;
% Mass, inertia and gravity parameters
prm.rho=7800; %kg/m^3
prm.D=0.015; %m
prm.M1=0.5; %kg
prm.M2=0.6; %kg %for section 6
prm.g=9.81; %kg/m^2
% Trajectory Position
X=[0.1,0.25];
Y=[0.05,-0.15];
Z=[0.25,0.35];

prm.X=X;
prm.Y=Y;
prm.Z=Z;

prm.dX=X(2)-X(1);
prm.dY=Y(2)-Y(1);
prm.dZ=Z(2)-Z(1);
% Time
T=2;

%For Trapezoidal profile - here for legacy code to work
dT=1/6*T;
prm.dT=dT;
prm.T1=dT;
prm.T2=T-dT;

prm.T=2;
prm.dt=1/1000;
%% Direct Kinematics
syms t1 t2 d3 H L L1 real
%----- Direct Kinematics
R1t0 = Rot(0,0,1,t1);
t1t0 = [0,0,H]';
A1t0 = BuildA(R1t0,t1t0);

R2t1 = Rot(1,0,0,t2);
t2t1 = [L,0,0]';
A2t1 = BuildA(R2t1,t2t1);

R3t2 = Rot(0,0,0,0);
t3t2 = [0,0,d3]';
A3t2 = BuildA(R3t2,t3t2);

A2t0=A1t0*A2t1;
A3t0=A2t0*A3t2;

prm.f_A1t0=matlabFunction(subs(A1t0,[H,L],[prm.H,prm.L]),'vars',{[t1,t2,d3]'});
prm.f_A2t0=matlabFunction(subs(A2t0,[H,L],[prm.H,prm.L]),'vars',{[t1,t2,d3]'});
prm.f_A3t0=matlabFunction(subs(A3t0,[H,L],[prm.H,prm.L]),'vars',{[t1,t2,d3]'},...
    'File',fullfile(FunctionFolder,'f_A3t0'));
%% End Point Jacobians
q=[t1,t2,d3];
syms t1dot t2dot d3dot real

%Linear
Translation=A3t0(1:3,4);
JL=jacobian(Translation,q);
JLdot=diff(JL,t1)*t1dot+diff(JL,t2)*t2dot+diff(JL,d3)*d3dot;

prm.f_JL=matlabFunction(subs(JL,[H,L],[prm.H,prm.L]),'vars',{[t1,t2,d3]'},...
      'File',fullfile(FunctionFolder,'f_JL'));
prm.f_JLdot=matlabFunction(subs(JLdot,[H,L],[prm.H,prm.L]),...
    'vars',{[t1,t2,d3]',[t1dot,t2dot,d3dot]'},...
      'File',fullfile(FunctionFolder,'f_JLdot'));

%Rotational Jacobian
R2t0=R1t0*R2t1;
JA=sym(zeros(3,3));
JA(:,1)=[0,0,1]';
JA(:,2)=R1t0*[1,0,0]';
JA(:,3)=[0,0,0]';
JAdot=diff(JA,t1)*t1dot+diff(JA,t2)*t2dot+diff(JA,d3)*d3dot;

prm.f_JA=matlabFunction(subs(JA,[H,L],[prm.H,prm.L]),'vars',{[t1,t2,d3]'},...
          'File',fullfile(FunctionFolder,'f_JA'));
prm.f_JAdot=matlabFunction(subs(JAdot,[H,L],[prm.H,prm.L]),...
    'vars',{[t1,t2,d3]',[t1dot,t2dot,d3dot]'});

%Tool Jaobians
R3t0=R1t0*R2t1*R3t2;
R0t3=R3t0';
JLt=R0t3*JL;
JAt=R0t3*JA;

prm.f_JLt=matlabFunction(subs(JLt,[H,L],[prm.H,prm.L]),'vars',{[t1,t2,d3]'});
prm.f_JAt=matlabFunction(subs(JAt,[H,L],[prm.H,prm.L]),'vars',{[t1,t2,d3]'});
%% Computing CG world frame Jacobians
JL_CG1=subs(JL,[t1,t2,d3,L,H],[t1,0,0,0,H/2]);
JL_CG1(:,2:3)=0;
JA_CG1=subs(JA,[t1,t2,d3,L,H],[t1,0,0,0,H/2]);
JA_CG1(:,2:3)=0;
J_CG1=simplify([JL_CG1;JA_CG1]);

JL_CG2=subs(JL,[t1,t2,d3,L,H],[t1,t2,0,L/2,H]);
JL_CG2(:,3)=0;
JA_CG2=subs(JA,[t1,t2,d3,L,H],[t1,t2,0,L/2,H]);
JA_CG2(:,3)=0;
J_CG2=simplify([JL_CG2;JA_CG2]);

JL_CG3=subs(JL,[t1,t2,d3,L,H],[t1,t2,d3-L1/2,L,H]);
JA_CG3=subs(JA,[t1,t2,d3,L,H],[t1,t2,d3-L1/2,L,H]);
J_CG3=simplify([JL_CG3;JA_CG3]);

JL_CG4=subs(JL,[t1,t2,d3,L,H],[t1,t2,d3,L,H]);
JA_CG4=subs(JA,[t1,t2,d3,L,H],[t1,t2,d3,L,H]);
J_CG4=simplify([JL_CG4;JA_CG4]);
%% Computing CG body frame Jacobians
JLt_CG1=subs(JLt,[t1,t2,d3,L,H],[t1,0,0,0,H/2]);
JLt_CG1(:,2:3)=0;
JAt_CG1=subs(JAt,[t1,t2,d3,L,H],[t1,0,0,0,H/2]);
JAt_CG1(:,2:3)=0;
Jt_CG1=simplify([JLt_CG1;JAt_CG1]);

JLt_CG2=subs(JLt,[t1,t2,d3,L,H],[t1,t2,0,L/2,H]);
JLt_CG2(:,3)=0;
JAt_CG2=subs(JAt,[t1,t2,d3,L,H],[t1,t2,0,L/2,H]);
JAt_CG2(:,3)=0;
Jt_CG2=simplify([JLt_CG2;JAt_CG2]);

JLt_CG3=subs(JLt,[t1,t2,d3,L,H],[t1,t2,d3-L1/2,L,H]);
JAt_CG3=subs(JAt,[t1,t2,d3,L,H],[t1,t2,d3-L1/2,L,H]);
Jt_CG3=simplify([JLt_CG3;JAt_CG3]);

JLt_CG4=subs(JLt,[t1,t2,d3,L,H],[t1,t2,d3,L,H]);
JAt_CG4=subs(JAt,[t1,t2,d3,L,H],[t1,t2,d3,L,H]);
Jt_CG4=simplify([JLt_CG4;JAt_CG4]);
%% Computing Link's Masses
syms rho D L1 M real
m1exp=pi*(D^2)/4*H*rho;
m2exp=pi*(D^2)/4*L*rho;
m3exp=pi*(D^2)/4*L1*rho;
m4exp=M;
%% Computing Link's Inertias
I1exp=diag([1,1,0])*m1exp*(H^2)/12;
I2exp=diag([0,1,1])*m2exp*(L^2)/12;
I3exp=diag([1,1,0])*m3exp*(L1^2)/12;
I4exp=diag([0,0,0]);
%% Computning Hdyn (different from H which is a height parameter!!)
JLt_CGi={JLt_CG1,JLt_CG2,JLt_CG3,JLt_CG4};
JAt_CGi={JAt_CG1,JAt_CG2,JAt_CG3,JAt_CG4};

%symbolic
syms m1 m2 m3 m4 real
mi={m1,m2,m3,m4};
I1=diag([1,1,0])*m1*(H^2)/12;
I2=diag([0,1,1])*m2*(L^2)/12;
I3=diag([1,1,0])*m3*(L1^2)/12;
I4=diag([0,0,0]);
Ii={I1,I2,I3,I4};

Hi=cell(4,1);
Hdyn=sym(zeros(3,3));
for i=1:4
    Hi{i}=mi{i}*JLt_CGi{i}'*JLt_CGi{i}+JAt_CGi{i}'*Ii{i}*JAt_CGi{i};
    Hdyn=Hdyn+Hi{i};
end

Hdyn=simplify(Hdyn,'steps',1000);
Hdyn_exp=subs(Hdyn,[m1,m2,m3,m4],...
    [m1exp,m2exp,m3exp,m4exp]);
Hdyn_exp_qM=subs(Hdyn_exp,[H,L,L1,rho,D],...
    [prm.H,prm.L,prm.L1,prm.rho,prm.D]);
prm.f_Hdyn=matlabFunction(Hdyn_exp_qM,'vars',{q',M},...
    'File',fullfile(FunctionFolder,'f_Hdyn'));
prm.f_YH=matlabFunction(diff(Hdyn_exp_qM,M),'vars',{q'},... %for adaptive control
    'File',fullfile(FunctionFolder,'f_YH'));
%% Computing Cdyn
qdot=[t1dot,t2dot,d3dot];

Cdyn=sym(zeros(3,3));
for i=1:3
    for j=1:3
        for k=1:3
            Cdyn(i,j)=0.5*(diff(Hdyn(i,j),q(k))+...
                diff(Hdyn(i,k),q(j))+...
                -diff(Hdyn(k,j),q(i)))*qdot(k)+...
                Cdyn(i,j);
        end
    end
end

Cdyn=simplify(Cdyn,'steps',1000);
Cdyn_exp=subs(Cdyn,[m1,m2,m3,m4],...
    [m1exp,m2exp,m3exp,m4exp]);
Cdyn_exp_qM=subs(Cdyn_exp,[H,L,L1,rho,D],...
    [prm.H,prm.L,prm.L1,prm.rho,prm.D]);
prm.f_Cdyn=matlabFunction(Cdyn_exp_qM,'vars',{q',qdot',M},...
    'File',fullfile(FunctionFolder,'f_Cdyn'));
prm.f_YC=matlabFunction(diff(Cdyn_exp_qM,M),'vars',{q',qdot'},... %for adaptive control
    'File',fullfile(FunctionFolder,'f_YC'));
%% Computing Gdyn - computing in world coordinates
syms g real
gvec=[0;0;-1]*g;
JL_CGi={JL_CG1,JL_CG2,JL_CG3,JL_CG4};
Gdyn=sym(zeros(3,1));
for i=1:4
    Gi=-mi{i}*JL_CGi{i}'*gvec;
    Gdyn=Gdyn+Gi;
end
% Gdyn=simplify(Gdyn,'steps',100);
Gdyn_exp=subs(Gdyn,[m1,m2,m3,m4],...
    [m1exp,m2exp,m3exp,m4exp]);
Gdyn_exp_qM=subs(Gdyn_exp,[H,L,L1,rho,D,g],...
    [prm.H,prm.L,prm.L1,prm.rho,prm.D,prm.g]);
prm.f_Gdyn=matlabFunction(Gdyn_exp_qM,'vars',{q',M},...
    'File',fullfile(FunctionFolder,'f_Gdyn'));
prm.f_YG=matlabFunction(diff(Gdyn_exp_qM,M),'vars',{q'},... %for adaptive control
    'File',fullfile(FunctionFolder,'f_YG'));
%% Test
disp('Hdyn symmetric?');
disp('Hdyn-Hdyn_transpose=');
disp(Hdyn-Hdyn');

disp('Hdyndot-2*C is a skew symmetric matrix?');
disp('A=Hdyndot-2*C');
disp('A_traponse+A=')

Hdyndot=diff(Hdyn,t1)*t1dot+diff(Hdyn,t2)*t2dot+diff(Hdyn,d3)*d3dot;
A=Hdyndot-2*Cdyn;
disp(simplify(A'+A,'steps',100));
%% Links Perpareness for Newton-Euler method (Question 3)
%Vectors of rotation in Link system
u=zeros(3,4);
u(:,1)=[0,0,1]'; %L1
u(:,2)=[1,0,0]'; %L2
u(:,3)=[0,0,1]'; %L3
u(:,4)=[0,0,0]'; %L4
prm.u=u;

%vector to c.m from start of link i, in link i system
r_c=zeros(3,4);
r_c(:,1)=[0,0,1]'*prm.H/2;
r_c(:,2)=[1,0,0]'*prm.L/2;
r_c(:,3)=[0,0,1]'*0; %should be d3-L1/2 - updated in loop itself
r_c(:,4)=[0,0,0]';
prm.r_c=r_c;

r_e=zeros(3,4);
r_e(:,1)=[0,0,1]'*prm.H;
r_e(:,2)=[1,0,0]'*prm.L;
r_e(:,3)=[0,0,1]'*0; %should be d3  - updated in loop itself
r_c(:,4)=[0,0,0]';
prm.r_e=r_e;

prm.jointType={'R','R','P','R'};

f_R1t0=matlabFunction(R1t0,'vars',{[t1,t2,d3]'});
f_R2t1=matlabFunction(R2t1,'vars',{[t1,t2,d3]'});
f_R3t2=matlabFunction(R3t2+0*diag([t1,t2,d3]),'vars',{[t1,t2,d3]'}); %stupid trick to make it work as R3t2 is eye(3)
f_R4t3=@(in) eye(3);
prm.f_Ritim1={f_R1t0,f_R2t1,f_R3t2,f_R4t3};

f_R1t0=matlabFunction(R1t0,'vars',{[t1,t2,d3]'});
f_R2t0=matlabFunction(R2t0,'vars',{[t1,t2,d3]'});
f_R3t0=matlabFunction(R3t0,'vars',{[t1,t2,d3]'});
f_R4t0=f_R3t0;
prm.f_Rit0={f_R1t0,f_R2t0,f_R3t0,f_R4t0};

prm.m=cell(1,4);
prm.m{1}=double(subs(m1exp,[D,H,L,L1,rho,M],[prm.D,prm.H,prm.L,prm.L1,prm.rho,prm.M1]));
prm.m{2}=double(subs(m2exp,[D,H,L,L1,rho,M],[prm.D,prm.H,prm.L,prm.L1,prm.rho,prm.M1]));
prm.m{3}=double(subs(m3exp,[D,H,L,L1,rho,M],[prm.D,prm.H,prm.L,prm.L1,prm.rho,prm.M1]));
prm.m{4}=double(subs(m4exp,[D,H,L,L1,rho,M],[prm.D,prm.H,prm.L,prm.L1,prm.rho,prm.M1]));

prm.I=cell(1,4);
prm.I{1}=double(subs(I1exp,[D,H,L,L1,rho,M],[prm.D,prm.H,prm.L,prm.L1,prm.rho,prm.M1]));
prm.I{2}=double(subs(I2exp,[D,H,L,L1,rho,M],[prm.D,prm.H,prm.L,prm.L1,prm.rho,prm.M1]));
prm.I{3}=double(subs(I3exp,[D,H,L,L1,rho,M],[prm.D,prm.H,prm.L,prm.L1,prm.rho,prm.M1]));
prm.I{4}=double(subs(I4exp,[D,H,L,L1,rho,M],[prm.D,prm.H,prm.L,prm.L1,prm.rho,prm.M1]));
%% Create Robot tree
robot = rigidBodyTree;

%Body 1
body1 = rigidBody('body1');
jnt1 = rigidBodyJoint('jnt1','revolute');
tform1 = trvec2tform([0, 0, 0]); 
setFixedTransform(jnt1,tform1);
body1.Joint = jnt1;
addBody(robot,body1,'base');

%Body 2
body2 = rigidBody('body2');
jnt2 = rigidBodyJoint('jnt2','revolute');
tform2 = trvec2tform([0, 0, prm.H]); 
setFixedTransform(jnt2,tform2);
body2.Joint = jnt2;
addBody(robot,body2,'body1');

%Body 3
body3 = rigidBody('body3');
jnt3 = rigidBodyJoint('jnt3','prismatic');
tform3 = trvec2tform([prm.L, 0, 0]); 
setFixedTransform(jnt3,tform3);
body3.Joint = jnt3;
addBody(robot,body3,'body2');

%Body 4
body4 = rigidBody('tool');
jnt4 = rigidBodyJoint('jnt4','fixed');
tform4 = trvec2tform([0, 0, 0]); 
setFixedTransform(jnt4,tform4);
body4.Joint = jnt4;
addBody(robot,body4,'body3');

prm.robot=robot;
%% Save to file
save(fullfile(proj.RootFolder,'Parameters&Functions','Parameters.mat'),'prm');
%% Functions
function [R] = Rot(nx, ny, nz, theta)
%Calcualte rotation matrix from normalized vector [nx,ny,nz] and angle in
%radians theta
N = [0 -nz ny;
    nz 0 -nx;
    -ny nx 0];

R=eye(3)+sin(theta)*N+(1-cos(theta))*N^2; %Rodrigues formula
% R = simplify(expm(N*theta)); %equivalent
end

function A=BuildA(R,t)
%create 4x4 transformation matrix from 3x3 rotation matrix and 3x1
%translation vector
h=[0,0,0,1];
A=[R,t; h];
end