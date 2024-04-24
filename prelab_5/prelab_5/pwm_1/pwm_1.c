/*
 * pwm_1.c
 *
 * Created: 4/17/2024 12:12:19 AM
 *  Author: lefaj
 */ 

#include "pwm_1.h"

void initPWM1(uint8_t invertido, uint16_t preescaler){
	DDRB |=(1<<DDB1);
	TCCR1A=0;
	TCCR1B=0;
	
	if (invertido==1){
		TCCR1A |=(1<<COM1A1)|(1<<COM1A0);//high
	} else{
		TCCR1A |=(1<<COM1A1); //low
	}
	
	switch(preescaler){
		case 0:
			TCCR1B |=(1<<CS10);
			break;
		case 8:
			TCCR1B |=(1<<CS11);
			break;
		case 64:
			TCCR1B |=(1<<CS10)|(1<<CS11);
			break;
		case 256:
			TCCR1B |=(1<<CS12);
			break;
		case 1024:
			TCCR1B |=(1<<CS12)|(1<<CS10); //preescaler de 1024 para un periodo máximo de 4 segundos
			break;
		default:
			TCCR1B|=(1<<CS10);
	}
	
	//FAST PWM 8 bits
	TCCR1A |=(1<<WGM10);
	TCCR1B |=(1<<WGM12);
	
	//ICR1=155;
	
	
	
}


void updateDC1(uint8_t prc_duty){
	OCR1A=prc_duty;
	} 
	


