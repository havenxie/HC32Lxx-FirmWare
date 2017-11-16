#ifndef __HC32L110_GPIO_H
#define __HC32L110_GPIO_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "hc32lxx.h"

#define IS_GPIO_LIST_PERIPH(PERIPH) (((PERIPH) == GPIO0) || \
                                    ((PERIPH) == GPIO1) || \
                                    ((PERIPH) == GPIO2) || \
                                    ((PERIPH) == GPIO3) )


/** @defgroup Configuration_Mode_enumeration 
  * @{
  */
typedef enum
{
  GPIO_Mode_IN   = 0x00, /*!< GPIO Input Mode              */
  GPIO_Mode_OUT  = 0x01, /*!< GPIO Output Mode             */
  GPIO_Mode_AF   = 0x02, /*!< GPIO Alternate function Mode */
  GPIO_Mode_AN   = 0x03  /*!< GPIO Analog In/Out Mode      */
}GPIOMode_TypeDef;

#define IS_GPIO_MODE(MODE) (((MODE) == GPIO_Mode_IN)|| ((MODE) == GPIO_Mode_OUT) || \
                            ((MODE) == GPIO_Mode_AF)|| ((MODE) == GPIO_Mode_AN))

typedef enum
{
  GPIO_OType_PP = 0x00,
  GPIO_OType_OD = 0x01
}GPIOOType_TypeDef;

#define IS_GPIO_OTYPE(OTYPE) (((OTYPE) == GPIO_OType_PP) || ((OTYPE) == GPIO_OType_OD))

/**
  * @}
  */

/** @defgroup Output_Maximum_frequency_enumeration 
  * @{
  */
#define GPIO_Speed_10MHz GPIO_Speed_Level_1   /*!< Fast Speed:10MHz   */
#define GPIO_Speed_2MHz  GPIO_Speed_Level_2   /*!< Medium Speed:2MHz  */
#define GPIO_Speed_50MHz GPIO_Speed_Level_3   /*!< High Speed:50MHz   */
typedef enum
{
  GPIO_Speed_Level_1  = 0x01, /*!< Medium Speed */
  GPIO_Speed_Level_2  = 0x02, /*!< Fast Speed   */
  GPIO_Speed_Level_3  = 0x03  /*!< High Speed   */
}GPIOSpeed_TypeDef;

#define IS_GPIO_SPEED(SPEED) (((SPEED) == GPIO_Speed_Level_1) || ((SPEED) == GPIO_Speed_Level_2) || \
                              ((SPEED) == GPIO_Speed_Level_3))
/**
  * @}
  */

/** @defgroup Configuration_Pull-Up_Pull-Down_enumeration 
  * @{
  */
typedef enum
{
  GPIO_PuPd_NOPULL = 0x00,
  GPIO_PuPd_UP     = 0x01,
  GPIO_PuPd_DOWN   = 0x02
}GPIOPuPd_TypeDef;

#define IS_GPIO_PUPD(PUPD) (((PUPD) == GPIO_PuPd_NOPULL) || ((PUPD) == GPIO_PuPd_UP) || \
                            ((PUPD) == GPIO_PuPd_DOWN))
/**
  * @}
  */

/** @defgroup Bit_SET_and_Bit_RESET_enumeration
  * @{
  */
typedef enum
{ 
  Bit_RESET = 0,
  Bit_SET
}BitAction;

#define IS_GPIO_BIT_ACTION(ACTION) (((ACTION) == Bit_RESET) || ((ACTION) == Bit_SET))
/**
  * @}
  */

/**
  * @brief  GPIO Init structure definition  
  */
typedef struct
{
  uint32_t GPIO_Pin;              /*!< Specifies the GPIO pins to be configured.
                                       This parameter can be any value of @ref GPIO_pins_define */
                                       
  GPIOMode_TypeDef GPIO_Mode;     /*!< Specifies the operating mode for the selected pins.
                                       This parameter can be a value of @ref GPIOMode_TypeDef   */

  GPIOSpeed_TypeDef GPIO_Speed;   /*!< Specifies the speed for the selected pins.
                                       This parameter can be a value of @ref GPIOSpeed_TypeDef  */

  GPIOOType_TypeDef GPIO_OType;   /*!< Specifies the operating output type for the selected pins.
                                       This parameter can be a value of @ref GPIOOType_TypeDef  */

  GPIOPuPd_TypeDef GPIO_PuPd;     /*!< Specifies the operating Pull-up/Pull down for the selected pins.
                                       This parameter can be a value of @ref GPIOPuPd_TypeDef   */
}GPIO_InitTypeDef;

/* Exported constants --------------------------------------------------------*/

/** @defgroup GPIO_Exported_Constants
  * @{
  */

/** @defgroup GPIO_pins_define 
  * @{
  */


