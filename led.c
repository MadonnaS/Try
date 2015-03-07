/* --------------------------------------------------------------------------------------------------- 
 ** @file    led.c
 ** @brief   led module header file for general use
 ** @author  Madonna Sedky
 ** @date    6/1/2014
 ** @version 1.0
 --------------------------------------------------------------------------------------------------- */



#include "led.h"

/* LED Configurations Structure */
static DioConfig g_ledConfig;
/*---------------------------------------------------------------------------------------------------------------
[Function Name] : LED_configurations
[Description] :This funcation is responsible for  fill the LED configurations structure
--------------------------------------------------------------------------------------------------------------- */
static void LED_configurations(void)
{
	g_ledConfig.s_port=LED_Port;/*led port*/
	g_ledConfig.s_direction=Output;/*led output*/
	g_ledConfig.s_pinNum=LED_PinNum ;/*led pin*/
	g_ledConfig.s_value=LED_OFF;/*led intial value*/
}
/*********************************************************************************************/
void LED_init(void)
{
	LED_configurations();/*fill the g_LED_Config structure with the led configurations*/
	DIO_setDirection(& g_ledConfig);/*set the direction of the LED */
	DIO_writePin(& g_ledConfig);/*set the Default value (initial value)*/
}
/*********************************************************************************************/
void LED_setON(void)
{
	g_ledConfig.s_value=LED_ON;
	DIO_writePin(&g_ledConfig);
}
/*********************************************************************************************/
void LED_setOFF(void)
{
	g_ledConfig.s_value=LED_OFF;
	DIO_writePin(&g_ledConfig);
}
/*********************************************************************************************/
void LED_toggle(void)
 {
	 
	 if(g_ledConfig.s_value==LED_OFF)
	 {
	   LED_setON();
	 }
	 else if(g_ledConfig.s_value==LED_ON)
	 {
		LED_setOFF();
	 }
         else
         {
         }
	   
 }
/*********************************************************************************************/
 
void LED_refresh(void)
{
	DIO_writePin(&g_ledConfig);
}
/*********************************************************************************************/