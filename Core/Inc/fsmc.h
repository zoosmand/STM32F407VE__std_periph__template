/**
  ******************************************************************************
  * File Name          : fsmc.h
  * Description        : This file provides code for the configuration
  *                      of the FSMC peripheral.
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __FSMC_H
#define __FSMC_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"


/* Private defines -----------------------------------------------------------*/
#define NORSRAM_BANK1             0
#define NORSRAM_BANK2             2
#define NORSRAM_BANK3             4
#define NORSRAM_BANK4             6

#define CHOSEN_BANK               NORSRAM_BANK4

#if (CHOSEN_BANK == NORSRAM_BANK1)
  #define DSPL_DATA               (__O uint32_t)0x60080000
  #define DSPL_CMD                (__O uint32_t)0x60000000
#elif (CHOSEN_BANK == NORSRAM_BANK2)
  #define DSPL_DATA               (__O uint32_t)0x64080000
  #define DSPL_CMD                (__O uint32_t)0x64000000
#elif (CHOSEN_BANK == NORSRAM_BANK3)
  #define DSPL_DATA               (__O uint32_t)0x68080000
  #define DSPL_CMD                (__O uint32_t)0x68000000
#elif (CHOSEN_BANK == NORSRAM_BANK4)
  #define DSPL_DATA               (__O uint32_t)0x6c080000
  #define DSPL_CMD                (__O uint32_t)0x6c000000
#endif

// PD14
#define LCD_D0_Pin                GPIO_PIN_14
#define LCD_D0_Pin_Pos            GPIO_PIN_14_Pos
#define LCD_D0_Pin_Mask           GPIO_PIN_14_Mask
#define LCD_D0_GPIO_Port          GPIOD
// PD15
#define LCD_D1_Pin                GPIO_PIN_15
#define LCD_D1_Pin_Pos            GPIO_PIN_15_Pos
#define LCD_D1_Pin_Mask           GPIO_PIN_15_Mask
#define LCD_D1_GPIO_Port          GPIOD
// PD0
#define LCD_D2_Pin                GPIO_PIN_0
#define LCD_D2_Pin_Pos            GPIO_PIN_0_Pos
#define LCD_D2_Pin_Mask           GPIO_PIN_0_Mask
#define LCD_D2_GPIO_Port          GPIOD
// PD1
#define LCD_D3_Pin                GPIO_PIN_1
#define LCD_D3_Pin_Pos            GPIO_PIN_1_Pos
#define LCD_D3_Pin_Mask           GPIO_PIN_1_Mask
#define LCD_D3_GPIO_Port          GPIOD
// PE7
#define LCD_D4_Pin                GPIO_PIN_7
#define LCD_D4_Pin_Pos            GPIO_PIN_7_Pos
#define LCD_D4_Pin_Mask           GPIO_PIN_7_Mask
#define LCD_D4_GPIO_Port          GPIOE
// PE8
#define LCD_D5_Pin                GPIO_PIN_8
#define LCD_D5_Pin_Pos            GPIO_PIN_8_Pos
#define LCD_D5_Pin_Mask           GPIO_PIN_8_Mask
#define LCD_D5_GPIO_Port          GPIOE
// PE9
#define LCD_D6_Pin                GPIO_PIN_9
#define LCD_D6_Pin_Pos            GPIO_PIN_9_Pos
#define LCD_D6_Pin_Mask           GPIO_PIN_9_Mask
#define LCD_D6_GPIO_Port          GPIOE
// PE10
#define LCD_D7_Pin                GPIO_PIN_10
#define LCD_D7_Pin_Pos            GPIO_PIN_10_Pos
#define LCD_D7_Pin_Mask           GPIO_PIN_10_Mask
#define LCD_D7_GPIO_Port          GPIOE
// PE11
#define LCD_D8_Pin                GPIO_PIN_11
#define LCD_D8_Pin_Pos            GPIO_PIN_11_Pos
#define LCD_D8_Pin_Mask           GPIO_PIN_11_Mask
#define LCD_D8_GPIO_Port          GPIOE
// PE12
#define LCD_D9_Pin                GPIO_PIN_12
#define LCD_D9_Pin_Pos            GPIO_PIN_12_Pos
#define LCD_D9_Pin_Mask           GPIO_PIN_12_Mask
#define LCD_D9_GPIO_Port          GPIOE
// PE13
#define LCD_D10_Pin               GPIO_PIN_13
#define LCD_D10_Pin_Pos           GPIO_PIN_13_Pos
#define LCD_D10_Pin_Mask          GPIO_PIN_13_Mask
#define LCD_D10_GPIO_Port         GPIOE
// PE14
#define LCD_D11_Pin               GPIO_PIN_14
#define LCD_D11_Pin_Pos           GPIO_PIN_14_Pos
#define LCD_D11_Pin_Mask          GPIO_PIN_14_Mask
#define LCD_D11_GPIO_Port         GPIOE
// PE15
#define LCD_D12_Pin               GPIO_PIN_15
#define LCD_D12_Pin_Pos           GPIO_PIN_15_Pos
#define LCD_D12_Pin_Mask          GPIO_PIN_15_Mask
#define LCD_D12_GPIO_Port         GPIOE
// PD8
#define LCD_D13_Pin               GPIO_PIN_8
#define LCD_D13_Pin_Pos           GPIO_PIN_8_Pos
#define LCD_D13_Pin_Mask          GPIO_PIN_8_Mask
#define LCD_D13_GPIO_Port         GPIOD
// PD9
#define LCD_D14_Pin               GPIO_PIN_9
#define LCD_D14_Pin_Pos           GPIO_PIN_9_Pos
#define LCD_D14_Pin_Mask          GPIO_PIN_9_Mask
#define LCD_D14_GPIO_Port         GPIOD
// PD10
#define LCD_D15_Pin               GPIO_PIN_10
#define LCD_D15_Pin_Pos           GPIO_PIN_10_Pos
#define LCD_D15_Pin_Mask          GPIO_PIN_10_Mask
#define LCD_D15_GPIO_Port         GPIOD
// PD4
#define LCD_RD_Pin                GPIO_PIN_4
#define LCD_RD_Pin_Pos            GPIO_PIN_4_Pos
#define LCD_RD_Pin_Mask           GPIO_PIN_4_Mask
#define LCD_RD_GPIO_Port          GPIOD
// PD5
#define LCD_WR_Pin                GPIO_PIN_5
#define LCD_WR_Pin_Pos            GPIO_PIN_5_Pos
#define LCD_WR_Pin_Mask           GPIO_PIN_5_Mask
#define LCD_WR_GPIO_Port          GPIOD
// PD7
#define LCD_CS_Pin                GPIO_PIN_7
#define LCD_CS_Pin_Pos            GPIO_PIN_7_Pos
#define LCD_CS_Pin_Mask           GPIO_PIN_7_Mask
#define LCD_CS_GPIO_Port          GPIOD
// PD13, FSMC A18
#define LCD_RS_Pin                GPIO_PIN_13
#define LCD_RS_Pin_Pos            GPIO_PIN_13_Pos
#define LCD_RS_Pin_Mask           GPIO_PIN_13_Mask
#define LCD_RS_GPIO_Port          GPIOD
// PB1, Backlight
#define LCD_BKL_Pin               GPIO_PIN_1
#define LCD_BKL_Pin_Pos           GPIO_PIN_1_Pos
#define LCD_BKL_Pin_Mask           GPIO_PIN_1_Mask
#define LCD_BKL_GPIO_Port         GPIOB
// PC5, Touchscreen interrupt
#define LCD_TC_INT_Pin            GPIO_PIN_5
#define LCD_TC_INT_Pin_Pos        GPIO_PIN_5_Pos
#define LCD_TC_INT_Pin_Mask       GPIO_PIN_5_Mask
#define LCD_TC_INT_GPIO_Port      GPIOC


