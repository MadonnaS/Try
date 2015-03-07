/* --------------------------------------------------------------------------------------------------- 
 ** @file    timer0.h
 ** @brief   timer0 module header file for this program 
 ** @author  Madonna Sedky
 ** @date    6/1/2014
 ** @version 1.0
 --------------------------------------------------------------------------------------------------- */




#ifndef TIMER0_H
#define TIMER0_H
#include <timers.h>
#include "std_type.h"
/*---------------------------------------------------------------------------------------------------------------
[Function Name] :  TIMER0_startMode
[Description] :This funcation is responsible for 1. Initialize Timer0 HW Driver to run in CTC Mode
 	                                         2. Set timer0 on in 16bit and loaded it by init value
[Args] :
[in] uint16 a_tickTime:
 initilization value to start the timer at it (65536-20*1000)

--------------------------------------------------------------------------------------------------------------- */
void TIMER0_startMode(uint16 a_initTime);
/*---------------------------------------------------------------------------------------------------------------
[Function Name] :   TIMER0_setCallBack
[Description] :This funcation is responsible for Points to the required function in the OS upper layer Scheduler
[in] void (*Ptr2Func)(void):Pointer to the required function
--------------------------------------------------------------------------------------------------------------- */


void TIMER0_setCallBack(void (*Ptr2Func)(void));

#endif /* TIMER0_H */