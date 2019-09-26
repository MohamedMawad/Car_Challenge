/*
 * Timers_config.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed ELameer
 */


#include "Timer_config.h"




Timer_config Timers_setup[MAX_num_of_timers]=
{
		{Timer2,EN_INT,F_cpu_1024,WG_Normal,64,NPWM_Normal},
		{Timer0,EN_INT,F_cpu_1024,WG_CTC,64,NPWM_Toggle}
		//{Timer2,EN_INT,F_cpu_clk,WG_FPWM,Normal}
};




