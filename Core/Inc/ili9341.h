#ifndef __ILI9341_H
#define __ILI9341_H

#ifdef __cplusplus
  extern "C" {
#endif 

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private typedef -----------------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/
// #define CS_H        PIN_H(LCD_CS_GPIO_Port,  LCD_CS_Pin_Pos)
// #define CS_L        PIN_L(LCD_CS_GPIO_Port,  LCD_CS_Pin_Pos)
#define BKL_H       PIN_H(LCD_BKL_GPIO_Port,  LCD_BKL_Pin_Pos)
#define BKL_L       PIN_L(LCD_BKL_GPIO_Port,  LCD_BKL_Pin_Pos)

#define ILI9341_WriteCmd(cmd) do { \
  *(__O uint8_t*)(DSPL_CMD) = (cmd); \
  __NOP(); \
} while (0);

#define ILI9341_WriteData8(data) do { \
  *(__O uint8_t*)(DSPL_DATA) = (data); \
  __NOP(); \
} while (0);

#define ILI9341_WriteData(data) do { \
  ILI9341_WriteData8(((data) >> 8) & 0xff); \
  ILI9341_WriteData8((data) & 0xff); \
} while (0);

#define ILI9341_SetColor(color) do { \
  *(__O uint16_t*)(DSPL_DATA) = (color); \
  __NOP(); \
} while (0);

#define ILI9341_ReadData()  (*(__I uint16_t*)(DSPL_WR))


/* Private defines -----------------------------------------------------------*/
/* ILI9341 Register defines */
#define ILI9341_NOP                 0x00
#define ILI9341_SOFTRESET           0x01
#define ILI9341_SLEEPIN             0x10
#define ILI9341_SLEEPOUT            0x11
#define ILI9341_NORMALDISP          0x13
#define ILI9341_INVERTOFF           0x20
#define ILI9341_INVERTON            0x21
#define ILI9341_GAMMASET            0x26
#define ILI9341_DISPLAYOFF          0x28
#define ILI9341_DISPLAYON           0x29
#define ILI9341_CASET               0x2a
#define ILI9341_PASET               0x2b
#define ILI9341_RAMWR               0x2c
#define ILI9341_RAMRD               0x2e
#define ILI9341_MEMCONTROL          0x36
#define ILI9341_PIXELFORMAT         0x3a
#define ILI9341_RGBSIGNAL           0xb0
#define ILI9341_FRAMECONTROL        0xb1
#define ILI9341_INVERSIONCONRTOL    0xb4
#define ILI9341_DISPLAYFUNC         0xb6
#define ILI9341_ENTRYMODE           0xb7
#define ILI9341_POWERCONTROL1       0xc0
#define ILI9341_POWERCONTROL2       0xc1
#define ILI9341_VCOMCONTROL1        0xc5
#define ILI9341_VCOMCONTROL2        0xc7
#define ILI9341_POWERCONTROLB       0xcf
#define ILI9341_POWERCONTROLA       0xcb
#define ILI9341_READID              0xd3
#define ILI9341_POSGAMMACORR        0xe0
#define ILI9341_NEGGAMMACORR        0xe1
#define ILI9341_DRIVERTIMINGA       0xe8
#define ILI9341_DRIVERTIMINGB       0xea
#define ILI9341_POWERONSEQ          0xed
#define ILI9341_ENABLE3G            0xf2
#define ILI9341_INTERFACECONTROL    0xf6
#define ILI9341_PUMPRATIOCONTROL    0xf7

// MADCTL Control Bit Definition
#define ILI9341_MADCTL_MY           0x80
#define ILI9341_MADCTL_MX           0x40
#define ILI9341_MADCTL_MV           0x20
#define ILI9341_MADCTL_ML           0x10
#define ILI9341_MADCTL_BGR          0x08
#define ILI9341_MADCTL_MH           0x04



/* Exported functions prototypes ---------------------------------------------*/
void ILI9341_Init(void);


#ifdef __cplusplus
}
#endif

#endif /* __ILI9341_H */
