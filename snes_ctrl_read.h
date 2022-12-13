#ifndef SNES_CTRL_READ_H
#define SNES_CTRL_READ_H

#include <arduino.h>

//  Snes controller port pinout
//    _________________
//   /      |         | 
//  ( 7 6 5 | 4 3 2 1 |
//   \______|_________|
//
//   1 VCC (5 Volt)
//   2 Clock
//   3 Strobe (Latch)
//   4 Data
//   7 GND


// Arduino Pinout
#define CLOCK  A0
#define LATCH  A1
#define DATA1  A2
//#define DATA2  A3  //define a pin for DATA2
//#define DATA3  A4? //define a pin for DATA3
//#define DATA4  A5? //define a pin for DATA4


typedef enum{
  SNES_BTN_B=0,
  SNES_BTN_Y,
  SNES_BTN_SELECT,
  SNES_BTN_START,
  SNES_BTN_UP,
  SNES_BTN_DOWN,
  SNES_BTN_LEFT,
  SNES_BTN_RIGHT,
  SNES_BTN_A,
  SNES_BTN_X,
  SNES_BTN_L,
  SNES_BTN_R,
  SNES_TOTAL_BUTTONS
}snes_ctrlr_button_t;

void snes_ctrl_setup();
void snes_ctrl_read(uint8_t* ctrl1, uint8_t* ctrl2, uint8_t* ctrl3, uint8_t* ctrl4);

#endif //SNES_CTRL_READ_H
