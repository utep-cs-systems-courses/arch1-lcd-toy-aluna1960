/** \file lcddemo.c
 *  \brief A simple demo that draws a string and circle
 */

#include <libTimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include <p2switches.h>


/** Initializes everything, clears the screen, draws "hello" and the circle */
void main()
{
  configureClocks();
  lcd_init();
  p2sw_init(15);
  or_sr(0x8);			/* GIE (enable interrupts) */
  u_char width = screenWidth, height = screenHeight;

  clearScreen(COLOR_BLUE);

  drawString5x7(10,10, "switches:", COLOR_GREEN, COLOR_BLUE);
  while (1) {
    u_int switches = p2sw_read(), i;
    char str[4];
    for (i = 0; i < 3; i++)
      str[i] = (switches & (1<<i)) ? '-' : '0'+5;
    str[3] = 0;
    drawString5x7(20,20, str, COLOR_GREEN, COLOR_BLUE);
  } 
}
