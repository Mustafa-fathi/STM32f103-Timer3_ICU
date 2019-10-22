#ifndef _MSTK_interface_h
#define _MSTK_interface_h

void MSTK_Intialization(void);
void  MSTK_SetCallBack(void(*ptr)(void));
//we didnt have to make prototype for systick_handler because it is an interrupt and noone can control or interface it


u32 MSTK_get_Value(void);
void MSTK_Enable_systick(void);
void MSTK_Disable_systick(void);

void MSTK_delay_micro(u32);


#endif
