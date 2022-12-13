#ifndef JAMMA_BUTTONS_H
#define JAMMA_BUTTONS_H

#include <arduino.h>

////  JAMMA PCB EDGE CONNECTOR

// GND           |A| | 1|      GND 
// GND           |B| | 2|      GND
// 5V            |C| | 3|      5V 
// 5V            |D| | 4|      5V 
//               |E| | 5|      
//               |F| | 6|      
// EMPTY					   EMPTY
//               |J| | 8|  
//               |K| | 9|  
//               |L| |10|  
//               |M| |11|  
//               |N| |12|  
//               |P| |13|  
//               |R| |14|  
//               |S| |15|  
// 2P Coin       |T| |16|      1P Coin
// 2P Start      |U| |17|      1P Start   
// 2P Up         |V| |18|      1P Up      
// 2P Down       |W| |19|      1P Down    
// 2P Left       |X| |20|      1P Left    
// 2P Right      |Y| |21|      1P Right   
// 2P 1          |Z| |22|      1P 1       
// 2P 2          |a| |23|      1P 2       
// 2P 3          |b| |24|      1P 3       
// 2P 4          |c| |25|      1P 4     
// 2P Select     |d| |26|      1P Select
// GND           |e| |27|      GND  
// GND           |f| |28|      GND  

#define JAMMA_TOTAL_CONTROLS 2
typedef enum{
	JAMMA_UP,
	JAMMA_DOWN,
	JAMMA_LEFT,
	JAMMA_RIGHT,
	JAMMA_1,
	JAMMA_2,
	JAMMA_3,
	JAMMA_4,
	JAMMA_START,
	JAMMA_COIN,
	JAMMA_SELECT,
	
	JAMMA_TOTAL_BUTTONS
}jamma_buttons_t;

const uint8_t jamma_ctrlr_pins[JAMMA_TOTAL_CONTROLS][JAMMA_TOTAL_BUTTONS]={
	{
		2, //1P UP
		3, //1P DOWN
		4, //1P LEFT
		5, //1P RIGHT
		6, //1P A
		7, //1P B
		8, //1P C
		9, //1P D
		11,//1P START
		10,//1P COIN
		-1 //1P SELECT
	},
	{
		-1, //2P UP
		-1, //2P DOWN
		-1, //2P LEFT
		-1, //2P RIGHT
		-1, //2P A
		-1, //2P B
		-1, //2P C
		-1, //2P D
		-1, //2P START
		-1, //2P COIN
		-1, //2P SELECT
	}
};


void setup_jamma_pins(void);
void write_jamma_button(int player, jamma_buttons_t btn, bool pressed);
#endif //SNES_CTRL_READ_H
