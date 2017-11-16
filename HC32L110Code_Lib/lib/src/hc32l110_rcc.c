#include "hc32lxx.h"
#include "hc32l110_rcc.h"

/**
  * @brief  Resets the RCC clock configuration to the default reset state.
  * @param  None
  * @retval None
  */
void RCC_DeInit(void)
{
    L005_SystemCtrl->PERI_CLKEN = 0xC0800000;
}



/**
  * @brief  Enables or disables the AHB peripheral clock.
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before 
  *         using it.    
  * @param  RCC_AHBPeriph: specifies the AHB peripheral to gates its clock.
  *         This parameter can be any combination of the following values:
  *             @arg RCC_AHBPeriph_UART0:         UART0 clock
  *             @arg RCC_AHBPeriph_UART1:         UART1 clock
  *             @arg RCC_AHBPeriph_LPUART:        LPUART clock
  *             @arg RCC_AHBPeriph_I2C:           I2C clock
  *             @arg RCC_AHBPeriph_SPI:           SPI clock
  *             @arg RCC_AHBPeriph_BASETIME:      BASETIME clock
  *             @arg RCC_AHBPeriph_ADVTIME:       ADVTIME(TIME456) clock
  *             @arg RCC_AHBPeriph_PCA:           PCA clock  
  *             @arg RCC_AHBPeriph_WDT:           WDT clock
  *             @arg RCC_AHBPeriph_ADC:           ADC clock
  *             @arg RCC_AHBPeriph_VC:            VC clock
  *             @arg RCC_AHBPeriph_RTC:           RTC clock
  *             @arg RCC_AHBPeriph_CLK_TRIM:      CLK_TRIM clock
  *             @arg RCC_AHBPeriph_BOOT:          BOOT clock
  *             @arg RCC_AHBPeriph_SYSTICK:       SYSTICK clock
  *             @arg RCC_AHBPeriph_SWD:           SWD clock
  *             @arg RCC_AHBPeriph_CRC:           CRC clock
  *             @arg RCC_AHBPeriph_GPIO:          GPIO clock
  *             @arg RCC_AHBPeriph_FLASH:         FLASH clock
  * @param  NewState: new state of the specified peripheral clock.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void RCC_AHBPeriphClockCmd(uint32_t RCC_AHBPeriph, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_RCC_AHB_PERIPH(RCC_AHBPeriph));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  
  if (NewState != DISABLE)
  {
    L005_SystemCtrl->PERI_CLKEN |= RCC_AHBPeriph;
  }
  else
  {
    L005_SystemCtrl->PERI_CLKEN &= ~RCC_AHBPeriph;
  }
}

/**
  * @brief  Forces or releases AHB peripheral reset.
  * @param  RCC_AHBPeriph: specifies the AHB peripheral to reset.
  *         This parameter can be any combination of the following values:
  *             @arg RCC_AHBPeriph_UART0:         UART0 clock
  *             @arg RCC_AHBPeriph_UART1:         UART1 clock
  *             @arg RCC_AHBPeriph_LPUART:        LPUART clock
  *             @arg RCC_AHBPeriph_I2C:           I2C clock
  *             @arg RCC_AHBPeriph_SPI:           SPI clock
  *             @arg RCC_AHBPeriph_BASETIME:      BASETIME clock
  *             @arg RCC_AHBPeriph_ADVTIME:       ADVTIME(TIME456) clock
  *             @arg RCC_AHBPeriph_PCA:           PCA clock  
  *             @arg RCC_AHBPeriph_WDT:           WDT clock
  *             @arg RCC_AHBPeriph_ADC:           ADC clock
  *             @arg RCC_AHBPeriph_VC:            VC clock
  *             @arg RCC_AHBPeriph_RTC:           RTC clock
  *             @arg RCC_AHBPeriph_CLK_TRIM:      CLK_TRIM clock
  *             @arg RCC_AHBPeriph_BOOT:          BOOT clock
  *             @arg RCC_AHBPeriph_SYSTICK:       SYSTICK clock
  *             @arg RCC_AHBPeriph_SWD:           SWD clock
  *             @arg RCC_AHBPeriph_CRC:           CRC clock
  *             @arg RCC_AHBPeriph_GPIO:          GPIO clock
  *             @arg RCC_AHBPeriph_FLASH:         FLASH clock
  * @param  NewState: new state of the specified peripheral reset.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void RCC_AHBPeriphResetCmd(uint32_t RCC_AHBPeriph, FunctionalState NewState)
{
  if (NewState != DISABLE)
  {
    L005_SystemCtrl->PREI_RESET |= RCC_AHBPeriph;
  }
  else
  {
    L005_SystemCtrl->PREI_RESET &= ~RCC_AHBPeriph;
  }
}
