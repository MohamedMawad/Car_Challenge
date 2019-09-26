/*
 * SEV_SEG.c
 *
 * Created: 9/22/2019 9:09:12 PM
 *  Author: M_Moawad
 */ 

#include "SEV_SEG.h"


Std_Func_t sevseg_Display(uint8 display_number)
{
	
	Std_Func_t retval = OK;
	uint8 loop_index = 0;
	uint8 pin_state = LOW;
	
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
				DIO_write(PORT_C,PIN0,pin_state);
			}
			else if (loop_index == 1)
			{
				DIO_write(PORT_C,PIN1,pin_state);
			}
			else if (loop_index == 2)
			{
				DIO_write(PORT_C,PIN2,pin_state);
			}
			else 
			{
				DIO_write(PORT_C,PIN3,pin_state);
			}
			
		}
	}
	else
	{
		retval = NOK;
	}
	
	return retval;
	
}