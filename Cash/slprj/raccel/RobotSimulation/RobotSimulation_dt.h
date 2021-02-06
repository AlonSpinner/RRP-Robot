#include "ext_types.h"
static DataTypeInfo rtDataTypeInfoTable [ ] = { { "real_T" , 0 , 8 } , {
"real32_T" , 1 , 4 } , { "int8_T" , 2 , 1 } , { "uint8_T" , 3 , 1 } , {
"int16_T" , 4 , 2 } , { "uint16_T" , 5 , 2 } , { "int32_T" , 6 , 4 } , {
"uint32_T" , 7 , 4 } , { "boolean_T" , 8 , 1 } , { "fcn_call_T" , 9 , 0 } , {
"int_T" , 10 , 4 } , { "pointer_T" , 11 , 8 } , { "action_T" , 12 , 8 } , {
"timer_uint32_pair_T" , 13 , 8 } } ; static uint_T rtDataTypeSizes [ ] = {
sizeof ( real_T ) , sizeof ( real32_T ) , sizeof ( int8_T ) , sizeof (
uint8_T ) , sizeof ( int16_T ) , sizeof ( uint16_T ) , sizeof ( int32_T ) ,
sizeof ( uint32_T ) , sizeof ( boolean_T ) , sizeof ( fcn_call_T ) , sizeof (
int_T ) , sizeof ( pointer_T ) , sizeof ( action_T ) , 2 * sizeof ( uint32_T
) } ; static const char_T * rtDataTypeNames [ ] = { "real_T" , "real32_T" ,
"int8_T" , "uint8_T" , "int16_T" , "uint16_T" , "int32_T" , "uint32_T" ,
"boolean_T" , "fcn_call_T" , "int_T" , "pointer_T" , "action_T" ,
"timer_uint32_pair_T" } ; static DataTypeTransition rtBTransitions [ ] = { {
( char_T * ) ( & rtB . jjv3wr13aa [ 0 ] ) , 0 , 0 , 77 } , { ( char_T * ) ( &
rtB . dxs50bidke . pvyobdscrq [ 0 ] ) , 0 , 0 , 9 } , { ( char_T * ) ( & rtB
. dgygkhiskz . cxxywhieo5 [ 0 ] ) , 0 , 0 , 3 } , { ( char_T * ) ( & rtB .
epk3a1n2lr . dkehoz2q2i [ 0 ] ) , 0 , 0 , 9 } , { ( char_T * ) ( & rtB .
ej5252hcor . pvyobdscrq [ 0 ] ) , 0 , 0 , 9 } , { ( char_T * ) ( & rtB .
oitjezxpmx . cxxywhieo5 [ 0 ] ) , 0 , 0 , 3 } , { ( char_T * ) ( & rtB .
hnu3zwzkde . dkehoz2q2i [ 0 ] ) , 0 , 0 , 9 } , { ( char_T * ) ( & rtB .
dzynjsmsgs . gth0wwswdl [ 0 ] ) , 0 , 0 , 9 } , { ( char_T * ) ( & rtB .
p3gwq53bun . gth0wwswdl [ 0 ] ) , 0 , 0 , 9 } , { ( char_T * ) ( & rtB .
f1kcndijvu . pvyobdscrq [ 0 ] ) , 0 , 0 , 9 } , { ( char_T * ) ( & rtB .
e3vd5ofmev . pvyobdscrq [ 0 ] ) , 0 , 0 , 9 } , { ( char_T * ) ( & rtB .
nnubrvj5fv . cxxywhieo5 [ 0 ] ) , 0 , 0 , 3 } , { ( char_T * ) ( & rtB .
kalm0nmkn2 . dkehoz2q2i [ 0 ] ) , 0 , 0 , 9 } , { ( char_T * ) ( & rtDW .
cn0jcb2rgj [ 0 ] ) , 0 , 0 , 29 } , { ( char_T * ) ( & rtDW . f4cgpynrj4 .
LoggedData [ 0 ] ) , 11 , 0 , 18 } , { ( char_T * ) ( & rtDW . gbgkc2rm53 ) ,
10 , 0 , 2 } } ; static DataTypeTransitionTable rtBTransTable = { 16U ,
rtBTransitions } ; static DataTypeTransition rtPTransitions [ ] = { { (
char_T * ) ( & rtP . ArcLength ) , 0 , 0 , 48 } } ; static
DataTypeTransitionTable rtPTransTable = { 1U , rtPTransitions } ;
