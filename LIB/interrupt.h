/*
 * interrupt.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: M_MOAWAD
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_


void __vector_1  (void) __attribute__((signal,__INTR_ATTRS));
void __vector_2  (void) __attribute__((signal,__INTR_ATTRS));
void __vector_3  (void) __attribute__((signal,__INTR_ATTRS));
void __vector_4  (void) __attribute__((signal,__INTR_ATTRS));
void __vector_5  (void) __attribute__((signal,__INTR_ATTRS));
void __vector_6  (void) __attribute__((signal,__INTR_ATTRS));
void __vector_7  (void) __attribute__((signal,__INTR_ATTRS));
void __vector_8  (void) __attribute__((signal,__INTR_ATTRS));
void __vector_9  (void) __attribute__((signal,__INTR_ATTRS));
void __vector_10 (void) __attribute__((signal,__INTR_ATTRS));
void __vector_11 (void) __attribute__((signal,__INTR_ATTRS));
void __vector_12 (void) __attribute__((signal,__INTR_ATTRS));
void __vector_13 (void) __attribute__((signal,__INTR_ATTRS));
void __vector_14 (void) __attribute__((signal,__INTR_ATTRS));
void __vector_15 (void) __attribute__((signal,__INTR_ATTRS));
void __vector_16 (void) __attribute__((signal,__INTR_ATTRS));
void __vector_17 (void) __attribute__((signal,__INTR_ATTRS));
void __vector_18 (void) __attribute__((signal,__INTR_ATTRS));
void __vector_19 (void) __attribute__((signal,__INTR_ATTRS));
void __vector_20 (void) __attribute__((signal,__INTR_ATTRS));

#define ISR_INT0		 __vector_1 
#define ISR_INT1		 __vector_2
#define ISR_INT2		 __vector_3 
#define ISR_TIMER2_COMP  __vector_4
#define ISR_TIMER2_OVF   __vector_5 
#define ISR_TIMER1_CAPT  __vector_6 
#define ISR_TIMER1_COMPA __vector_7 
#define ISR_TIMER1_COMPB __vector_8 
#define ISR_TIMER1_OVF   __vector_9 
#define ISR_TIMER0_COMP  __vector_10 
#define ISR_TIMER0_OVF   __vector_11 
#define ISR_SPI_STC      __vector_12 
#define ISR_USART_RXC    __vector_13 
#define ISR_USART_UDRE   __vector_14
#define ISR_USART_TXC    __vector_15 
#define ISR_ADC          __vector_16 
#define ISR_EE_RDY       __vector_17 
#define ISR_ANA_COMP     __vector_18 
#define ISR_TWI          __vector_19 
#define ISR_SPM_RDY      __vector_20 


void sei (void);

void cli (void);

#endif /* INTERRUPT_H_ */