/* FSMC NORSRAM Register's Bit definitions */
#define DATA_ADDR_MUX_DIS         0x00000000
#define DATA_ADDR_MUX_EN          0x00000002
#define MEM_TYPE_SRAM             0x00000000
#define MEM_TYPE_PSRAM            0x00000004
#define MEM_TYPE_NOR              0x00000008
#define NORSRAM_BUS_W8            0x00000000
#define NORSRAM_BUS_W16           0x00000010
#define NORSRAM_BUS_W32           0x00000020
#define BURST_MODE_DIS            0x00000000 
#define BURST_MODE_EN             0x00000100
#define WAIT_SIG_POL_LOW          0x00000000
#define WAIT_SIG_POL_HIGH         0x00000200
#define WRAP_MODE_DIS             0x00000000
#define WRAP_MODE_EN              0x00000400
#define WAIT_BEFORE               0x00000000
#define WAIT_DURING               0x00000800
#define WR_OP_DIS                 0x00000000
#define WR_OP_EN                  0x00001000
#define WAIT_SIG_DIS              0x00000000
#define WAIT_SIG_EN               0x00002000
#define EXT_MODE_DIS              0x00000000
#define EXT_MODE_EN               0x00004000
#define ASYNC_WAIT_DIS            0x00000000
#define ASYNC_WAIT_EN             0x00008000
#define PAGE_SIZE_NONE            0x00000000U
#define PAGE_SIZE_128             FSMC_BCR1_CPSIZE_0
#define PAGE_SIZE_256             FSMC_BCR1_CPSIZE_1
#define PAGE_SIZE_512             (FSMC_BCR1_CPSIZE_0 | FSMC_BCR1_CPSIZE_1)
#define PAGE_SIZE_1024            FSMC_BCR1_CPSIZE_2
#define WRITE_BURST_DIS           0x00000000
#define WRITE_BURST_EN            0x00080000
#define NORSRAM_FLAC_DIS          0x00000000
#define NORSRAM_FLAC_EN           0x00000040
#define ACCESS_MODE_A             0x00000000
#define ACCESS_MODE_B             0x10000000
#define ACCESS_MODE_C             0x20000000
#define ACCESS_MODE_D             0x30000000




/* Exported functions prototypes ---------------------------------------------*/
void FSMC_Init(void);


#ifdef __cplusplus
}
#endif
#endif /*__FSMC_H */
