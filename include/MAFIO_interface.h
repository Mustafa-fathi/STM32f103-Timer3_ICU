#ifndef MAFIO_INTERFACE_H
#define MAFIO_INTERFACE_H

#define TIMER1 0x40
#define TIMER2 0x300

#define MAFIO_PORTA 0x0
#define MAFIO_PORTB 0x1
#define MAFIO_PORTC 0x2

void MAFIO_remap(u32 prephiral);
void MAFIO_external_interrupt_remap(u32 prephiral);


#endif
