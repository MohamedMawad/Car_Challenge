
#include "Timers.h"




/* Global variables to hold the address of the call back function in the application */
static volatile void (*g_callBackPtr)(void) = NULL_PTR;
static volatile void (*g_callBackPtr2)(void) = NULL_PTR;

#define NUMBER_OF_OVERFLOWS_PER_HALF_SECOND 2

uint8_t duty_percentage;


volatile uint8_t  g_tick_off=0;

volatile uint64_t g_time_MS;

volatile uint8_t  g_tick = 0,g_tick2=0;


/*********************************************************************************************************
 * *******************************************************************************************************
 * ****************************************************************************************************
 * *******************************************************************************************************/
/*TIMER0________________Interrupt*/

void ISR_TIMER0_OVF(void)
{

	if(g_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr)();
		/* another method to call the function using pointer to function g_callBackPtr(); */
	}
}



void ISR_TIMER0_COMP (void)
{

	if(g_callBackPtr2 != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr2)();
		/* another method to call the function using pointer to function g_callBackPtr(); */
	}

}


/*********************************************************************************************************
 * *******************************************************************************************************
 * ****************************************************************************************************
 * *******************************************************************************************************/

/*Timer2_______Interrupt*/

void ISR_TIMER2_OVF (void)
{
	if(g_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}



void ISR_TIMER2_COMP (void)
{

	if(g_callBackPtr2 != NULL_PTR)
	{ 		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr2)();
		/* another method to call the function using pointer to function g_callBackPtr(); */

	}

}


/*********************************************************************************************************
 * *******************************************************************************************************
 * ****************************************************************************************************
 * *******************************************************************************************************/

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



/*********************************************************************************************************
 * *******************************************************************************************************
 * ****************************************************************************************************
 * *******************************************************************************************************/