#define GPIO_PinSource0                 ((uint16_t)0x0001)  /*!< Pin 0 selected    */
#define GPIO_PinSource1                 ((uint16_t)0x0002)  /*!< Pin 1 selected    */
#define GPIO_PinSource2                 ((uint16_t)0x0004)  /*!< Pin 2 selected    */
#define GPIO_PinSource3                 ((uint16_t)0x0008)  /*!< Pin 3 selected    */
#define GPIO_PinSource4                 ((uint16_t)0x0010)  /*!< Pin 4 selected    */
#define GPIO_PinSource5                 ((uint16_t)0x0020)  /*!< Pin 5 selected    */
#define GPIO_PinSource6                 ((uint16_t)0x0040)  /*!< Pin 6 selected    */
#define GPIO_PinSource7                 ((uint16_t)0x0080)  /*!< Pin 7 selected    */
#define PINALL                          ((uint16_t)0xFFFF)  /*!< All pins selected */

#define IS_GPIO_PIN(PIN) ((PIN) != (uint16_t)0x00)

#define IS_GET_GPIO_PIN(PIN) (((PIN) == GPIO_PinSource0) || \
                              ((PIN) == GPIO_PinSource1) || \
                              ((PIN) == GPIO_PinSource2) || \
                              ((PIN) == GPIO_PinSource3) || \
                              ((PIN) == GPIO_PinSource4) || \
                              ((PIN) == GPIO_PinSource5) || \
                              ((PIN) == GPIO_PinSource6) || \
                              ((PIN) == GPIO_PinSource7))



/** @defgroup GPIO_Alternate_function_selection_define 
  * @{
  */

/** 
  * @brief  AF 0 selection
  */
#define GPIO_AF_0            ((uint8_t)0x00) /* WKUP, EVENTOUT, TIM15, SPI1, TIM17,
                                                MCO, SWDAT, SWCLK, TIM14, BOOT,
                                                USART1, CEC, IR_OUT, SPI2 */
/** 
  * @brief  AF 1 selection
  */
#define GPIO_AF_1            ((uint8_t)0x01) /* USART2, CEC, Tim3, USART1, USART2,
                                                EVENTOUT, I2C1, I2C2, TIM15 */
/** 
  * @brief  AF 2 selection
  */
#define GPIO_AF_2            ((uint8_t)0x02) /* TIM2, TIM1, EVENTOUT, TIM16, TIM17 */
/** 
  * @brief  AF 3 selection
  */
#define GPIO_AF_3            ((uint8_t)0x03) /* TS, I2C1, TIM15, EVENTOUT */

/** 
  * @brief  AF 4 selection
  */
#define GPIO_AF_4            ((uint8_t)0x04) /* TIM14 */
/** 
  * @brief  AF 5 selection
  */
#define GPIO_AF_5            ((uint8_t)0x05) /* TIM16, TIM17 */

/** 
  * @brief  AF 6 selection
  */
#define GPIO_AF_6            ((uint8_t)0x06) /* EVENTOUT */
/** 
  * @brief  AF 7 selection
  */
#define GPIO_AF_7            ((uint8_t)0x07) /* COMP1 OUT and COMP2 OUT */

#define IS_GPIO_AF(AF)   (((AF) == GPIO_AF_0) || ((AF) == GPIO_AF_1) || \
                          ((AF) == GPIO_AF_2) || ((AF) == GPIO_AF_3) || \
                          ((AF) == GPIO_AF_4) || ((AF) == GPIO_AF_5) || \
                          ((AF) == GPIO_AF_6) || ((AF) == GPIO_AF_7))

/**
  * @}
  */

/** @defgroup GPIO_Speed_Legacy 
  * @{
  */



/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
/* Function used to set the GPIO configuration to the default reset state *****/
void GPIO_DeInit(void);

/* Initialization and Configuration functions *********************************/
void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct);
//void GPIO_StructInit(GPIO_InitTypeDef* GPIO_InitStruct);
//void GPIO_PinLockConfig(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

///* GPIO Read and Write functions **********************************************/
//uint8_t GPIO_ReadInputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
//uint16_t GPIO_ReadInputData(GPIO_TypeDef* GPIOx);
//uint8_t GPIO_ReadOutputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
//uint16_t GPIO_ReadOutputData(GPIO_TypeDef* GPIOx);
//void GPIO_SetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
//void GPIO_ResetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void GPIO_WriteBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, BitAction BitVal);
void GPIO_Write(GPIO_TypeDef* GPIOx, uint16_t PortVal);

///* GPIO Alternate functions configuration functions ***************************/
void GPIO_PinAFConfig(GPIO_TypeDef* GPIOx, uint16_t GPIO_PinSource, uint8_t GPIO_AF);
void McuDelay( uint32_t cnt );
void GPIO_Test(void);
#ifdef __cplusplus
}
#endif

#endif /* __STM32F0XX_GPIO_H */
/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
