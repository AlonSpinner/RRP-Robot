#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "RobotSimulation_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "RobotSimulation.h"
#include "RobotSimulation_capi.h"
#include "RobotSimulation_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 7 , TARGET_STRING (
"RobotSimulation/High level Controllers" ) , TARGET_STRING ( "tau" ) , 0 , 0
, 0 , 0 , 0 } , { 1 , 16 , TARGET_STRING ( "RobotSimulation/Plant" ) ,
TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 1 } , { 2 , 16 , TARGET_STRING (
"RobotSimulation/Plant" ) , TARGET_STRING ( "" ) , 2 , 0 , 0 , 0 , 1 } , { 3
, 18 , TARGET_STRING ( "RobotSimulation/Reference Builder" ) , TARGET_STRING
( "x_ref" ) , 0 , 0 , 0 , 0 , 0 } , { 4 , 17 , TARGET_STRING (
"RobotSimulation/Reference Builder" ) , TARGET_STRING ( "q_ref" ) , 1 , 0 , 0
, 0 , 0 } , { 5 , 17 , TARGET_STRING ( "RobotSimulation/Reference Builder" )
, TARGET_STRING ( "" ) , 2 , 0 , 0 , 0 , 0 } , { 6 , 17 , TARGET_STRING (
"RobotSimulation/Reference Builder" ) , TARGET_STRING ( "" ) , 3 , 0 , 0 , 0
, 0 } , { 7 , 26 , TARGET_STRING ( "RobotSimulation/Sensor Analyzer" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 8 , 26 , TARGET_STRING (
"RobotSimulation/Sensor Analyzer" ) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 ,
0 } , { 9 , 26 , TARGET_STRING ( "RobotSimulation/Sensor Analyzer" ) ,
TARGET_STRING ( "" ) , 2 , 0 , 0 , 0 , 0 } , { 10 , 0 , TARGET_STRING (
"RobotSimulation/Quantizer" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } ,
{ 11 , 0 , TARGET_STRING ( "RobotSimulation/Rate Transition1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 12 , 0 , TARGET_STRING (
"RobotSimulation/Step" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 2 } , { 13
, 7 , TARGET_STRING (
"RobotSimulation/High level Controllers/Inverse Dynamics + PD" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 14 , 12 , TARGET_STRING (
"RobotSimulation/Plant/Compute C" ) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 ,
1 } , { 15 , 13 , TARGET_STRING ( "RobotSimulation/Plant/Compute G" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 16 , 14 , TARGET_STRING (
"RobotSimulation/Plant/Compute H" ) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 ,
1 } , { 17 , 16 , TARGET_STRING ( "RobotSimulation/Plant/Int_2qdot" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 18 , 16 , TARGET_STRING (
"RobotSimulation/Plant/Product" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1
} , { 19 , 16 , TARGET_STRING ( "RobotSimulation/Plant/Sum3" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 20 , 17 , TARGET_STRING (
"RobotSimulation/Reference Builder/Inverse Kinematics" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 21 , 17 , TARGET_STRING (
"RobotSimulation/Reference Builder/Inverse Kinematics" ) , TARGET_STRING ( ""
) , 1 , 0 , 0 , 0 , 0 } , { 22 , 17 , TARGET_STRING (
"RobotSimulation/Reference Builder/Inverse Kinematics" ) , TARGET_STRING ( ""
) , 2 , 0 , 0 , 0 , 0 } , { 23 , 18 , TARGET_STRING (
"RobotSimulation/Reference Builder/MinJerk Trajectory Planner" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 24 , 20 , TARGET_STRING (
"RobotSimulation/Scopes/Direct Kinematics" ) , TARGET_STRING ( "x_meas" ) , 0
, 0 , 0 , 0 , 0 } , { 25 , 25 , TARGET_STRING (
"RobotSimulation/Scopes/Clock" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 }
, { 26 , 25 , TARGET_STRING ( "RobotSimulation/Scopes/Constant" ) ,
TARGET_STRING ( "Desired Error @1.5s" ) , 0 , 0 , 1 , 0 , 3 } , { 27 , 25 ,
TARGET_STRING ( "RobotSimulation/Scopes/Gain" ) , TARGET_STRING (
"abs Percentile Error" ) , 0 , 0 , 1 , 0 , 0 } , { 28 , 25 , TARGET_STRING (
"RobotSimulation/Scopes/Memory" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 2
} , { 29 , 25 , TARGET_STRING ( "RobotSimulation/Scopes/Memory1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 2 } , { 30 , 25 , TARGET_STRING (
"RobotSimulation/Scopes/Max" ) , TARGET_STRING ( "Max" ) , 0 , 0 , 1 , 0 , 1
} , { 31 , 25 , TARGET_STRING ( "RobotSimulation/Scopes/Add" ) ,
TARGET_STRING ( "qdot_err" ) , 0 , 0 , 0 , 0 , 0 } , { 32 , 25 ,
TARGET_STRING ( "RobotSimulation/Scopes/Add1" ) , TARGET_STRING ( "q_err" ) ,
0 , 0 , 0 , 0 , 0 } , { 33 , 25 , TARGET_STRING (
"RobotSimulation/Scopes/Add2" ) , TARGET_STRING ( "x_err" ) , 0 , 0 , 0 , 0 ,
0 } , { 34 , 25 , TARGET_STRING ( "RobotSimulation/Scopes/Add3" ) ,
TARGET_STRING ( "tau_diff" ) , 0 , 0 , 0 , 0 , 0 } , { 35 , 25 ,
TARGET_STRING ( "RobotSimulation/Scopes/Add4" ) , TARGET_STRING ( "qdot2_err"
) , 0 , 0 , 0 , 0 , 0 } , { 36 , 25 , TARGET_STRING (
"RobotSimulation/Scopes/Sum" ) , TARGET_STRING ( "Step_Size" ) , 0 , 0 , 1 ,
0 , 1 } , { 37 , 26 , TARGET_STRING ( "RobotSimulation/Sensor Analyzer/q_SE"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 38 , 1 , TARGET_STRING (
"RobotSimulation/High level Controllers/Inverse Dynamics + PD/Compute C" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 39 , 2 , TARGET_STRING (
"RobotSimulation/High level Controllers/Inverse Dynamics + PD/Compute G" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 40 , 3 , TARGET_STRING (
"RobotSimulation/High level Controllers/Inverse Dynamics + PD/Compute H" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 41 , 4 , TARGET_STRING (
"RobotSimulation/High level Controllers/Inverse Dynamics + PD/Compute H1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 42 , 5 , TARGET_STRING (
"RobotSimulation/High level Controllers/Inverse Dynamics + PD/Diag" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 43 , 6 , TARGET_STRING (
"RobotSimulation/High level Controllers/Inverse Dynamics + PD/Diag1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 44 , 7 , TARGET_STRING (
"RobotSimulation/High level Controllers/Inverse Dynamics + PD/Sum2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 45 , 25 , TARGET_STRING (
"RobotSimulation/Scopes/Discrete Derivative/Diff" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 46 , 25 , TARGET_STRING (
"RobotSimulation/Scopes/Discrete Derivative/TSamp" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 47 , 22 , TARGET_STRING (
"RobotSimulation/Scopes/OpenLoop/Compute C" ) , TARGET_STRING ( "" ) , 0 , 0
, 2 , 0 , 0 } , { 48 , 23 , TARGET_STRING (
"RobotSimulation/Scopes/OpenLoop/Compute G" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 0 } , { 49 , 24 , TARGET_STRING (
"RobotSimulation/Scopes/OpenLoop/Compute H" ) , TARGET_STRING ( "" ) , 0 , 0
, 2 , 0 , 0 } , { 50 , 25 , TARGET_STRING (
"RobotSimulation/Scopes/OpenLoop/Sum4" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 0 } , { 51 , 26 , TARGET_STRING (
"RobotSimulation/Sensor Analyzer/LPF for qdot/Gain7" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 52 , 26 , TARGET_STRING (
"RobotSimulation/Sensor Analyzer/LPF1 for qdot2/Gain7" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 53 , 26 , TARGET_STRING (
"RobotSimulation/Sensor Analyzer/LPF2 for qdot2/Gain7" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 }
} ; static const rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 54 ,
TARGET_STRING ( "RobotSimulation/Quantizer" ) , TARGET_STRING (
"QuantizationInterval" ) , 0 , 1 , 0 } , { 55 , TARGET_STRING (
"RobotSimulation/Rate Transition1" ) , TARGET_STRING ( "InitialCondition" ) ,
0 , 1 , 0 } , { 56 , TARGET_STRING ( "RobotSimulation/Step" ) , TARGET_STRING
( "Time" ) , 0 , 1 , 0 } , { 57 , TARGET_STRING ( "RobotSimulation/Step" ) ,
TARGET_STRING ( "Before" ) , 0 , 1 , 0 } , { 58 , TARGET_STRING (
"RobotSimulation/Step" ) , TARGET_STRING ( "After" ) , 0 , 1 , 0 } , { 59 ,
TARGET_STRING (
"RobotSimulation/High level Controllers/Inverse Dynamics + PD" ) ,
TARGET_STRING ( "Kp" ) , 0 , 3 , 0 } , { 60 , TARGET_STRING (
"RobotSimulation/High level Controllers/Inverse Dynamics + PD" ) ,
TARGET_STRING ( "Kd" ) , 0 , 3 , 0 } , { 61 , TARGET_STRING (
"RobotSimulation/Initialize Function/MinJerk Trajectory Planner" ) ,
TARGET_STRING ( "Tbreaks" ) , 0 , 1 , 0 } , { 62 , TARGET_STRING (
"RobotSimulation/Initialize Function/Constant1" ) , TARGET_STRING ( "Value" )
, 0 , 1 , 0 } , { 63 , TARGET_STRING ( "RobotSimulation/Plant/Int_2q" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 64 , TARGET_STRING (
"RobotSimulation/Plant/Int_2qdot" ) , TARGET_STRING ( "InitialCondition" ) ,
0 , 0 , 0 } , { 65 , TARGET_STRING (
"RobotSimulation/Reference Builder/MinJerk Trajectory Planner" ) ,
TARGET_STRING ( "Tbreaks" ) , 0 , 1 , 0 } , { 66 , TARGET_STRING (
"RobotSimulation/Scopes/Discrete Derivative" ) , TARGET_STRING (
"ICPrevScaledInput" ) , 0 , 1 , 0 } , { 67 , TARGET_STRING (
"RobotSimulation/Scopes/Constant" ) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 }
, { 68 , TARGET_STRING ( "RobotSimulation/Scopes/Memory" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 1 , 0 } , { 69 , TARGET_STRING (
"RobotSimulation/Scopes/Memory1" ) , TARGET_STRING ( "InitialCondition" ) , 0
, 1 , 0 } , { 70 , TARGET_STRING (
"RobotSimulation/Sensor Analyzer/LPF for qdot" ) , TARGET_STRING ( "Freq" ) ,
0 , 1 , 0 } , { 71 , TARGET_STRING (
"RobotSimulation/Sensor Analyzer/LPF for qdot" ) , TARGET_STRING ( "s0" ) , 0
, 1 , 0 } , { 72 , TARGET_STRING (
"RobotSimulation/Sensor Analyzer/LPF1 for qdot2" ) , TARGET_STRING ( "Freq" )
, 0 , 1 , 0 } , { 73 , TARGET_STRING (
"RobotSimulation/Sensor Analyzer/LPF1 for qdot2" ) , TARGET_STRING ( "s0" ) ,
0 , 1 , 0 } , { 74 , TARGET_STRING (
"RobotSimulation/Sensor Analyzer/LPF2 for qdot2" ) , TARGET_STRING ( "Freq" )
, 0 , 1 , 0 } , { 75 , TARGET_STRING (
"RobotSimulation/Sensor Analyzer/LPF2 for qdot2" ) , TARGET_STRING ( "s0" ) ,
0 , 1 , 0 } , { 76 , TARGET_STRING (
"RobotSimulation/Scopes/Discrete Derivative/TSamp" ) , TARGET_STRING ( "WtEt"
) , 0 , 1 , 0 } , { 77 , TARGET_STRING (
"RobotSimulation/Sensor Analyzer/LPF for qdot/Discrete-Time Integrator1" ) ,
TARGET_STRING ( "gainval" ) , 0 , 1 , 0 } , { 78 , TARGET_STRING (
"RobotSimulation/Sensor Analyzer/LPF1 for qdot2/Discrete-Time Integrator1" )
, TARGET_STRING ( "gainval" ) , 0 , 1 , 0 } , { 79 , TARGET_STRING (
"RobotSimulation/Sensor Analyzer/LPF2 for qdot2/Discrete-Time Integrator1" )
, TARGET_STRING ( "gainval" ) , 0 , 1 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 ,
0 , 0 } } ; static const rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , (
NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_Signals
rtRootOutputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ;
static const rtwCAPI_ModelParameters rtModelParameters [ ] = { { 80 ,
TARGET_STRING ( "ArcLength" ) , 0 , 1 , 0 } , { 81 , TARGET_STRING ( "H" ) ,
0 , 1 , 0 } , { 82 , TARGET_STRING ( "L" ) , 0 , 1 , 0 } , { 83 ,
TARGET_STRING ( "MActual" ) , 0 , 1 , 0 } , { 84 , TARGET_STRING ( "MPlanned"
) , 0 , 1 , 0 } , { 85 , TARGET_STRING ( "P0" ) , 0 , 0 , 0 } , { 86 ,
TARGET_STRING ( "Pf" ) , 0 , 0 , 0 } , { 87 , TARGET_STRING ( "T" ) , 0 , 1 ,
0 } , { 88 , TARGET_STRING ( "elbows" ) , 0 , 4 , 0 } , { 0 , ( NULL ) , 0 ,
0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . l021hpyxvi [ 0 ] , & rtB .
fxyjxb2a3b [ 0 ] , & rtB . ddsa0w12hq [ 0 ] , & rtB . ndfmx5opo3 [ 0 ] , &
rtB . mt4g2ecmso [ 0 ] , & rtB . di5zg3biou [ 0 ] , & rtB . enw4u3xr3e [ 0 ]
, & rtB . i1fnqqwanu [ 0 ] , & rtB . fx14ydaqio [ 0 ] , & rtB . dhnlb4gzje [
0 ] , & rtB . ijksz3mwsc [ 0 ] , & rtB . jjv3wr13aa [ 0 ] , & rtB .
g3hbvfsfhp , & rtB . l021hpyxvi [ 0 ] , & rtB . hnu3zwzkde . dkehoz2q2i [ 0 ]
, & rtB . oitjezxpmx . cxxywhieo5 [ 0 ] , & rtB . ej5252hcor . pvyobdscrq [ 0
] , & rtB . fxyjxb2a3b [ 0 ] , & rtB . ddsa0w12hq [ 0 ] , & rtB . mz0ojksblg
[ 0 ] , & rtB . mt4g2ecmso [ 0 ] , & rtB . di5zg3biou [ 0 ] , & rtB .
enw4u3xr3e [ 0 ] , & rtB . ndfmx5opo3 [ 0 ] , & rtB . mrs1pmhp1d [ 0 ] , &
rtB . chrv4y5ams , & rtB . h4umnby0fu , & rtB . fbzun2rgtp , & rtB .
m4vjemwhgy , & rtB . bvw24fh042 , & rtB . nreersdhrm , & rtB . g1obqvlufw [ 0
] , & rtB . mv031dgyem [ 0 ] , & rtB . lfrmso4j40 [ 0 ] , & rtB . atgwh4qunb
[ 0 ] , & rtB . f4mdnihu4k [ 0 ] , & rtB . c0fkxjxeef , & rtB . i1fnqqwanu [
0 ] , & rtB . kalm0nmkn2 . dkehoz2q2i [ 0 ] , & rtB . nnubrvj5fv . cxxywhieo5
[ 0 ] , & rtB . e3vd5ofmev . pvyobdscrq [ 0 ] , & rtB . f1kcndijvu .
pvyobdscrq [ 0 ] , & rtB . p3gwq53bun . gth0wwswdl [ 0 ] , & rtB . dzynjsmsgs
. gth0wwswdl [ 0 ] , & rtB . l021hpyxvi [ 0 ] , & rtB . itcf1zidza [ 0 ] , &
rtB . azozh0ni1z [ 0 ] , & rtB . epk3a1n2lr . dkehoz2q2i [ 0 ] , & rtB .
dgygkhiskz . cxxywhieo5 [ 0 ] , & rtB . dxs50bidke . pvyobdscrq [ 0 ] , & rtB
. jwa5m1quha [ 0 ] , & rtB . fx14ydaqio [ 0 ] , & rtB . dx4qfoouu3 [ 0 ] , &
rtB . dhnlb4gzje [ 0 ] , & rtP . Quantizer_Interval , & rtP .
RateTransition1_InitialCondition , & rtP . Step_Time , & rtP . Step_Y0 , &
rtP . Step_YFinal , & rtP . InverseDynamicsPD_Kp [ 0 ] , & rtP .
InverseDynamicsPD_Kd [ 0 ] , & rtP . MinJerkTrajectoryPlanner_Tbreaks , & rtP
. Constant1_Value , & rtP . Int_2q_IC [ 0 ] , & rtP . Int_2qdot_IC [ 0 ] , &
rtP . MinJerkTrajectoryPlanner_Tbreaks_bavenone0d , & rtP .
DiscreteDerivative_ICPrevScaledInput , & rtP . Constant_Value , & rtP .
Memory_InitialCondition , & rtP . Memory1_InitialCondition , & rtP .
LPFforqdot_Freq , & rtP . LPFforqdot_s0 , & rtP . LPF1forqdot2_Freq , & rtP .
LPF1forqdot2_s0 , & rtP . LPF2forqdot2_Freq , & rtP . LPF2forqdot2_s0 , & rtP
. TSamp_WtEt , & rtP . DiscreteTimeIntegrator1_gainval , & rtP .
DiscreteTimeIntegrator1_gainval_lk5uk2rrci , & rtP .
DiscreteTimeIntegrator1_gainval_jt1p1klapo , & rtP . ArcLength , & rtP . H ,
& rtP . L , & rtP . MActual , & rtP . MPlanned , & rtP . P0 [ 0 ] , & rtP .
Pf [ 0 ] , & rtP . T , & rtP . elbows [ 0 ] , } ; static int32_T *
rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_VECTOR , 0 , 2 , 0 } , { rtwCAPI_SCALAR , 2 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 4 , 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } , {
rtwCAPI_VECTOR , 8 , 2 , 0 } } ; static const uint_T rtDimensionArray [ ] = {
3 , 1 , 1 , 1 , 3 , 3 , 1 , 3 , 1 , 2 } ; static const real_T
rtcapiStoredFloats [ ] = { 0.001 , 0.0 , 1.0 } ; static const
rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 1 ] , 2 , 0 } , { ( const void * ) &
rtcapiStoredFloats [ 1 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , 0 ,
0 } , { ( const void * ) & rtcapiStoredFloats [ 1 ] , ( const void * ) &
rtcapiStoredFloats [ 2 ] , 1 , 0 } , { ( NULL ) , ( NULL ) , 4 , 0 } } ;
static rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 54 ,
rtRootInputs , 0 , rtRootOutputs , 0 } , { rtBlockParameters , 26 ,
rtModelParameters , 9 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap
, rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float"
, { 4102892843U , 2685053547U , 2124228778U , 1766344491U } , ( NULL ) , 0 ,
0 } ; const rtwCAPI_ModelMappingStaticInfo * RobotSimulation_GetCAPIStaticMap
( void ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void RobotSimulation_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( (
* rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void RobotSimulation_host_InitializeDataMapInfo (
RobotSimulation_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
