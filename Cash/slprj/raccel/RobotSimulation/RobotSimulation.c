#include "rt_logging_mmi.h"
#include "RobotSimulation_capi.h"
#include <math.h>
#include "RobotSimulation.h"
#include "RobotSimulation_private.h"
#include "RobotSimulation_dt.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 3 , & stopRequested ) ; }
rtExtModeShutdown ( 3 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 5 ; const char_T
* gbl_raccel_Version = "9.4 (R2020b) 29-Jul-2020" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const int_T gblNumRootInportBlks = 0 ; const int_T
gblNumModelInputs = 0 ; extern const char * gblInportFileName ; extern
rtInportTUtable * gblInportTUtables ; const int_T gblInportDataTypeIdx [ ] =
{ - 1 } ; const int_T gblInportDims [ ] = { - 1 } ; const int_T
gblInportComplex [ ] = { - 1 } ; const int_T gblInportInterpoFlag [ ] = { - 1
} ; const int_T gblInportContinuous [ ] = { - 1 } ; int_T enableFcnCallFlag [
] = { 1 , 1 , 1 , 1 , 1 } ; const char * raccelLoadInputsAndAperiodicHitTimes
( SimStruct * S , const char * inportFileName , int * matFileFormat ) {
return rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; }
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ; static void nuhda0230y ( const real_T A [ 9 ] , const real_T B_p
[ 3 ] , real_T C [ 3 ] ) ; void e5ldib0bf2 ( const real_T pnpy3pytfz [ 3 ] ,
const real_T n1lhttlas2 [ 3 ] , bp1rwuuloc * localB , real_T rtp_M ) { real_T
t10 ; real_T t11 ; real_T t12 ; real_T t27 ; real_T t28 ; real_T t3 ; real_T
t4 ; real_T t5 ; real_T t6 ; t3 = muDoubleScalarCos ( pnpy3pytfz [ 1 ] ) ; t4
= muDoubleScalarSin ( pnpy3pytfz [ 1 ] ) ; t5 = rtp_M * 2.0 ; t6 = pnpy3pytfz
[ 2 ] * pnpy3pytfz [ 2 ] ; t10 = muDoubleScalarSin ( pnpy3pytfz [ 1 ] * 2.0 )
; t11 = t4 * t4 ; t12 = t3 * t3 - 1.0 ; t27 = ( pnpy3pytfz [ 2 ] * t5 +
pnpy3pytfz [ 2 ] * 0.27567475535250435 ) + - 0.013783737767625218 ; t28 = t27
* n1lhttlas2 [ 1 ] / 2.0 ; t3 = ( rtp_M + 0.13783737767625218 ) * t3 / 20.0 +
( t5 + 0.27567475535250435 ) * t3 / 40.0 ; t5 = ( ( rtp_M * t6 * t10 / 2.0 +
t10 * 3.1415926535897931 * 7.3125E-5 ) + - ( pnpy3pytfz [ 2 ] * t10 *
3.1415926535897931 * 0.00219375 ) ) + t6 * t10 * 3.1415926535897931 *
0.0219375 ; localB -> dkehoz2q2i [ 0 ] = ( ( t11 * 3.1415926535897931 * -
0.00219375 + rtp_M * pnpy3pytfz [ 2 ] * t11 ) + pnpy3pytfz [ 2 ] * t11 *
0.13783737767625218 ) * n1lhttlas2 [ 2 ] + t5 * n1lhttlas2 [ 1 ] ; localB ->
dkehoz2q2i [ 1 ] = ( ( ( 0.0013783737767625217 - pnpy3pytfz [ 2 ] *
3.1415926535897931 * 0.0131625 ) + rtp_M * t6 * 3.0 ) + t6 *
3.1415926535897931 * 0.131625 ) * ( t10 * n1lhttlas2 [ 0 ] ) * -
0.16666666666666666 ; localB -> dkehoz2q2i [ 2 ] = t11 * t27 * n1lhttlas2 [ 0
] * - 0.5 ; localB -> dkehoz2q2i [ 3 ] = t4 * t27 * n1lhttlas2 [ 1 ] / 20.0 +
( - n1lhttlas2 [ 2 ] * t3 + t5 * n1lhttlas2 [ 0 ] ) ; localB -> dkehoz2q2i [
4 ] = n1lhttlas2 [ 2 ] * t27 / 2.0 ; localB -> dkehoz2q2i [ 5 ] = - t28 ;
localB -> dkehoz2q2i [ 6 ] = - t3 * n1lhttlas2 [ 1 ] - ( ( t12 *
3.1415926535897931 * - 0.00219375 + rtp_M * pnpy3pytfz [ 2 ] * t12 ) +
pnpy3pytfz [ 2 ] * t12 * 0.13783737767625218 ) * n1lhttlas2 [ 0 ] ; localB ->
dkehoz2q2i [ 7 ] = t28 ; localB -> dkehoz2q2i [ 8 ] = 0.0 ; } void ls5wg34vyw
( const real_T ffgwybumsz [ 3 ] , lfj1s0cxtb * localB , real_T rtp_M ) {
real_T t3 ; real_T t4 ; t3 = muDoubleScalarCos ( ffgwybumsz [ 1 ] ) ; t4 =
muDoubleScalarSin ( ffgwybumsz [ 1 ] ) ; localB -> cxxywhieo5 [ 0 ] = 0.0 ;
localB -> cxxywhieo5 [ 1 ] = rtp_M * ffgwybumsz [ 2 ] * t4 * - 9.81 - t4 *
3.1415926535897931 * ( ffgwybumsz [ 2 ] - 0.05 ) * 0.43041375 ; localB ->
cxxywhieo5 [ 2 ] = rtp_M * t3 * 9.81 + t3 * 3.1415926535897931 * 0.43041375 ;
} void nvdv3lqtgw ( const real_T ncunp54gwx [ 3 ] , krxjaa2z0k * localB ,
real_T rtp_M ) { real_T t17 ; real_T t4 ; real_T t5 ; real_T t7 ; t4 =
muDoubleScalarSin ( ncunp54gwx [ 1 ] ) ; t5 = ncunp54gwx [ 2 ] * ncunp54gwx [
2 ] ; t7 = t4 * t4 ; t4 = - ( ( rtp_M + 0.13783737767625218 ) * t4 / 10.0 ) ;
t17 = - ( ( ( rtp_M * ncunp54gwx [ 2 ] * 2.0 + ncunp54gwx [ 2 ] *
3.1415926535897931 * 0.08775 ) + - 0.013783737767625218 ) * muDoubleScalarCos
( ncunp54gwx [ 1 ] ) / 20.0 ) ; localB -> pvyobdscrq [ 0 ] = ( ( ( ( rtp_M /
100.0 + 0.0018378317023500291 ) + t7 * 3.1415926535897931 * 0.00014625 ) -
ncunp54gwx [ 2 ] * t7 * 3.1415926535897931 * 0.0043875 ) + rtp_M * t5 * t7 )
+ t5 * t7 * 0.13783737767625218 ; localB -> pvyobdscrq [ 1 ] = t17 ; localB
-> pvyobdscrq [ 2 ] = t4 ; localB -> pvyobdscrq [ 3 ] = t17 ; localB ->
pvyobdscrq [ 4 ] = ( ( 0.00045945792558750728 - ncunp54gwx [ 2 ] *
3.1415926535897931 * 0.0043875 ) + rtp_M * t5 ) + t5 * 0.13783737767625218 ;
localB -> pvyobdscrq [ 5 ] = 0.0 ; localB -> pvyobdscrq [ 6 ] = t4 ; localB
-> pvyobdscrq [ 7 ] = 0.0 ; localB -> pvyobdscrq [ 8 ] = rtp_M +
0.13783737767625218 ; } void ot40bdmo1z ( const real_T c1frlqkuky [ 3 ] ,
ljdzojdqbq * localB ) { memset ( & localB -> gth0wwswdl [ 0 ] , 0 , 9U *
sizeof ( real_T ) ) ; localB -> gth0wwswdl [ 0 ] = c1frlqkuky [ 0 ] ; localB
-> gth0wwswdl [ 4 ] = c1frlqkuky [ 1 ] ; localB -> gth0wwswdl [ 8 ] =
c1frlqkuky [ 2 ] ; } static void nuhda0230y ( const real_T A [ 9 ] , const
real_T B_p [ 3 ] , real_T C [ 3 ] ) { real_T b_A [ 9 ] ; real_T maxval ;
real_T y ; int32_T r1 ; int32_T r2 ; int32_T r3 ; int32_T rtemp ; memcpy ( &
b_A [ 0 ] , & A [ 0 ] , 9U * sizeof ( real_T ) ) ; r1 = 0 ; r2 = 1 ; r3 = 2 ;
maxval = muDoubleScalarAbs ( A [ 0 ] ) ; y = muDoubleScalarAbs ( A [ 1 ] ) ;
if ( y > muDoubleScalarAbs ( A [ 0 ] ) ) { maxval = y ; r1 = 1 ; r2 = 0 ; }
if ( muDoubleScalarAbs ( A [ 2 ] ) > maxval ) { r1 = 2 ; r2 = 1 ; r3 = 0 ; }
b_A [ r2 ] = A [ r2 ] / A [ r1 ] ; b_A [ r3 ] /= b_A [ r1 ] ; b_A [ r2 + 3 ]
-= b_A [ r1 + 3 ] * b_A [ r2 ] ; b_A [ r3 + 3 ] -= b_A [ r1 + 3 ] * b_A [ r3
] ; b_A [ r2 + 6 ] -= b_A [ r1 + 6 ] * b_A [ r2 ] ; b_A [ r3 + 6 ] -= b_A [
r1 + 6 ] * b_A [ r3 ] ; if ( muDoubleScalarAbs ( b_A [ r3 + 3 ] ) >
muDoubleScalarAbs ( b_A [ r2 + 3 ] ) ) { rtemp = r2 ; r2 = r3 ; r3 = rtemp ;
} b_A [ r3 + 3 ] /= b_A [ r2 + 3 ] ; b_A [ r3 + 6 ] -= b_A [ r3 + 3 ] * b_A [
r2 + 6 ] ; C [ 1 ] = B_p [ r2 ] - B_p [ r1 ] * b_A [ r2 ] ; C [ 2 ] = ( B_p [
r3 ] - B_p [ r1 ] * b_A [ r3 ] ) - b_A [ r3 + 3 ] * C [ 1 ] ; C [ 2 ] /= b_A
[ r3 + 6 ] ; C [ 0 ] = B_p [ r1 ] - b_A [ r1 + 6 ] * C [ 2 ] ; C [ 1 ] -= b_A
[ r2 + 6 ] * C [ 2 ] ; C [ 1 ] /= b_A [ r2 + 3 ] ; C [ 0 ] -= b_A [ r1 + 3 ]
* C [ 1 ] ; C [ 0 ] /= b_A [ r1 ] ; } void rt_invd3x3_snf ( const real_T u [
9 ] , real_T y [ 9 ] ) { real_T x [ 9 ] ; real_T absx11 ; real_T absx21 ;
real_T absx31 ; int32_T itmp ; int32_T p1 ; int32_T p2 ; int32_T p3 ; memcpy
( & x [ 0 ] , & u [ 0 ] , 9U * sizeof ( real_T ) ) ; p1 = 1 ; p2 = 3 ; p3 = 6
; absx11 = muDoubleScalarAbs ( u [ 0 ] ) ; absx21 = muDoubleScalarAbs ( u [ 1
] ) ; absx31 = muDoubleScalarAbs ( u [ 2 ] ) ; if ( ( absx21 > absx11 ) && (
absx21 > absx31 ) ) { p1 = 4 ; p2 = 0 ; x [ 0 ] = u [ 1 ] ; x [ 1 ] = u [ 0 ]
; x [ 3 ] = u [ 4 ] ; x [ 4 ] = u [ 3 ] ; x [ 6 ] = u [ 7 ] ; x [ 7 ] = u [ 6
] ; } else { if ( absx31 > absx11 ) { p1 = 7 ; p3 = 0 ; x [ 2 ] = x [ 0 ] ; x
[ 0 ] = u [ 2 ] ; x [ 5 ] = x [ 3 ] ; x [ 3 ] = u [ 5 ] ; x [ 8 ] = x [ 6 ] ;
x [ 6 ] = u [ 8 ] ; } } absx11 = x [ 1 ] / x [ 0 ] ; x [ 1 ] /= x [ 0 ] ;
absx21 = x [ 2 ] / x [ 0 ] ; x [ 2 ] /= x [ 0 ] ; x [ 4 ] -= absx11 * x [ 3 ]
; x [ 5 ] -= absx21 * x [ 3 ] ; x [ 7 ] -= absx11 * x [ 6 ] ; x [ 8 ] -=
absx21 * x [ 6 ] ; if ( muDoubleScalarAbs ( x [ 5 ] ) > muDoubleScalarAbs ( x
[ 4 ] ) ) { itmp = p2 ; p2 = p3 ; p3 = itmp ; x [ 1 ] = absx21 ; x [ 2 ] =
absx11 ; absx11 = x [ 4 ] ; x [ 4 ] = x [ 5 ] ; x [ 5 ] = absx11 ; absx11 = x
[ 7 ] ; x [ 7 ] = x [ 8 ] ; x [ 8 ] = absx11 ; } absx11 = x [ 5 ] / x [ 4 ] ;
x [ 5 ] /= x [ 4 ] ; x [ 8 ] -= absx11 * x [ 7 ] ; absx11 = ( x [ 5 ] * x [ 1
] - x [ 2 ] ) / x [ 8 ] ; absx21 = - ( x [ 7 ] * absx11 + x [ 1 ] ) / x [ 4 ]
; y [ p1 - 1 ] = ( ( 1.0 - x [ 3 ] * absx21 ) - x [ 6 ] * absx11 ) / x [ 0 ]
; y [ p1 ] = absx21 ; y [ p1 + 1 ] = absx11 ; absx11 = - x [ 5 ] / x [ 8 ] ;
absx21 = ( 1.0 - x [ 7 ] * absx11 ) / x [ 4 ] ; y [ p2 ] = - ( x [ 3 ] *
absx21 + x [ 6 ] * absx11 ) / x [ 0 ] ; y [ p2 + 1 ] = absx21 ; y [ p2 + 2 ]
= absx11 ; absx11 = 1.0 / x [ 8 ] ; absx21 = - x [ 7 ] * absx11 / x [ 4 ] ; y
[ p3 ] = - ( x [ 3 ] * absx21 + x [ 6 ] * absx11 ) / x [ 0 ] ; y [ p3 + 1 ] =
absx21 ; y [ p3 + 2 ] = absx11 ; } void MdlInitialize ( void ) { real_T c2_p
[ 9 ] ; real_T ls1qbycgkq [ 3 ] ; real_T niz3k4wldu [ 3 ] ; real_T c2 ;
real_T d3 ; real_T ml1cpn0bgu_idx_0 ; real_T ml1cpn0bgu_idx_1 ; real_T
ml1cpn0bgu_idx_2 ; real_T s2 ; real_T t4 ; rtDW . arabdgyja5 [ 0 ] = rtP .
RateTransition1_InitialCondition ; rtX . mrjjr04vhg [ 0 ] = rtP . Int_2q_IC [
0 ] ; rtX . cgz4e3b2hd [ 0 ] = rtP . Int_2qdot_IC [ 0 ] ; rtDW . cn0jcb2rgj [
0 ] = rtP . LPFforqdot_s0 ; rtDW . h4pprbp2zw [ 0 ] = rtP . LPF1forqdot2_s0 ;
rtDW . bjor124ftp [ 0 ] = rtP . LPF2forqdot2_s0 ; rtDW . hbhhzhssgt [ 0 ] =
rtP . DiscreteDerivative_ICPrevScaledInput ; rtDW . arabdgyja5 [ 1 ] = rtP .
RateTransition1_InitialCondition ; rtX . mrjjr04vhg [ 1 ] = rtP . Int_2q_IC [
1 ] ; rtX . cgz4e3b2hd [ 1 ] = rtP . Int_2qdot_IC [ 1 ] ; rtDW . cn0jcb2rgj [
1 ] = rtP . LPFforqdot_s0 ; rtDW . h4pprbp2zw [ 1 ] = rtP . LPF1forqdot2_s0 ;
rtDW . bjor124ftp [ 1 ] = rtP . LPF2forqdot2_s0 ; rtDW . hbhhzhssgt [ 1 ] =
rtP . DiscreteDerivative_ICPrevScaledInput ; rtDW . arabdgyja5 [ 2 ] = rtP .
RateTransition1_InitialCondition ; rtX . mrjjr04vhg [ 2 ] = rtP . Int_2q_IC [
2 ] ; rtX . cgz4e3b2hd [ 2 ] = rtP . Int_2qdot_IC [ 2 ] ; rtDW . cn0jcb2rgj [
2 ] = rtP . LPFforqdot_s0 ; rtDW . h4pprbp2zw [ 2 ] = rtP . LPF1forqdot2_s0 ;
rtDW . bjor124ftp [ 2 ] = rtP . LPF2forqdot2_s0 ; rtDW . hbhhzhssgt [ 2 ] =
rtP . DiscreteDerivative_ICPrevScaledInput ; rtDW . nwjbwtsk0s = rtP .
Memory_InitialCondition ; rtDW . aonnjayrqu = rtP . Memory1_InitialCondition
; if ( rtP . Constant1_Value < rtP . MinJerkTrajectoryPlanner_Tbreaks ) {
ls1qbycgkq [ 0 ] = rtP . P0 [ 0 ] ; niz3k4wldu [ 0 ] = 0.0 ; ls1qbycgkq [ 1 ]
= rtP . P0 [ 1 ] ; niz3k4wldu [ 1 ] = 0.0 ; ls1qbycgkq [ 2 ] = rtP . P0 [ 2 ]
+ 0.1 ; niz3k4wldu [ 2 ] = 0.0 ; } else if ( rtP . Constant1_Value < rtP . T
+ rtP . MinJerkTrajectoryPlanner_Tbreaks ) { d3 = rtP . Constant1_Value - rtP
. MinJerkTrajectoryPlanner_Tbreaks ; t4 = ( muDoubleScalarPower ( d3 / rtP .
T , 3.0 ) * 10.0 - muDoubleScalarPower ( d3 / rtP . T , 4.0 ) * 15.0 ) +
muDoubleScalarPower ( d3 / rtP . T , 5.0 ) * 6.0 ; c2 = rtP . Pf [ 0 ] - rtP
. P0 [ 0 ] ; ls1qbycgkq [ 0 ] = t4 * c2 + rtP . P0 [ 0 ] ; niz3k4wldu [ 0 ] =
c2 ; c2 = rtP . Pf [ 1 ] - rtP . P0 [ 1 ] ; ls1qbycgkq [ 1 ] = t4 * c2 + rtP
. P0 [ 1 ] ; niz3k4wldu [ 1 ] = c2 ; c2 = rtP . Pf [ 2 ] - ( rtP . P0 [ 2 ] +
0.1 ) ; ls1qbycgkq [ 2 ] = t4 * c2 + ( rtP . P0 [ 2 ] + 0.1 ) ; t4 = ( d3 *
d3 * 30.0 / muDoubleScalarPower ( rtP . T , 3.0 ) - 60.0 *
muDoubleScalarPower ( d3 , 3.0 ) / muDoubleScalarPower ( rtP . T , 4.0 ) ) +
30.0 * muDoubleScalarPower ( d3 , 4.0 ) / muDoubleScalarPower ( rtP . T , 5.0
) ; niz3k4wldu [ 0 ] *= t4 ; niz3k4wldu [ 1 ] *= t4 ; niz3k4wldu [ 2 ] = t4 *
c2 ; } else { ls1qbycgkq [ 0 ] = rtP . Pf [ 0 ] ; niz3k4wldu [ 0 ] = 0.0 ;
ls1qbycgkq [ 1 ] = rtP . Pf [ 1 ] ; niz3k4wldu [ 1 ] = 0.0 ; ls1qbycgkq [ 2 ]
= rtP . Pf [ 2 ] ; niz3k4wldu [ 2 ] = 0.0 ; } t4 = ls1qbycgkq [ 2 ] - rtP . H
; d3 = muDoubleScalarSqrt ( ( ( ls1qbycgkq [ 0 ] * ls1qbycgkq [ 0 ] +
ls1qbycgkq [ 1 ] * ls1qbycgkq [ 1 ] ) + t4 * t4 ) - rtP . L * rtP . L ) * rtP
. elbows [ 1 ] ; c2 = ( ls1qbycgkq [ 2 ] - rtP . H ) / ( d3 +
2.2204460492503131E-16 ) ; s2 = muDoubleScalarSqrt ( 1.0 - c2 * c2 ) * rtP .
elbows [ 0 ] ; t4 = d3 * s2 ; ml1cpn0bgu_idx_0 = muDoubleScalarAtan2 ( t4 *
ls1qbycgkq [ 0 ] - rtP . L * - ls1qbycgkq [ 1 ] , t4 * - ls1qbycgkq [ 1 ] +
rtP . L * ls1qbycgkq [ 0 ] ) ; ml1cpn0bgu_idx_1 = muDoubleScalarAtan2 ( s2 ,
c2 ) ; ml1cpn0bgu_idx_2 = d3 ; t4 = muDoubleScalarCos ( ml1cpn0bgu_idx_0 ) ;
d3 = muDoubleScalarCos ( ml1cpn0bgu_idx_1 ) ; c2 = muDoubleScalarSin (
ml1cpn0bgu_idx_0 ) ; s2 = muDoubleScalarSin ( ml1cpn0bgu_idx_1 ) ; c2_p [ 0 ]
= ml1cpn0bgu_idx_2 * t4 * s2 + c2 * - 0.1 ; c2_p [ 1 ] = ml1cpn0bgu_idx_2 *
c2 * s2 + t4 / 10.0 ; c2_p [ 2 ] = 0.0 ; c2_p [ 3 ] = ml1cpn0bgu_idx_2 * d3 *
c2 ; c2_p [ 4 ] = - ml1cpn0bgu_idx_2 * t4 * d3 ; c2_p [ 5 ] = -
ml1cpn0bgu_idx_2 * s2 ; c2_p [ 6 ] = c2 * s2 ; c2_p [ 7 ] = - t4 * s2 ; c2_p
[ 8 ] = d3 ; nuhda0230y ( c2_p , niz3k4wldu , ls1qbycgkq ) ; rtDW .
cn0jcb2rgj [ 0 ] = ml1cpn0bgu_idx_0 ; rtDW . h4pprbp2zw [ 0 ] = ls1qbycgkq [
0 ] ; rtX . mrjjr04vhg [ 0 ] = ml1cpn0bgu_idx_0 ; rtDW . cn0jcb2rgj [ 1 ] =
ml1cpn0bgu_idx_1 ; rtDW . h4pprbp2zw [ 1 ] = ls1qbycgkq [ 1 ] ; rtX .
mrjjr04vhg [ 1 ] = ml1cpn0bgu_idx_1 ; rtDW . cn0jcb2rgj [ 2 ] =
ml1cpn0bgu_idx_2 ; rtDW . h4pprbp2zw [ 2 ] = ls1qbycgkq [ 2 ] ; rtX .
mrjjr04vhg [ 2 ] = ml1cpn0bgu_idx_2 ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
ssSetContTimeOutputInconsistentWithStateAtMajorStep ( rtS ) ; rtX .
cgz4e3b2hd [ 0 ] = ls1qbycgkq [ 0 ] ; rtX . cgz4e3b2hd [ 1 ] = ls1qbycgkq [ 1
] ; rtX . cgz4e3b2hd [ 2 ] = ls1qbycgkq [ 2 ] ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
ssSetContTimeOutputInconsistentWithStateAtMajorStep ( rtS ) ; rtDW .
bjor124ftp [ 0 ] = ls1qbycgkq [ 0 ] ; rtDW . bjor124ftp [ 1 ] = ls1qbycgkq [
1 ] ; rtDW . bjor124ftp [ 2 ] = ls1qbycgkq [ 2 ] ; } void MdlStart ( void ) {
{ bool externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} { { { { sdiSignalSourceInfoU srcInfo ; sdiLabelU loggedName =
sdiGetLabelFromChars ( "q_err" ) ; sdiLabelU origSigName =
sdiGetLabelFromChars ( "q_err" ) ; sdiLabelU propName = sdiGetLabelFromChars
( "" ) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"RobotSimulation/Scopes/Add1" ) ; sdiLabelU blockSID = sdiGetLabelFromChars (
"" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ;
sdiLabelU sigName = sdiGetLabelFromChars ( "q_err" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_DISCRETE ; int_T sigDimsArray [
1 ] = { 3 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . p5vastsvrw . AQHandles =
sdiAsyncRepoCreateAsyncioQueue ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "1a2fdbc9-1086-4112-902b-d10d2c9377d0" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ; if ( rtDW
. p5vastsvrw . AQHandles ) { ssCachePointer ( rtS , & ( rtDW . p5vastsvrw .
AQHandles ) ) ; sdiSetSignalSampleTimeString ( rtDW . p5vastsvrw . AQHandles
, "0.001" , 0.001 , ssGetTFinal ( rtS ) ) ; sdiSetRunStartTime ( rtDW .
p5vastsvrw . AQHandles , ssGetTaskTime ( rtS , 2 ) ) ;
sdiAsyncRepoSetSignalExportSettings ( rtDW . p5vastsvrw . AQHandles , 1 , 0 )
; sdiAsyncRepoSetSignalExportName ( rtDW . p5vastsvrw . AQHandles ,
loggedName , origSigName , propName ) ; } sdiFreeLabel ( sigName ) ;
sdiFreeLabel ( loggedName ) ; sdiFreeLabel ( origSigName ) ; sdiFreeLabel (
propName ) ; sdiFreeLabel ( blockPath ) ; sdiFreeLabel ( blockSID ) ;
sdiFreeLabel ( subPath ) ; } } } } } { { { { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "tau_dot" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "tau_dot" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"RobotSimulation/Scopes/Discrete Derivative" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "tau_dot" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_DISCRETE ; int_T sigDimsArray [
1 ] = { 3 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . f0vm4ehx4o . AQHandles =
sdiAsyncRepoCreateAsyncioQueue ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "f42aafec-609d-46cd-930d-1fc699d57ba9" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ; if ( rtDW
. f0vm4ehx4o . AQHandles ) { ssCachePointer ( rtS , & ( rtDW . f0vm4ehx4o .
AQHandles ) ) ; sdiSetSignalSampleTimeString ( rtDW . f0vm4ehx4o . AQHandles
, "0.001" , 0.001 , ssGetTFinal ( rtS ) ) ; sdiSetRunStartTime ( rtDW .
f0vm4ehx4o . AQHandles , ssGetTaskTime ( rtS , 2 ) ) ;
sdiAsyncRepoSetSignalExportSettings ( rtDW . f0vm4ehx4o . AQHandles , 1 , 0 )
; sdiAsyncRepoSetSignalExportName ( rtDW . f0vm4ehx4o . AQHandles ,
loggedName , origSigName , propName ) ; } sdiFreeLabel ( sigName ) ;
sdiFreeLabel ( loggedName ) ; sdiFreeLabel ( origSigName ) ; sdiFreeLabel (
propName ) ; sdiFreeLabel ( blockPath ) ; sdiFreeLabel ( blockSID ) ;
sdiFreeLabel ( subPath ) ; } } } } } { { { { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "" ) ; sdiLabelU origSigName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU propName = sdiGetLabelFromChars ( ""
) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"RobotSimulation/Scopes/bounds - percentile error/u" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_DISCRETE ; int_T sigDimsArray [
1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . buw2g0pqmj . AQHandles =
sdiAsyncRepoCreateAsyncioQueue ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "deb9304d-1bf6-4ac8-b5e5-d0363575eead" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ; if ( rtDW
. buw2g0pqmj . AQHandles ) { ssCachePointer ( rtS , & ( rtDW . buw2g0pqmj .
AQHandles ) ) ; sdiSetSignalSampleTimeString ( rtDW . buw2g0pqmj . AQHandles
, "0.001" , 0.001 , ssGetTFinal ( rtS ) ) ; sdiSetRunStartTime ( rtDW .
buw2g0pqmj . AQHandles , ssGetTaskTime ( rtS , 2 ) ) ;
sdiAsyncRepoSetSignalExportSettings ( rtDW . buw2g0pqmj . AQHandles , 1 , 0 )
; sdiAsyncRepoSetSignalExportName ( rtDW . buw2g0pqmj . AQHandles ,
loggedName , origSigName , propName ) ; } sdiFreeLabel ( sigName ) ;
sdiFreeLabel ( loggedName ) ; sdiFreeLabel ( origSigName ) ; sdiFreeLabel (
propName ) ; sdiFreeLabel ( blockPath ) ; sdiFreeLabel ( blockSID ) ;
sdiFreeLabel ( subPath ) ; } } } } } rtB . jjv3wr13aa [ 0 ] = rtP .
RateTransition1_InitialCondition ; rtB . jjv3wr13aa [ 1 ] = rtP .
RateTransition1_InitialCondition ; rtB . jjv3wr13aa [ 2 ] = rtP .
RateTransition1_InitialCondition ; MdlInitialize ( ) ; } void MdlOutputs (
int_T tid ) { real_T j24qsfz3xi [ 3 ] ; real_T b [ 9 ] ; real_T tmp [ 9 ] ;
real_T eeml5qblvn [ 3 ] ; real_T ptomshbz5r [ 3 ] ; real_T tmp_e [ 3 ] ;
real_T tmp_p [ 3 ] ; real_T c2 ; real_T ltip0ky15l ; real_T s2 ; real_T t5 ;
real_T tmp_i ; real_T tmp_m ; int32_T i ; if ( ssIsSampleHit ( rtS , 2 , 0 )
) { ltip0ky15l = ssGetTaskTime ( rtS , 2 ) ; if ( ltip0ky15l < rtP .
MinJerkTrajectoryPlanner_Tbreaks_bavenone0d ) { rtB . ndfmx5opo3 [ 0 ] = rtP
. P0 [ 0 ] ; eeml5qblvn [ 0 ] = 0.0 ; ptomshbz5r [ 0 ] = 0.0 ; rtB .
ndfmx5opo3 [ 1 ] = rtP . P0 [ 1 ] ; eeml5qblvn [ 1 ] = 0.0 ; ptomshbz5r [ 1 ]
= 0.0 ; rtB . ndfmx5opo3 [ 2 ] = rtP . P0 [ 2 ] ; eeml5qblvn [ 2 ] = 0.0 ;
ptomshbz5r [ 2 ] = 0.0 ; } else if ( ltip0ky15l < rtP . T + rtP .
MinJerkTrajectoryPlanner_Tbreaks_bavenone0d ) { ltip0ky15l -= rtP .
MinJerkTrajectoryPlanner_Tbreaks_bavenone0d ; t5 = ( muDoubleScalarPower (
ltip0ky15l / rtP . T , 3.0 ) * 10.0 - muDoubleScalarPower ( ltip0ky15l / rtP
. T , 4.0 ) * 15.0 ) + muDoubleScalarPower ( ltip0ky15l / rtP . T , 5.0 ) *
6.0 ; c2 = rtP . Pf [ 0 ] - rtP . P0 [ 0 ] ; rtB . ndfmx5opo3 [ 0 ] = t5 * c2
+ rtP . P0 [ 0 ] ; ptomshbz5r [ 0 ] = c2 ; c2 = rtP . Pf [ 1 ] - rtP . P0 [ 1
] ; rtB . ndfmx5opo3 [ 1 ] = t5 * c2 + rtP . P0 [ 1 ] ; ptomshbz5r [ 1 ] = c2
; c2 = rtP . Pf [ 2 ] - rtP . P0 [ 2 ] ; rtB . ndfmx5opo3 [ 2 ] = t5 * c2 +
rtP . P0 [ 2 ] ; t5 = ( ltip0ky15l * ltip0ky15l * 30.0 / muDoubleScalarPower
( rtP . T , 3.0 ) - 60.0 * muDoubleScalarPower ( ltip0ky15l , 3.0 ) /
muDoubleScalarPower ( rtP . T , 4.0 ) ) + 30.0 * muDoubleScalarPower (
ltip0ky15l , 4.0 ) / muDoubleScalarPower ( rtP . T , 5.0 ) ; ltip0ky15l = (
60.0 * ltip0ky15l / muDoubleScalarPower ( rtP . T , 3.0 ) - ltip0ky15l *
ltip0ky15l * 180.0 / muDoubleScalarPower ( rtP . T , 4.0 ) ) + 120.0 *
muDoubleScalarPower ( ltip0ky15l , 3.0 ) / muDoubleScalarPower ( rtP . T ,
5.0 ) ; eeml5qblvn [ 0 ] = t5 * ptomshbz5r [ 0 ] ; ptomshbz5r [ 0 ] *=
ltip0ky15l ; eeml5qblvn [ 1 ] = t5 * ptomshbz5r [ 1 ] ; ptomshbz5r [ 1 ] *=
ltip0ky15l ; eeml5qblvn [ 2 ] = t5 * c2 ; ptomshbz5r [ 2 ] = ltip0ky15l * c2
; } else { rtB . ndfmx5opo3 [ 0 ] = rtP . Pf [ 0 ] ; eeml5qblvn [ 0 ] = 0.0 ;
ptomshbz5r [ 0 ] = 0.0 ; rtB . ndfmx5opo3 [ 1 ] = rtP . Pf [ 1 ] ; eeml5qblvn
[ 1 ] = 0.0 ; ptomshbz5r [ 1 ] = 0.0 ; rtB . ndfmx5opo3 [ 2 ] = rtP . Pf [ 2
] ; eeml5qblvn [ 2 ] = 0.0 ; ptomshbz5r [ 2 ] = 0.0 ; } t5 = rtB . ndfmx5opo3
[ 2 ] - rtP . H ; ltip0ky15l = muDoubleScalarSqrt ( ( ( rtB . ndfmx5opo3 [ 0
] * rtB . ndfmx5opo3 [ 0 ] + rtB . ndfmx5opo3 [ 1 ] * rtB . ndfmx5opo3 [ 1 ]
) + t5 * t5 ) - rtP . L * rtP . L ) * rtP . elbows [ 1 ] ; c2 = ( rtB .
ndfmx5opo3 [ 2 ] - rtP . H ) / ( ltip0ky15l + 2.2204460492503131E-16 ) ; s2 =
muDoubleScalarSqrt ( 1.0 - c2 * c2 ) * rtP . elbows [ 0 ] ; t5 = ltip0ky15l *
s2 ; rtB . mt4g2ecmso [ 0 ] = muDoubleScalarAtan2 ( t5 * rtB . ndfmx5opo3 [ 0
] - rtP . L * - rtB . ndfmx5opo3 [ 1 ] , t5 * - rtB . ndfmx5opo3 [ 1 ] + rtP
. L * rtB . ndfmx5opo3 [ 0 ] ) ; rtB . mt4g2ecmso [ 1 ] = muDoubleScalarAtan2
( s2 , c2 ) ; rtB . mt4g2ecmso [ 2 ] = ltip0ky15l ; ltip0ky15l =
muDoubleScalarCos ( rtB . mt4g2ecmso [ 0 ] ) ; t5 = muDoubleScalarCos ( rtB .
mt4g2ecmso [ 1 ] ) ; c2 = muDoubleScalarSin ( rtB . mt4g2ecmso [ 0 ] ) ; s2 =
muDoubleScalarSin ( rtB . mt4g2ecmso [ 1 ] ) ; b [ 0 ] = rtB . mt4g2ecmso [ 2
] * ltip0ky15l * s2 + c2 * - 0.1 ; b [ 1 ] = rtB . mt4g2ecmso [ 2 ] * c2 * s2
+ ltip0ky15l / 10.0 ; b [ 2 ] = 0.0 ; b [ 3 ] = rtB . mt4g2ecmso [ 2 ] * t5 *
c2 ; b [ 4 ] = - rtB . mt4g2ecmso [ 2 ] * ltip0ky15l * t5 ; b [ 5 ] = - rtB .
mt4g2ecmso [ 2 ] * s2 ; b [ 6 ] = c2 * s2 ; b [ 7 ] = - ltip0ky15l * s2 ; b [
8 ] = t5 ; nuhda0230y ( b , eeml5qblvn , rtB . di5zg3biou ) ; ltip0ky15l =
muDoubleScalarCos ( rtB . mt4g2ecmso [ 0 ] ) ; t5 = muDoubleScalarCos ( rtB .
mt4g2ecmso [ 1 ] ) ; c2 = muDoubleScalarSin ( rtB . mt4g2ecmso [ 0 ] ) ; s2 =
muDoubleScalarSin ( rtB . mt4g2ecmso [ 1 ] ) ; tmp [ 0 ] = ( ( rtB .
mt4g2ecmso [ 2 ] * c2 * s2 + ltip0ky15l / 10.0 ) * - rtB . di5zg3biou [ 0 ] +
rtB . di5zg3biou [ 2 ] * ltip0ky15l * s2 ) + rtB . mt4g2ecmso [ 2 ] *
ltip0ky15l * t5 * rtB . di5zg3biou [ 1 ] ; tmp [ 1 ] = ( ( c2 / 10.0 - rtB .
mt4g2ecmso [ 2 ] * ltip0ky15l * s2 ) * - rtB . di5zg3biou [ 0 ] + rtB .
di5zg3biou [ 2 ] * c2 * s2 ) + rtB . mt4g2ecmso [ 2 ] * t5 * c2 * rtB .
di5zg3biou [ 1 ] ; tmp [ 2 ] = 0.0 ; tmp [ 3 ] = ( rtB . mt4g2ecmso [ 2 ] *
ltip0ky15l * t5 * rtB . di5zg3biou [ 0 ] + rtB . di5zg3biou [ 2 ] * t5 * c2 )
- rtB . mt4g2ecmso [ 2 ] * c2 * s2 * rtB . di5zg3biou [ 1 ] ; tmp [ 4 ] = (
rtB . mt4g2ecmso [ 2 ] * t5 * c2 * rtB . di5zg3biou [ 0 ] + - rtB .
di5zg3biou [ 2 ] * ltip0ky15l * t5 ) + rtB . mt4g2ecmso [ 2 ] * ltip0ky15l *
s2 * rtB . di5zg3biou [ 1 ] ; tmp [ 5 ] = - rtB . di5zg3biou [ 2 ] * s2 - rtB
. mt4g2ecmso [ 2 ] * t5 * rtB . di5zg3biou [ 1 ] ; tmp [ 6 ] = ltip0ky15l *
s2 * rtB . di5zg3biou [ 0 ] + t5 * c2 * rtB . di5zg3biou [ 1 ] ; tmp [ 7 ] =
- ltip0ky15l * t5 * rtB . di5zg3biou [ 1 ] + c2 * s2 * rtB . di5zg3biou [ 0 ]
; tmp [ 8 ] = - s2 * rtB . di5zg3biou [ 1 ] ; for ( i = 0 ; i < 3 ; i ++ ) {
eeml5qblvn [ i ] = ptomshbz5r [ i ] - ( ( tmp [ i + 3 ] * rtB . di5zg3biou [
1 ] + tmp [ i ] * rtB . di5zg3biou [ 0 ] ) + tmp [ i + 6 ] * rtB . di5zg3biou
[ 2 ] ) ; } nuhda0230y ( b , eeml5qblvn , rtB . enw4u3xr3e ) ; } if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { rtB
. jjv3wr13aa [ 0 ] = rtDW . arabdgyja5 [ 0 ] ; rtB . jjv3wr13aa [ 1 ] = rtDW
. arabdgyja5 [ 1 ] ; rtB . jjv3wr13aa [ 2 ] = rtDW . arabdgyja5 [ 2 ] ; }
rtDW . gbgkc2rm53 = ( ssGetTaskTime ( rtS , 1 ) >= rtP . Step_Time ) ; if (
rtDW . gbgkc2rm53 == 1 ) { rtB . g3hbvfsfhp = rtP . Step_YFinal ; } else {
rtB . g3hbvfsfhp = rtP . Step_Y0 ; } } j24qsfz3xi [ 0 ] = rtX . mrjjr04vhg [
0 ] ; rtB . fxyjxb2a3b [ 0 ] = rtX . cgz4e3b2hd [ 0 ] ; j24qsfz3xi [ 1 ] =
rtX . mrjjr04vhg [ 1 ] ; rtB . fxyjxb2a3b [ 1 ] = rtX . cgz4e3b2hd [ 1 ] ;
j24qsfz3xi [ 2 ] = rtX . mrjjr04vhg [ 2 ] ; rtB . fxyjxb2a3b [ 2 ] = rtX .
cgz4e3b2hd [ 2 ] ; e5ldib0bf2 ( j24qsfz3xi , rtB . fxyjxb2a3b , & rtB .
hnu3zwzkde , rtP . MActual ) ; ls5wg34vyw ( j24qsfz3xi , & rtB . oitjezxpmx ,
rtP . MActual ) ; nvdv3lqtgw ( j24qsfz3xi , & rtB . ej5252hcor , rtP .
MActual ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . mz0ojksblg [ 0 ] =
rtB . jjv3wr13aa [ 0 ] ; rtB . mz0ojksblg [ 1 ] = rtB . jjv3wr13aa [ 1 ] ;
rtB . mz0ojksblg [ 2 ] = rtB . jjv3wr13aa [ 2 ] ; } rt_invd3x3_snf ( rtB .
ej5252hcor . pvyobdscrq , tmp ) ; for ( i = 0 ; i < 3 ; i ++ ) { ptomshbz5r [
i ] = ( rtB . mz0ojksblg [ i ] - rtB . oitjezxpmx . cxxywhieo5 [ i ] ) - ( (
rtB . hnu3zwzkde . dkehoz2q2i [ i + 3 ] * rtB . fxyjxb2a3b [ 1 ] + rtB .
hnu3zwzkde . dkehoz2q2i [ i ] * rtB . fxyjxb2a3b [ 0 ] ) + rtB . hnu3zwzkde .
dkehoz2q2i [ i + 6 ] * rtB . fxyjxb2a3b [ 2 ] ) ; } for ( i = 0 ; i < 3 ; i
++ ) { rtB . ddsa0w12hq [ i ] = rtB . g3hbvfsfhp * ( tmp [ i + 6 ] *
ptomshbz5r [ 2 ] + ( tmp [ i + 3 ] * ptomshbz5r [ 1 ] + tmp [ i ] *
ptomshbz5r [ 0 ] ) ) ; rtB . ijksz3mwsc [ i ] = muDoubleScalarRound (
j24qsfz3xi [ i ] / rtP . Quantizer_Interval ) * rtP . Quantizer_Interval ; }
if ( ssIsSampleHit ( rtS , 1 , 0 ) && ssIsSampleHit ( rtS , 2 , 0 ) ) { rtDW
. gtbumdp141 [ 0 ] = rtB . ijksz3mwsc [ 0 ] ; rtDW . gtbumdp141 [ 1 ] = rtB .
ijksz3mwsc [ 1 ] ; rtDW . gtbumdp141 [ 2 ] = rtB . ijksz3mwsc [ 2 ] ; } if (
ssIsSampleHit ( rtS , 2 , 0 ) ) { ltip0ky15l = 6.2831853071795862 * rtP .
LPFforqdot_Freq ; rtB . i1fnqqwanu [ 0 ] = rtDW . gtbumdp141 [ 0 ] ; rtB .
fx14ydaqio [ 0 ] = ( rtB . i1fnqqwanu [ 0 ] - rtDW . cn0jcb2rgj [ 0 ] ) *
ltip0ky15l ; rtB . i1fnqqwanu [ 1 ] = rtDW . gtbumdp141 [ 1 ] ; rtB .
fx14ydaqio [ 1 ] = ( rtB . i1fnqqwanu [ 1 ] - rtDW . cn0jcb2rgj [ 1 ] ) *
ltip0ky15l ; rtB . i1fnqqwanu [ 2 ] = rtDW . gtbumdp141 [ 2 ] ; rtB .
fx14ydaqio [ 2 ] = ( rtB . i1fnqqwanu [ 2 ] - rtDW . cn0jcb2rgj [ 2 ] ) *
ltip0ky15l ; ltip0ky15l = 6.2831853071795862 * rtP . LPF1forqdot2_Freq ; rtB
. dx4qfoouu3 [ 0 ] = ( rtB . fx14ydaqio [ 0 ] - rtDW . h4pprbp2zw [ 0 ] ) *
ltip0ky15l ; rtB . dx4qfoouu3 [ 1 ] = ( rtB . fx14ydaqio [ 1 ] - rtDW .
h4pprbp2zw [ 1 ] ) * ltip0ky15l ; rtB . dx4qfoouu3 [ 2 ] = ( rtB . fx14ydaqio
[ 2 ] - rtDW . h4pprbp2zw [ 2 ] ) * ltip0ky15l ; ltip0ky15l =
6.2831853071795862 * rtP . LPF2forqdot2_Freq ; rtB . dhnlb4gzje [ 0 ] = (
rtDW . h4pprbp2zw [ 0 ] - rtDW . bjor124ftp [ 0 ] ) * ltip0ky15l ; rtB .
dhnlb4gzje [ 1 ] = ( rtDW . h4pprbp2zw [ 1 ] - rtDW . bjor124ftp [ 1 ] ) *
ltip0ky15l ; rtB . dhnlb4gzje [ 2 ] = ( rtDW . h4pprbp2zw [ 2 ] - rtDW .
bjor124ftp [ 2 ] ) * ltip0ky15l ; if ( ssIsSampleHit ( rtS , 2 , 0 ) &&
ssIsSampleHit ( rtS , 2 , 0 ) ) { ot40bdmo1z ( rtP . InverseDynamicsPD_Kp , &
rtB . p3gwq53bun ) ; ot40bdmo1z ( rtP . InverseDynamicsPD_Kd , & rtB .
dzynjsmsgs ) ; e5ldib0bf2 ( rtB . i1fnqqwanu , rtB . fx14ydaqio , & rtB .
kalm0nmkn2 , rtP . MPlanned ) ; ls5wg34vyw ( rtB . i1fnqqwanu , & rtB .
nnubrvj5fv , rtP . MPlanned ) ; nvdv3lqtgw ( rtB . i1fnqqwanu , & rtB .
e3vd5ofmev , rtP . MPlanned ) ; nvdv3lqtgw ( rtB . i1fnqqwanu , & rtB .
f1kcndijvu , rtP . MPlanned ) ; for ( i = 0 ; i < 3 ; i ++ ) { ptomshbz5r [ i
] = rtB . kalm0nmkn2 . dkehoz2q2i [ i + 6 ] * rtB . fx14ydaqio [ 2 ] + ( rtB
. kalm0nmkn2 . dkehoz2q2i [ i + 3 ] * rtB . fx14ydaqio [ 1 ] + rtB .
kalm0nmkn2 . dkehoz2q2i [ i ] * rtB . fx14ydaqio [ 0 ] ) ; } for ( i = 0 ; i
< 3 ; i ++ ) { eeml5qblvn [ i ] = rtB . f1kcndijvu . pvyobdscrq [ i + 6 ] *
rtB . enw4u3xr3e [ 2 ] + ( rtB . f1kcndijvu . pvyobdscrq [ i + 3 ] * rtB .
enw4u3xr3e [ 1 ] + rtB . f1kcndijvu . pvyobdscrq [ i ] * rtB . enw4u3xr3e [ 0
] ) ; } ltip0ky15l = rtB . mt4g2ecmso [ 0 ] - rtB . i1fnqqwanu [ 0 ] ; t5 =
rtB . di5zg3biou [ 0 ] - rtB . fx14ydaqio [ 0 ] ; c2 = rtB . mt4g2ecmso [ 1 ]
- rtB . i1fnqqwanu [ 1 ] ; s2 = rtB . di5zg3biou [ 1 ] - rtB . fx14ydaqio [ 1
] ; tmp_i = rtB . mt4g2ecmso [ 2 ] - rtB . i1fnqqwanu [ 2 ] ; tmp_m = rtB .
di5zg3biou [ 2 ] - rtB . fx14ydaqio [ 2 ] ; for ( i = 0 ; i < 3 ; i ++ ) {
tmp_p [ i ] = rtB . p3gwq53bun . gth0wwswdl [ i + 6 ] * tmp_i + ( rtB .
p3gwq53bun . gth0wwswdl [ i + 3 ] * c2 + rtB . p3gwq53bun . gth0wwswdl [ i ]
* ltip0ky15l ) ; } for ( i = 0 ; i < 3 ; i ++ ) { tmp_e [ i ] = rtB .
dzynjsmsgs . gth0wwswdl [ i + 6 ] * tmp_m + ( rtB . dzynjsmsgs . gth0wwswdl [
i + 3 ] * s2 + rtB . dzynjsmsgs . gth0wwswdl [ i ] * t5 ) ; } ltip0ky15l =
tmp_p [ 0 ] + tmp_e [ 0 ] ; c2 = tmp_p [ 1 ] + tmp_e [ 1 ] ; tmp_i = tmp_p [
2 ] + tmp_e [ 2 ] ; for ( i = 0 ; i < 3 ; i ++ ) { rtB . l021hpyxvi [ i ] = (
( rtB . e3vd5ofmev . pvyobdscrq [ i + 3 ] * c2 + rtB . e3vd5ofmev .
pvyobdscrq [ i ] * ltip0ky15l ) + rtB . e3vd5ofmev . pvyobdscrq [ i + 6 ] *
tmp_i ) + ( ( ptomshbz5r [ i ] + eeml5qblvn [ i ] ) + rtB . nnubrvj5fv .
cxxywhieo5 [ i ] ) ; } } c2 = 3.3121686421112381E-170 ; rtB . mrs1pmhp1d [ 0
] = rtB . i1fnqqwanu [ 2 ] * muDoubleScalarSin ( rtB . i1fnqqwanu [ 0 ] ) *
muDoubleScalarSin ( rtB . i1fnqqwanu [ 1 ] ) + muDoubleScalarCos ( rtB .
i1fnqqwanu [ 0 ] ) / 10.0 ; rtB . lfrmso4j40 [ 0 ] = rtB . ndfmx5opo3 [ 0 ] -
rtB . mrs1pmhp1d [ 0 ] ; s2 = muDoubleScalarAbs ( rtB . lfrmso4j40 [ 0 ] ) ;
if ( s2 > 3.3121686421112381E-170 ) { t5 = 1.0 ; c2 = s2 ; } else {
ltip0ky15l = s2 / 3.3121686421112381E-170 ; t5 = ltip0ky15l * ltip0ky15l ; }
rtB . mrs1pmhp1d [ 1 ] = muDoubleScalarSin ( rtB . i1fnqqwanu [ 0 ] ) / 10.0
- rtB . i1fnqqwanu [ 2 ] * muDoubleScalarCos ( rtB . i1fnqqwanu [ 0 ] ) *
muDoubleScalarSin ( rtB . i1fnqqwanu [ 1 ] ) ; rtB . lfrmso4j40 [ 1 ] = rtB .
ndfmx5opo3 [ 1 ] - rtB . mrs1pmhp1d [ 1 ] ; s2 = muDoubleScalarAbs ( rtB .
lfrmso4j40 [ 1 ] ) ; if ( s2 > c2 ) { ltip0ky15l = c2 / s2 ; t5 = t5 *
ltip0ky15l * ltip0ky15l + 1.0 ; c2 = s2 ; } else { ltip0ky15l = s2 / c2 ; t5
+= ltip0ky15l * ltip0ky15l ; } rtB . mrs1pmhp1d [ 2 ] = rtB . i1fnqqwanu [ 2
] * muDoubleScalarCos ( rtB . i1fnqqwanu [ 1 ] ) + 0.2 ; rtB . lfrmso4j40 [ 2
] = rtB . ndfmx5opo3 [ 2 ] - rtB . mrs1pmhp1d [ 2 ] ; s2 = muDoubleScalarAbs
( rtB . lfrmso4j40 [ 2 ] ) ; if ( s2 > c2 ) { ltip0ky15l = c2 / s2 ; t5 = t5
* ltip0ky15l * ltip0ky15l + 1.0 ; c2 = s2 ; } else { ltip0ky15l = s2 / c2 ;
t5 += ltip0ky15l * ltip0ky15l ; } t5 = c2 * muDoubleScalarSqrt ( t5 ) ; rtB .
fbzun2rgtp = 100.0 / rtP . ArcLength * t5 ; rtB . mv031dgyem [ 0 ] = rtB .
mt4g2ecmso [ 0 ] - rtB . i1fnqqwanu [ 0 ] ; rtB . mv031dgyem [ 1 ] = rtB .
mt4g2ecmso [ 1 ] - rtB . i1fnqqwanu [ 1 ] ; rtB . mv031dgyem [ 2 ] = rtB .
mt4g2ecmso [ 2 ] - rtB . i1fnqqwanu [ 2 ] ; { if ( rtDW . p5vastsvrw .
AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . p5vastsvrw .
AQHandles , ssGetTaskTime ( rtS , 2 ) , ( char * ) & rtB . mv031dgyem [ 0 ] +
0 ) ; } } rtB . azozh0ni1z [ 0 ] = rtB . l021hpyxvi [ 0 ] * rtP . TSamp_WtEt
; rtB . itcf1zidza [ 0 ] = rtB . azozh0ni1z [ 0 ] - rtDW . hbhhzhssgt [ 0 ] ;
rtB . azozh0ni1z [ 1 ] = rtB . l021hpyxvi [ 1 ] * rtP . TSamp_WtEt ; rtB .
itcf1zidza [ 1 ] = rtB . azozh0ni1z [ 1 ] - rtDW . hbhhzhssgt [ 1 ] ; rtB .
azozh0ni1z [ 2 ] = rtB . l021hpyxvi [ 2 ] * rtP . TSamp_WtEt ; rtB .
itcf1zidza [ 2 ] = rtB . azozh0ni1z [ 2 ] - rtDW . hbhhzhssgt [ 2 ] ; { if (
rtDW . f0vm4ehx4o . AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal (
rtDW . f0vm4ehx4o . AQHandles , ssGetTaskTime ( rtS , 2 ) , ( char * ) & rtB
. itcf1zidza [ 0 ] + 0 ) ; } } { if ( rtDW . buw2g0pqmj . AQHandles &&
ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . buw2g0pqmj . AQHandles ,
ssGetTaskTime ( rtS , 2 ) , ( char * ) & rtB . fbzun2rgtp + 0 ) ; } } rtB .
f4mdnihu4k [ 0 ] = rtB . enw4u3xr3e [ 0 ] - rtB . dhnlb4gzje [ 0 ] ; rtB .
f4mdnihu4k [ 1 ] = rtB . enw4u3xr3e [ 1 ] - rtB . dhnlb4gzje [ 1 ] ; rtB .
f4mdnihu4k [ 2 ] = rtB . enw4u3xr3e [ 2 ] - rtB . dhnlb4gzje [ 2 ] ; rtB .
g1obqvlufw [ 0 ] = rtB . di5zg3biou [ 0 ] - rtB . fx14ydaqio [ 0 ] ; rtB .
g1obqvlufw [ 1 ] = rtB . di5zg3biou [ 1 ] - rtB . fx14ydaqio [ 1 ] ; rtB .
g1obqvlufw [ 2 ] = rtB . di5zg3biou [ 2 ] - rtB . fx14ydaqio [ 2 ] ;
e5ldib0bf2 ( rtB . mt4g2ecmso , rtB . di5zg3biou , & rtB . epk3a1n2lr , rtP .
MPlanned ) ; nvdv3lqtgw ( rtB . mt4g2ecmso , & rtB . dxs50bidke , rtP .
MPlanned ) ; ls5wg34vyw ( rtB . mt4g2ecmso , & rtB . dgygkhiskz , rtP .
MPlanned ) ; for ( i = 0 ; i < 3 ; i ++ ) { ptomshbz5r [ i ] = rtB .
epk3a1n2lr . dkehoz2q2i [ i + 6 ] * rtB . di5zg3biou [ 2 ] + ( rtB .
epk3a1n2lr . dkehoz2q2i [ i + 3 ] * rtB . di5zg3biou [ 1 ] + rtB . epk3a1n2lr
. dkehoz2q2i [ i ] * rtB . di5zg3biou [ 0 ] ) ; } for ( i = 0 ; i < 3 ; i ++
) { eeml5qblvn [ i ] = rtB . dxs50bidke . pvyobdscrq [ i + 6 ] * rtB .
enw4u3xr3e [ 2 ] + ( rtB . dxs50bidke . pvyobdscrq [ i + 3 ] * rtB .
enw4u3xr3e [ 1 ] + rtB . dxs50bidke . pvyobdscrq [ i ] * rtB . enw4u3xr3e [ 0
] ) ; } rtB . jwa5m1quha [ 0 ] = ( ptomshbz5r [ 0 ] + eeml5qblvn [ 0 ] ) +
rtB . dgygkhiskz . cxxywhieo5 [ 0 ] ; rtB . jwa5m1quha [ 1 ] = ( ptomshbz5r [
1 ] + eeml5qblvn [ 1 ] ) + rtB . dgygkhiskz . cxxywhieo5 [ 1 ] ; rtB .
jwa5m1quha [ 2 ] = ( ptomshbz5r [ 2 ] + eeml5qblvn [ 2 ] ) + rtB . dgygkhiskz
. cxxywhieo5 [ 2 ] ; rtB . atgwh4qunb [ 0 ] = rtB . jwa5m1quha [ 0 ] - rtB .
l021hpyxvi [ 0 ] ; rtB . atgwh4qunb [ 1 ] = rtB . jwa5m1quha [ 1 ] - rtB .
l021hpyxvi [ 1 ] ; rtB . atgwh4qunb [ 2 ] = rtB . jwa5m1quha [ 2 ] - rtB .
l021hpyxvi [ 2 ] ; } rtB . chrv4y5ams = ssGetT ( rtS ) ; if ( ssIsSampleHit (
rtS , 1 , 0 ) ) { rtB . m4vjemwhgy = rtDW . nwjbwtsk0s ; rtB . bvw24fh042 =
rtDW . aonnjayrqu ; } rtB . c0fkxjxeef = rtB . chrv4y5ams - rtB . m4vjemwhgy
; if ( ssIsMajorTimeStep ( rtS ) ) { rtB . nreersdhrm = rtB . c0fkxjxeef ;
rtDW . aipubp0sep = 0 ; if ( rtB . bvw24fh042 > rtB . c0fkxjxeef ) { rtB .
nreersdhrm = rtB . bvw24fh042 ; rtDW . aipubp0sep = 1 ; } } else { rtB .
nreersdhrm = rtB . c0fkxjxeef ; if ( rtDW . aipubp0sep == 1 ) { rtB .
nreersdhrm = rtB . bvw24fh042 ; } } UNUSED_PARAMETER ( tid ) ; } void
MdlOutputsTID4 ( int_T tid ) { rtB . h4umnby0fu = rtP . Constant_Value ;
UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) { if (
ssIsSampleHit ( rtS , 2 , 0 ) ) { rtDW . arabdgyja5 [ 0 ] = rtB . l021hpyxvi
[ 0 ] ; rtDW . cn0jcb2rgj [ 0 ] += rtP . DiscreteTimeIntegrator1_gainval *
rtB . fx14ydaqio [ 0 ] ; rtDW . h4pprbp2zw [ 0 ] += rtP .
DiscreteTimeIntegrator1_gainval_lk5uk2rrci * rtB . dx4qfoouu3 [ 0 ] ; rtDW .
bjor124ftp [ 0 ] += rtP . DiscreteTimeIntegrator1_gainval_jt1p1klapo * rtB .
dhnlb4gzje [ 0 ] ; rtDW . hbhhzhssgt [ 0 ] = rtB . azozh0ni1z [ 0 ] ; rtDW .
arabdgyja5 [ 1 ] = rtB . l021hpyxvi [ 1 ] ; rtDW . cn0jcb2rgj [ 1 ] += rtP .
DiscreteTimeIntegrator1_gainval * rtB . fx14ydaqio [ 1 ] ; rtDW . h4pprbp2zw
[ 1 ] += rtP . DiscreteTimeIntegrator1_gainval_lk5uk2rrci * rtB . dx4qfoouu3
[ 1 ] ; rtDW . bjor124ftp [ 1 ] += rtP .
DiscreteTimeIntegrator1_gainval_jt1p1klapo * rtB . dhnlb4gzje [ 1 ] ; rtDW .
hbhhzhssgt [ 1 ] = rtB . azozh0ni1z [ 1 ] ; rtDW . arabdgyja5 [ 2 ] = rtB .
l021hpyxvi [ 2 ] ; rtDW . cn0jcb2rgj [ 2 ] += rtP .
DiscreteTimeIntegrator1_gainval * rtB . fx14ydaqio [ 2 ] ; rtDW . h4pprbp2zw
[ 2 ] += rtP . DiscreteTimeIntegrator1_gainval_lk5uk2rrci * rtB . dx4qfoouu3
[ 2 ] ; rtDW . bjor124ftp [ 2 ] += rtP .
DiscreteTimeIntegrator1_gainval_jt1p1klapo * rtB . dhnlb4gzje [ 2 ] ; rtDW .
hbhhzhssgt [ 2 ] = rtB . azozh0ni1z [ 2 ] ; } if ( ssIsSampleHit ( rtS , 1 ,
0 ) ) { rtDW . nwjbwtsk0s = rtB . chrv4y5ams ; rtDW . aonnjayrqu = rtB .
nreersdhrm ; } UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID4 ( int_T tid )
{ UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) { XDot * _rtXdot
; _rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ; _rtXdot -> mrjjr04vhg [ 0 ] =
rtB . fxyjxb2a3b [ 0 ] ; _rtXdot -> cgz4e3b2hd [ 0 ] = rtB . ddsa0w12hq [ 0 ]
; _rtXdot -> mrjjr04vhg [ 1 ] = rtB . fxyjxb2a3b [ 1 ] ; _rtXdot ->
cgz4e3b2hd [ 1 ] = rtB . ddsa0w12hq [ 1 ] ; _rtXdot -> mrjjr04vhg [ 2 ] = rtB
. fxyjxb2a3b [ 2 ] ; _rtXdot -> cgz4e3b2hd [ 2 ] = rtB . ddsa0w12hq [ 2 ] ; }
void MdlProjection ( void ) { } void MdlZeroCrossings ( void ) { ZCV *
_rtZCSV ; _rtZCSV = ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) ; _rtZCSV
-> f5zlbpovjt = ssGetT ( rtS ) - rtP . Step_Time ; if ( rtB . c0fkxjxeef >
rtB . bvw24fh042 ) { if ( rtDW . aipubp0sep == 0 ) { _rtZCSV -> hsu0syig3s =
rtB . c0fkxjxeef - rtB . c0fkxjxeef ; } else { _rtZCSV -> hsu0syig3s = rtB .
c0fkxjxeef - rtB . bvw24fh042 ; } } else if ( rtDW . aipubp0sep == 0 ) {
_rtZCSV -> hsu0syig3s = rtB . bvw24fh042 - rtB . c0fkxjxeef ; } else {
_rtZCSV -> hsu0syig3s = rtB . bvw24fh042 - rtB . bvw24fh042 ; } } void
MdlTerminate ( void ) { { if ( rtDW . p5vastsvrw . AQHandles ) {
sdiTerminateStreaming ( & rtDW . p5vastsvrw . AQHandles ) ; } } { if ( rtDW .
f0vm4ehx4o . AQHandles ) { sdiTerminateStreaming ( & rtDW . f0vm4ehx4o .
AQHandles ) ; } } { if ( rtDW . buw2g0pqmj . AQHandles ) {
sdiTerminateStreaming ( & rtDW . buw2g0pqmj . AQHandles ) ; } } } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 6 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
3 ) ; ssSetNumBlocks ( rtS , 110 ) ; ssSetNumBlockIO ( rtS , 44 ) ;
ssSetNumBlockParams ( rtS , 48 ) ; } void MdlInitializeSampleTimes ( void ) {
ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.0 ) ;
ssSetSampleTime ( rtS , 2 , 0.001 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 1.0 ) ; ssSetOffsetTime ( rtS , 2 , 0.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 4102892843U ) ;
ssSetChecksumVal ( rtS , 1 , 2685053547U ) ; ssSetChecksumVal ( rtS , 2 ,
2124228778U ) ; ssSetChecksumVal ( rtS , 3 , 1766344491U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; ( void ) memset ( ( char * ) rtS , 0 ,
sizeof ( SimStruct ) ) ; ( void ) memset ( ( char * ) & mdlInfo , 0 , sizeof
( struct _ssMdlInfo ) ) ; ssSetMdlInfoPtr ( rtS , & mdlInfo ) ;
ssSetExecutionInfo ( rtS , executionInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ssSetWorkSizeInBytes ( rtS , sizeof ( rtB ) ,
"BlockIO" ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof ( B ) ) ; }
{ real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ; ( void )
memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = ( void * ) &
rtDW ; ssSetRootDWork ( rtS , dwork ) ; ssSetWorkSizeInBytes ( rtS , sizeof (
rtDW ) , "DWork" ) ; ( void ) memset ( dwork , 0 , sizeof ( DW ) ) ; } {
static DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T * ) & dtInfo , 0
, sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo .
numDataTypes = 14 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo
. dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = &
rtBTransTable ; dtInfo . PTransTable = & rtPTransTable ; dtInfo .
dataTypeInfoTable = rtDataTypeInfoTable ; }
RobotSimulation_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive (
rtS , true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "RobotSimulation" ) ;
ssSetPath ( rtS , "RobotSimulation" ) ; ssSetTStart ( rtS , 0.0 ) ;
ssSetTFinal ( rtS , 2.5 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
rt_DataLoggingInfo . loggingInterval = NULL ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { { static int_T rt_LoggedStateWidths [ ] = { 3 , 3
, 3 , 3 , 3 , 3 } ; static int_T rt_LoggedStateNumDimensions [ ] = { 1 , 1 ,
1 , 1 , 1 , 1 } ; static int_T rt_LoggedStateDimensions [ ] = { 3 , 3 , 3 , 3
, 3 , 3 } ; static boolean_T rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0 ,
0 , 0 } ; static BuiltInDTypeId rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ; static int_T
rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 , 0 , 0 , 0 } ; static
RTWPreprocessingFcnPtr rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) } ; static const char_T
* rt_LoggedStateLabels [ ] = { "CSTATE" , "CSTATE" , "DSTATE" , "DSTATE" ,
"DSTATE" , "DSTATE" } ; static const char_T * rt_LoggedStateBlockNames [ ] =
{ "RobotSimulation/Plant/Int_2q" , "RobotSimulation/Plant/Int_2qdot" ,
"RobotSimulation/Sensor Analyzer/LPF for qdot/Discrete-Time\nIntegrator1" ,
"RobotSimulation/Sensor Analyzer/LPF1 for qdot2/Discrete-Time\nIntegrator1" ,
"RobotSimulation/Sensor Analyzer/LPF2 for qdot2/Discrete-Time\nIntegrator1" ,
"RobotSimulation/Scopes/Discrete Derivative/UD" } ; static const char_T *
rt_LoggedStateNames [ ] = { "" , "" , "DSTATE" , "DSTATE" , "DSTATE" ,
"DSTATE" } ; static boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0
, 0 , 0 } ; static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0
, SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static
RTWLogSignalInfo rt_LoggedStateSignalInfo = { 6 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert } ; static void *
rt_LoggedStateSignalPtrs [ 6 ] ; rtliSetLogXSignalPtrs ( ssGetRTWLogInfo (
rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . mrjjr04vhg [ 0 ] ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . cgz4e3b2hd [ 0 ] ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) rtDW . cn0jcb2rgj ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) rtDW . h4pprbp2zw ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) rtDW . bjor124ftp ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) rtDW . hbhhzhssgt ; } rtliSetLogT
( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX ( ssGetRTWLogInfo ( rtS )
, "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssJacobianPerturbationBounds jacobianPerturbationBounds ;
ssSetJacobianPerturbationBounds ( rtS , & jacobianPerturbationBounds ) ; } {
static ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 6 ] ;
static real_T absTol [ 6 ] = { 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 } ; static uint8_T absTolControl [ 6 ] = { 0U , 0U , 0U , 0U , 0U , 0U
} ; static real_T contStateJacPerturbBoundMinVec [ 6 ] ; static real_T
contStateJacPerturbBoundMaxVec [ 6 ] ; static uint8_T zcAttributes [ 2 ] = {
( ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL ) } ; static ssNonContDerivSigInfo
nonContDerivSigInfo [ 2 ] = { { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
g3hbvfsfhp ) , ( NULL ) } , { 3 * sizeof ( real_T ) , ( char * ) ( & rtB .
mz0ojksblg [ 0 ] ) , ( NULL ) } } ; { int i ; for ( i = 0 ; i < 6 ; ++ i ) {
contStateJacPerturbBoundMinVec [ i ] = 0 ; contStateJacPerturbBoundMaxVec [ i
] = rtGetInf ( ) ; } } ssSetSolverRelTol ( rtS , 0.001 ) ; ssSetStepSize (
rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , -
1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ; ssSetMaxStepSize ( rtS , 0.001
) ; ssSetSolverMaxOrder ( rtS , - 1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ;
ssSetOutputTimes ( rtS , ( NULL ) ) ; ssSetNumOutputTimes ( rtS , 0 ) ;
ssSetOutputTimesOnly ( rtS , 0 ) ; ssSetOutputTimesIndex ( rtS , 0 ) ;
ssSetZCCacheNeedsReset ( rtS , 1 ) ; ssSetDerivCacheNeedsReset ( rtS , 0 ) ;
ssSetNumNonContDerivSigInfos ( rtS , 2 ) ; ssSetNonContDerivSigInfos ( rtS ,
nonContDerivSigInfo ) ; ssSetSolverInfo ( rtS , & slvrInfo ) ;
ssSetSolverName ( rtS , "ode45" ) ; ssSetVariableStepSolver ( rtS , 1 ) ;
ssSetSolverConsistencyChecking ( rtS , 0 ) ; ssSetSolverAdaptiveZcDetection (
rtS , 0 ) ; ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector (
rtS , absTol ) ; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetJacobianPerturbationBoundsMinVec ( rtS , contStateJacPerturbBoundMinVec
) ; ssSetJacobianPerturbationBoundsMaxVec ( rtS ,
contStateJacPerturbBoundMaxVec ) ; ssSetSolverStateProjection ( rtS , 0 ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetSolverZcSignalAttrib ( rtS , zcAttributes ) ;
ssSetSolverNumZcSignals ( rtS , 2 ) ; ssSetModelZeroCrossings ( rtS ,
MdlZeroCrossings ) ; ssSetSolverConsecutiveZCsStepRelTol ( rtS ,
2.8421709430404007E-14 ) ; ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ;
ssSetSolverConsecutiveZCsError ( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic (
rtS , 1 ) ; ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ;
ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ;
ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 2 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 4102892843U ) ; ssSetChecksumVal ( rtS , 1 ,
2685053547U ) ; ssSetChecksumVal ( rtS , 2 , 2124228778U ) ; ssSetChecksumVal
( rtS , 3 , 1766344491U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 27 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = & rtAlwaysEnabled ;
systemRan [ 2 ] = & rtAlwaysEnabled ; systemRan [ 3 ] = & rtAlwaysEnabled ;
systemRan [ 4 ] = & rtAlwaysEnabled ; systemRan [ 5 ] = & rtAlwaysEnabled ;
systemRan [ 6 ] = & rtAlwaysEnabled ; systemRan [ 7 ] = & rtAlwaysEnabled ;
systemRan [ 8 ] = & rtAlwaysEnabled ; systemRan [ 9 ] = & rtAlwaysEnabled ;
systemRan [ 10 ] = & rtAlwaysEnabled ; systemRan [ 11 ] = & rtAlwaysEnabled ;
systemRan [ 12 ] = & rtAlwaysEnabled ; systemRan [ 13 ] = & rtAlwaysEnabled ;
systemRan [ 14 ] = & rtAlwaysEnabled ; systemRan [ 15 ] = & rtAlwaysEnabled ;
systemRan [ 16 ] = & rtAlwaysEnabled ; systemRan [ 17 ] = & rtAlwaysEnabled ;
systemRan [ 18 ] = & rtAlwaysEnabled ; systemRan [ 19 ] = & rtAlwaysEnabled ;
systemRan [ 20 ] = & rtAlwaysEnabled ; systemRan [ 21 ] = & rtAlwaysEnabled ;
systemRan [ 22 ] = & rtAlwaysEnabled ; systemRan [ 23 ] = & rtAlwaysEnabled ;
systemRan [ 24 ] = & rtAlwaysEnabled ; systemRan [ 25 ] = & rtAlwaysEnabled ;
systemRan [ 26 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; } return
rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 4 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID4 ( tid ) ; }
