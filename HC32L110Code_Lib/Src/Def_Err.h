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
#ifndef __Def_Err_H
#define __Def_Err_H


#define		CRR_PASS			0X00
#define		ERR_Slave_Busy		0x50
#define		ERR_Master_Idle		0x51
#define		ERR_Slave_ExeTimeOut	0x51
#define		ERR_XSPI_TX_TimeOut		0x60
#define		ERR_XSPI_RX_TimeOut		0x61
//#define		ERR_XSPI_RX_TimeOut		0x62
#define		ERR_XSPI_RX_DataLen		0x63

#define		ERR_Cla				0x70
#define		ERR_INS				0x71


#endif


