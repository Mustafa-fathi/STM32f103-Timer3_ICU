#include "LSTD_TYPES.h"
#include "MNVK_interface.h"
#include "MNVK_private.h"





void MNVK_EnableInt(u8 ID)
{
	if(ID>=0&&ID<=31)
	{
		MNVK -> ISER[0] = (1<<ID);
	}
	else if(ID>=32&&ID<=59)
	{
		ID = ID - 32;
		MNVK -> ISER[1] = (1<<ID);
	}
}

void MNVK_DisableInt(u8 ID)
{
	if(ID>=0&&ID<=31)
	{
		MNVK -> ICER[0] = (1<<ID);
	}
	else if(ID>=32&&ID<=59)
	{
		ID = ID - 32;
		MNVK -> ICER[1] = (1<<ID);
	}
}

void MNVK_SetPendingFlag(u8 ID)
{
	if(ID>=0&&ID<=31)
	{
		MNVK -> ISPR[0] = (1<<ID);
	}
	else if(ID>=32&&ID<=59)
	{
		ID = ID - 32;
		MNVK -> ISPR[1] = (1<<ID);
	}
}

void MNVK_ClearPendingFlag(u8 ID)
{
	if(ID>=0&&ID<=31)
	{
		MNVK -> ICPR[0] = (1<<ID);
	}
	else if(ID>=32&&ID<=59)
	{
		ID = ID - 32;
		MNVK -> ICPR[1] = (1<<ID);
	}
}

void MNVK_SetPriority(void)
{
	/*Disable Nesting*/
	AIRCR = 0x05FA0000;
	/*EXTI0 Interrupt 6 Priority*/
	//MNVK_IPR[6] = 0x10;
	/*EXTI1 Interrupt 7 Priority*/
	//MNVK_IPR[7] = 0x00;
}
