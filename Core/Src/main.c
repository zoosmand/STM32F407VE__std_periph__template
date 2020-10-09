/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Global variables ---------------------------------------------------------*/
uint32_t sysQuantum       = 0U;
uint32_t millis           = 0U;
uint32_t seconds          = 0U;
uint32_t minutes          = 0U;
uint32_t _EREG_           = 0U;
uint32_t delay_tmp        = 0U;
uint32_t SystemCoreClock  = 16000000U;
RCC_ClocksTypeDef RccClocks;

/* Private variables ---------------------------------------------------------*/
static uint32_t millis_tmp    = 100U;
static uint32_t seconds_tmp   = 1000U;
static uint32_t minutes_tmp   = 60U;

/* Private function prototypes -----------------------------------------------*/
static void CronSysQuantum_Handler(void);
static void CronMillis_Handler(void);
static void CronSeconds_Handler(void);
static void CronMinutes_Handler(void);
static void Flags_Handler(void);









////////////////////////////////////////////////////////////////////////////////

/**
  * @brief  The application entry point.
  * @return int
  */
int main(void) {
  while (1) {
    Delay_Handler(0);
    Cron_Handler();
    Flags_Handler();
  }
}








/********************************************************************************/
/*                                     CRON                                     */
/********************************************************************************/
void Cron_Handler() {
  $CronStart:
  if (SysTick->CTRL & (1 << SysTick_CTRL_COUNTFLAG_Pos)) { 
    sysQuantum++;
    CronSysQuantum_Handler();
  }

  if (sysQuantum >= millis_tmp) {
    millis++;
    millis_tmp = sysQuantum + 100;
    CronMillis_Handler();
  }
  
  if (millis >= seconds_tmp) {
    seconds++;
    seconds_tmp += 1000;
    CronSeconds_Handler();
  }
  
  if (seconds >= minutes_tmp) {
    minutes++;
    minutes_tmp += 60;
    CronMinutes_Handler();
  }

  while (sysQuantum < delay_tmp) {
    goto $CronStart;
  }
  // !!!!!!!!! The bug!!!!!!!!
  delay_tmp = 0;
  FLAG_CLR(_EREG_, _DELAYF_);
}






/********************************************************************************/
/*                             CRON EVENTS HANDLERS                             */
/********************************************************************************/
// ---- System Quantum ---- //
static void CronSysQuantum_Handler(void) {
  //
}

// ---- Milliseconds ---- //
static void CronMillis_Handler(void) {
  //
}

// ---- Seconds ---- //
static void CronSeconds_Handler(void) {
  //
  WRITE_REG(IWDG->KR, IWDG_KEY_RELOAD);
  printf("test\n");
  LED_Blink(LED0_Port, LED0_Pin_Pos);
  LED_Blink(LED1_Port, LED1_Pin_Pos);
}

// ---- Minutes ---- //
static void CronMinutes_Handler(void) {
  //
}






/********************************************************************************/
/*                                     FLAGS                                    */
/********************************************************************************/
void Flags_Handler(void){
  if (FLAG_CHECK(_EREG_, _BT7F_)) {
    // BasicTimer_FromIT_Handler(TIM7);
    FLAG_CLR(_EREG_, _BT7F_);
  }

  /* USART1 action */
  if (FLAG_CHECK(_USARTREG_, _USART1_RXAF_)) {
    USART1_RX_Handler();
    FLAG_CLR(_USARTREG_, _USART1_RXAF_);
  }
}










/**
  * @brief  Reset of all peripherals, Initializes the Flash interface and the Systick.
  * @return None
  */
