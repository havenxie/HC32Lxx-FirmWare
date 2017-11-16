#ifndef __HC32L110_UART_H
#define __HC32L110_UART_H

#ifdef __cplusplus
 extern "C" {
#endif
     
#include "hc32lxx.h"
     
/** @defgroup USART_Word_Length 
  * @{
  */ 

#define USART_WordLength_8b                  ((uint32_t)0x00000000)
#define USART_WordLength_9b                  ((uint32_t)0x0000000B)
#define IS_USART_WORD_LENGTH(LENGTH) (((LENGTH) == USART_WordLength_8b) || \
                                      ((LENGTH) == USART_WordLength_9b))     
/**
  * @}
  */ 


/** @defgroup USART_RECEN 
  * @{
  */ 

#define USART_RECEN_Tx                        ((uint32_t)0x00000000)//send only
#define USART_RECEN_TxRx                      UART_SCON_REN//enable receive
#define IS_USART_RECEN(PARITY) (((PARITY) == USART_Mode_Tx) || ((PARITYPARITY) == USART_Mode_TxRx))
            
/** @defgroup USART_Mode
  * @{
  */ 
#define USART_MODE0                          ((uint32_t)0x00000000)     
#define USART_MODE1                          UART_SCON_SM01_1
#define USART_MODE2                          UART_SCON_SM01_2
#define USART_MODE3                          UART_SCON_SM01_3
#define IS_USART_MODE(MODE)  (((MODE) == ((uint32_t)0x00000000)) || \
                              ((MODE) == USART_MODE1) || \
                              ((MODE) == USART_MODE2) || \
                              ((MODE) == USART_MODE3))
/** 
  * @brief  USART Init Structure definition  
  */ 

typedef struct
{
  uint32_t USART_BaudRate;            /*!< This member configures the USART communication baud rate.
                                           The baud rate is computed using the following formula:
                                            - IntegerDivider = ((PCLKx) / (16 * (USART_InitStruct->USART_BaudRate)))
                                            - FractionalDivider = ((IntegerDivider - ((uint32_t) IntegerDivider)) * 16) + 0.5 */

  uint32_t USART_WordLength;          /*!< Specifies the number of data bits transmitted or received in a frame.
                                           This parameter can be a value of @ref USART_Word_Length */

  uint32_t USART_Parity;              /*!< Specifies the parity mode.
                                           This parameter can be a value of @ref USART_Parity
                                           @note When parity is enabled, the computed parity is inserted
                                                 at the MSB position of the transmitted data (9th bit when
                                                 the word length is set to 9 data bits; 8th bit when the
                                                 word length is set to 8 data bits). */
 
  uint32_t USART_Mode;                /*!< Specifies wether the Receive or Transmit mode is enabled or disabled.
                                           This parameter can be a value of @ref USART_Mode */
  uint32_t USART_RECEN;

} USART_InitTypeDef;     
     
#ifdef __cplusplus
 }
#endif
#endif
