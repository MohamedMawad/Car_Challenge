/*
 * Timers.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed ELameer
 */

#ifndef TIMERS_H_
#define TIMERS_H_





#include "Timer_config.h"

#define NUMBER_OF_OVERFLOWS_PER_HALF_SECOND 2

void timer_init(void );
void Timer0_CTC_Square_Wave_Init(void);

void Timer_setCallBack(void(*a_ptr)(void));

void Toggle_half_sec(void);










#endif /* TIMERS_H_ */
