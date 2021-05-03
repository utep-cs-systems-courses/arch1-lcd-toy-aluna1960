#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "shape.h"

const AbRect rect10 = {abRectGetBounds, abRectCheck, 10,10};;

void
abDrawPos(AbShape *shape, Vec2 *shapeCenter, u_int fg_color, u_int bg_color)
{
  u_char row, col;
  Region bounds;
  abShapeGetBounds(shape, shapeCenter, &bounds);
  lcd_setArea(bounds.topLeft.axes[0], bounds.topLeft.axes[1],
	      bounds.botRight.axes[0]-1, bounds.botRight.axes[1]-1);
  for (row = bounds.topLeft.axes[1]; row < bounds.botRight.axes[1]; row++) {
    for (col = bounds.topLeft.axes[0]; col < bounds.botRight.axes[0]; col++) {
      Vec2 pixelPos = {col, row};
      int color = abShapeCheck(shape, shapeCenter, &pixelPos) ?
	fg_color : bg_color;
      lcd_writeColor(color);
    }
  }
}



int
main()
{
  configureClocks();
  lcd_init();
  shapeInit();
  Vec2 rectPos = screenCenter;

  clearScreen(COLOR_BLUE);
  //drawString5x7(20,20, "hello", COLOR_GREEN, COLOR_RED);
  shapeInit();
  
  //abDrawPos((AbShape*)&rect10, &rectPos, COLOR_ORANGE, COLOR_BLUE);
  int smallT = 1;
  int offset_rT1 = 50;
  int offset_cT1 = 70;
  
  
  int size = 70;
  for(int r = 0; r < 40; r++){
    for(int c = 0; c < r; c++){
      drawPixel(c+offset_cT1,r+offset_rT1,COLOR_RED);
      drawPixel(-c+offset_cT1,r+offset_rT1,COLOR_RED);
      //drawPixel(c-r,r,COLOR_RED);
      //fillRectangle(20,20,40,40,COLOR_RED);
      //fillRectangle(90,90,110,110,COLOR_RED);
      /*if((smallT+size)<100){ 
	drawPixel((c-50),size+smallT,COLOR_RED);
	drawPixel((c-50),size+smallT,COLOR_RED);
	}*/
    }
  }
  fillRectangle(30,90,30,30,COLOR_RED);
  fillRectangle(80,90,30,30,COLOR_RED);
  fillRectangle(35,65,20,20,COLOR_RED);
}