void SystemInit(void) {

  #if (INSTRUCTION_CACHE_ENABLE != 0U)
    PREG_SET(FLASH->ACR, FLASH_ACR_ICEN_Pos);
  #endif /* INSTRUCTION_CACHE_ENABLE */

  #if (DATA_CACHE_ENABLE != 0U)
    PREG_SET(FLASH->ACR, FLASH_ACR_DCEN_Pos);
  #endif /* DATA_CACHE_ENABLE */

  #if (PREFETCH_ENABLE != 0U)
    PREG_SET(FLASH->ACR, FLASH_ACR_PRFTEN_Pos);
  #endif /* PREFETCH_ENABLE */

  NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

    /* SysTick */
  SET_BIT(SysTick->CTRL, (SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk));
  SysTick->LOAD = 1680U - 1U;
  SysTick->VAL = 0;
  SET_BIT(SysTick->CTRL, SysTick_CTRL_ENABLE_Msk);

  /* SysTick interrupt configuration */
  NVIC_SetPriority(SysTick_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 0, 0));
  NVIC_EnableIRQ(SysTick_IRQn);

  /* SysCfg */
  PREG_SET(RCC->APB2ENR, RCC_APB2ENR_SYSCFGEN_Pos);
  while (!(PREG_CHECK(RCC->APB2ENR, RCC_APB2ENR_SYSCFGEN_Pos)));

  /* PWR */
  PREG_SET(RCC->APB1ENR, RCC_APB1ENR_PWREN_Pos);
  while (!(PREG_CHECK(RCC->APB1ENR, RCC_APB1ENR_PWREN_Pos)))

  /* FLASH_IRQn interrupt configuration */
  NVIC_SetPriority(FLASH_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 0, 0));
  NVIC_EnableIRQ(FLASH_IRQn);

  /* RCC_IRQn interrupt configuration */
  NVIC_SetPriority(RCC_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 0, 0));
  NVIC_EnableIRQ(RCC_IRQn);


  MODIFY_REG(FLASH->ACR, FLASH_ACR_LATENCY, FLASH_ACR_LATENCY_5WS);

  if (READ_BIT(FLASH->ACR, FLASH_ACR_LATENCY) != FLASH_ACR_LATENCY_5WS) {
    Error_Handler();
  }
  
  MODIFY_REG(PWR->CR, PWR_CR_VOS_Msk, PWR_CR_VOS);

   /* HSE enable and wait till it's ready */
  PREG_SET(RCC->CR, RCC_CR_HSEON_Pos);
  while(!(PREG_CHECK(RCC->CR, RCC_CR_HSERDY_Pos)));
  
  /* LSI enable and wait till it's ready */
  PREG_SET(RCC->CSR, RCC_CSR_LSION_Pos);
  while(!(PREG_CHECK(RCC->CSR, RCC_CSR_LSIRDY_Pos)));

  /* Backup registers enable access */
  PREG_SET(PWR->CR, PWR_CR_DBP_Pos);

  /* force backup domain reset */
  PREG_SET(RCC->BDCR, RCC_BDCR_BDRST_Pos);
  PREG_CLR(RCC->BDCR, RCC_BDCR_BDRST_Pos);
  
  /* LSE enable and wait till it's ready */
  PREG_SET(RCC->BDCR, RCC_BDCR_LSEON_Pos);
  while(!(PREG_CHECK(RCC->BDCR, RCC_BDCR_LSERDY_Pos)));

  /* RTC source is LSE */
  MODIFY_REG(RCC->BDCR, RCC_BDCR_RTCSEL_Msk, RCC_BDCR_RTCSEL_0);

  /* Enable RTC */
  PREG_SET(RCC->BDCR, RCC_BDCR_RTCEN_Pos);

  /* Configure PLL domain end prescaller */
  MODIFY_REG(RCC->PLLCFGR, (RCC_PLLCFGR_PLLSRC_Msk | RCC_PLLCFGR_PLLM_Msk | RCC_PLLCFGR_PLLN_Msk), (
      RCC_PLLCFGR_PLLSRC_HSE
    | RCC_PLLCFGR_PLLM_2
    | 168 << RCC_PLLCFGR_PLLN_Pos
  ));

  /* PLL isn't divided */
  MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLLP_Msk, 0);
  
  /* PLL enable and wait till it's ready */
  PREG_SET(RCC->CR, RCC_CR_PLLON_Pos);
  while (!(PREG_CHECK(RCC->CR, RCC_CR_PLLRDY_Pos)));


  /* AHB isn't divided */
  // MODIFY_REG(RCC->CFGR, RCC_CFGR_HPRE, LL_RCC_SYSCLK_DIV_1);
  /* APB1 divided by 4 */
  MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE1, RCC_CFGR_PPRE1_DIV4);
  /* APB2 divided by 2 */
  MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE2, RCC_CFGR_PPRE2_DIV2);

  /* Enable PLL as sysclock and wait till it's ready */
  MODIFY_REG(RCC->CFGR, RCC_CFGR_SW, RCC_CFGR_SW_PLL);
  while(!(READ_BIT(RCC->CFGR, RCC_CFGR_SWS) == RCC_CFGR_SWS_PLL));

  SystemCoreClock = 168000000U;
  RccClocks.HCLK_Freq = SystemCoreClock;
  RccClocks.PCLK1_Freq = 42000000U;
  RccClocks.PCLK1_Freq_Tim = 84000000U;
  RccClocks.PCLK2_Freq = 84000000U;
  RccClocks.PCLK2_Freq_Tim = 168000000U;



  /*****************************************************************************************/
  /*****************************************************************************************/
  /*****************************************************************************************/
  /* Freeze some peripherals for the debug purpose */
  #ifdef DEBUG
  SET_BIT(DBGMCU->APB1FZ, (
      DBGMCU_APB1_FZ_DBG_TIM7_STOP
    | DBGMCU_APB1_FZ_DBG_IWDG_STOP
    | DBGMCU_APB1_FZ_DBG_WWDG_STOP
  ));
  #endif

  /*****************************************************************************************/
  /* IWDG */
  WRITE_REG(IWDG->KR, IWDG_KEY_ENABLE);
  WRITE_REG(IWDG->KR, IWDG_KEY_WR_ACCESS_ENABLE);
  WRITE_REG(IWDG->PR, IWDG_PR_PR & (IWDG_PR_PR_2 | IWDG_PR_PR_0)); /*!< Divider by 128 */
  WRITE_REG(IWDG->RLR, IWDG_RLR_RL & (625 - 1));
  while (!(PREG_CHECK(IWDG->SR, IWDG_SR_PVU_Pos)));
  WRITE_REG(IWDG->KR, IWDG_KEY_RELOAD);



   /* Peripheral clock */
  /* APB1 */
  SET_BIT(RCC->APB1ENR, (
      RCC_APB1ENR_TIM7EN
    // | RCC_APB1ENR_I2C3EN
  ));

  /* AHB1 */
  SET_BIT(RCC->AHB1ENR, ( 
      RCC_AHB1ENR_GPIOAEN
    | RCC_AHB1ENR_GPIOBEN
    // | RCC_AHB1ENR_GPIOCEN
    // | RCC_AHB1ENR_GPIODEN
    // | RCC_AHB1ENR_GPIOEEN
    // | RCC_AHB1ENR_GPIOFEN
    // | RCC_AHB1ENR_GPIOGEN
    // | RCC_AHB1ENR_GPIOHEN
    | RCC_AHB1ENR_CRCEN
  ));

  /* APB2 */
  SET_BIT(RCC->APB2ENR, (
      RCC_APB2ENR_USART1EN
  ));

  // /* AHB3 */
  // SET_BIT(RCC->AHB3ENR, (
  //     RCC_AHB3ENR_FMCEN
  // ));
  // /* Wait for FMC starts */
  // while (!(PREG_CHECK(RCC->AHB3ENR, RCC_AHB3ENR_FMCEN_Pos)));




  /************************************************************************************************/
  /************************************************************************************************/
  /************************************************************************************************/
  Delay(500);
  
  /* LED */
  LED_Init();

  /* USART1 */ 
  USART1_Init();


}


