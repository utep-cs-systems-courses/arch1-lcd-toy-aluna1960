#include <msp430.h>
#include "stateMachines.h"
#include <libTimer.h>
#include "led.h"
#include "buzzer.h"
#include "p2switches.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "shape.h"
#include <sr.h>
#include "stateAdv_assembly.h"
#define LED_GREEN BIT6


short redrawScreen = 1;




void wdt_c_handler()
{
  static int secCount = 0;
  static int drawCnt = 0;
  if(bState == 2){
    if(drawCnt == 250){      
      redrawScreen = 1;
      drawCnt = 0;
      
    }
    
    drawCnt++;
    state_advance();
  }
  else{
    secCount = 0;
    state_advance();
    
  }
  secCount++;
  /*
  

  switch(bState){
  case 2:
    if(drawCnt == 250){
      
      
      //drawString5x7(20,40,"Boo Behind you!", COLOR_RED,COLOR_BLACK);
      redrawScreen = 1;
      drawCnt = 0;
    }
    drawCnt++;
	//redrawScreen = 1;
      //drawCnt=0;
      // clearScreen(COLOR_BLACK);
      //drawChar11x16(50,70,'$',COLOR_RED,COLOR_WHITE);
      //drawString5x7(20,40,"Boo! Behind you!",COLOR_RED,COLOR_BLACK);
    
    if(drawCnt==500){
      //drawString5x7(20,40,"Boo! Behind you!",COLOR_BLACK,COLOR_BLACK);
      drawString5x7(40,95,"Gotcha!",COLOR_RED,COLOR_BLACK);
      drawCnt = 0;
    }
    buzzer_set_period(0);
    drawCnt++;
   
    break;
  default:
    if(secCount == 1) {
      buzzer_set_period(0);
      secCount = 0;
      
      state_advance();
    }
    secCount++;
    }*/
}


int main(void) {
  P1DIR |= LED_GREEN;
  P1OUT |= LED_GREEN;
  configureClocks();
  led_init();
  lcd_init();
  buzzer_init();
  p2sw_init(15);
  enableWDTInterrupts();/* enable periodic interrupt */
  or_sr(0x8); //Turns on GIE

  
  while (1) {           /* forever */
    if(redrawScreen){
      redrawScreen=0;
      if(bState==1){
	state_advance();
      }
      P1OUT &= ~LED_GREEN;/* green off */
      or_sr(0x10);/**< CPU OFF */
      P1OUT |= LED_GREEN;/* green on */
    }
  }
}
