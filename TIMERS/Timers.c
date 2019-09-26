/*
 * Timers.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed ELameer
 */

#include "Timers.h"
#include "interrupt.h"
//#include "DIO.h"


/* Global variables to hold the address of the call back function in the application */
static volatile void (*g_callBackPtr)(void) = NULL_PTR;

volatile uint8_t  g_tick = 0;




void ISR_TIMER0_OVF (void) 
 {
	 if(g_callBackPtr != NULL_PTR)
	 {
		 /* Call the Call Back function in the application after the edge is detected */
		 (*g_callBackPtr)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	 }
	 
 }
// ISR(TIMER0_OVF_vect)
// {
// 	if(g_callBackPtr != NULL_PTR)
// 		{
// 			/* Call the Call Back function in the application after the edge is detected */
// 			(*g_callBackPtr)(); /* another method to call the function using pointer to function g_callBackPtr(); */
// 		}
// }

void ISR_TIMER0_COMP (void)
{

	if(g_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}




// 
// ISR(TIMER0_COMP_vect)
// {
// 
// 	if(g_callBackPtr != NULL_PTR)
// 		{
// 			/* Call the Call Back function in the application after the edge is detected */
// 			(*g_callBackPtr)(); /* another method to call the function using pointer to function g_callBackPtr(); */
// 		}
// }





void timer_init(void )
{
	uint8_t Loop_index;
	for(Loop_index=0;Loop_index<MAX_num_of_timers;Loop_index++)
	{
		switch(Timers_setup[Loop_index].T_type)
		{
			case Timer0:
				    Clear_T0(); //timer initial value

				    TCCR0 = (1<<FOC0) | (Timers_setup[Loop_index].T_clk)|((Timers_setup[Loop_index].T_WGMode&0x02)<<2)
				    		|((Timers_setup[Loop_index].T_WGMode&0x01)<<6)|(Timers_setup[Loop_index].T_Compare_out_mode.NPWM<<4);

					switch(Timers_setup[Loop_index].T_WGMode)   //enable overflow interrupt
					  {
					       case WG_Normal:
					    	  if(Timers_setup[Loop_index].T_INT1)
					    	        En_T0OF_interrupt();
							
					    	   break;
					       case WG_CTC :
					    	   if(Timers_setup[Loop_index].T_INT1)
					    	       En_T0COM_interrupt();

					    	   T0_ComVal(250);

					           break;
					       default:
					    	   break;
					  }




				   break;

			/*case Timer1:

				   break;


			case Timer2:

			      break;*/

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




void Toggle_half_sec(void){


		g_tick++;
		if(g_tick == NUMBER_OF_OVERFLOWS_PER_HALF_SECOND)
		{
			PORTC = PORTC ^ (1<<PC0); //toggle led every 0.5 second
			//DIO_write(PORT_C,PIN0,Toggle);
			g_tick = 0; //clear the tick counter again to count a new 0.5 second
		}

}

void Timer0_CTC_Square_Wave_Init(void)
{

	DDRB = DDRB | (1<<PB3); // OC0 Pin as output pin
	/* Configure timer control register
	 * 1. Non PWM mode FOC0=1
	 * 2. CTC Mode WGM01=1 & WGM00=0
	 * 3. Toggle OC0 on compare match COM00=1 & COM01=0
	 * 4. clock = CPU clock CS00=1 CS01=0 CS02=0
	 */

}

void Clear_T0(void){
	TCNT0 = 0;
}

void En_T0OF_interrupt(void){
	TIMSK |= (1<<TOIE0);

}

void En_T0COM_interrupt(void){
	TIMSK |= (1<<OCIE0);

}

void T0_ComVal(uint8_t ComVal){
	OCR0=ComVal;
}


