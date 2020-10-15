/**
  ******************************************************************************
  * File Name          : fsmc.c
  * Description        : This file provides code for the configuration
  *                      of the FSMC peripheral.
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "fsmc.h"







void FSMC_Init(void) {
  /* ----------------------------------------------------------------------------- */
  /* ----------------------------------------------------------------------------- */
  /* ----------------------------------------------------------------------------- */
  #define E_MASK     (LCD_D4_Pin_Mask | LCD_D5_Pin_Mask | LCD_D6_Pin_Mask | LCD_D7_Pin_Mask | LCD_D8_Pin_Mask \
                    | LCD_D9_Pin_Mask | LCD_D10_Pin_Mask | LCD_D11_Pin_Mask | LCD_D12_Pin_Mask)

  /* Mode alternative */
  MODIFY_REG(GPIOE->MODER, E_MASK,
    (   (_MODE_AF << LCD_D4_Pin_Pos * 2)
      | (_MODE_AF << LCD_D5_Pin_Pos * 2)
      | (_MODE_AF << LCD_D6_Pin_Pos * 2)
      | (_MODE_AF << LCD_D7_Pin_Pos * 2)
      | (_MODE_AF << LCD_D8_Pin_Pos * 2)
      | (_MODE_AF << LCD_D9_Pin_Pos * 2)
      | (_MODE_AF << LCD_D10_Pin_Pos * 2)
      | (_MODE_AF << LCD_D11_Pin_Pos * 2)
      | (_MODE_AF << LCD_D12_Pin_Pos * 2)
    )
  );
  /* Speed very high */
  MODIFY_REG(GPIOE->OSPEEDR, E_MASK, 
    (   (_SPEED_V << LCD_D4_Pin_Pos * 2)
      | (_SPEED_V << LCD_D5_Pin_Pos * 2)
      | (_SPEED_V << LCD_D6_Pin_Pos * 2)
      | (_SPEED_V << LCD_D7_Pin_Pos * 2)
      | (_SPEED_V << LCD_D8_Pin_Pos * 2)
      | (_SPEED_V << LCD_D9_Pin_Pos * 2)
      | (_SPEED_V << LCD_D10_Pin_Pos * 2)
      | (_SPEED_V << LCD_D11_Pin_Pos * 2)
      | (_SPEED_V << LCD_D12_Pin_Pos * 2)
    )
  );
  /* Output type */
  /* Push mode */
  /* Alternate function */
  MODIFY_REG(GPIOE->AFR[0], 0xf0000000, (GPIO_AF_12 << LCD_D4_Pin_Pos * 4));
  
  MODIFY_REG(GPIOE->AFR[1], 0xffffffff, 
    (   (GPIO_AF_12 << (LCD_D5_Pin_Pos - 8) * 4)
      | (GPIO_AF_12 << (LCD_D6_Pin_Pos - 8) * 4)
      | (GPIO_AF_12 << (LCD_D7_Pin_Pos - 8) * 4)
      | (GPIO_AF_12 << (LCD_D8_Pin_Pos - 8) * 4)
      | (GPIO_AF_12 << (LCD_D9_Pin_Pos - 8) * 4)
      | (GPIO_AF_12 << (LCD_D10_Pin_Pos - 8) * 4)
      | (GPIO_AF_12 << (LCD_D11_Pin_Pos - 8) * 4)
      | (GPIO_AF_12 << (LCD_D12_Pin_Pos - 8) * 4)
    )
  );


  /* ----------------------------------------------------------------------------- */
  /* ----------------------------------------------------------------------------- */
  /* ----------------------------------------------------------------------------- */
  #define D_MASK     (LCD_D0_Pin_Mask | LCD_D1_Pin_Mask | LCD_D2_Pin_Mask | LCD_D3_Pin_Mask | LCD_D13_Pin_Mask \
                    | LCD_D14_Pin_Mask | LCD_D15_Pin_Mask | LCD_RD_Pin_Mask | LCD_WR_Pin_Mask | LCD_RS_Pin_Mask | LCD_CS_Pin_Mask)

  /* Mode alternative */
  MODIFY_REG(GPIOD->MODER, D_MASK, (
      (_MODE_AF << LCD_D0_Pin_Pos * 2)
    | (_MODE_AF << LCD_D1_Pin_Pos * 2)
    | (_MODE_AF << LCD_D2_Pin_Pos * 2)
    | (_MODE_AF << LCD_D3_Pin_Pos * 2)
    | (_MODE_AF << LCD_D13_Pin_Pos * 2)
    | (_MODE_AF << LCD_D14_Pin_Pos * 2)
    | (_MODE_AF << LCD_D15_Pin_Pos * 2)
    | (_MODE_AF << LCD_RD_Pin_Pos * 2)
    | (_MODE_AF << LCD_WR_Pin_Pos * 2)
    | (_MODE_AF << LCD_RS_Pin_Pos * 2)
  ));
  /* Speed very high */
  MODIFY_REG(GPIOD->OSPEEDR, D_MASK, (
      (_SPEED_V << LCD_D0_Pin_Pos * 2)
    | (_SPEED_V << LCD_D1_Pin_Pos * 2)
    | (_SPEED_V << LCD_D2_Pin_Pos * 2)
    | (_SPEED_V << LCD_D3_Pin_Pos * 2)
    | (_SPEED_V << LCD_D13_Pin_Pos * 2)
    | (_SPEED_V << LCD_D14_Pin_Pos * 2)
    | (_SPEED_V << LCD_D15_Pin_Pos * 2)
    | (_SPEED_V << LCD_RD_Pin_Pos * 2)
    | (_SPEED_V << LCD_WR_Pin_Pos * 2)
    | (_SPEED_V << LCD_RS_Pin_Pos * 2)
    | (_SPEED_V << LCD_CS_Pin_Pos * 2)
  ));
  /* Output type */
  /* Push mode */
  /* Alternate function */
  MODIFY_REG(GPIOD->AFR[0], 0x00ff00ff, (
      (GPIO_AF_12 << LCD_D2_Pin_Pos * 4)
    | (GPIO_AF_12 << LCD_D3_Pin_Pos * 4)
    | (GPIO_AF_12 << LCD_RD_Pin_Pos * 4)
    | (GPIO_AF_12 << LCD_WR_Pin_Pos * 4)
    | (GPIO_AF_12 << LCD_CS_Pin_Pos * 4)
  ));
  
  MODIFY_REG(GPIOD->AFR[1], 0xfff00fff, (
      (GPIO_AF_12 << (LCD_D0_Pin_Pos - 8) * 4)
    | (GPIO_AF_12 << (LCD_D1_Pin_Pos - 8) * 4)
    | (GPIO_AF_12 << (LCD_D13_Pin_Pos - 8) * 4)
    | (GPIO_AF_12 << (LCD_D14_Pin_Pos - 8) * 4)
    | (GPIO_AF_12 << (LCD_D15_Pin_Pos - 8) * 4)
    | (GPIO_AF_12 << (LCD_RS_Pin_Pos - 8) * 4)
  ));


  /* ----------------------------------------------------------------------------- */
  /* ----------------------------------------------------------------------------- */
  /* ----------------------------------------------------------------------------- */
  /* Backlight */
  /* Mode output */
  MODIFY_REG(LCD_BKL_GPIO_Port->MODER, LCD_BKL_Pin_Mask, (_MODE_OUT << LCD_BKL_Pin_Pos * 2));
  BKL_H;



  /* ----------------------------------------------------------------------------- */
  /* ----------------------------------------------------------------------------- */
  /* ----------------------------------------------------------------------------- */
  /* Touch screen PC5, interrupt Init */
  /* Mode input, low speed */
  /* EXTI Touchscreen event */
  // SET_BIT(SYSCFG->EXTICR[1], (EXTI_PC << EXTI5_Pos)); // PC5, LCD Touchscreen int
  // NVIC_SetPriority(EXTI9_5_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 15, 0));
  // NVIC_EnableIRQ(EXTI9_5_IRQn);



  /* Setup FSMC Bank1, NORSRAM */
  MODIFY_REG(FSMC_Bank1->BTCR[CHOSEN_BANK], 0x000fffff, (
      DATA_ADDR_MUX_DIS
    | MEM_TYPE_NOR
    | NORSRAM_BUS_W16
    | BURST_MODE_DIS
    | WAIT_SIG_POL_LOW
    | WRAP_MODE_DIS
    | WAIT_BEFORE
    | WR_OP_EN
    | WAIT_SIG_DIS
    | EXT_MODE_DIS
    | ASYNC_WAIT_DIS
    | PAGE_SIZE_NONE
    | WRITE_BURST_DIS
    | NORSRAM_FLAC_EN
  ));


  MODIFY_REG(FSMC_Bank1->BTCR[(CHOSEN_BANK + 1)], 0x3fffffff, (
      (0x0f << FSMC_BTR1_ADDSET_Pos)
    | (0 << FSMC_BTR1_ADDHLD_Pos)
    | (0x22 << FSMC_BTR1_DATAST_Pos)
    | (0 << FSMC_BTR1_BUSTURN_Pos)
    | (0 << FSMC_BTR1_CLKDIV_Pos)
    | (0 << FSMC_BTR1_DATLAT_Pos)
    | ACCESS_MODE_B
  ));

  SET_BIT(FSMC_Bank1->BTCR[CHOSEN_BANK], FSMC_BCR1_MBKEN);
}
