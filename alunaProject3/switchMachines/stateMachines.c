
#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
//#include "switches.h"

int button;
int i;
int hertz;

void noise(){
  static char sound_state = 0;
  
  switch(sound_state){
  case 0:
    hertz = 1318; //E6
    buzzer_set_period(hertz);
    hertz = 0;
    sound_state = 1;
    break;
  case 1:
    hertz = 587; //D5
    buzzer_set_period(hertz);
    sound_state = 2;
    hertz = 0;
    break;
  case 2:
    hertz = 1318; //E6
    buzzer_set_period(hertz);
    sound_state = 3;
    hertz = 0;
    break;
  case 3:
    hertz = 587; //D5
    buzzer_set_period(hertz);
    sound_state = 4;
    hertz = 0;
    break;
  case 4:
    hertz = 1318; //E6
    buzzer_set_period(hertz);
    sound_state = 5;
    hertz = 0;
    break;
  case 5:
    hertz = 247; //B3
    buzzer_set_period(hertz);
    sound_state = 6;
    hertz = 0;
    break;
  case 6:
    hertz = 587; //D4
    buzzer_set_period(hertz);
    sound_state = 7;
    hertz = 0;
    break;
  case 7:
    hertz = 261; //C4
    buzzer_set_period(hertz);
    sound_state = 8;
    hertz = 0;
    break;
  case 8:
    hertz = 220; //A2
    buzzer_set_period(hertz);
    sound_state = 9;
    hertz = 0;
    break;
  case 9:
    hertz = 130; //C2
    buzzer_set_period(hertz);
    sound_state = 10;
    hertz = 0;
    break;
  case 10:
    hertz = 164; //E3
    buzzer_set_period(hertz);
    sound_state = 11;
    hertz = 0;
    break;
  case 11:
    hertz = 880; //A5
    buzzer_set_period(hertz);
    sound_state = 12;
    hertz = 0;
    break;
  case 12:
    hertz = 988; //B5
    buzzer_set_period(hertz);
    sound_state = 13;
    hertz = 0;
    break;
  case 13:
    hertz = 164; //E2
    buzzer_set_period(hertz);
    sound_state = 14;
    hertz = 0;
    break;
  case 14:
    hertz = 196; //G3
    buzzer_set_period(hertz);
    sound_state = 15;
    hertz = 0;
    break;
  case 15:
    hertz = 988; //B5
    buzzer_set_period(hertz);
    sound_state = 16;
    hertz = 0;
    break;
  case 16:
    hertz = 1047; //C6
    buzzer_set_period(hertz);
    sound_state = 0;
    hertz = 0;
    break;
  }    
}  

void reset(){
  buzzer_set_period(0);
  red_on = 0;
  green_on = 0;
  led_changed = 1;
  led_update();
}

void lightPattern(){
  
  static char state_new = 0;
  switch(state_new){
  case 0:
    red_on=1;
    green_on=1;
    state_new = 1;
    break;
  case 1:
    red_on = 1;
    green_on = 0;
    state_new=2;
    break;
  case 2:
    red_on = 0;
    green_on = 1;
    state_new = 3;
    break;
  case 3:
    green_on = 1;
    red_on = 1;
    state_new = 0;
    break;
  }
  led_changed = 1;
  led_update();
 
}


