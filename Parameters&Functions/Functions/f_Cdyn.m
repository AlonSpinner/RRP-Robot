function Cdyn_exp_qM = f_Cdyn(in1,in2,M)
%F_CDYN
%    CDYN_EXP_QM = F_CDYN(IN1,IN2,M)

%    This function was generated by the Symbolic Math Toolbox version 8.6.
%    09-Feb-2021 18:41:44

d3 = in1(3,:);
d3dot = in2(3,:);
t2 = in1(2,:);
t1dot = in2(1,:);
t2dot = in2(2,:);
t3 = cos(t2);
t4 = sin(t2);
t5 = M.*2.0;
t6 = d3.^2;
t7 = t2.*2.0;
t13 = pi.*8.775e-2;
t14 = pi.*4.3875e-2;
t17 = pi.*4.3875e-3;
t8 = d3.*t5;
t9 = t3.^2;
t10 = sin(t7);
t11 = t4.^2;
t15 = d3.*t13;
t16 = M+t14;
t19 = -t17;
t20 = t5+t13;
t12 = t9-1.0;
t18 = (M.*t6.*t10)./2.0;
t21 = d3.*t10.*pi.*2.19375e-3;
t22 = t10.*pi.*7.3125e-5;
t24 = t6.*t10.*pi.*2.19375e-2;
t25 = (t3.*t16)./2.0e+1;
t26 = (t3.*t20)./4.0e+1;
t27 = t8+t15+t19;
t23 = -t21;
t28 = (t27.*t2dot)./2.0;
t29 = t25+t26;
t30 = t18+t22+t23+t24;
Cdyn_exp_qM = reshape([t30.*t2dot+d3dot.*(t11.*pi.*(-2.19375e-3)+M.*d3.*t11+d3.*t11.*t14),t10.*t1dot.*(pi.*4.3875e-4-d3.*pi.*1.31625e-2+M.*t6.*3.0+t6.*pi.*1.31625e-1).*(-1.0./6.0),t11.*t27.*t1dot.*(-1.0./2.0),-d3dot.*t29+t30.*t1dot+(t4.*t27.*t2dot)./2.0e+1,(d3dot.*t27)./2.0,-t28,-t29.*t2dot-t1dot.*(t12.*pi.*(-2.19375e-3)+M.*d3.*t12+d3.*t12.*t14),t28,0.0],[3,3]);
