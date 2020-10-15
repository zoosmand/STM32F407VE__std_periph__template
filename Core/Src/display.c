/* Includes ------------------------------------------------------------------*/
#include "display.h"


/* Private variables ---------------------------------------------------------*/
/**
  * @brief  Dotted 15x21 pixels font, white, dark-green backgrounded.
  * 18x24 pixels rectangle on the screen.
  */
 const Font_TypeDef font_dot15x21 = {
  .width    = 18,
  .height   = 24,
  .color    = RGB565_White,
  .bgcolor  = RGB565_Darkgreen,
  .use_bg   = 1,
  .font     = (uint8_t*)font_15x21
};

/**
  * @brief  Dotted 20x28 pixels font, white, dark-green backgrounded.
  * 24x32 pixels rectangle on the screen.
  */
 const Font_TypeDef font_dot20x28 = {
  .width    = 24,
  .height   = 32,
  .color    = RGB565_White,
  .bgcolor  = RGB565_Darkgreen,
  .use_bg   = 1,
  .font =   (uint8_t*)font_20x28
};

static uint16_t xStart = 0;
static uint16_t yStart = 0;


/* Private function prototypes -----------------------------------------------*/











////////////////////////////////////////////////////////////////////////////////

void Display_Handler(Display_TypeDef device) {
  //
  DrawVLine(60, 20, 50, RGB565_White);

  DrawHLine(30, 10, 180, RGB565_Yellow);

  FillRectangle(150, 30, 100, 22, RGB565_Orange);

  // xStart = 20;
  // yStart = 160;

  // char *buf = "Hello!!!";

  // PrintString(&xStart, &yStart, &font_dot20x28, "Hello!!!", 0);

  static char dateStr[11];
  static char timeStr[11];
    // // uint32_t tm = LL_RTC_TIME_Get(RTC);
    // // uint32_t dt = LL_RTC_DATE_Get(RTC);
    
  sprintf(timeStr, "%2x:%02x:%02x", RTC_GetHour, RTC_GetMinute, RTC_GetSecond);
  sprintf(dateStr, "%2x/%x/%4x", RTC_GetDay, RTC_GetMonth, RTC_GetYear);
    // printf("date: %s\n", dateStr);
    // printf("time: %s\n", timeStr);

    // PrintDate(L1, dateStr);
    // PrintTime(L1, timeStr);

  xStart = 25;
  yStart = 100;
  PrintString(&xStart, &yStart, &font_dot20x28, timeStr, 0);

  xStart = 30;
  yStart = 140;
  PrintString(&xStart, &yStart, &font_dot15x21, dateStr, 0);

}







void SetRectangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1) {
  ILI9341_WriteCmd(ILI9341_CASET);
  ILI9341_WriteData(y0);
  ILI9341_WriteData(y1);
  
  ILI9341_WriteCmd(ILI9341_PASET);
  ILI9341_WriteData(x0);
  ILI9341_WriteData(x1);

  ILI9341_WriteCmd(ILI9341_RAMWR);
}











void FillRectangle(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color) {
  if ((x >= DISPLAY_WIDTH) || (y >= DISPLAY_HEIGHT) || (w == 0) || (h == 0)) return;
  if ((x + w - 1) >= DISPLAY_WIDTH)  w = DISPLAY_WIDTH  - x;
  if ((y + h - 1) >= DISPLAY_HEIGHT) h = DISPLAY_HEIGHT - y;

  SetRectangle(x, y, (x + w - 1), (y + h -1));
  
  uint16_t ww = 0;
  while (h--) {
    ww = w;
    while (ww--) {
      ILI9341_SetColor(color);
    }
  }
}







void DrawVLine(uint16_t x, uint16_t y, uint16_t h, uint16_t color) {
  if ((x >= DISPLAY_HEIGHT) || (y >= DISPLAY_WIDTH)) return;
  if ((y + h - 1) >= DISPLAY_HEIGHT)  h = DISPLAY_HEIGHT - y;

  ILI9341_WriteCmd(ILI9341_CASET);
  ILI9341_WriteData(y);
  ILI9341_WriteData(y + h - 1);

  ILI9341_WriteCmd(ILI9341_PASET);
  ILI9341_WriteData(x);
  ILI9341_WriteData(x);
  
  ILI9341_WriteCmd(ILI9341_RAMWR);
  
  while (h--) {
    ILI9341_SetColor(color);
  }
}







void DrawHLine(uint16_t x, uint16_t y, uint16_t w, uint16_t color) {
  if ((x >= DISPLAY_HEIGHT) || (y >= DISPLAY_WIDTH)) return;
  if ((x + w - 1) >= DISPLAY_WIDTH)  w = DISPLAY_WIDTH - x;

  ILI9341_WriteCmd(ILI9341_CASET);
  ILI9341_WriteData(y);
  ILI9341_WriteData(y);

  ILI9341_WriteCmd(ILI9341_PASET);
  ILI9341_WriteData(x);
  ILI9341_WriteData(x + w - 1);
  
  ILI9341_WriteCmd(ILI9341_RAMWR);
  
  while (w--) {
    ILI9341_SetColor(color);
  }
}







void DrawSymbol(uint16_t *x, uint16_t *y, const Font_TypeDef *font, uint8_t pos) {
  if ((pos > 126) || (pos < 32)) {
    if (pos == 176) pos = 95;
    else return;
  } else {
    pos -= 32;
  }   

  int16_t w = font->width;
  int16_t h = font->height;
  if ((*x >= DISPLAY_WIDTH) || (*y >= DISPLAY_HEIGHT) || (w == 0) || (h == 0)) return;
  if ((*x + w - 1) >= DISPLAY_WIDTH)  w = DISPLAY_WIDTH  - *x;
  if ((*y + h - 1) >= DISPLAY_HEIGHT) h = DISPLAY_HEIGHT - *y;

  uint8_t smb = 0;
  uint8_t z = 0;
  uint8_t hh = 0;
  uint8_t *symbols = font->font;
  
  SetRectangle(*x, *y, (*x + w - 1), (*y + h -1));
  *x += w;
  
  while (w--) {
    z = font->height / 8;
    while (z--) {
      smb = symbols[(pos * font->width * (font->height / 8))];
      symbols++;
      
      hh = 8;
      while (hh--) {
        if (smb & 0x01) {
          ILI9341_SetColor(font->color);
        } else {
          if (font->use_bg) {
            ILI9341_SetColor(font->bgcolor);
          } else {
            // ToDo; to read the pixel and write it down again
          }
        }
        smb >>= 1;
      }
    }
  }
}





/**
  * @brief  Print a string on a layer of display
  * @param  x: pointer to x coordinate
  * @param  y: pointer to y coordinate 
  * @param  font: pointer to font structure containes font paramenters:
  *               - width of a symbol
  *               - height of a symbol
  *               - color of a symbol
  *               - background color behind a symbol
  *               - flag - use or not use background color
  *               - array of symbols
  * @param  buf: pointer to buffer with a string
  * @param  wrap: wrap or not wrap to the next line 
  * @return None
  */
void PrintString(uint16_t *x, uint16_t *y, const Font_TypeDef *font, const char *buf, uint8_t wrap) {
  while (*buf) {
    if (*x > DISPLAY_WIDTH - 20) {
      if (wrap) {
        *x = 20;
        *y -= font->height;
      } else {
        return;
      }
    }
    DrawSymbol(x, y, font, *buf);
    buf++;
  }
}
