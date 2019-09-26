/*
 * AVR_REG_LIB.h
 *
 * Created: 9/20/2019 10:05:36 PM
 *  Author: M_Moawad
 */ 



#ifndef AVR_REG_LIB_H_
#define AVR_REG_LIB_H_

//testing with delay
#include <util/delay.h>

//must be included without any ready made libraries 
//#include "data_types.h"


/* 0x5F SREG */
#define SREG   (*(volatile uint8_t *)0x5F)

/* 0x5D..0x5E SP */
#define SPH   (*(volatile uint8_t *)0x5E)
#define SPL   (*(volatile uint8_t *)0x5D)

/* Timer 0 */
#define OCR0   (*(volatile uint8_t *)0x5C)

#define GICR   (*(volatile uint8_t *)0x5B)
#define GIFR   (*(volatile uint8_t *)0x5A)

#define TIMSK  (*(volatile uint8_t *)0x59)

#define TIFR   (*(volatile uint8_t *)0x58)

#define SPMCR  (*(volatile uint8_t *)0x57)

#define TWCR   (*(volatile uint8_t *)0x56)

#define MCUCR  (*(volatile uint8_t *)0x55)
#define MCUCSR (*(volatile uint8_t *)0x54)

#define TCCR0  (*(volatile uint8_t *)0x53)
#define TCNT0  (*(volatile uint8_t *)0x52)

/* Timer 1 */
#define OSCCAL (*(volatile uint8_t *)0x51)
#define OCDR   OSCCAL

#define SFIOR  (*(volatile uint8_t *)0x50)

#define TCCR1A (*(volatile uint8_t *)0x4F)
#define TCCR1B (*(volatile uint8_t *)0x4E)
#define TCNT1H (*(volatile uint8_t *)0x4D)
#define TCNT1L (*(volatile uint8_t *)0x4C)
#define OCR1AH (*(volatile uint8_t *)0x4B)
#define OCR1AL (*(volatile uint8_t *)0x4A)
#define OCR1BH (*(volatile uint8_t *)0x49)
#define OCR1BL (*(volatile uint8_t *)0x48)
#define ICR1H  (*(volatile uint8_t *)0x47)
#define ICR1L  (*(volatile uint8_t *)0x46)


/* Timer 2 */
#define TCCR2  (*(volatile uint8_t *)0x45)
#define TCNT2  (*(volatile uint8_t *)0x44)
#define OCR2   (*(volatile uint8_t *)0x43)

/* EEPROM Address Register */
#define ASSR   (*(volatile uint8_t *)0x42)

#define WDTCR  (*(volatile uint8_t *)0x41)

#define UBRRH  (*(volatile uint8_t *)0x40)
#define UCSRC  UBRRH

#define EEARH  (*(volatile uint8_t *)0x3F)
#define EEARL  (*(volatile uint8_t *)0x3E)

/* EEPROM Data Register */
#define EEDR   (*(volatile uint8_t *)0x3D)

/* EEPROM Control Register */
#define EECR   (*(volatile uint8_t *)0x3C)


/* Port A */
#define PORTA  (*(volatile uint8_t *)0x3B)
#define DDRA   (*(volatile uint8_t *)0x3A)
#define PINA   (*(volatile uint8_t *)0x39)


/* Port B */
#define PORTB  (*(volatile uint8_t *)0x38)
#define DDRB   (*(volatile uint8_t *)0x37)
#define PINB   (*(volatile uint8_t *)0x36)


/* Port C */
#define PORTC  (*(volatile uint8_t *)0x35)
#define DDRC   (*(volatile uint8_t *)0x34)
#define PINC   (*(volatile uint8_t *)0x33)


/* Port D */
#define PORTD  (*(volatile uint8_t *)0x32)
#define DDRD   (*(volatile uint8_t *)0x31)
#define PIND   (*(volatile uint8_t *)0x30)


/* SPI */
#define SPDR   (*(volatile uint8_t *)0x2F)
#define SPSR   (*(volatile uint8_t *)0x2E)
#define SPCR   (*(volatile uint8_t *)0x2D)

/* USART */
#define UDR    (*(volatile uint8_t *)0x2C)
#define UCSRA  (*(volatile uint8_t *)0x2B)
#define UCSRB  (*(volatile uint8_t *)0x2A)
#define UBRRL  (*(volatile uint8_t *)0x29)

/* analog comparator */
#define ACSR   (*(volatile uint8_t *)0x28)


/* ADC */
#define ADMUX  (*(volatile uint8_t *)0x27)
#define ADCSRA (*(volatile uint8_t *)0x26)
#define ADCH   (*(volatile uint8_t *)0x25)
#define ADCL   (*(volatile uint8_t *)0x24)

/* TWI stands for "Two Wire Interface" or "TWI Was I2C(tm)" */
#define TWDR   (*(volatile uint8_t *)0x23)
#define TWAR   (*(volatile uint8_t *)0x22)
#define TWSR   (*(volatile uint8_t *)0x21)
#define TWBR   (*(volatile uint8_t *)0x20)



#endif /* AVR_REG_LIB_H_ */
