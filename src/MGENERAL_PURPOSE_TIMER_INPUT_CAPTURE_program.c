#include "LSTD_TYPES.h"
#include "MGENERAL_PURPOSE_TIMER_INPUT_CAPTURE_private.h"
#include "MGENERAL_PURPOSE_TIMER_INPUT_CAPTURE_interface.h"

/*
T1---->IC1 (no-prescaler)(no-filtering)(rising edge)
T1---->IC2 (no-prescaler)(no-filtering)(falling edge)

*/


 u32 frequency=0;

void MTIMER3_INPUT_CAPTURE_Initialize(void)
{


    TIMER3 -> TIMx_PSC=7999 ; //8MHZ(8,000,000)  PSC=7999+1  -> 8000,000 /8000 	 =1000HZ =1ms
	TIMER3 -> TIMx_ARR =0xffff;   //
    TIMER3 ->TIMx_CNT=0; //clear counter

	// IC1 mapped Tl1 and configured as input 
	TIMER3 -> TIMx_CCMR1|=1;
	TIMER3 -> TIMx_CCMR1&=~(1<<1);
	
	//there is no filtering on IC1
	/*
	TIMER3 -> TIMx_CCMR1 &=~(1<<4);
	TIMER3 -> TIMx_CCMR1 &=~(1<<5);
	TIMER3 -> TIMx_CCMR1 &=~(1<<6);
	TIMER3 -> TIMx_CCMR1 &=~(1<<7);
	*/
	//rising edge polarity on IC1
	TIMER3 -> TIMx_CCER &=~(1<<1);
	
	//no-prescaler on IC1
	/*
	TIMER3 -> TIMx_CCMR1 &=~(1<<2);
	TIMER3 -> TIMx_CCMR1 &=~(1<<3);
	////////
	*/
	// IC2 mapped Tl1 and configured as input 
	TIMER3 -> TIMx_CCMR1&=~(1<<8);
	TIMER3 -> TIMx_CCMR1|=(1<<9);
	
	//there is no filtering on IC2
	/*
	TIMER3 -> TIMx_CCMR1 &=~(1<<12);
	TIMER3 -> TIMx_CCMR1 &=~(1<<13);
	TIMER3 -> TIMx_CCMR1 &=~(1<<14);
	TIMER3 -> TIMx_CCMR1 &=~(1<<15);
	*/
	//falling edge polarity on IC2
	TIMER3 -> TIMx_CCER |=(1<<5);
	
	//no-prescaler on IC2
	/*
	TIMER3 -> TIMx_CCMR1 &=~(1<<10);
	TIMER3 -> TIMx_CCMR1 &=~(1<<11);
	*/
	////////////////////////////////
	//timer3 cinfiguration mode
	//we will select T1FP1 (filtered input capture channel 1)(rising edge)to trigger
    	
	TIMER3 -> TIMx_SMCR |=(1<<4);
	TIMER3 -> TIMx_SMCR &=~(1<<5);
	TIMER3 -> TIMx_SMCR |=(1<<6);
	
	//select reset mode
	TIMER3 -> TIMx_SMCR &=~(1<<0);
	TIMER3 -> TIMx_SMCR &=~(1<<1);
	TIMER3 -> TIMx_SMCR |=(1<<2);

	//enable capture compare generation
//	TIMER3 ->TIMx_EGR |=(1<<1);

	/////////////////////////////////
	/* -->
	//timer3 MDMA configurations
	/*we want DMA to read from 2 registers (CCR1)(CCR2)
	 *so we will send the base address of CCR1
	 *and make 2 transfer to enable DMA
	 *to read also CCR2
	 * */

	/*13-> is the base address of (CCR1) that the DMA will start to read from it
	 * we obtain 13 from register map of timers
	*/ /* -->
	TIMER3 ->TIMx_DCR |=13;

	//making 2 transfers
	TIMER3 ->TIMx_DCR |=1;



	//enable DMA request on capture compare 1
	TIMER3 ->TIMx_DIER |=(1<<9);
	*/ //--->
	//////////////////////////////////////////////


	//enable capture compare 1 (CCR1) will contain the value
	TIMER3 -> TIMx_CCER |=1;
	//enable capture compare 2 (CCR2) will contain the value
	TIMER3 -> TIMx_CCER |=(1<<4);

	//enable counter
	TIMER3 -> TIMx_CR1 |= 0x1;
	

}

u32 measurePWM(void)
{
	frequency = 0 ;

	while (((TIMER3 ->TIMx_SR) <<1 ==0) && ((TIMER3 ->TIMx_SR )<<2 ==0));  //wait until signal captured

	//clearing the flags
	TIMER3 ->TIMx_SR &=~(1<<1);
	TIMER3 ->TIMx_SR &=~(1<<2);


	frequency = (TIMER3->TIMx_CCR2) - (TIMER3 -> TIMx_CCR1);









	return frequency;
}

