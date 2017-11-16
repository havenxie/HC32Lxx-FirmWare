#include "hc32l110_gpio.h"
#include "hc32l110_rcc.h"

void GPIO_DeInit(void)
{
    RCC_AHBPeriphResetCmd(RCC_AHBPeriph_GPIO, ENABLE);
    RCC_AHBPeriphResetCmd(RCC_AHBPeriph_GPIO, DISABLE);
}


void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct)
{
  uint32_t pinpos = 0x00, pos = 0x00 , currentpin = 0x00;

  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GPIO_PIN(GPIO_InitStruct->GPIO_Pin));
  assert_param(IS_GPIO_MODE(GPIO_InitStruct->GPIO_Mode));
  assert_param(IS_GPIO_PUPD(GPIO_InitStruct->GPIO_PuPd));

  /*-------------------------- Configure the port pins -----------------------*/
  /*-- GPIO Mode Configuration --*/
  for (pinpos = 0x00; pinpos < 0x8; pinpos++)
  {
    pos = ((uint32_t)0x01) << pinpos;

    /* Get the port pins position */
    currentpin = (GPIO_InitStruct->GPIO_Pin) & pos;

    if (currentpin == pos)
    {
      if ((GPIO_InitStruct->GPIO_Mode == GPIO_Mode_OUT) || (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_AF))
      {
        /* Check Output mode parameters */
        assert_param(IS_GPIO_OTYPE(GPIO_InitStruct->GPIO_OType));

        /* Output mode configuration */
        GPIOx->PxOD &= ~(0X1 << ((uint16_t)pinpos));
        GPIOx->PxOD |= (uint16_t)(((uint16_t)GPIO_InitStruct->GPIO_OType) << ((uint16_t)pinpos));
      }
      switch((uint32_t)(GPIO_InitStruct->GPIO_Mode))
      {
          case GPIO_Mode_IN:
              GPIOx->PxADS &= ~(0x1 << pinpos);
              GPIOx->PxDIR |= 0x1 << pinpos;
              break;
          case GPIO_Mode_OUT:
              GPIOx->PxADS &= ~(0x1 << pinpos);
              GPIOx->PxDIR &= ~(0x1 << pinpos);
              break;
          case GPIO_Mode_AF:
              break;
          case GPIO_Mode_AN:
              GPIOx->PxADS |= (0x1 << pinpos);              
              break;
          default:
              break;
      }

      /* Pull-up Pull down resistor configuration */
      if(GPIO_InitStruct->GPIO_PuPd == GPIO_PuPd_UP)
      {
        GPIOx->PxPU &= ~(0x1 << pinpos);
        GPIOx->PxPU |= (0x1 << pinpos);  
      }
      else if(GPIO_InitStruct->GPIO_PuPd == GPIO_PuPd_DOWN)
      {
        GPIOx->PxPD &= ~(0x1 << pinpos);
        GPIOx->PxPD |= (0x1 << pinpos);  
      }
    }
  }
}

///**
//  * @brief  Fills each GPIO_InitStruct member with its default value.
//  * @param  GPIO_InitStruct: pointer to a GPIO_InitTypeDef structure which will 
//  *         be initialized.
//  * @retval None
//  */
void GPIO_StructInit(GPIO_InitTypeDef* GPIO_InitStruct)
{
  /* Reset GPIO init structure parameters values */
  GPIO_InitStruct->GPIO_Pin  = PINALL;
  GPIO_InitStruct->GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStruct->GPIO_Speed = GPIO_Speed_Level_2;
  GPIO_InitStruct->GPIO_OType = GPIO_OType_PP;
  GPIO_InitStruct->GPIO_PuPd = GPIO_PuPd_NOPULL;
}


  
// ===============================================================================
//                      ##### GPIO Read and Write #####
// ===============================================================================  


//uint8_t GPIO_ReadInputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
//{
//  uint8_t bitstatus = 0x00;

//  /* Check the parameters */
//  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
//  assert_param(IS_GET_GPIO_PIN(GPIO_Pin));

//  if ((GPIOx->IDR & GPIO_Pin) != (uint32_t)Bit_RESET)
//  {
//    bitstatus = (uint8_t)Bit_SET;
//  }
//  else
//  {
//    bitstatus = (uint8_t)Bit_RESET;
//  }
//  return bitstatus;
//}

