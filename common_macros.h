/* --------------------------------------------------------------------------------------------------- 
 ** @file    common_macros.h
 ** @brief   common macros module header file for this program 
 ** @author  Madonna Sedky
 ** @date    2/1/2014
 ** @version 1.0
 --------------------------------------------------------------------------------------------------- */



#ifndef COMMON_MACROS_H
#define COMMON_MACROS_H
/* ---------------------------------------------------------------------------------------------------------------
[Function Name] : SET_BIT
[Description] :Set a certain bit in any register 
[Args] :
[in] (REG,BIT_NUM):
REG: Register that has pin 
BIT_NUM:number of pin will set 

[out] logic high on the BIT_num

--------------------------------------------------------------------------------------------------------------- */
#define SET_BIT(REG,BIT_NUM) ( REG = REG | (1<<BIT_NUM) ) 
/* ---------------------------------------------------------------------------------------------------------------
[Function Name] : CLEAR_BIT
[Description] : clear a certain bit in any register 
[Args] :
[in] (REG,BIT_NUM):
REG: Register that has pin 
BIT_NUM:number of pin will set 

[out] logic low on the BIT_num

--------------------------------------------------------------------------------------------------------------- */
#define CLEAR_BIT(REG,BIT_NUM) ( REG = REG & (~(1<<BIT_NUM)) ) //clear a certain bit in any register
 /* ---------------------------------------------------------------------------------------------------------------
[Function Name] : BIT_is_set
[Description] : check if any bit is set in any register and return true if yes 
[Args] :
[in] (REG,BIT_NUM):
REG: Register that has pin 
BIT_NUM:number of pin on register 

[return]  true if check pin  result is true 

--------------------------------------------------------------------------------------------------------------- */
#define BIT_IS_SET(REG,BIT_NUM) ( REG & (1<<BIT_NUM) ) 
 /* ---------------------------------------------------------------------------------------------------------------
[Function Name] : BIT_IS_CLEAR
[Description] : //check if any bit is clear in any register and return true if yes 
[Args] :
[in] (REG,BIT_NUM):
REG: Register that has pin 
BIT_NUM:number of pin on register

[return]  true if check pin  result is true 

--------------------------------------------------------------------------------------------------------------- */
#define BIT_IS_CLEAR(REG,BIT_NUM) ( !(REG & (1<<BIT_NUM)) ) 
#define toggle
#endif /* COMMON_MACROS_H */
