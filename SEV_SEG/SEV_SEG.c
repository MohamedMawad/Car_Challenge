/*
 * SEV_SEG.c
 *
 * Created: 9/22/2019 9:09:12 PM
 *  Author: M_Moawad
 */ 

#include "SEV_SEG.h"

/*DIPLAY THE NUMBER THAT YOU GIT BY SPLITIING ITS BINNARY
 * EX : ENTER 9
 * BINARY:1001
 * access every bit and & it with 1
 * 1 & 1
 * 0 & 1
 * 0 & 1
 * 1 & 1
 *
 */
Std_Func_t sevseg_Display(uint8_t display_number)
{
	
	Std_Func_t retval = OK;
	uint8_t loop_index = 0;
	uint8_t pin_state = LOW;
	
	if (display_number <= 9)
	{
		for (loop_index = 0; loop_index < NUM_OF_7_segment_PINS; loop_index++)
		{
			pin_state = LOW;
			if (1u&(display_number>>loop_index))
			{
				pin_state = HIGH;
			}
			if (loop_index == 0)
			{
				DIO_write(PORT_B,PIN0,pin_state);
			}
			else if (loop_index == 1)
			{
				DIO_write(PORT_B,PIN1,pin_state);
			}
			else if (loop_index == 2)
			{
				DIO_write(PORT_B,PIN2,pin_state);
			}
			else 
			{
				DIO_write(PORT_B,PIN3,pin_state);
			}
			
		}
	}
	else
	{
		retval = NOK;
	}
	
	return retval;
	
}
