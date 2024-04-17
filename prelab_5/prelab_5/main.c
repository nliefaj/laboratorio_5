/*
 * prelab_5.c
 *
 * Created: 4/16/2024 9:52:56 PM
 * Author : lefaj
 */ 

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "pwm_1/pwm_1.h"

//variables
uint8_t valor_pot1=0;
uint8_t duty_cycle=0;

ISR(ADC_vect){
	valor_pot1=ADCH;
	ADCSRA&=~(1<<ADIF);
}

void setup(void){
	cli();
	//DDRD=0b11111111;
	DDRB=0b00000101;
	DDRC=0b00000000;
	PCICR=0;
	UCSR0B=0;
	sei();
}

void init_adc(void){
	ADMUX = 0;
	ADCSRA=0;
	
	// VCC=5V
	ADMUX |=(1<<REFS0);
	
	// Entrada 0 de MUX ADC0 para el prelab entonces no se cambian los bits de mux
	ADMUX |=(1<<MUX1)|(1<<MUX2)|(1<<ADLAR);
	
	//Encender ADC y  habilitar isr adc
	ADCSRA=0;
	ADCSRA|=(1<<ADEN)|(1<<ADIE);
	
	// preescaler = 16M/128=125k
	ADCSRA|=(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);
	
	//no se utilizara el estado B
	ADCSRB=0;
	
	
	//DIDRO=0;
}

int main(void)
{
	initPWM1(1,1024);
	
    while (1) 
    {
	updateDC(valor_pot1);
	_delay_ms(30);	

    }
}

