function out1 = f_Gdyn(in1,M)
%F_GDYN
%    OUT1 = F_GDYN(IN1,M)

%    This function was generated by the Symbolic Math Toolbox version 8.6.
%    22-Jan-2021 14:26:08

d3 = in1(3,:);
t2 = in1(2,:);
t3 = cos(t2);
t4 = sin(t2);
out1 = [0.0;M.*d3.*t4.*(-9.81e+2./1.0e+2)-t4.*pi.*(d3-1.0./2.0e+1).*4.3041375e-1;M.*t3.*(9.81e+2./1.0e+2)+t3.*pi.*4.3041375e-1];
