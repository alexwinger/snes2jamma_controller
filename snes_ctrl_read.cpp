#include "snes_ctrl_read.h"


#define LATCH_DELAY 16
#define CLOCK_DELAY  8

// Setup IO pins
void snes_ctrl_setup(){
	
	pinMode(CLOCK, OUTPUT);
	pinMode(LATCH, OUTPUT);
	
  #ifdef DATA1
	pinMode(DATA1,INPUT_PULLUP);
  #endif

  #ifdef DATA2
	pinMode(DATA2,INPUT_PULLUP);
  #endif

  #ifdef DATA3
	pinMode(DATA3,INPUT_PULLUP);
  #endif

  #ifdef DATA4
	pinMode(DATA4,INPUT_PULLUP);
  #endif
  
  digitalWrite(CLOCK, HIGH);
  digitalWrite(LATCH, LOW);
}



// Reading SNES Controllers
void snes_ctrl_read(uint8_t* ctrl1, uint8_t* ctrl2, uint8_t* ctrl3, uint8_t* ctrl4){
  uint8_t button_status;

  //Update button state into shift register
  digitalWrite(LATCH,1);
  delayMicroseconds(LATCH_DELAY);
  digitalWrite(LATCH,0);
  delayMicroseconds(LATCH_DELAY);

  //Start clocking each button
  for(int current_button = SNES_BTN_B; current_button < SNES_TOTAL_BUTTONS; current_button++)
  {
	#ifdef DATA1
		if(ctrl1 != NULL){
			button_status = ( digitalRead(DATA1) == LOW );
			ctrl1[current_button] = button_status;
		}
	#endif

	#ifdef DATA2
		if(ctrl2 != NULL){
			button_status = ( digitalRead(DATA2) == LOW );
			ctrl2[current_button] = button_status;
		}
	#endif
    
	#ifdef DATA3
		if(ctrl3 != NULL){
			button_status = ( digitalRead(DATA3) == LOW );
			ctrl3[current_button] = button_status;
		}
	#endif
	
	#ifdef DATA4
		if(ctrl4 != NULL){
			button_status = ( digitalRead(DATA4) == LOW );
			ctrl4[current_button] = button_status;
		}
	#endif
	
    digitalWrite(CLOCK,LOW);
    delayMicroseconds(CLOCK_DELAY);
    
    digitalWrite(CLOCK,HIGH);
    delayMicroseconds(CLOCK_DELAY);
  }
}
