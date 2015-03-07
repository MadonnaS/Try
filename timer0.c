/* --------------------------------------------------------------------------------------------------- 
 ** @file    timer0.c
 ** @brief   timer0 module header file for general use
 ** @author  Madonna Sedky
 ** @date    6/1/2014
 ** @version 1.0
 --------------------------------------------------------------------------------------------------- */





#include "timer0.h"
#include <xc.h>

/* Global pointer to function used to point upper layer functions
  to be used in Call Back */
static void (*g_timer0CallBack_Ptr)(void);
/*global variable to save the inialization value of timer0 */
static uint16 g_initTime;
/*********************************************************************************************/ 
void TIMER0_startMode(uint16 a_initTime)
{

     T0CON=0;/*timer zero comtrol register all bits equal zero
                                          1-T08BIT >> to be 16 bit
                                          2-T0CS   >> Internal instruction cycle clock*/
     T0CON =(1<<3) ;/*BIT 3  >> PSA not assigned prescaler*/
     INTCON=(1<<5)|(1<<7);/*Bit 5 >>T0IE to enable interrupt at tiomer 0
                           Bit 7 >>GIE global interrupt enable bit*/
	 
   
    g_initTime=a_initTime;
    TMR0L=(uint8)(a_initTime);/*intialization of timer*/
    TMR0H=(uint8)(a_initTime>>8);
    T0CON=(1<<7);/*bit 7>>TMR0ON turn on timer*/
   	


}
/*********************************************************************************************/
void TIMER0_setCallBack(void(*Ptr2Func)(void))
{
	g_timer0CallBack_Ptr = Ptr2Func;
}
/*********************************************************************************************/
/* Interrupt Service Routine for Timer0 compare mode */
void interrupt timer0_ISR()
{
     /*bit 5 at INTCON T0IE to enable interrupt at timer
      *bit 2 to check T0IF flag of interrupt*/
     if((INTCON&(1<<5))&&(INTCON&(1<<2)))
     {
          INTCON&=(~(1<<2));
          TMR0L=(uint8)(g_initTime);
          TMR0H=(uint8)(g_initTime>>8);
	  (*g_timer0CallBack_Ptr)(); /*call the function in the scheduler using call-back concept*/
     }


}
/*********************************************************************************************/