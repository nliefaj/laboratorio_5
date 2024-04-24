/*
 * pwm_0.c
 *
 * Created: 4/23/2024 11:13:11 AM
 *  Author: lefaj
 */ 

#include "pwm_0.h"
#include <avr/io.h>
#include <stdint.h>

void initPWM0(uint8_t invertido, uint16_t preescaler){
	DDRD|=(1<<DDD6);
	
	TCCR0A=0;
	TCCR0B=0;
	
	if (invertido==1){
		TCCR0A=(1<<COM0A1)|(1<<COM0A0);
	}else{
		TCCR0A=(1<<COM0A1);
	}
	
	TCCR0A |=(1<<WGM00)|(1<<WGM01);
	
	switch (preescaler){
		case 0:
		TCCR0B |=(1<<CS00);
		break;
		case 8:
		TCCR0B |=(1<<CS01);
		break;
		case 64:
		TCCR0B |=(1<<CS00)|(1<<CS01);
		break;
		case 256:
		TCCR0B |=(1<<CS02);
		break;
		case 1024:
		TCCR0B |=(1<<CS00)|(1<<CS02); //preescaler de 1024 para un periodo máximo de 4 segundos
		break;
		default:
		TCCR0B|=(1<<CS00);
	}
	
}

void updateDC0(uint8_t duty_cycle){
	OCR0A=duty_cycle;
}