/**
  ******************************************************************************
  * File Name          : gpio.c
  * Description        : This file provides code for the configuration
  *                      of all used GPIO pins.
  ******************************************************************************
  *
  */

/* Includes ------------------------------------------------------------------*/

#include "SlaveMcu.h"
#include "Def_Err.h"

//==============================================================================
 


//==============================================================================
void XSPI_Init( void )
{
	XSPI_NCS_SetInput();
	XSPI_SCK_SetInput();
	XSPI_MOSI_SetInput();

	XSPI_MISO_SetOutput();
	XSPI_BUSY_SetOutput();
	XSPI_MISO_SetLow();
	XSPI_BUSY_SetLow();
}


//==============================================================================
//从HostMCU接收8bit数据
uint8_t  XSPI_RecvOneByteFromHostMcu( uint8_t *pBuf )
{
	uint8_t i,tmp;

	for ( i=0; i<8; i++ )
	{
		//等待SCK变高,
		while ( XSPI_SCK_GetValue()==0x00 )
		{
			if ( XSPI_NCS_GetValue() == 0x00 )
			{
				return( ERR_XSPI_RX_TimeOut );
			}
		}

		//读数据
		tmp >>= 1;
		if ( XSPI_MOSI_GetValue() )
		{
			tmp |= 0x80;
			//XSPI_MISO_SetHigh();
		}
		else
		{
			tmp &= 0x7f;
			//XSPI_MISO_SetLow();
		}

		//拉高BUSY
		XSPI_BUSY_SetHigh();

		//等待SCK变低
		while ( XSPI_SCK_GetValue()!=0x00 )
		{
			if ( XSPI_NCS_GetValue()==0x00 )
			{
				return( ERR_XSPI_RX_TimeOut );
			}
		}  

		//拉低BUSY
		XSPI_BUSY_SetLow();
	}

	*pBuf = tmp;
	return( CRR_PASS );
}

//==============================================================================
//从HostMCU接收数据
uint8_t XSPI_RecvMsgFromHostMcu( uint8_t *pRxBuf , uint8_t *pRxCnt )
{
	uint8_t	cnt , ErrFlag;


	XSPI_BUSY_SetLow();
	if ( XSPI_NCS_GetValue()==0x00 )
	{
		return( ERR_Master_Idle );
	}

	//接收数据长度
	*pRxCnt = 0x00;
	ErrFlag = XSPI_RecvOneByteFromHostMcu( &cnt );
	if ( ErrFlag!=CRR_PASS )
	{
		return( ErrFlag );
	}

	//接收数据
	*pRxCnt = cnt;
	while ( cnt )
	{
		ErrFlag = XSPI_RecvOneByteFromHostMcu( pRxBuf );
		if ( ErrFlag != CRR_PASS )
		{
			*pRxCnt = 0x00;
			return( ErrFlag );
		}
		pRxBuf++;
		cnt--;
	}

	//等待HostMCU通知执行任务 , 等待SCK变高
	while ( XSPI_SCK_GetValue()==0x00 )
	{
		if ( XSPI_NCS_GetValue()==0x00 )
		{
			return( ERR_XSPI_RX_TimeOut );
		}
	}

	//拉高BUSY，等SCK变低后，开始做任务
	XSPI_BUSY_SetHigh();
	while ( XSPI_SCK_GetValue()!=0x00 )
	{
		if ( XSPI_NCS_GetValue()==0x00 )
		{
			return( ERR_XSPI_RX_TimeOut );
		}
	}

	return( ErrFlag );
}

//==============================================================================
//向HostMcu发送8bit数据
uint8_t  XSPI_SendOneByteToHostMcu( uint8_t va )
{
	uint8_t i ;

	for ( i=0; i<8; i++ )
	{
		//等待SCK变高
		while (XSPI_SCK_GetValue()==0x00)
		{
			if ( XSPI_NCS_GetValue() == 0x00 )
			{
				return( ERR_XSPI_TX_TimeOut );
			}
		}

		//输出数据
		if ( va & 0x01 )
		{
			XSPI_MISO_SetHigh();
		}
		else
		{
			XSPI_MISO_SetLow();
		}
		va >>= 1;

		//拉高BUSY
		XSPI_BUSY_SetHigh();
		//等待SCK变低
		while (XSPI_SCK_GetValue() != 0x00)
		{
			if ( XSPI_NCS_GetValue() == 0x00 )
			{
				return( ERR_XSPI_TX_TimeOut );
			}
		}

		//拉低BUSY
		XSPI_BUSY_SetLow();

	}

	return( CRR_PASS );
}


//==============================================================================
//向HostMcu发送msg
uint8_t XSPI_SendMsgToMasterMcu( uint8_t *pTxBuf , uint8_t TxCnt  , uint8_t Status)
{
	uint8_t ErrFlag;

	//做完任务， 拉低BUSY
	XSPI_BUSY_SetLow();
	

	//发送数据长度及数据体
	ErrFlag = XSPI_SendOneByteToHostMcu( TxCnt + 2 );
	if ( ErrFlag==CRR_PASS )
	{
		while ( TxCnt )
		{
			ErrFlag = XSPI_SendOneByteToHostMcu( *pTxBuf );
			if ( ErrFlag!=CRR_PASS )
			{
				break;
			}

			pTxBuf++;
			TxCnt--;
		}
	}

	if ( ErrFlag==CRR_PASS )
	{
		XSPI_SendOneByteToHostMcu( 0x90 );
	}
	if ( ErrFlag==CRR_PASS )
	{
		XSPI_SendOneByteToHostMcu( Status );
	}


	//拉低BUSY , MISO
	XSPI_BUSY_SetLow();
	XSPI_MISO_SetLow();

	return( ErrFlag );

}


/* USER CODE END 2 */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
