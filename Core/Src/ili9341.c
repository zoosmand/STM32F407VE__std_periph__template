/* Includes ------------------------------------------------------------------*/
#include "ili9341.h"


/* Private variables ---------------------------------------------------------*/
// static uint16_t ddd = 0;

/* Private function prototypes -----------------------------------------------*/








////////////////////////////////////////////////////////////////////////////////

void ILI9341_Init(void) {
  Delay(50);

  // ILI9341_WriteCmd(ILI9341_READID);

  // ILI9341_ReadData();
  // if (!(ILI9341_ReadData())) {
  //   ddd = (ILI9341_ReadData() << 8) & 0xff00;
  //   ddd |= ILI9341_ReadData() & 0x00ff;
  // }

  // if (ddd != 9341) return;


  ILI9341_WriteCmd(ILI9341_SOFTRESET); // 0x01
  Delay(5);

  ILI9341_WriteCmd(0x28); // 0x28
  Delay(5);
  ILI9341_WriteCmd(ILI9341_NOP);
 
  // ----------------- Power ------------------
  ILI9341_WriteCmd(ILI9341_POWERCONTROL1); // 0xc0
  ILI9341_WriteData8(0x26);
  ILI9341_WriteCmd(ILI9341_POWERCONTROL2); // 0xc1
  ILI9341_WriteData8(0x11);
  ILI9341_WriteCmd(ILI9341_VCOMCONTROL1); // 0xc5
  ILI9341_WriteData8(0x5c);
  ILI9341_WriteData8(0x4c);
  ILI9341_WriteCmd(ILI9341_VCOMCONTROL2); // 0xc7
  ILI9341_WriteData8(0x94);
  
  // ---------------- Memory ------------------
  ILI9341_WriteCmd(ILI9341_MEMCONTROL); // 0x36
  // -------- Portrait ---------
  #ifdef _PORTRAIT_
    ILI9341_WriteData8(ILI9341_MADCTL_BGR | ILI9341_MADCTL_MV | ILI9341_MADCTL_MX | ILI9341_MADCTL_MY);
  #endif
  // -------- Landscape --------
  #ifdef _LANDSCAPE_
    ILI9341_WriteData8(ILI9341_MADCTL_BGR | ILI9341_MADCTL_MY);
  #endif
  
  ILI9341_WriteCmd(ILI9341_PIXELFORMAT); // 0x3a
  ILI9341_WriteData8(0x55);

  
  // // -------------- Frame rate ---------------
  ILI9341_WriteCmd(ILI9341_FRAMECONTROL); // 0xb1
  ILI9341_WriteData8(0x00);
  ILI9341_WriteData8(0x1b);
  
  // ---------------- Gamma ------------------
  ILI9341_WriteCmd(ILI9341_GAMMASET); // 0x26
  ILI9341_WriteData8(0x01);
  // ILI9341_WriteCmd(ILI9341_POSGAMMACORR); // 0xe0
  // ILI9341_WriteData(0x001f);
  // ILI9341_WriteData(0x001a);
  // ILI9341_WriteData(0x0018);
  // ILI9341_WriteData(0x000a);
  // ILI9341_WriteData(0x000f);
  // ILI9341_WriteData(0x0006);
  // ILI9341_WriteData(0x0045);
  // ILI9341_WriteData(0x0087);
  // ILI9341_WriteData(0x0032);
  // ILI9341_WriteData(0x000a);
  // ILI9341_WriteData(0x0007);
  // ILI9341_WriteData(0x0002);
  // ILI9341_WriteData(0x0007);
  // ILI9341_WriteData(0x0005);
  // ILI9341_WriteData(0x0000);
  // ILI9341_WriteCmd(ILI9341_NEGGAMMACORR); // 0xe1
  // ILI9341_WriteData(0x0000);
  // ILI9341_WriteData(0x0025);
  // ILI9341_WriteData(0x0027);
  // ILI9341_WriteData(0x0005);
  // ILI9341_WriteData(0x0010);
  // ILI9341_WriteData(0x0009);
  // ILI9341_WriteData(0x003a);
  // ILI9341_WriteData(0x0078);
  // ILI9341_WriteData(0x004d);
  // ILI9341_WriteData(0x0005);
  // ILI9341_WriteData(0x0018);
  // ILI9341_WriteData(0x000d);
  // ILI9341_WriteData(0x0038);
  // ILI9341_WriteData(0x003a);
  // ILI9341_WriteData(0x001f);
  
  // ---------------- DDRAM -------------------  
  // ILI9341_WriteCmd(ILI9341_CASET); // 0x2a
  // ILI9341_WriteData8(0x00);
  // ILI9341_WriteData8(0x00);
  // ILI9341_WriteData8(0x00);
  // ILI9341_WriteData8(0xef);
  // ILI9341_WriteCmd(ILI9341_PASET); // 0x2b
  // ILI9341_WriteData8(0x00);
  // ILI9341_WriteData8(0x00);
  // ILI9341_WriteData8(0x01);
  // ILI9341_WriteData8(0x3f);
  // ILI9341_WriteCmd(ILI9341_RAMWR); // 0x2c

  ILI9341_WriteCmd(ILI9341_ENTRYMODE); // 0xb7
  ILI9341_WriteData8(0x07);

  // --------------- Display -----------------
  ILI9341_WriteCmd(ILI9341_DISPLAYFUNC); // 0xb6
  ILI9341_WriteData8(0x0a);
  ILI9341_WriteData8(0x82);
  ILI9341_WriteData8(0x27);
  ILI9341_WriteData8(0x00);
  // ILI9341_WriteCmd(ILI9341_INVERTON);

  ILI9341_WriteCmd(ILI9341_ENABLE3G); // 0xf2
  ILI9341_WriteData8(0x03);

  ILI9341_WriteCmd(ILI9341_PUMPRATIOCONTROL); //0xf7
  ILI9341_WriteData8(0x20);
  
  ILI9341_WriteCmd(ILI9341_SLEEPOUT); // 0x11
  Delay(5);
  ILI9341_WriteCmd(ILI9341_DISPLAYON); // 0x29
  Delay(5);

  /* Fill the efault background */
  FillRectangle(0, 0, DISPLAY_WIDTH, DISPLAY_HEIGHT, RGB565_Darkgreen);
}

