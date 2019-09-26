/*
 * Timer_config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed ELameer
 */

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

#include "std_types.h"
#include "MICRO_setting.h"

#define NA  0xFF

/*
typedef enum{
	Timer0,Timer1,Timer2,MAX_num_of_timers
}timer_type;*/

typedef enum{
	Dis_INTT,EN_INTT1
}InT_timer;

typedef enum{
	Timer0,MAX_num_of_timers
}timer_type;

typedef enum{
	NO_clk,F_cpu_clk,F_cpu_8,F_cpu_64,F_cpu_256,F_cpu_1024,Exter_F_clk,Exter_R_clk
}timer_clk;

typedef enum{
	WG_Normal,WG_PWM_PHC,WG_CTC,WG_FPWM
}timer_WGMode;



typedef enum{
	Normal,Toggle,Clear,Set
}No_pwm;

typedef enum{
	Clear_up_set_down=2,Set_up_clear_down
}Phc_pwm;

typedef enum{
	No_inverting_mode=2,Inverting_mode
}F_pwm;

typedef struct{
	No_pwm  NPWM;
	Phc_pwm PHC_PWM;
	F_pwm   FPWM;

}timer_COM;


typedef enum{
	Falling,Rising
}ICU_edges;


typedef struct{
	timer_clk clock;
	ICU_edges edge;
}ICU_config;

typedef struct{
    timer_type   T_type;
	InT_timer    T_INT1;
	timer_clk    T_clk;
	timer_WGMode T_WGMode;
	timer_COM    T_Compare_out_mode;
	
	//ICU_config  ICU_conf;

}Timer_config;



void Clear_T0(void);
void T0_ComVal(uint8_t ComVal);
void En_T0OF_interrupt(void);
void En_T0COM_interrupt(void);



extern Timer_config Timers_setup[MAX_num_of_timers];



#endif /* TIMER_CONFIG_H_ */