///**
//  * @brief  Reads the specified input port pin.
//  * @param  GPIOx: where x can be (A, B, C, D or F) to select the GPIO peripheral.
//  * @retval The input port pin value.
//  */
//uint16_t GPIO_ReadInputData(GPIO_TypeDef* GPIOx)
//{
//  /* Check the parameters */
//  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));

//  return ((uint16_t)GPIOx->IDR);
//}

///**
//  * @brief  Reads the specified output data port bit.
//  * @param  GPIOx: where x can be (A, B, C, D or F) to select the GPIO peripheral.
//  * @param  GPIO_Pin: Specifies the port bit to read.
//  * @note   This parameter can be GPIO_Pin_x where x can be:(0..15) for GPIOA, 
//  *         GPIOB or GPIOC,(0..2) for GPIOD and(0..3) for GPIOF.
//  * @retval The output port pin value.
//  */
//uint8_t GPIO_ReadOutputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
//{
//  uint8_t bitstatus = 0x00;

//  /* Check the parameters */
//  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
//  assert_param(IS_GET_GPIO_PIN(GPIO_Pin));

//  if ((GPIOx->ODR & GPIO_Pin) != (uint32_t)Bit_RESET)
//  {
//    bitstatus = (uint8_t)Bit_SET;
//  }
//  else
//  {
//    bitstatus = (uint8_t)Bit_RESET;
//  }
//  return bitstatus;
//}

///**
//  * @brief  Reads the specified GPIO output data port.
//  * @param  GPIOx: where x can be (A, B, C, D or F) to select the GPIO peripheral.
//  * @retval GPIO output data port value.
//  */
//uint16_t GPIO_ReadOutputData(GPIO_TypeDef* GPIOx)
//{
//  /* Check the parameters */
//  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));

//  return ((uint16_t)GPIOx->ODR);
//}

///**
//  * @brief  Sets the selected data port bits.
//  * @param  GPIOx: where x can be (A, B, C, D or F) to select the GPIO peripheral.
//  * @param  GPIO_Pin: specifies the port bits to be written.
//  * @note   This parameter can be GPIO_Pin_x where x can be:(0..15) for GPIOA, 
//  *         GPIOB or GPIOC,(0..2) for GPIOD and(0..3) for GPIOF.
//  * @retval None
//  */
//void GPIO_SetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
//{
//  /* Check the parameters */
//  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
//  assert_param(IS_GPIO_PIN(GPIO_Pin));

//  GPIOx->BSRR = GPIO_Pin;
//}

///**
//  * @brief  Clears the selected data port bits.
//  * @param  GPIOx: where x can be (A, B, C, D or F) to select the GPIO peripheral.
//  * @param  GPIO_Pin: specifies the port bits to be written.
//  * @note   This parameter can be GPIO_Pin_x where x can be: (0..15) for GPIOA, 
//  *         GPIOB or GPIOC,(0..2) for GPIOD and(0..3) for GPIOF.
//  * @retval None
//  */
//void GPIO_ResetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
//{
//  /* Check the parameters */
//  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
//  assert_param(IS_GPIO_PIN(GPIO_Pin));

//  GPIOx->BRR = GPIO_Pin;
//}

///**
//  * @brief  Sets or clears the selected data port bit.
//  * @param  GPIOx: where x can be (A, B, C, D or F) to select the GPIO peripheral.
//  * @param  GPIO_Pin: specifies the port bit to be written.
//  * @param  BitVal: specifies the value to be written to the selected bit.
//  *   This parameter can be one of the BitAction enumeration values:
//  *     @arg Bit_RESET: to clear the port pin
//  *     @arg Bit_SET: to set the port pin
//  * @note   The GPIO_Pin parameter can be GPIO_Pin_x where x can be: (0..15) for GPIOA, 
//  *         GPIOB or GPIOC,(0..2) for GPIOD and(0..3) for GPIOF.  
//  * @retval None
//  */
void GPIO_WriteBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, BitAction BitVal)
{
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GET_GPIO_PIN(GPIO_Pin));
  assert_param(IS_GPIO_BIT_ACTION(BitVal));

  if(BitVal)
    GPIOx->PxOUT |= (GPIO_Pin);
  else
    GPIOx->PxOUT &= ~(GPIO_Pin); 

}

