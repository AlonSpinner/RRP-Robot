#ifndef RTW_HEADER_RobotSimulation_h_
#define RTW_HEADER_RobotSimulation_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef RobotSimulation_COMMON_INCLUDES_
#define RobotSimulation_COMMON_INCLUDES_
#include <stdlib.h>
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "RobotSimulation_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME RobotSimulation
#define NSAMPLE_TIMES (5) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (44) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (6)   
#elif NCSTATES != 6
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T dkehoz2q2i [ 9 ] ; } bp1rwuuloc ; typedef struct {
real_T cxxywhieo5 [ 3 ] ; } lfj1s0cxtb ; typedef struct { real_T pvyobdscrq [
9 ] ; } krxjaa2z0k ; typedef struct { real_T gth0wwswdl [ 9 ] ; } ljdzojdqbq
; typedef struct { real_T jjv3wr13aa [ 3 ] ; real_T g3hbvfsfhp ; real_T
ijksz3mwsc [ 3 ] ; real_T i1fnqqwanu [ 3 ] ; real_T fx14ydaqio [ 3 ] ; real_T
dx4qfoouu3 [ 3 ] ; real_T dhnlb4gzje [ 3 ] ; real_T lfrmso4j40 [ 3 ] ; real_T
fbzun2rgtp ; real_T mv031dgyem [ 3 ] ; real_T azozh0ni1z [ 3 ] ; real_T
itcf1zidza [ 3 ] ; real_T f4mdnihu4k [ 3 ] ; real_T g1obqvlufw [ 3 ] ; real_T
jwa5m1quha [ 3 ] ; real_T atgwh4qunb [ 3 ] ; real_T chrv4y5ams ; real_T
m4vjemwhgy ; real_T c0fkxjxeef ; real_T bvw24fh042 ; real_T nreersdhrm ;
real_T h4umnby0fu ; real_T mrs1pmhp1d [ 3 ] ; real_T ndfmx5opo3 [ 3 ] ;
real_T mt4g2ecmso [ 3 ] ; real_T di5zg3biou [ 3 ] ; real_T enw4u3xr3e [ 3 ] ;
real_T fxyjxb2a3b [ 3 ] ; real_T mz0ojksblg [ 3 ] ; real_T ddsa0w12hq [ 3 ] ;
real_T l021hpyxvi [ 3 ] ; krxjaa2z0k dxs50bidke ; lfj1s0cxtb dgygkhiskz ;
bp1rwuuloc epk3a1n2lr ; krxjaa2z0k ej5252hcor ; lfj1s0cxtb oitjezxpmx ;
bp1rwuuloc hnu3zwzkde ; ljdzojdqbq dzynjsmsgs ; ljdzojdqbq p3gwq53bun ;
krxjaa2z0k f1kcndijvu ; krxjaa2z0k e3vd5ofmev ; lfj1s0cxtb nnubrvj5fv ;
bp1rwuuloc kalm0nmkn2 ; } B ; typedef struct { real_T cn0jcb2rgj [ 3 ] ;
real_T h4pprbp2zw [ 3 ] ; real_T bjor124ftp [ 3 ] ; real_T hbhhzhssgt [ 3 ] ;
real_T arabdgyja5 [ 3 ] ; real_T gtbumdp141 [ 3 ] ; real_T nwjbwtsk0s ;
real_T aonnjayrqu ; real_T gey2dafowy [ 9 ] ; struct { void * LoggedData [ 2
] ; } f4cgpynrj4 ; struct { void * AQHandles ; } p5vastsvrw ; struct { void *
AQHandles ; } f0vm4ehx4o ; struct { void * AQHandles ; } buw2g0pqmj ; struct
{ void * LoggedData [ 2 ] ; } pqmhoyu5lv ; struct { void * LoggedData [ 2 ] ;
} hnwbshcjdz ; struct { void * LoggedData [ 2 ] ; } e1ux5t5pq4 ; struct {
void * LoggedData [ 2 ] ; } f220u1tzs1 ; struct { void * LoggedData ; }
njf1v3jmtu ; struct { void * LoggedData [ 2 ] ; } hspu4502dq ; struct { void
* LoggedData [ 2 ] ; } jwoqu1igx4 ; int_T gbgkc2rm53 ; int_T aipubp0sep ; }
DW ; typedef struct { real_T mrjjr04vhg [ 3 ] ; real_T cgz4e3b2hd [ 3 ] ; } X
; typedef struct { real_T mrjjr04vhg [ 3 ] ; real_T cgz4e3b2hd [ 3 ] ; } XDot
; typedef struct { boolean_T mrjjr04vhg [ 3 ] ; boolean_T cgz4e3b2hd [ 3 ] ;
} XDis ; typedef struct { real_T mrjjr04vhg [ 3 ] ; real_T cgz4e3b2hd [ 3 ] ;
} CStateAbsTol ; typedef struct { real_T mrjjr04vhg [ 3 ] ; real_T cgz4e3b2hd
[ 3 ] ; } CXPtMin ; typedef struct { real_T mrjjr04vhg [ 3 ] ; real_T
cgz4e3b2hd [ 3 ] ; } CXPtMax ; typedef struct { real_T f5zlbpovjt ; real_T
hsu0syig3s ; } ZCV ; typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
DataMapInfo ; struct P_ { real_T ArcLength ; real_T H ; real_T L ; real_T
MActual ; real_T MPlanned ; real_T P0 [ 3 ] ; real_T Pf [ 3 ] ; real_T T ;
real_T elbows [ 2 ] ; real_T LPFforqdot_Freq ; real_T LPF1forqdot2_Freq ;
real_T LPF2forqdot2_Freq ; real_T DiscreteDerivative_ICPrevScaledInput ;
real_T InverseDynamicsPD_Kd [ 3 ] ; real_T InverseDynamicsPD_Kp [ 3 ] ;
real_T MinJerkTrajectoryPlanner_Tbreaks ; real_T
MinJerkTrajectoryPlanner_Tbreaks_bavenone0d ; real_T LPFforqdot_s0 ; real_T
LPF1forqdot2_s0 ; real_T LPF2forqdot2_s0 ; real_T Constant1_Value ; real_T
Int_2q_IC [ 3 ] ; real_T Int_2qdot_IC [ 3 ] ; real_T TSamp_WtEt ; real_T
Memory_InitialCondition ; real_T Memory1_InitialCondition ; real_T
Constant_Value ; real_T DiscreteTimeIntegrator1_gainval ; real_T
DiscreteTimeIntegrator1_gainval_lk5uk2rrci ; real_T
DiscreteTimeIntegrator1_gainval_jt1p1klapo ; real_T
RateTransition1_InitialCondition ; real_T Step_Time ; real_T Step_Y0 ; real_T
Step_YFinal ; real_T Quantizer_Interval ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern P rtP ; extern const rtwCAPI_ModelMappingStaticInfo *
RobotSimulation_GetCAPIStaticMap ( void ) ; extern SimStruct * const rtS ;
extern const int_T gblNumToFiles ; extern const int_T gblNumFrFiles ; extern
const int_T gblNumFrWksBlocks ; extern rtInportTUtable * gblInportTUtables ;
extern const char * gblInportFileName ; extern const int_T
gblNumRootInportBlks ; extern const int_T gblNumModelInputs ; extern const
int_T gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ;
extern const int_T gblInportComplex [ ] ; extern const int_T
gblInportInterpoFlag [ ] ; extern const int_T gblInportContinuous [ ] ;
extern const int_T gblParameterTuningTid ; extern DataMapInfo *
rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ;
void MdlOutputs ( int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T
tid ) ; void MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) ;
#endif
