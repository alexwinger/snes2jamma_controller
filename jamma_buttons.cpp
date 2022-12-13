#include "jamma_buttons.h"


void setup_jamma_pins(void){
	for(int p=0;p<JAMMA_TOTAL_CONTROLS;p++)
		for(int b=0; b<JAMMA_TOTAL_BUTTONS; b++){
			digitalWrite(jamma_ctrlr_pins[p][b], LOW);
			pinMode(jamma_ctrlr_pins[p][b], INPUT);
		}
}

void write_jamma_button(int player, jamma_buttons_t btn, bool pressed){
	int pin = jamma_ctrlr_pins[player][btn];
	if(pin >=0){
		if(pressed == HIGH){
		  pinMode(pin, OUTPUT);
		}else{
		  pinMode(pin, INPUT);
		}
	}
}
