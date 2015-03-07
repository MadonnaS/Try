/* --------------------------------------------------------------------------------------------------- 
 ** @file    scheduler.c
 ** @brief   scheduler module header file for general use
 ** @author  Madonna Sedky
 ** @date    6/1/2014
 ** @version 1.0
 --------------------------------------------------------------------------------------------------- */
#include "scheduler.h"

static uint8 g_timeTickCount = 0;
static uint8 g_newTimeTickFlag = 0;
 
/*********************************************************************************************/
void SCHEDULER_init(void)
{
	/* 
	 * Set the Call Back function call to Scheduler_New_Timer_Tick 
	 * this function will be called every Timer0 Compare Interrupt(20ms) 
	 */
    TIMER0_setCallBack(SCHEDULER_newTimerTick);
	
	/* Start Timer0 in Compare Mode to generate interrupt every 20ms */ 
	TIMER0_startMode(BASE_TIMER_START); 
} 
/*********************************************************************************************/
void SCHEDULER_newTimerTick(void)
{
	g_timeTickCount += SCHEDULER_BASE_TIME;
	g_newTimeTickFlag = 1;
}
/*********************************************************************************************/
void SCHEDULER_engine(void)
{
	if(g_newTimeTickFlag == 1)
	{
		switch(g_timeTickCount)
		{
			case 20:
			case 100:
			    BUTTON_refreshState ();
				g_newTimeTickFlag= 0;
				break;
			case 40:
			case 80:
				BUTTON_refreshState ();
				LED_refresh();
				g_newTimeTickFlag = 0;
				break;
			case 60:
			    BUTTON_refreshState ();
				APP_start();
		        g_newTimeTickFlag = 0;
				break;
			case 120:
				BUTTON_refreshState ();
				APP_start();
				LED_refresh();
				g_newTimeTickFlag = 0;
		    	g_timeTickCount = 0;	
		}
	}		
}
/*********************************************************************************************/