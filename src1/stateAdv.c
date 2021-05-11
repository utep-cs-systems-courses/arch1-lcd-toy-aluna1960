#include "p2switches.h"
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"


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
    //clearScreen(COLOR_BLACK);
    clearBlack();
    // drawChar11x16(50,70,'$',COLOR_RED,COLOR_WHITE);
    drawFace();
    bState = 4;
  case 3:
    buzzer_set_period(0);
    off();
    bState = 4;
  }
}
