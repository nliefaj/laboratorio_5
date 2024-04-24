/*
 * pwm_0.h
 *
 * Created: 4/23/2024 11:06:01 AM
 *  Author: lefaj
 */ 


#ifndef PWM_0_H_
#define PWM_0_H_

#include <avr/io.h>
#include <stdint.h>

//invertido=1, no invertido =0

//configurarpwm1 modo fast
void initPWM0(uint8_t invertido, uint16_t preescaler);

void updateDC0(uint8_t duty_cycle); //percentage duty



#endif /* PWM_0_H_ */