#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "p2switches.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "shape.h"
#include "libTimer.h"

char bState=4;

void manFig()
{
  static char stateMan = 0;
  
  switch(stateMan){
  case 0:    
    fillRectangle(70,30,20,20,COLOR_BROWN);
    fillRectangle(75,30,3,3,COLOR_BLACK);
    fillRectangle(82,30,3,3,COLOR_BLACK);
    
    fillRectangle(76,45,10,10,COLOR_BROWN);
    fillRectangle(65,54,30,30,COLOR_BROWN);
    fillRectangle(70,84,7,7,COLOR_BLUE);
    fillRectangle(83,84,7,7,COLOR_BLUE);
    fillRectangle(70,87,7,7,COLOR_BLUE);
    fillRectangle(83,87,7,7,COLOR_BLUE);
    fillRectangle(70,90,7,7,COLOR_BLUE);
    fillRectangle(83,90,7,7,COLOR_BLUE);    
    fillRectangle(70,93,7,7,COLOR_BLUE);
    fillRectangle(83,93,7,7,COLOR_BLUE);    


    fillRectangle(53,56,10,10,COLOR_BROWN);
    fillRectangle(59,56,10,10,COLOR_BROWN);
    fillRectangle(57,56,10,10,COLOR_BROWN);
    fillRectangle(55,56,10,10,COLOR_BROWN);
    fillRectangle(53,56,10,10,COLOR_BROWN);
    fillRectangle(51,56,10,10,COLOR_BROWN);
    fillRectangle(49,56,10,10,COLOR_BROWN);

    for(int i = 30; i > 0; i--){
      buzzer_set_period(0);
      fillRectangle(i+1,56,10,10,COLOR_WHITE);      
      
      for(int j = i-1; j < 49; j++){
	fillRectangle(i,56,10,10,COLOR_RED);
        if(j == 27){
	  fillRectangle(0,61,4,4,COLOR_WHITE);
          fillRectangle(0,50,4,4,COLOR_WHITE);
          fillRectangle(8,66,7,7,COLOR_WHITE);
          fillRectangle(8,46,7,7,COLOR_WHITE);
	}
      }
      buzzer_set_period(400);
      fillRectangle(i,56,10,10,COLOR_WHITE);
      
    }
    fillRectangle(0,61,4,4,COLOR_ORANGE);
    fillRectangle(0,50,4,4,COLOR_ORANGE);
    fillRectangle(8,66,7,7,COLOR_YELLOW);
    fillRectangle(8,46,7,7,COLOR_YELLOW);

      
    stateMan = 1;
    break;
  case 1:  
    stateMan = 0;
    break;
    
  default:
    stateMan++;
    break;
  }
  redrawScreen = 1;
}
  
void off()
{
  red_on=0;
  buzzer_set_period(0);
  led_changed=1;

  led_update();
  clearScreen(COLOR_WHITE);
  redrawScreen=1;
  or_sr(0x10);
}

//BORDERS**************
void borders(){
  
  fillRectangle(0,0,130,12,COLOR_BLACK);
  fillRectangle(0,0,12,160,COLOR_BLACK);
  fillRectangle(130,152,17,130,COLOR_BLACK);
  fillRectangle(114,0,70,180,COLOR_BLACK);
  redrawScreen=1;

}
static char manSt=0;
void state_advance()
{
  switch(bState){
  case 0:
    buzzer_set_period(0);
    borders();
    bState = 4;
    break;

  case 1:
    manFig();
    bState = 4;
    break;

  case 2:
    clearScreen(COLOR_BLACK);
    drawChar11x16(50,70,'$',COLOR_RED,COLOR_WHITE);
    bState = 4;
  case 3:
    buzzer_set_period(0);
    off();
    bState = 4;
  }
}

  //static char sState=0;

  /*if(bState==0){

    if(manSt==0){
      buzzer_set_period(0);
      borders();
      manSt=1;
      red_on=1;
    }
  }
  else if (bState == 1){
    //static char space = 0;
    if (manSt == 1) {	
      manFig();
      //manSt = 0
      
 
    }
  }
 else if(bState==3){
    clearScreen(COLOR_WHITE);
    buzzer_set_period(0);
    off();
  }
  }*/
