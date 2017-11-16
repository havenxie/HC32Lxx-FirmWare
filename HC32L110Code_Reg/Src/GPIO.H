#ifndef __GPIO__
#define __GPIO__

//==============================================================================

#include "hc32lxx.h"
#include "stdio.h"

//==============================================================================

#define	P01_SetOutput()		L005_GPIO->P0DIR_f.P0DIR1 = 0
#define	P01_SetInput()		L005_GPIO->P0DIR_f.P0DIR1 = 1
#define	P01_SetHigh()		L005_GPIO->P0OUT_f.P0OUT1 = 1
#define	P01_SetLow()		L005_GPIO->P0OUT_f.P0OUT1 = 0
#define	P01_GetValue()		L005_GPIO->P0IN_f.P0IN1

#define	P02_SetOutput()		L005_GPIO->P0DIR_f.P0DIR2 = 0
#define	P02_SetInput()		L005_GPIO->P0DIR_f.P0DIR2 = 1
#define	P02_SetHigh()		L005_GPIO->P0OUT_f.P0OUT2 = 1
#define	P02_SetLow()		L005_GPIO->P0OUT_f.P0OUT2 = 0
#define	P02_GetValue()		L005_GPIO->P0IN_f.P0IN2

#define	P03_SetOutput()		L005_GPIO->P0DIR_f.P0DIR3 = 0
#define	P03_SetInput()		L005_GPIO->P0DIR_f.P0DIR3 = 1
#define	P03_SetHigh()		L005_GPIO->P0OUT_f.P0OUT3 = 1
#define	P03_SetLow()		L005_GPIO->P0OUT_f.P0OUT3 = 0
#define	P03_GetValue()		L005_GPIO->P0IN_f.P0IN3

//--------------------------------------------------------------------------

#define	P14_SetOutput()		L005_GPIO->P1DIR_f.P1DIR4 = 0
#define	P14_SetInput()		L005_GPIO->P1DIR_f.P1DIR4 = 1
#define	P14_SetHigh()		L005_GPIO->P1OUT_f.P1OUT4 = 1
#define	P14_SetLow()		L005_GPIO->P1OUT_f.P1OUT4 = 0
#define	P14_GetValue()		L005_GPIO->P1IN_f.P1IN4

#define	P15_SetOutput()		L005_GPIO->P1DIR_f.P1DIR5 = 0
#define	P15_SetInput()		L005_GPIO->P1DIR_f.P1DIR5 = 1
#define	P15_SetHigh()		L005_GPIO->P1OUT_f.P1OUT5 = 1
#define	P15_SetLow()		L005_GPIO->P1OUT_f.P1OUT5 = 0
#define	P15_GetValue()		L005_GPIO->P1IN_f.P1IN5

//--------------------------------------------------------------------------

#define	P23_SetOutput()		L005_GPIO->P2DIR_f.P2DIR3 = 0
#define	P23_SetInput()		L005_GPIO->P2DIR_f.P2DIR3 = 1
#define	P23_SetHigh()		L005_GPIO->P2OUT_f.P2OUT3 = 1
#define	P23_SetLow()		L005_GPIO->P2OUT_f.P2OUT3 = 0
#define	P23_GetValue()		L005_GPIO->P2IN_f.P2IN3

#define	P24_SetOutput()		L005_GPIO->P2DIR_f.P2DIR4 = 0
#define	P24_SetInput()		L005_GPIO->P2DIR_f.P2DIR4 = 1
#define	P24_SetHigh()		L005_GPIO->P2OUT_f.P2OUT4 = 1
#define	P24_SetLow()		L005_GPIO->P2OUT_f.P2OUT4 = 0
#define	P24_GetValue()		L005_GPIO->P2IN_f.P2IN4

#define	P25_SetOutput()		L005_GPIO->P2DIR_f.P2DIR5 = 0
#define	P25_SetInput()		L005_GPIO->P2DIR_f.P2DIR5 = 1
#define	P25_SetHigh()		L005_GPIO->P2OUT_f.P2OUT5 = 1
#define	P25_SetLow()		L005_GPIO->P2OUT_f.P2OUT5 = 0
#define	P25_GetValue()		L005_GPIO->P2IN_f.P2IN5

