#ifndef MAFIO_PRIVATE_H
#define MAFIO_PRIVATE_H

typedef struct
{
	volatile u32 AFIO_EVCR;
	volatile u32 AFIO_MAPR;
	volatile u32 AFIO_EXTICR1;
	volatile u32 AFIO_EXTICR2;
	volatile u32 AFIO_EXTICR3;
	volatile u32 AFIO_EXTICR4;
	volatile u32 AFIO_MAPR2;
}AFIO_type;

#define MAFIO  ((volatile AFIO_type*) 0x40010000)


#endif
