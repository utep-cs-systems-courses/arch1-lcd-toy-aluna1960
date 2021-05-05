#include <msp430.h>
#include "stateMachines.h"
#include "libTimer.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "shape.h"
#include <sr.h>

#define LED_GREEN BIT6


int redrawScreen = 1;
int main(){
  P1DIR |= LED_GREEN;
  P1OUT |= LED_GREEN;
  configureClocks();
  switch_init();
  buzzer_init();
  led_init();
  
  lcd_init();
  enableWDTInterrupts();
  
  
  or_sr(0x8); 
  clearScreen(COLOR_BLUE);
  drawhouse(40);
  while(1){
    P1OUT &= ~LED_GREEN;
    or_sr(0x10);

    P1OUT |= LED_GREEN;
  
    redrawScreen = 1;
  }
  /*  for(;;){
    while(!redrawScreen){
      P1OUT &= ~LED_GREEN;
      or_sr(0x10);
      
    }
    P1OUT |= LED_GREEN;
    redrawScreen = 0;
    }*/
}

void wdt_c_handler(){
  static short count = 0;

  count++;
  if(count == 125){
    state_advance();
    count = 0;

  }

  
    /*
    if (switch_state_changed == 2){
      if (count == 5){
        state_advance();
        count = 0;
      }
      }*/
}

