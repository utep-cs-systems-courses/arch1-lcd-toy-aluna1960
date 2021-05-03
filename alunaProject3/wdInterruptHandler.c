#include <msp430.h>
#include "buzzer.h"
#include "stateMachines.h"
#include "switches.h"
#include "led.h"

char button = 0;
void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char buzz_count = 0;


  static char blink_count = 0;

  
  
  if (++blink_count == 125 && musicSw == 1) {    
    noise();
    blink_count = 0;
  }

  if (musicSw == 0){
    buzzer_set_period(0);
  }
  
}
