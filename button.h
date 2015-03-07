/* --------------------------------------------------------------------------------------------------- 
 ** @file    button.h
 ** @brief   button module header file for this program 
 ** @author  Madonna Sedky
 ** @date    6/1/2014
 ** @version 1.0
 --------------------------------------------------------------------------------------------------- */




#ifndef BUTTON_H
#define BUTTON_H

#include "dio.h"
/* Button State according to its configuration PULL UP/Down */
#define Button_Pressed  LogicHigh
#define Button_Released LogicLow
/* Set the Button Port */
#define Button_Port 'B'

/* Set the Button Pin Number */
#define Button_PinNum 0
/*---------------------------------------------------------------------------------------------------------------
[Function Name] :    BUTTON_getState
[Description] :This funcation is responsible for Read the Button state Pressed/NOT Pressed 
[return] the state of the button
--------------------------------------------------------------------------------------------------------------- */

uint8 BUTTON_getState(void);
/*---------------------------------------------------------------------------------------------------------------
[Function Name] :    BUTTON_init
[Description] : 1. fill the button configurations structure 
                            2. set the PIN direction which the button is connected to INPUT
--------------------------------------------------------------------------------------------------------------- */

void BUTTON_init(void);
/*---------------------------------------------------------------------------------------------------------------
[Function Name] :    BUTTON_refreshState
[Description] : This function is called every 20ms by Scheduler and it responsible for Updating 
                the BUTTON State. it should be in a PRESSED State if the button is pressed for 60ms.
                 and it should be in a RELEASED State if the button is released for 60ms.
--------------------------------------------------------------------------------------------------------------- */

void BUTTON_refreshState (void);

#endif /* BUTTON_H */