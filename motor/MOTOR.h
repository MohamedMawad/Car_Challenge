/*
 * MOTOR.h
 *
 * Created: 9/26/2019 6:46:55 PM
 *  Author: M_Moawad
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_

#include "DIO.h"

#define LEFT_MOTOR		0
#define RIGHT_MOTOR		1


#define FORWARD			0
#define BACKWARD		1


Std_Func_t motor_On(uint8_t motor_num, uint8_t motor_direction);
Std_Func_t motor_Off(uint8_t motor_num);





#endif /* MOTOR_H_ */