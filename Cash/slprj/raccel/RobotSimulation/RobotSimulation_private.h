#ifndef RTW_HEADER_RobotSimulation_private_h_
#define RTW_HEADER_RobotSimulation_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "RobotSimulation.h"
#if !defined(rt_VALIDATE_MEMORY)
#define rt_VALIDATE_MEMORY(S, ptr)   if(!(ptr)) {\
  ssSetErrorStatus(rtS, RT_MEMORY_ALLOCATION_ERROR);\
  }
#endif
#if !defined(rt_FREE)
#if !defined(_WIN32)
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((ptr));\
  (ptr) = (NULL);\
  }
#else
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((void *)(ptr));\
  (ptr) = (NULL);\
  }
#endif
#endif
extern void rt_invd3x3_snf ( const real_T u [ 9 ] , real_T y [ 9 ] ) ; extern
void e5ldib0bf2 ( const real_T pnpy3pytfz [ 3 ] , const real_T n1lhttlas2 [ 3
] , bp1rwuuloc * localB , real_T rtp_M ) ; extern void ls5wg34vyw ( const
real_T ffgwybumsz [ 3 ] , lfj1s0cxtb * localB , real_T rtp_M ) ; extern void
nvdv3lqtgw ( const real_T ncunp54gwx [ 3 ] , krxjaa2z0k * localB , real_T
rtp_M ) ; extern void ot40bdmo1z ( const real_T c1frlqkuky [ 3 ] , ljdzojdqbq
* localB ) ;
#if defined(MULTITASKING)
#error Models using the variable step solvers cannot define MULTITASKING
#endif
#endif
