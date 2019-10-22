#ifndef MRCC_INTEFACE_H
#define MRCC_INTEFACE_H

#define BUS_AHB         5
#define BUS_ABP1        7
#define BUS_ABP2        29

#define PERIPHERAL_DMA1 1
#define PERIPHERAL_DMA2 2

#define PERIPHERAL_GPIOA 0x04
#define PERIPHERAL_GPIOB 0x08
#define PERIPHERAL_GPIOC 0x16

#define PERIPHERAL_TIMER1 0x800
#define PERIPHERAL_TIMER2 0x01
#define PERIPHERAL_TIMER3 0x02
#define PERIPHERAL_AFIO 0x1

void MRCC_Initialize(void);
void MRCC_EnableClock(u8 Bus, u8 Peripheral);
void MRCC_DisableClock(u8 Bus, u8 Peripheral);

#endif
