#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "stateMachines.h"
#include "buzzer.h"

char switch_state_down, switch_state_changed,sw1,sw2,sw3,sw4,musicSw; /* effectively boolean */

char buttons;
static char 
switch_update_interrupt_sense()
{
  char p1val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p1val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p1val | ~SWITCHES);	/* if switch down, sense up */
  return p1val;
}

void 
switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE |= SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  led_update();
}

int
switch_interrupt_handler()
{
  char p1val = switch_update_interrupt_sense();

  sw1 = (p1val & SW1) ? 0 : 1; /* 0 when SW1 is up */
  sw2 = (p1val & SW2) ? 0 : 1;
  sw3 = (p1val & SW3) ? 0 : 1;
  sw4 = (p1val & SW4) ? 0 : 1;
  
  
  //led_update();
  if(sw1){
    musicSw = 1;
  }
  if(sw2){
    light();
  }
  if(sw3){
    reset();
  }
  if(sw4){
    musicSw = 0;
  }
}
