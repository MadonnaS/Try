/* --------------------------------------------------------------------------------------------------- 
 ** @file    dio.h
 ** @brief   dio module header file for this program 
 ** @author  Madonna Sedky
 ** @date    6/1/2014
 ** @version 1.0
 --------------------------------------------------------------------------------------------------- */




#ifndef DIO_H
#define DIO_H

#include "std_type.h"
#include "common_macros.h"

#define Input 1
#define Output 0
#define LogicHigh 1
#define LogicLow 0
/* ---------------------------------------------------------------------------------------------------------------
Structure Name]: DioConfig
[Structure Description]:
 Structure to describe each individual PIN contains:
 *													   1. the PORT Which the pin belongs to. 'A 'B' 'C' or 'D'
 *													   2. the number of the pin in the PORT.
 *													   3. the direction of pin --> INPUT or OUTPUT
 *													   4. the value of the pin  
--------------------------------------------------------------------------------------------------------------- */


typedef struct {
	uint8 s_port;
	uint8 s_direction;
	uint8 s_pinNum;
	uint8 s_value;
	}DioConfig;
/* ---------------------------------------------------------------------------------------------------------------
[Function Name] : DIO_setDirection
[Description] :This function is responsible for set the direction of external (input or output)
[Args] :
[in] const DIO_Config *s_Config_Msg:
Const pointer to structure to check which port used(A,B,C,D)
[out] set or clear the corresponding bit in the TRIS register depend on external phripheril
-------------------------------------------------------------------------------------------------------------- */	
void DIO_setDirection (const DioConfig *a_sConfigMsg_Ptr);
/* ---------------------------------------------------------------------------------------------------------------
[Function Name] : DIO_writePin
[Description] :This function is responsible for modify the the value on the pin (High or Low)
[Args] :
[in] const DIO_Config *sState_Ptr:
Const pointer to structure to check which port used
[out] 
set or clear the corresponding bit in the PORT(A,B,C,D)
--------------------------------------------------------------------------------------------------------------- */	
void DIO_writePin (const DioConfig *a_sState_Ptr);
/* ---------------------------------------------------------------------------------------------------------------
[Function Name] : DIO_readPin
[Description] :This function is responsible for check the the value on the pin (High or Low)
[Args] :
[in] const DIO_Config *sState_Ptr:
Const pointer to structure to check which port used (A,B,C,D)
[return] 
Logic high or logic low depend on the value on the pin
--------------------------------------------------------------------------------------------------------------- */
uint8 DIO_readPin (const DioConfig *a_sState_Ptr);

#endif /* DIO_H */