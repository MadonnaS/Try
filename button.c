 /* --------------------------------------------------------------------------------------------------- 
 ** @file    button.c
 ** @brief   button module header file for general use
 ** @author  Madonna Sedky
 ** @date    6/1/2014
 ** @version 1.0
 --------------------------------------------------------------------------------------------------- */


#include "button.h"
/* Count the number of Pressed times increment if the switch pressed for 20 ms */
 static uint8 g_pressedCount=0;
/* Count the number of Released times increment if the switch released for 20 ms */
 static uint8 g_releasedCount=0;
 /* Button Configurations Structure */
 static DioConfig g_buttonConfig;
/*---------------------------------------------------------------------------------------------------------------
[Function Name] : BUTTON_configurations
[Description] :This funcation is responsible for  fill the Button configurations structure
--------------------------------------------------------------------------------------------------------------- */

 static void BUTTON_configurations(void)
 {
	g_buttonConfig.s_port=Button_Port;/*button port*/
	g_buttonConfig.s_direction=Input;/*button input*/
	g_buttonConfig.s_pinNum=Button_PinNum ;/*button pin*/
	g_buttonConfig.s_value=Button_Released;/*button value*/
 }

/*******************************************************************************************************************/
 void BUTTON_init(void)
 {
	BUTTON_configurations();
	DIO_setDirection(& g_buttonConfig);	
 }

/*******************************************************************************************************************/
 uint8 BUTTON_getState(void)
{
	return 	g_buttonConfig.s_value;
}

/*******************************************************************************************************************/
void BUTTON_refreshState (void)
 {
	 uint8 state =DIO_readPin(& g_buttonConfig);
	if(state == Button_Pressed)
	 {
		 g_pressedCount++;
         g_releasedCount=0;
	 }
     else	 
	 {	 
		 g_releasedCount++;
         g_pressedCount=0;	
	 }
   if(g_pressedCount==3) 
   {
		  g_buttonConfig.s_value=Button_Pressed;
		  g_pressedCount=0;
		  g_releasedCount=0;
   }
   else if(g_releasedCount==3)
   {
	 g_buttonConfig.s_value=Button_Released;
	 g_pressedCount=0;
	 g_releasedCount=0;
   }
   else 
   { 
   } 
 }

/*******************************************************************************************************************/