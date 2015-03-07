/* --------------------------------------------------------------------------------------------------- 
 ** @file    app.h
 ** @brief   app module header file for this program 
 ** @author  Madonna Sedky
 ** @date    6/1/2014
 ** @version 1.0
 --------------------------------------------------------------------------------------------------- */





#ifndef APP_H
#define APP_H

#include "button.h"
#include "led.h"
/*---------------------------------------------------------------------------------------------------------------
[Function Name] :  APP_init
[Description] : This function is responsible for init application (led&Button)
--------------------------------------------------------------------------------------------------------------- */

void APP_init(void);
/*---------------------------------------------------------------------------------------------------------------
[Function Name] :  APP_start
[Description] : This function is responsible for start the application by check the button and toggle the led if it stat pressed
--------------------------------------------------------------------------------------------------------------- */
void APP_start(void);


#endif /* APP_H */