function out1 = f_YC(in1,in2)
%F_YC
%    OUT1 = F_YC(IN1,IN2)

%    This function was generated by the Symbolic Math Toolbox version 8.6.
%    09-Feb-2021 18:41:44

d3 = in1(3,:);
d3dot = in2(3,:);
t2 = in1(2,:);
t1dot = in2(1,:);
t2dot = in2(2,:);
t3 = cos(t2);
t4 = sin(t2);
t5 = d3.*t2dot;
t6 = d3.^2;
t7 = t2.*2.0;
t8 = sin(t7);
t9 = t4.^2;
t10 = (t6.*t8.*t1dot)./2.0;
out1 = reshape([d3.*d3dot.*t9+(d3.*t5.*t8)./2.0,-t10,-d3.*t9.*t1dot,t10-(d3dot.*t3)./1.0e+1+(t4.*t5)./1.0e+1,d3.*d3dot,-t5,t3.*t2dot.*(-1.0./1.0e+1)-d3.*t1dot.*(t3.^2-1.0),t5,0.0],[3,3]);
