function out1 = f_A3t0(in1)
%F_A3T0
%    OUT1 = F_A3T0(IN1)

%    This function was generated by the Symbolic Math Toolbox version 8.6.
%    09-Feb-2021 18:41:20

d3 = in1(3,:);
t1 = in1(1,:);
t2 = in1(2,:);
t4 = cos(t1);
t5 = cos(t2);
t6 = sin(t1);
t7 = sin(t2);
out1 = reshape([t4,t6,0.0,0.0,-t5.*t6,t4.*t5,t7,0.0,t6.*t7,-t4.*t7,t5,0.0,t4./1.0e+1+d3.*t6.*t7,t6./1.0e+1-d3.*t4.*t7,d3.*t5+1.0./5.0,1.0],[4,4]);
