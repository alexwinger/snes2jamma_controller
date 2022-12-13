#include "snes_ctrl_read.h"
#include "jamma_buttons.h"

#define PRINT_BUTTON_PRESSES //Uncomment for printing button presses into serial port, adding input lag
#define PLAYER1 0
#define PLAYER2 1

#ifdef PRINT_BUTTON_PRESSES
//For printing button presses
char button_name[SNES_TOTAL_BUTTONS][15]={
  "BUTTON_B",
  "BUTTON_Y",
  "BUTTON_SELECT",
  "BUTTON_START",
  "BUTTON_UP",
  "BUTTON_DOWN",
  "BUTTON_LEFT",
  "BUTTON_RIGHT",
  "BUTTON_A",
  "BUTTON_X",
  "BUTTON_L",
  "BUTTON_R"
};
static uint8_t previous_ctrl[SNES_TOTAL_BUTTONS];
#endif

void write_jamma_controllers(uint8_t* ctrl){
  for(int button_index = SNES_BTN_B; button_index < SNES_TOTAL_BUTTONS; button_index++){
    bool state = ctrl[button_index];
    switch(button_index){
      case SNES_BTN_B:      write_jamma_button(PLAYER1, JAMMA_1,    state);break;
      case SNES_BTN_A:      write_jamma_button(PLAYER1, JAMMA_2,    state);break;
      case SNES_BTN_Y:      write_jamma_button(PLAYER1, JAMMA_3,    state);break;
      case SNES_BTN_X:      write_jamma_button(PLAYER1, JAMMA_4,    state);break;
      case SNES_BTN_UP:     write_jamma_button(PLAYER1, JAMMA_UP,   state);break;
      case SNES_BTN_DOWN:   write_jamma_button(PLAYER1, JAMMA_DOWN, state);break;
      case SNES_BTN_LEFT:   write_jamma_button(PLAYER1, JAMMA_LEFT, state);break;
      case SNES_BTN_RIGHT:  write_jamma_button(PLAYER1, JAMMA_RIGHT,state);break;
      case SNES_BTN_START:  write_jamma_button(PLAYER1, JAMMA_START, state);break;
      case SNES_BTN_SELECT: write_jamma_button(PLAYER1, JAMMA_COIN,state);break;
    }

    #ifdef PRINT_BUTTON_PRESSES
      if( ( ctrl[button_index] != 0 ) && ( previous_ctrl[button_index] == 0) )  // If previously not pressed, and now is pressed Then print which button is pressed
      {
        Serial.print("Pressed ");
        Serial.println(button_name[button_index]);
      }
      previous_ctrl[button_index] = ctrl[button_index]; // Update button state
    #endif
  }
}

uint8_t ctrl1[SNES_TOTAL_BUTTONS];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  snes_ctrl_setup();
  setup_jamma_pins();
}

void loop() {
  // put your main code here, to run repeatedly:
   snes_ctrl_read(ctrl1, NULL, NULL, NULL);
   write_jamma_controllers(ctrl1);
}
