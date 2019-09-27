/*
 * Test.c
 *
 * Created: 9/25/2019 6:09:42 PM
 * Author : M_Moawad
 */ 

#include "MOTOR.h"
#include "SEV_SEG.h"
#include "Timers.h"

static uint8_t flag = 0; 

void car_forward (void)
{
	motor_On(LEFT_MOTOR,FORWARD);
	motor_On(RIGHT_MOTOR,FORWARD);
}

void car_backward (void)
{
	motor_On(LEFT_MOTOR,BACKWARD);
	motor_On(RIGHT_MOTOR,BACKWARD);
}

void car_rotate_left (void)
{
	motor_Off(LEFT_MOTOR);
	motor_On(RIGHT_MOTOR,FORWARD);
}

void car_rotate_right (void)
{
	motor_On(LEFT_MOTOR,FORWARD);
	motor_Off(RIGHT_MOTOR);
}
void car_stop (void)
{
	motor_Off(RIGHT_MOTOR);
	motor_Off(LEFT_MOTOR);
}

void caller_fun (void){
	static uint8_t i = 0 ; 
	if ( i < 9 & flag == 0)
	{
		i++;
	}
	else 
	{
		flag = 1;
		i--;
		if (i == 0)
		{
			flag = 2;
			cli();
		}
	}
   sevseg_Display(i);

}
int main(void)
{
	DIO_init ();
	timer_init();
	sei ();


	Dely_ms_service(Timer0,1500,caller_fun);
	while (1) 
    {
		if (flag == 0)
		{
			car_forward();
		}
		else if ( flag == 1)
		{
			car_backward();
		}
		else 
		{
			car_stop();
		}


    }
}

