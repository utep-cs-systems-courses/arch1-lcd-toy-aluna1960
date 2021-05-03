#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "p2switches.h"

#define LED_GREEN BIT6             // P1.6


short redrawScreen = 1;
u_int fontFgColor = COLOR_GREEN;

u_int object = 10;
u_int objectNext = 10;
signed int speed = 2;
void wdt_c_handler()
{
  static int secCount = 0;
  static int desCount = 0;
  secCount ++;
  desCount ++;
  if (secCount == 250) {		/* once/sec */
    secCount = 0;
    fontFgColor = (fontFgColor == COLOR_GREEN) ? COLOR_BLACK : COLOR_GREEN;
    redrawScreen = 1;
  }
  if (desCount == 25){
    desCount = 0;
    objectNext += speed;
    if (objectNext >60 || objectNext <= 10){
      speed = -speed;
      objectNext += speed;
    }
    redrawScreen = 1;
	
  }
}
 
  

void main()
{
  P1DIR |= LED_GREEN;		/**< Green led on when CPU on */		
  P1OUT |= LED_GREEN;
  configureClocks();
  lcd_init();
  
  enableWDTInterrupts();      /**< enable periodic interrupt */
  or_sr(0x8);	              /**< GIE (enable interrupts) */
  int offset_c = 20;
  int offset_r = 50;
  clearScreen(COLOR_BLUE);
  int x = 10;
  int p = 1;
  while (1) {			/* forever */

    if (redrawScreen) {
      redrawScreen = 0;
      
      drawString5x7(object,20+x, "hello", COLOR_BLUE,COLOR_BLUE);
      drawString5x7(objectNext,20+x, "hello", fontFgColor, COLOR_BLUE);

      fillRectangle(object,20+x,60,60,COLOR_ORANGE);
      fillRectangle(objectNext,20+x,60,60,COLOR_ORANGE);
      //fillRectangle(object,20,60,60,COLOR_GREEN);
      
      clearScreen(COLOR_BLUE);
      //fillRectangle(objectNext,20,60,60,COLOR_ORANGE);
      object = objectNext;
      if(x%60==0){
	if(p==1){
	  p=0;
	}
	else{
	  p = 1;
	}
      }
 
      if(p==1){
	x+=10;
      }
      else{
	x=x-10;
      }
    }
    P1OUT &= ~LED_GREEN;	/* green off */
    or_sr(0x10);		/**< CPU OFF */
    P1OUT |= LED_GREEN;		/* green on */
  }
}

    
    



