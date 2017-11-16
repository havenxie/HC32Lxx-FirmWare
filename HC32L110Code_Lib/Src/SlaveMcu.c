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
//��HostMCU����8bit����
uint8_t  XSPI_RecvOneByteFromHostMcu( uint8_t *pBuf )
{
	uint8_t i,tmp;

	for ( i=0; i<8; i++ )
	{
		//�ȴ�SCK���,
		while ( XSPI_SCK_GetValue()==0x00 )
		{
			if ( XSPI_NCS_GetValue() == 0x00 )
			{
				return( ERR_XSPI_RX_TimeOut );
			}
		}

		//������
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

		//����BUSY
		XSPI_BUSY_SetHigh();

		//�ȴ�SCK���
		while ( XSPI_SCK_GetValue()!=0x00 )
		{
			if ( XSPI_NCS_GetValue()==0x00 )
			{
				return( ERR_XSPI_RX_TimeOut );
			}
		}  

		//����BUSY
		XSPI_BUSY_SetLow();
	}

	*pBuf = tmp;
	return( CRR_PASS );
}

//==============================================================================
//��HostMCU��������
uint8_t XSPI_RecvMsgFromHostMcu( uint8_t *pRxBuf , uint8_t *pRxCnt )
{
	uint8_t	cnt , ErrFlag;


	XSPI_BUSY_SetLow();
	if ( XSPI_NCS_GetValue()==0x00 )
	{
		return( ERR_Master_Idle );
	}

	//�������ݳ���
	*pRxCnt = 0x00;
	ErrFlag = XSPI_RecvOneByteFromHostMcu( &cnt );
	if ( ErrFlag!=CRR_PASS )
	{
		return( ErrFlag );
	}

	//��������
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

	//�ȴ�HostMCUִ֪ͨ������ , �ȴ�SCK���
	while ( XSPI_SCK_GetValue()==0x00 )
	{
		if ( XSPI_NCS_GetValue()==0x00 )
		{
			return( ERR_XSPI_RX_TimeOut );
		}
	}

	//����BUSY����SCK��ͺ󣬿�ʼ������
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
//��HostMcu����8bit����
uint8_t  XSPI_SendOneByteToHostMcu( uint8_t va )
{
	uint8_t i ;

	for ( i=0; i<8; i++ )
	{
		//�ȴ�SCK���
		while (XSPI_SCK_GetValue()==0x00)
		{
			if ( XSPI_NCS_GetValue() == 0x00 )
			{
				return( ERR_XSPI_TX_TimeOut );
			}
		}

		//�������
		if ( va & 0x01 )
		{
			XSPI_MISO_SetHigh();
		}
		else
		{
			XSPI_MISO_SetLow();
		}
		va >>= 1;

		//����BUSY
		XSPI_BUSY_SetHigh();
		//�ȴ�SCK���
		while (XSPI_SCK_GetValue() != 0x00)
		{
			if ( XSPI_NCS_GetValue() == 0x00 )
			{
				return( ERR_XSPI_TX_TimeOut );
			}
		}

		//����BUSY
		XSPI_BUSY_SetLow();

	}

	return( CRR_PASS );
}


//==============================================================================
//��HostMcu����msg
uint8_t XSPI_SendMsgToMasterMcu( uint8_t *pTxBuf , uint8_t TxCnt  , uint8_t Status)
{
	uint8_t ErrFlag;

	//�������� ����BUSY
	XSPI_BUSY_SetLow();
	

	//�������ݳ��ȼ�������
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


	//����BUSY , MISO
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
