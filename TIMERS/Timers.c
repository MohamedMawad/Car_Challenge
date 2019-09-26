
#include "Timers.h"

//#define  Timer0 5
/* Global variables to hold the address of the call back function in the application */
static volatile void (*g_callBackPtr)(void) = NULL_PTR;
static volatile void (*g_callBackPtr2)(void) = NULL_PTR;




volatile uint8_t  g_tick = 0,g_tick2=0;

#define NUMBER_OF_OVERFLOWS_PER_HALF_SECOND 2



ISR(TIMER0_OVF_vect)
{
	if(g_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}


ISR(TIMER0_COMP_vect)
{

	if(g_callBackPtr2 != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr2)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}

ISR(TIMER2_OVF_vect)
{
	if(g_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}


ISR(TIMER2_COMP_vect)
{

	if(g_callBackPtr2 != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr2)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}



void timer_init(void )
{
	uint8_t Loop_index=0;


	for(Loop_index=0;Loop_index<MAX_num_of_timers;Loop_index++)
	{
		switch(Timers_setup[Loop_index].T_type)
		{
		case Timer0:
			Clear_Timers(); //timer initial value

			TCCR0 = (1<<FOC0) | (Timers_setup[Loop_index].T_clk)|((Timers_setup[Loop_index].T_WGMode&0x02)<<2)
				    		|((Timers_setup[Loop_index].T_WGMode&0x01)<<6)|(Timers_setup[Loop_index].T_Compare_out_mode<<4);

			switch(Timers_setup[Loop_index].T_WGMode)   //enable overflow interrupt
			{
			case WG_Normal:
				if(Timers_setup[Loop_index].T_INT)
					TIMSK |= (1<<TOIE0);				 //En_TOF_interrupt of timer0
					
				break;
			case WG_CTC :
				if(Timers_setup[Loop_index].T_INT)
					TIMSK |= (1<<OCIE0);				//En_TCOM_interrupt of timer0

				OCR0 = Timers_setup[Loop_index].ComVal;
				
				break;
			case WG_FPWM :
				OCR0 = Timers_setup[Loop_index].ComVal;
				
				break;
			default:
				break;
			}




			break;

			/*case Timer1:

				   break;*/


			case Timer2:
				Clear_Timers(); //timer initial value

				TCCR2 = (1<<FOC2) | (Timers_setup[Loop_index].T_clk)|((Timers_setup[Loop_index].T_WGMode&0x02)<<2)
								    		|((Timers_setup[Loop_index].T_WGMode&0x01)<<6)|(Timers_setup[Loop_index].T_Compare_out_mode<<4);

				switch(Timers_setup[Loop_index].T_WGMode)   //enable overflow interrupt
				{
				case WG_Normal:
					//TIMSK |= (1<<TOIE2);
					if(Timers_setup[Loop_index].T_INT)
						TIMSK |= (1<<TOIE2);              //En_TOF_interrupt of timer0
					break;
				case WG_CTC :
					if(Timers_setup[Loop_index].T_INT)
						TIMSK |= (1<<OCIE2); //En_TCOM_interrupt of timer2

					OCR2 = Timers_setup[Loop_index].ComVal;

					break;
				case WG_FPWM :
					OCR2 = Timers_setup[Loop_index].ComVal;
					
					break;
				default:
					break;
				}


				break;

//				case Timer1:

				default:
					break;


		}
	}
}




void Timer_setCallBack(void(*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable */
	g_callBackPtr = a_ptr;
}
void Timer_setCallBack2(void(*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable */
	g_callBackPtr2 = a_ptr;
}

void Toggle_Sec(void){


	g_tick2++;
	if(g_tick2 == 4)
	{
		PORTC = PORTC ^ (1<<PC1); //toggle led every 0.5 second
		//DIO_write(PORT_C,PIN0,Toggle);
		g_tick2 = 0; //clear the tick counter again to count a new 0.5 second
	}

}



void Toggle_half_sec(void){


	g_tick++;
	if(g_tick == NUMBER_OF_OVERFLOWS_PER_HALF_SECOND)
	{
		PORTC = PORTC ^ (1<<PC0); //toggle led every 0.5 second
		//DIO_write(PORT_C,PIN0,Toggle);
		g_tick = 0; //clear the tick counter again to count a new 0.5 second
	}

}

void Timer_Square_Wave_Init(void)
{



	uint8_t loop_index=0;
		for(loop_index=0;loop_index<MAX_num_of_timers;loop_index++)
		{

			if(Timers_setup[loop_index].T_type==Timer0)
			{
				DDRB = DDRB | (1<<PB3);
			}
			if(Timers_setup[loop_index].T_type==Timer2)
			{
				DDRD = DDRD | (1<<PD7);
			}
		}



}

void Clear_Timers(void){
	uint8_t loop_index=0;
	for(loop_index=0;loop_index<MAX_num_of_timers;loop_index++)
	{

		if(Timers_setup[loop_index].T_type==Timer0)
		{
			TCNT0 = 0;
		}
		if(Timers_setup[loop_index].T_type==Timer2)
		{
			TCNT2=0;
		}
	}


}






