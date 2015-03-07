/* --------------------------------------------------------------------------------------------------- 
 ** @file    app.c
 ** @brief   app module header file for general use
 ** @author  Madonna Sedky
 ** @date    6/1/2014
 ** @version 1.0
 --------------------------------------------------------------------------------------------------- */


#include "app.h"

void APP_init(void)
{
	/* Initialize LED Driver */
    LED_init();
	
	/* Initialize BUTTON Driver */
   BUTTON_init();
}

/*******************************************************************************************************************/
void APP_start(void)
{
	static uint8 button_previous_state = Button_Released;
	static uint8 button_current_state  = Button_Released;
	
	button_current_state = BUTTON_getState(); /*Read the button state */
	
	/* Only Toggle the led in case the current state of the switch is pressed
	 * and the previous state is released */ 
	if((button_current_state == Button_Pressed) && (button_previous_state ==Button_Released))
	{
		LED_toggle(); 
	}
	
	button_previous_state = button_current_state;
}

/*******************************************************************************************************************/