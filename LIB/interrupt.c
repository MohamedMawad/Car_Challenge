/*
 * interrupt.c
 *
 * Created: 9/27/2019 7:16:53 PM
 *  Author: M_Moawad
 */ 
 
 #include "interrupt.h"
 #include "AVR_REG_LIB.h"
 
 void sei (void)
 {
	SREG |= (1<<7); 
 }
 
 
 void cli (void)
 {
	 SREG &= ~(1<<7);
 }