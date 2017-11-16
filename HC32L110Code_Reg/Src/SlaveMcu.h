/**
  ******************************************************************************
  * File Name          : HostMcu.h
  * Description        : This file contains all the functions prototypes for
  *                      the gpio
  ******************************************************************************
  *
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __HostMcu_H
#define __HostMcu_H


/* Includes ------------------------------------------------------------------*/
#include "GPIO.h"

/* USER CODE BEGIN Includes */

//==============================================================================


#define		XSPI_NCS_SetInput()		P32_SetInput()
#define		XSPI_NCS_GetValue()		P32_GetValue()

#define		XSPI_SCK_SetInput()		P33_SetInput()
#define		XSPI_SCK_GetValue()		P33_GetValue()

#define		XSPI_MOSI_SetInput()	P34_SetInput()
#define		XSPI_MOSI_GetValue()	P34_GetValue()

#define		XSPI_MISO_SetOutput()	P25_SetOutput()
#define		XSPI_MISO_SetHigh()		P25_SetHigh()
#define		XSPI_MISO_SetLow()		P25_SetLow()
#define		XSPI_MISO_GetValue()	P25_GetValue()

#define		XSPI_BUSY_SetOutput()	P26_SetOutput()
#define		XSPI_BUSY_SetHigh()		P26_SetHigh()
#define		XSPI_BUSY_SetLow()		P26_SetLow()

//==============================================================================

void XSPI_Init(void);
uint8_t XSPI_RecvMsgFromHostMcu( uint8_t *pRxBuf , uint8_t *pRxCnt );
uint8_t XSPI_SendMsgToMasterMcu( uint8_t *pTxBuf , uint8_t TxCnt , uint8_t Status);

//==============================================================================


#endif /*__ pinoutConfig_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/





