/*
 * main.c
 *
 *  Created on: Oct 25, 2018
 *      Author: Hampota
 *
 *      title : INPUT CAPTURE
 *
 * description:-we will use input capture from Timer3 channel 1 (PA6)to measure the PWM of TIMER2 channel1 (PA0)
 * in input capture channel 1 the signal(T1) divided into 2 signals (IC1),(IC2)
 * so we will make IC1 on rising edge to calculate periodic time
 * and store it in(CCR1)
 * and use IC2 on falling edge to calculate duty cycle
 * and store it in(CCR2)
 * take care we will also us IC1 to reset mode
 * to reset all registers CCR1,CCR2,CCR3,CCR4
 *
 * we will also use DMA1 channel6 why?
 *  we watch on DMA (documentation)that TIMER3 channel1
 *  go through DMA1 channel 6
 *  we will use DMA to read registers (CCR1),(CCR2)
 *
 */

#include "LSTD_TYPES.h"
#include "MGENERAL_PURPOSE_TIMER_INPUT_CAPTURE_interface.h"
#include "MSTK_interface.h"
#include "MDIO_interface.h"
#include "MNVK_interface.h"
#include "MRCC_interface.h"
 f32 frequency1=0;
 u32 distance ;
void main(void)
{

MRCC_Initialize();

MRCC_EnableClock(BUS_ABP1,PERIPHERAL_TIMER3);
MRCC_EnableClock(BUS_ABP2,PERIPHERAL_AFIO);
MRCC_EnableClock(BUS_ABP2,PERIPHERAL_GPIOA);


MDIO_Initialize();
MDIO_SetPinValue(MDIO_PORTA,6,0);     //P6 "ICU" pull down

MSTK_Intialization();



//MDMA_Intialize();

MDIO_clr_pin(MDIO_PORTA,1);


MTIMER3_INPUT_CAPTURE_Initialize(); //input capture on PA6

//MDMA_Ch1Start(&TIMER3->TIMx_DMAR , &CCR.CCR1);
//(TIMER3->TIMx_CCR1 >0) ||


MDIO_clr_pin(MDIO_PORTA,2);
MDIO_clr_pin(MDIO_PORTA,3);

while(1)
    {


	// set the signal on the trigger pin on ultrasonic
	MDIO_set_pin(MDIO_PORTA,1);
	MSTK_delay_micro(10);   //delay 10 microsecond
	MDIO_clr_pin(MDIO_PORTA,1);


	// now we will receive the signal on Echo pin on the hand Input capture unit 'PA6'
	frequency1=measurePWM();
    // distance = (u32)frequency1;
    distance=(frequency1/2)* 0.034029;
    if ((distance >=0 ) && (distance < 50))
    {

    	MDIO_set_pin(MDIO_PORTA,3);
    	MDIO_clr_pin(MDIO_PORTA,2);
    }

    else if(distance > 50)
    {
    	//MDIO_set_pin(MDIO_PORTA,2);

    	MDIO_clr_pin(MDIO_PORTA,2);
    	MDIO_clr_pin(MDIO_PORTA,3);
    }

    else
      {
      	MDIO_set_pin(MDIO_PORTA,2);
      //	MDIO_set_pin(MDIO_PORTA,3);
      }


    }

}
