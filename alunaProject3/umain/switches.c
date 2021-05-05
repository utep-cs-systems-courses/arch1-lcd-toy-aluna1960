#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "stateMachines.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"



char switch_state_down, switch_state_changed,sw1,sw2,sw3,sw4,musicSw; /* effectively boolean */

int redrawScreen;
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

  if (p1val & SW1 ? 0 : 1){
    switch_state_changed = 1;
    redrawScreen = 1;

  }
  if (p1val & SW2 ? 0 : 1){
    switch_state_changed = 2;
    redrawScreen = 1;
  }

  if (p1val & SW3 ? 0 : 1){
    switch_state_changed = 3;
    redrawScreen = 1;
  }
  /*else if (p1val & SW4 ? 0 : 1){
    switch_state_changed = 4;
    redrawScreen = 1;
    }*/
  else{
    clearScreen(COLOR_BLUE);
    switch_state_changed = 0;

  }
}
