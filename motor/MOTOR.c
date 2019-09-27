/*
 * MOTOR.c
 *
 * Created: 9/26/2019 6:46:40 PM
 *  Author: M_Moawad
 */ 

#include "MOTOR.h"


Std_Func_t motor_On(uint8_t motor_num, uint8_t motor_direction)
{
	Std_Func_t retval = OK;
	
	switch (motor_num)
	{
		case LEFT_MOTOR:
		
			if (motor_direction == FORWARD)
			{
				DIO_write(PORT_D,PIN0,HIGH);
				DIO_write(PORT_D,PIN1,LOW);
			}
			else if (motor_direction == BACKWARD)
			{
				DIO_write(PORT_D,PIN0,LOW);
				DIO_write(PORT_D,PIN1,HIGH);
				
			}
			else
			{
				retval = NOK;
			}
			break;
			
		case RIGHT_MOTOR:
			if (motor_direction == FORWARD)
			{
				DIO_write(PORT_D,PIN2,HIGH);
				DIO_write(PORT_D,PIN3,LOW);
			}
			else if (motor_direction == BACKWARD)
			{
				DIO_write(PORT_D,PIN2,LOW);
				DIO_write(PORT_D,PIN3,HIGH);
				
			}
			else
			{
				retval = NOK;
			}
			break;
		
			
		default:
			retval = NOK;
			break;
	}
	
	return retval;
}


Std_Func_t motor_Off(uint8_t motor_num)
{
	Std_Func_t retval = OK;
	
	switch (motor_num)
	{
		case LEFT_MOTOR:

			DIO_write(PORT_D,PIN2,LOW);
			DIO_write(PORT_D,PIN3,LOW);
	
		break;
		
		case RIGHT_MOTOR:
		
			DIO_write(PORT_D,PIN6,LOW);
			DIO_write(PORT_D,PIN7,LOW);

		break;
		
		default:
		retval = NOK;
	
	}

	return retval;
		
}