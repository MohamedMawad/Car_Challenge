/*
 * Timers.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed ELameer
 */

#ifndef TIMERS_H_
#define TIMERS_H_





#include "Timer_config.h"




void timer_init(void );
void Timer_Square_Wave_Init(void);

void Timer_setCallBack(void(*a_ptr)(void));
void Timer_setCallBack2(void(*a_ptr)(void));

void Toggle_half_sec(void);


void Toggle_Sec(void);







#endif /* TIMERS_H_ */
