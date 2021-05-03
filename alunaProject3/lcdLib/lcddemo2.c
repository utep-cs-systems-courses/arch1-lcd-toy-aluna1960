/** \file lcddemo.c
 *  \brief A simple demo that draws a string and square
 */

#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

/** Initializes everything, clears the screen, draws "hello" and a square */
int
main()
{
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;

  clearScreen(COLOR_BLUE);

  drawString5x7(20,20, "hello", COLOR_GREEN, COLOR_RED);
  fillTriangle(30,30,COLOR_PURPLE);
  //fillRectangle(30,30, 60, 60, COLOR_ORANGE);
  u_char offset_r = 50, offset_c = 50;
  /*for (int r = 0; r<=10;r++){
    for(int c = 0; c<= r; c++){
      // drawPixel(offset_c + c+r, offset_r + r-c, COLOR_ORANGE);
      fillRectangle(r,c,80,20)
    }
    }*/
  //fillRectangle();
  
}
