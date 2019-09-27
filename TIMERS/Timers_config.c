/*
 * Timers_config.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed ELameer
 */


#include "Timer_config.h"

/*timers_type
 * ,interrupt                                FOR      EACH        TIMER
 * ,clock
 * ,wave generation
 * ,out put compare
 * ,out compare output as value */


Timer_config Timers_setup[MAX_num_of_timers]=
{
		{Timer2,EN_INT,F_cpu_clk,WG_Normal,NA,NPWM_Normal},
		{Timer0,EN_INT,F_cpu_clk,WG_Normal,NA,NPWM_Normal},
		{NA,NA,NA,NA,NA,NA}
};