void timer_init(void )
{
	uint8_t Loop_index=0;


	for(Loop_index=0;Loop_index<MAX_num_of_timers;Loop_index++)
	{
		switch(Timers_setup[Loop_index].T_type)
		{
		case Timer0:

			TCNT0=0; //timer initial value

			/*******************TIMER0 EDIT SETTINGS************/

			TCCR0 = (1<<FOC0) | (Timers_setup[Loop_index].T_clk)
					|((Timers_setup[Loop_index].T_WGMode&0x02)<<2)
				    |((Timers_setup[Loop_index].T_WGMode&0x01)<<6)
					|(Timers_setup[Loop_index].T_Compare_out_mode<<4);

			/*************CHOOSE TIMER0 MODES*************************/

					switch(Timers_setup[Loop_index].T_WGMode)   //enable overflow interrupt
					{
					case WG_Normal:
						if(Timers_setup[Loop_index].T_INT)
							TIMSK |= (1<<TOIE0);				 //En_TOF_interrupt of timer0

						break;
						/***********************************************/

					case WG_CTC :
						if(Timers_setup[Loop_index].T_INT)
							TIMSK |= (1<<OCIE0);				//En_TCOM_interrupt of timer0

						OCR0 = Timers_setup[Loop_index].ComVal;

						 /***********************************************/

						break;
						 /*****************************************************/

					case WG_FPWM :
						OCR0 = Timers_setup[Loop_index].ComVal;

						break;
						/******************************************************/

					default:
						break;
					}
					break;



			  case Timer1:

				 TCNT1H = 0; // clear T1
				 TCNT1L = 0;
				//open A units
				TCCR1A = (1<<FOC1A) | ((Timers_setup[Loop_index].T_WGMode)&0x03)
				         |((Timers_setup[Loop_index].T_Compare_out_mode<<6));

				TCCR1B = ((Timers_setup[Loop_index].T_WGMode)&0x0C)|(Timers_setup[Loop_index].T_clk);

				//open B units
				/*TCCR1A = (1<<FOC1B) | ((Timers_setup[Loop_index].T_WGMode)&0x03)
				         |((Timers_setup[Loop_index].T_Compare_out_mode<<4));*/

				switch(Timers_setup[Loop_index].T_WGMode)   //enable overflow interrupt
								{
								case WG_Normal:

									if(Timers_setup[Loop_index].T_INT)
										TIMSK |= (1<<TOIE1);
									break;
								case WG_T1CTC :
									if(Timers_setup[Loop_index].T_INT)
									    {
										    //unit A
										    TIMSK |= (1<<OCIE1A);
										    //unit B
										    //TIMSK |= (1<<OCIE1B);
								        }

									//unit A
									OCR1AH=(char)(0x1324>>8);
									OCR1AL=(char)(0x1324);
									//unit B
									//OCR1BH=(64<<8);
									//OCR1BL=(64>>8);

									break;
								/*case WG_FPWM :
									//unit A
									OCR1AH=(64<<8);
									OCR1AL=(64>>8);
									//unit B
									OCR1BH=(64<<8);
									OCR1BL=(64>>8);
									break;*/

								default:
									break;
								}
							break;








			case Timer2:

				TCNT2=0; //timer initial value

                 /*EDIT_________ TIMER02*/

				TCCR2 = (1<<FOC2) | (Timers_setup[Loop_index].T_clk)
						|((Timers_setup[Loop_index].T_WGMode&0x02)<<2)
						|((Timers_setup[Loop_index].T_WGMode&0x01)<<6)
						|(Timers_setup[Loop_index].T_Compare_out_mode<<4);

				/*************CHOOSE TIMER0 MODES*************************/

						switch(Timers_setup[Loop_index].T_WGMode)   //enable overflow interrupt
						{
						case WG_Normal:

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



				default:
					break;


		}
	}
}




/*********************************************************************************************************
 * *******************************************************************************************************
 * ****************************************************************************************************
 * *******************************************************************************************************/



/*********************************************************************************************************
 * *******************************************************************************************************
 * ****************************************************************************************************
 * *******************************************************************************************************/

void Timer_Square_Wave_Init(void)
{

	uint8_t loop_index=0;
	for(loop_index=0;loop_index<MAX_num_of_timers;loop_index++)
	{

		if(Timers_setup[loop_index].T_type==Timer0)
		{
			DDRB = DDRB | (1<<PB3);                       	//enable OC0 as output PIN
		}
		if(Timers_setup[loop_index].T_type==Timer2)
		{
			DDRD = DDRD | (1<<PD7);                         //enable OC2 as output PIN
		}
		if(Timers_setup[loop_index].T_type==Timer1)
				{
					DDRD = DDRD | (1<<PD5);             //enable OC1A as output PIN
					//DDRD = DDRD | (1<<PD4);            //enable OC1B as output PIN
				}
	}



}



/*********************************************************************************************************
 * *******************************************************************************************************
 * ****************************************************************************************************
 * *******************************************************************************************************/

/*DELAY______BY_______POLLING*/

void Delay_ms(uint64_t n_milleSec,t_type timer)
{


	static uint8_t count31=0;

	if(timer==T0)
	{

		while(n_milleSec)
		 {

			while( !(TIFR & (1<<TOV0) ) );        //go out of loop if there is interrupt happens
			count31++;
			if (31 == count31)                    //if timer flag be one by 31 time as 1ms "interrupt happens
				                                  //by o.f
				{

					count31 = 0;
					n_milleSec--;

				}
			TIFR |= (1<<TOV0);                    //clear T0 interrupt flag
		 }

	}

	if(timer==T2)
	{

		while(n_milleSec)
		{

			while( !(TIFR & (1<<TOV2) ) );
			count31++;
			if (31 == count31)
			{

				count31 = 0;
				n_milleSec--;

			}
			TIFR |= (1<<TOV2);



		}
	}

}



/*********************************************************************************************************
 * *******************************************************************************************************
 * ****************************************************************************************************
 * *******************************************************************************************************/

/*pointer to call the function when the interrupt happens*/

void Wait_ms(void)
{

	static uint64_t count=0;                           //the number you wanted to delay as EX delay(3000ms)
	static uint8_t count31=0;                          //the number that will reach to make a 1ms
	count31++;

	if (31 == count31)
	{
		count++;
		count31 = 0;

	}

	if(count == g_time_MS)                            //if the number reached the number you want call the func
	{

		if(g_callBackPtr2 != NULL_PTR)
		{
			/* Call the Call Back function in the application after the edge is detected */
			(*g_callBackPtr2)();
			/* another method to call the function using pointer to function g_callBackPtr(); */
		}

		count=0;

	}

}



void Dely_ms_service(t_type timer,uint64_t time_MS,void(*ptr_display)(void))
{


	g_time_MS = time_MS;
	g_callBackPtr = Wait_ms;                //interrupt call

	g_callBackPtr2=ptr_display;             //func call



}


void SPEED(void){


	//g_tick_on++;
	g_tick_off++;
	if(g_tick_off == 100- duty_percentage)
	{
		PORTC|= (1<<PC0); //toggle led every 0.5 second

		//clear the tick counter again to count a new 0.5 second



	}
	if(g_tick_off ==  100 )
	{
		PORTC  &=~ (1<<PC0); //toggle led every 0.5 second
		//DIO_write(PORT_C,PIN0,Toggle);
		g_tick_off = 0; //clear the tick counter again to count a new 0.5 second
	}


}




