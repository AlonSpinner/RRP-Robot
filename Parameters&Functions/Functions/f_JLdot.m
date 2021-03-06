function out1 = f_JLdot(in1,in2)
%F_JLDOT
%    OUT1 = F_JLDOT(IN1,IN2)

%    This function was generated by the Symbolic Math Toolbox version 8.6.
%    09-Feb-2021 18:41:21

d3 = in1(3,:);
d3dot = in2(3,:);
t1 = in1(1,:);
t2 = in1(2,:);
t1dot = in2(1,:);
t2dot = in2(2,:);
t4 = cos(t1);
t5 = cos(t2);
t6 = sin(t1);
t7 = sin(t2);
out1 = reshape([-t1dot.*(t4./1.0e+1+d3.*t6.*t7)+d3dot.*t4.*t7+d3.*t4.*t5.*t2dot,-t1dot.*(t6./1.0e+1-d3.*t4.*t7)+d3dot.*t6.*t7+d3.*t5.*t6.*t2dot,0.0,d3dot.*t5.*t6+d3.*t4.*t5.*t1dot-d3.*t6.*t7.*t2dot,-d3dot.*t4.*t5+d3.*t5.*t6.*t1dot+d3.*t4.*t7.*t2dot,-d3dot.*t7-d3.*t5.*t2dot,t4.*t7.*t1dot+t5.*t6.*t2dot,-t4.*t5.*t2dot+t6.*t7.*t1dot,-t7.*t2dot],[3,3]);
