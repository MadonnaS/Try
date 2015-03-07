/* --------------------------------------------------------------------------------------------------- 
 ** @file    project.c
 ** @brief   project module header file for general use
 ** @author  Madonna Sedky
 ** @date    6/1/2014
 ** @version 1.0
 --------------------------------------------------------------------------------------------------- */



#include "app.h"
#include "scheduler.h"

int main(void)
{
	/* Initialize Application --> LED and Button in the HWAL */
    APP_init();
	
	/* Initialize Scheduler */
	SCHEDULER_init();

	while(1)
    {
	SCHEDULER_engine();
	}
}