///**
//  * @brief  Writes data to the specified GPIO data port.
//  * @param  GPIOx: where x can be (A, B, C, D or F) to select the GPIO peripheral.
//  * @param  PortVal: specifies the value to be written to the port output data 
//  *                  register.
//  * @retval None
//  */
void GPIO_Write(GPIO_TypeDef* GPIOx, uint16_t PortVal)
{
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));

  GPIOx->PxOUT = PortVal;
}

///**
//  * @}
//  */

///** @defgroup GPIO_Group3 GPIO Alternate functions configuration functions
// *  @brief   GPIO Alternate functions configuration functions
// *
//@verbatim   
// ===============================================================================
//          ##### GPIO Alternate functions configuration functions #####
// ===============================================================================  

//@endverbatim
//  * @{
//  */

/**
  * @brief  Writes data to the specified GPIO data port.
  * @param  GPIOx: where x can be (A or B) to select the GPIO peripheral.
  * @param  GPIO_PinSource: specifies the pin for the Alternate function.
  *   This parameter can be GPIO_PinSourcex where x can be (0..15).
  * @param  GPIO_AF: selects the pin to used as Alternate function.
  *   This parameter can be one of the following value:
 *     @arg GPIO_AF_0:WKUP, EVENTOUT, TIM15, SPI1, TIM17,MCO, SWDAT, SWCLK, TIM14,
 *                    BOOT,USART1, CEC, IR_OUT, SPI2 
 *     @arg GPIO_AF_1:USART2, CEC, Tim3, USART1, USART2,EVENTOUT, I2C1, I2C2, TIM15 
 *     @arg GPIO_AF_2:TIM2, TIM1, EVENTOUT, TIM16, TIM17.
 *     @arg GPIO_AF_3:TS, I2C1, TIM15, EVENTOUT 
 *     @arg GPIO_AF_4:TIM14.
 *     @arg GPIO_AF_5:TIM16, TIM17.
 *     @arg GPIO_AF_6:EVENTOUT.
 *     @arg GPIO_AF_7:COMP1 OUT, COMP2 OUT 
 * @note  The pin should already been configured in Alternate Function mode(AF)
 *        using GPIO_InitStruct->GPIO_Mode = GPIO_Mode_AF
 * @note  Refer to the Alternate function mapping table in the device datasheet 
 *        for the detailed mapping of the system and peripherals'alternate 
 *        function I/O pins.
 * @retval None
 */
void GPIO_PinAFConfig(GPIO_TypeDef* GPIOx, uint16_t GPIO_PinSource, uint8_t GPIO_AF)
{
  uint32_t temp = 0x00;
  /* Check the parameters */
  assert_param(IS_GPIO_LIST_PERIPH(GPIOx));
  assert_param(IS_GPIO_PIN_SOURCE(GPIO_PinSource));
  assert_param(IS_GPIO_AF(GPIO_AF));
  if(GPIOx == GPIO0) 
  {
      if((GPIO_PinSource < GPIO_PinSource1) || (GPIO_PinSource > GPIO_PinSource3))
          return;
  }
  else if(GPIOx == GPIO1)
  {
      if((GPIO_PinSource < GPIO_PinSource4) || (GPIO_PinSource > GPIO_PinSource5))
          return;
  }
  else if(GPIOx == GPIO2)
  {
      if(GPIO_PinSource < GPIO_PinSource3) return;
  }
  else if(GPIOx == GPIO3)
  {
      if((GPIO_PinSource == GPIO_PinSource0) || (GPIO_PinSource == GPIO_PinSource7))return;
  }
  

  while((GPIO_PinSource & 0x0001) != 0x0001)
  {
      GPIO_PinSource>>=1;
      temp++;
  }
  GPIOx->SEL[temp] = GPIO_AF;  
}

void McuDelay( uint32_t cnt )
{
	while( cnt )
	{
		cnt--;
	}
	 
}
void GPIO_Test(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIO, ENABLE);
    
    GPIO_InitStructure.GPIO_Pin = GPIO_PinSource3 ;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;	
    GPIO_Init(GPIO0, &GPIO_InitStructure);
    while(1)
    {
        GPIO_WriteBit(GPIO0, GPIO_PinSource3, Bit_SET);
        //GPIO_WriteBit(GPIO2, GPIO_PinSource4, Bit_SET);
        McuDelay(40000);
        GPIO_WriteBit(GPIO0, GPIO_PinSource3, Bit_RESET);
        //GPIO_WriteBit(GPIO2, GPIO_PinSource4, Bit_RESET);
        McuDelay(200000);
    }
}
