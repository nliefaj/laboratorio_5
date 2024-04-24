/*
 * pwm_2.h
 *
 * Created: 4/23/2024 11:06:26 AM
 *  Author: lefaj
 */ 


#ifndef PWM_2_H_
#define PWM_2_H_

#include <avr/io.h>
#include <stdint.h>

void initPWM2(uint8_t invertido, uint16_t preescaler);
void updateDC2(uint8_t dutycycle);

#endif /* PWM_2_H_ */