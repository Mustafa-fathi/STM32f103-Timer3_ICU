#include "LSTD_TYPES.h"
#include "MAFIO_private .h"
#include "MAFIO_interface.h"




void MAFIO_remap(u32 prephiral)
{
	
	switch(prephiral)
	{
		case TIMER1 :MAFIO ->  AFIO_MAPR |=prephiral; break;
		case TIMER2 :MAFIO -> AFIO_MAPR |= prephiral ;break;
		default: break;
		
		
		
	}
	
	
	
	
}


void MAFIO_external_interrupt_remap(u32 prephiral)
{
	switch (prephiral)
	{
	case MAFIO_PORTA : MAFIO->AFIO_EXTICR1 |=prephiral; break;
	case MAFIO_PORTB : MAFIO->AFIO_EXTICR1 |=prephiral; break;
	case MAFIO_PORTC : MAFIO->AFIO_EXTICR1 |=prephiral; break;
	default :break;


	}
}
