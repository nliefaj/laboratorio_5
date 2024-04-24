/*
 * pwm_2.c
 *
 * Created: 4/23/2024 11:08:54 AM
 *  Author: lefaj
 */ 
#include "pwm_2.h"
#include <avr/io.h>
#include <stdint.h>

void initPWM2(uint8_t invertido, uint16_t preescaler){
	DDRB|=(1<<DDB3);
	
	TCCR2A=0;
	TCCR2B=0;
	
	if (invertido==1){
		TCCR2A|=(1<<COM2A1)|(1<<COM2A0);
		}else{
		TCCR2A|=(1<<COM2A1);
	}
	
	//fastpwm 0xff top
	TCCR2A|=(1<<WGM20)|(1<<WGM21);
	
	switch (preescaler){
		case 0:
		TCCR2B|=(1<<CS20);
		break;
		case 8:
		TCCR2B |=(1<<CS21);
		break;
		case 32:
		TCCR2B |=(1<<CS20)|(1<<CS21);
		break;
		case 64:
		TCCR2B |=(1<<CS22);
		break;
		case 128:
		TCCR2B |=(1<<CS20)|(1<<CS22);
		break;
		case 256:
		TCCR2B |=(1<<CS21)|(1<<CS22);
		break;
		case 1024:
		TCCR2B |=(1<<CS20)|(1<<CS21)|(1<<CS22); //preescaler de 1024 para un periodo máximo de 4 segundos
		break;
		default:
		TCCR2B|=(1<<CS20);
	}
}

void updateDC2(uint8_t dutycycle){
	OCR2A=dutycycle;
}