#define	P26_SetOutput()		L005_GPIO->P2DIR_f.P2DIR6 = 0
#define	P26_SetInput()		L005_GPIO->P2DIR_f.P2DIR6 = 1
#define	P26_SetHigh()		L005_GPIO->P2OUT_f.P2OUT6 = 1
#define	P26_SetLow()		L005_GPIO->P2OUT_f.P2OUT6 = 0
#define	P26_GetValue()		L005_GPIO->P2IN_f.P2IN6

#define	P27_SetOutput()		L005_GPIO->P2DIR_f.P2DIR7 = 0
#define	P27_SetInput()		L005_GPIO->P2DIR_f.P2DIR7 = 1
#define	P27_SetHigh()		L005_GPIO->P2OUT_f.P2OUT7 = 1
#define	P27_SetLow()		L005_GPIO->P2OUT_f.P2OUT7 = 0
#define	P27_GetValue()		L005_GPIO->P2IN_f.P2IN7

//--------------------------------------------------------------------------

#define	P31_SetOutput()		L005_GPIO->P3DIR_f.P3DIR1 = 0
#define	P31_SetInput()		L005_GPIO->P3DIR_f.P3DIR1 = 1
#define	P31_SetHigh()		L005_GPIO->P3OUT_f.P3OUT1 = 1
#define	P31_SetLow()		L005_GPIO->P3OUT_f.P3OUT1 = 0
#define	P31_GetValue()		L005_GPIO->P3IN_f.P3IN1

#define	P32_SetOutput()		L005_GPIO->P3DIR_f.P3DIR2 = 0
#define	P32_SetInput()		L005_GPIO->P3DIR_f.P3DIR2 = 1
#define	P32_SetHigh()		L005_GPIO->P3OUT_f.P3OUT2 = 1
#define	P32_SetLow()		L005_GPIO->P3OUT_f.P3OUT2 = 0
#define	P32_GetValue()		L005_GPIO->P3IN_f.P3IN2

#define	P33_SetOutput()		L005_GPIO->P3DIR_f.P3DIR3 = 0
#define	P33_SetInput()		L005_GPIO->P3DIR_f.P3DIR3 = 1
#define	P33_SetHigh()		L005_GPIO->P3OUT_f.P3OUT3 = 1
#define	P33_SetLow()		L005_GPIO->P3OUT_f.P3OUT3 = 0
#define	P33_GetValue()		L005_GPIO->P3IN_f.P3IN3

#define	P34_SetOutput()		L005_GPIO->P3DIR_f.P3DIR4 = 0
#define	P34_SetInput()		L005_GPIO->P3DIR_f.P3DIR4 = 1
#define	P34_SetHigh()		L005_GPIO->P3OUT_f.P3OUT4 = 1
#define	P34_SetLow()		L005_GPIO->P3OUT_f.P3OUT4 = 0
#define	P34_GetValue()		L005_GPIO->P3IN_f.P3IN4

#define	P35_SetOutput()		L005_GPIO->P3DIR_f.P3DIR5 = 0
#define	P35_SetInput()		L005_GPIO->P3DIR_f.P3DIR5 = 1
#define	P35_SetHigh()		L005_GPIO->P3OUT_f.P3OUT5 = 1
#define	P35_SetLow()		L005_GPIO->P3OUT_f.P3OUT5 = 0
#define	P35_GetValue()		L005_GPIO->P3IN_f.P3IN5

#define	P36_SetOutput()		L005_GPIO->P3DIR_f.P3DIR6 = 0
#define	P36_SetInput()		L005_GPIO->P3DIR_f.P3DIR6 = 1
#define	P36_SetHigh()		L005_GPIO->P3OUT_f.P3OUT6 = 1
#define	P36_SetLow()		L005_GPIO->P3OUT_f.P3OUT6 = 0
#define	P36_GetValue()		L005_GPIO->P3IN_f.P3IN6


//==============================================================================

#endif

//==============================================================================
