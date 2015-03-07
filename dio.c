/* --------------------------------------------------------------------------------------------------- 
 ** @file    dio.c
 ** @brief   dio module header file for general use
 ** @author  Madonna Sedky
 ** @date    6/1/2014
 ** @version 1.0
 --------------------------------------------------------------------------------------------------- */


#include "dio.h"
/******************************************************************************************************************/
void DIO_setDirection (const DioConfig *a_sConfigMsg_Ptr)
{
	volatile uint8* TRIS_Ptr;/* point to the required TRIS Register to check which port used */
	switch (a_sConfigMsg_Ptr->s_port)/* switch by using pointer to structure */
	{
		case 'A':
		 TRIS_Ptr=&TRISA;
		 break;
		case 'B':
		 TRIS_Ptr=&TRISB;
		 break;
		case 'C':
		 TRIS_Ptr=&TRISC;
		 break;
	   case 'D':
		 TRIS_Ptr=&TRISD;
		 break;
default: TRIS_Ptr=&TRISE;
	}
    /* set the corresponding bit in the TRIS register to configure it as input pin*/
	if (a_sConfigMsg_Ptr->s_direction==Input)
	{
		SET_BIT(*TRIS_Ptr,a_sConfigMsg_Ptr->s_pinNum);
	}
	else if (a_sConfigMsg_Ptr->s_direction==Output)
	{
/* clear the corresponding bit in the TRIS register to configure it as output pin*/
		CLEAR_BIT(*TRIS_Ptr,a_sConfigMsg_Ptr->s_pinNum);
	}
    else
   { 
   } 

}
/******************************************************************************************************************/
void DIO_writePin(const DioConfig *a_sState_Ptr)
{
  /* point to the required PORT Register to check which port used and then write in Bitnum at register */
	volatile uint8* PORT_Ptr;
	switch (a_sState_Ptr->s_port)
	{
		case 'A':
		PORT_Ptr=&PORTA;
		break;
		case 'B':
		PORT_Ptr=&PORTB;
		break;
		case 'C':
		PORT_Ptr=&PORTC;
		break;
		case 'D':
		PORT_Ptr=&PORTD;
		break;
        default: PORT_Ptr = &PORTE;
	}
	if (a_sState_Ptr->s_value==LogicHigh)
	{
       /*set the corresponding pin in the PORT register*/
		SET_BIT(*PORT_Ptr,a_sState_Ptr->s_pinNum);
	}
	else if (a_sState_Ptr->s_value==LogicLow)
	{
       /*clear the corresponding pin in the PORT register*/
		CLEAR_BIT(*PORT_Ptr,a_sState_Ptr->s_pinNum);
	}
    else
    {
    }
}

/******************************************************************************************************************/
uint8 DIO_readPin(const DioConfig *a_sState_Ptr)
{   
	uint8  out;
   	volatile uint8* PORT_Ptr; /* point to the required PORT Register to check which port used and then read value in it*/
	switch (a_sState_Ptr->s_port)
	{
		case 'A':
		PORT_Ptr=&PORTA;
		break;
		case 'B':
		PORT_Ptr=&PORTB;
		break;
		case 'C':
		PORT_Ptr=&PORTC;
		break;
		case 'D':
		PORT_Ptr=&PORTD;
		break;
        default: PORT_Ptr = &PORTE;

	}
if (BIT_IS_SET(*PORT_Ptr,a_sState_Ptr->s_pinNum))
	{/*check if the corresponding bit is set in the PORT registe*/
	     out=LogicHigh;	
	}
	else if(BIT_IS_CLEAR(*PORT_Ptr,a_sState_Ptr->s_pinNum))
	{/*check if the corresponding bit is clear in the PORT registe*/
		out=LogicLow;
	}
    else 
    {
    } 
return out ;
} 