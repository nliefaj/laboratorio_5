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
#include "pwm_2/pwm_2.h"
#include "pwm_0/pwm_0.h"

//variables
uint8_t valor_pot1=0;
uint8_t valor_pot2=0;
uint8_t valor_pot3=0;
uint8_t switch_pot=0;

ISR(ADC_vect){
	switch_pot=(ADMUX&0x0F);
	
	if(switch_pot==7){
		valor_pot1=ADCH;
		ADMUX=((ADMUX&0xF0)|6);
	} else if(switch_pot==6){
		valor_pot2=ADCH;
		ADMUX=((ADMUX&0xF0)|5);
	}else{
		valor_pot3=ADCH;
		ADMUX=((ADMUX&0xF0)|7);
	}
	
	ADCSRA|=(1<<ADIF);//apagar bandera 
}


void init_adc(void){
	ADMUX = 0;
	ADCSRA=0;
	
	// VCC=5V
	ADMUX |=(1<<REFS0);
	
	// Entrada 0 de MUX ADC0 para el prelab entonces no se cambian los bits de mux
	ADMUX |=(1<<ADLAR);
	
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
	CLKPR|=(1<<CLKPCE);
	CLKPR|=(1<<CLKPS0);//8Mhz
	
	initPWM1(0,1024); //no invertido, 1024 preescaler
	initPWM2(0,1024);//no invertido, preescaler 1024
	initPWM0(0,1024); //no invertido preescaler 1024
	sei();
	
    while (1) 
    {
		ADCSRA|=(1<<ADSC);
		
		updateDC1(valor_pot1/6);//primer servo timmer 1
		updateDC2(valor_pot2/6); //segundo servo timmer 2
		updateDC0(valor_pot3);//potenciometro led
		_delay_ms(10);

    }
}

