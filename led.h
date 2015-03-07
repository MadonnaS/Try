/* --------------------------------------------------------------------------------------------------- 
 ** @file    led.h
 ** @brief   led module header file for this program 
 ** @author  Madonna Sedky
 ** @date    6/1/2014
 ** @version 1.0
 --------------------------------------------------------------------------------------------------- */




#ifndef LED_H
#define LED_H

#include "dio.h"
/* Set the led ON/OFF according to its configuration Positive logic or negative logic */
#define  LED_ON LogicHigh
#define  LED_OFF LogicLow
/* Set the LED Port */
#define  LED_Port 'C'

/* Set the LED Pin Number */
#define  LED_PinNum 5

/* ---------------------------------------------------------------------------------------------------------------
[Function Name] : LED_init
[Description] :This funcation is responsible /* Description: 1. fill the led configurations structure
 *                                                           2. set the PIN direction which the led is connected to OUTPUT
 				                             3. Initialize the led ON/OFF according to the initial value

-------------------------------------------------------------------------------------------------------------- */	

void LED_init(void);
/* ---------------------------------------------------------------------------------------------------------------
[Function Name] : LED_setON
[Description] :This funcation is responsible for   Set the LED state to ON
-------------------------------------------------------------------------------------------------------------- */

void LED_setON(void);
/* ---------------------------------------------------------------------------------------------------------------
[Function Name] : LED_toggle
[Description] :This function is responsible for   Toggle the LED state
-------------------------------------------------------------------------------------------------------------- */

void LED_toggle(void);
/* ---------------------------------------------------------------------------------------------------------------
[Function Name] : LED_refresh
[Description] :This function is responsible for  Refresh the LED state
-------------------------------------------------------------------------------------------------------------- */
void LED_refresh(void);
/* ---------------------------------------------------------------------------------------------------------------
[Function Name] : LED_setOFF
[Description] :This function is responsible for  Set the LED state to OFF
-------------------------------------------------------------------------------------------------------------- */

void LED_setOFF(void);



#endif /* LED_H */