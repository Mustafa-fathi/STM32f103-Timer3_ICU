
#include "LSTD_TYPES.h"

#include "MSTK_interface.h"

#include "MSTK_private.h"


void (* MSTK_CallBack)(void);    //pointer to function 

void SysTick_Handler(void)// interrupt void and return void because it executed by hardware and hardware doesnt take any thing
{
	
	MSTK_CallBack();
}
//take care if there is an interrupt fired after firing systick_handeler callback will jump to garbage location
// so itis recomendded to make call_back function before initialization in main()

void MSTK_SetCallBack(void(*ptr)(void))  //take pointer to function
{
	
	MSTK_CallBack=ptr;   
}
/*
 * take we make in the CTRL register = 3 in this case the frequency = 8mhz/8
 * so the new one that will operate the systick = 1mhz
 * */

void MSTK_Intialization(void)
{
	MSTK -> CTRL |=(1<<1);  /*down counting mode*/
	//MSTK -> VAL =1000000;     //1sec
//	MSTK -> LOAD=1000000;
	
	
}

/*
 * will return the current value of the SYStick timer and reset it
 * */
u32 MSTK_get_Value(void)
{
	u32 MSTK_current_value = MSTK->VAL;

	return MSTK_current_value;

}

void MSTK_Enable_systick(void)
{
	MSTK ->CTRL |=1;   //enable counter
}

void MSTK_Disable_systick(void)
{
	MSTK ->CTRL &=~1;   //disable counter

}

/*
 * we want to make a delay with 10 micro second
 * as we make SYSTICK work on 1 mhz
 * so LOAD register should hold this value = 10 micro_second * 1mhz = 10
 *
 * */
void MSTK_delay_micro(u32 period)
{

	MSTK->VAL=232;     //any value will reset the timer
	MSTK ->LOAD=period;   /*this register hold the value that will specify the start value that will loaded into VAL register*/


}


