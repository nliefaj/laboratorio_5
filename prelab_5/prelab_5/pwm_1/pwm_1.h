/*
 * pwm_1.h
 *
 * Created: 4/16/2024 11:24:41 PM
 *  Author: lefaj
 */ 


#ifndef PWM_1_H_
#define PWM_1_H_

#include <avr/io.h>
#include <stdint.h>

//invertido=1, no invertido =0

//configurarpwm1 modo fast
void initPWM1(uint8_t invertido, uint16_t preescaler);

void updateDC(uint8_t prc_duty); //percentage duty




#endif /* PWM_1_H_ */