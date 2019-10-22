#ifndef MGENERAL_PURPOSE_TIMER_INPUT_CAPTURE_interface_H
#define MGENERAL_PURPOSE_TIMER_INPUT_CAPTURE_interface_H


void MTIMER3_INPUT_CAPTURE_Initialize(void);
void setCallBack(void(*ptr)(void));
u32 measurePWM(void );

#endif
