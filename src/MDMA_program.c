#include "LSTD_TYPES.h"
#include "MDMA_interface.h"
#include "MDMA_private.h"
//now DMA operates at speed of AHP

/*
 * peripheral--->registers of timer
 * memory---> variable that created by me
 * take care:- TIMER3 channel 1 exisit on MDMA1 channel 6
 * we need MDMA1 channel 6 to read data from TIMER3 (CCR1,CCR2)
 * because (CCR1) will contain the time that the pulse on rising
 * because (CCR2) will contain the time that the pulse on falling
 *
 *
 *
 *
 * */


void MDMA_Intialize(void)
{
	//pirioty of channel is very high
	MDMA1 -> DMA_CCR6 |=(1<<12);
	MDMA1 -> DMA_CCR6 |=(1<<13);
	
	//memory size -->(structure variable that contains the periodic and duty cycle time  )
	//16-bit
	MDMA1 -> DMA_CCR6 |=(1<<10);
	MDMA1 -> DMA_CCR6 &=~(1<<11);

	//peripheral size --> registers of timer3(CCR1,CCR2)
	//16-bit
	MDMA1 -> DMA_CCR6 |=(1<<8);
	MDMA1 -> DMA_CCR6 &=~(1<<9);

	//enable memory increment
	MDMA1 -> DMA_CCR6 |=(1<<7);

	//enable circular mode
	MDMA1 -> DMA_CCR6 |=(1<<5);

	//read from peripheral(timer3 registers)
	MDMA1 -> DMA_CCR6 &=~(1<<4);

	//number of data to transfer
	//we have 2 registers we want to transfer it's data
	MDMA1 -> DMA_CNDTR6 =2;

	
	


}

//source -->2 registers of TIMER3
// destination -->structure variable

void MDMA_Ch1Start(u32 source , u32 destination)
{
	MDMA1 -> DMA_CPAR6 = (u32)source;   //we make casting beacuse source is pointer and we cant put pointer to varialble
	
	MDMA1 -> DMA_CMAR6=(u32)destination;
	
	MDMA1 -> DMA_CCR6 |=1; //we enable channel 6
}
