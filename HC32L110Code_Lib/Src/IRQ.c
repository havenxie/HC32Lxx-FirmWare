
//===================================================================================

#include "hc32lxx.h"
#include "GPIO.h"
#include "stdio.h"

//===================================================================================

//extern __IO uint8_t GPIO_Int_Flag;

//===================================================================================


void GPIO_P0_IRQHandler( void )
{
	L005_GPIO->P0_ICLR = 0x00;
	//GPIO_Int_Flag = 1;
}

void GPIO_P1_IRQHandler( void )
{
	L005_GPIO->P1_ICLR = 0x00;
	//GPIO_Int_Flag = 1;
}

void GPIO_P2_IRQHandler( void )
{
	L005_GPIO->P2_ICLR = 0x00;
	//GPIO_Int_Flag = 1;
}

void GPIO_P3_IRQHandler( void )
{
	L005_GPIO->P3_ICLR = 0x00;
	//GPIO_Int_Flag = 1;
}

//===================================================================================

void RTC_IRQHandler( void )
{
	L005_RTC->CR1_f.PRDF = 0;

	if( P14_GetValue() )
	{
		P14_SetLow();
	}
	else
	{
		P14_SetHigh();
	}
}

//===================================================================================
void BASE_TIMER0_IRQHandler( void )
{
	L005_TIM0->ICLR = 0;

	if( P32_GetValue() )
	{
		P32_SetLow();
	}
	else
	{
	
		P32_SetHigh();
	}
}


void BASE_TIMER1_IRQHandler( void )
{
	L005_TIM1->ICLR = 0;
	
	// if( PORT_CTRL_REG->P2OUT_f.P2OUT3 )
	// {
		// PORT_CTRL_REG->P2OUT_f.P2OUT3 = 0;
	// }
	// else
	// {
		// PORT_CTRL_REG->P2OUT_f.P2OUT3 = 1;
	// }
	
	if( P34_GetValue() )
	{
		P34_SetLow();
	}
	else
	{
		P34_SetHigh();
	}
}

void BASE_TIMER2_IRQHandler( void )
{
	L005_TIM2->ICLR = 0;
	
	
	if( P35_GetValue() )
	{
		P35_SetLow();
	}
	else
	{
		P35_SetHigh();
	}
}


void BASE_TIMER3_IRQHandler( void )
{
	L005_LPTIM->ICLR = 0;

	if( P14_GetValue() )
	{
		P14_SetLow();
	}
	else
	{
		P14_SetHigh();
	}
}



//===================================================================================

