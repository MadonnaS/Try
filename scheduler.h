/* --------------------------------------------------------------------------------------------------- 
 ** @file    scheduler.h
 ** @brief   scheduler module header file for this program 
 ** @author  Madonna Sedky
 ** @date    6/1/2014
 ** @version 1.0
 --------------------------------------------------------------------------------------------------- */



#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "button.h"
#include "led.h"
#include "app.h"
#include "timer0.h"
#include "std_type.h"
/* Timer counting time in ms */
#define SCHEDULER_BASE_TIME 20 /*each 20ms*/
/*To determine the initalization value for timer to count 20ms 1-find max no. in 16bit timer =65536
                                                        2-find 20ms represented by 20000 steps
 *                                                      3-start the timer from (65536-20*1000)
 *                                                      4- so it will count untill reach 0 (overflow) then loadded again */
#define BASE_TIMER_START (65536-(20*1000))

/* ---------------------------------------------------------------------------------------------------------------
[Function Name] : SCHEDULER_init
[Description] :This function  is responsible for  Initialize the Scheduler
-------------------------------------------------------------------------------------------------------------- */
void SCHEDULER_init(void);
/* ---------------------------------------------------------------------------------------------------------------
[Function Name] : SCHEDULER_engine
[Description] :This function is responsible for switch between different tasks
-------------------------------------------------------------------------------------------------------------- */

void SCHEDULER_engine(void);
/* ---------------------------------------------------------------------------------------------------------------
[Function Name] : SCHEDULER_newTimerTick
[Description] :This function called by the Timer Driver in the MCAL layer using the call back pointer
-------------------------------------------------------------------------------------------------------------- */

void SCHEDULER_newTimerTick(void);

#endif /* SCHEDULER_H_ */