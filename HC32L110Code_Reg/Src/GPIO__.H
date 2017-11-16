#ifndef __GPIO__
#define __GPIO__

//==============================================================================

#include "HC32L110.h"
#include "stdio.h"

//==============================================================================

#define	P01_SetOutput()		M0P_GPIO->P0DIR_f.P01 = 0
#define	P01_SetHigh()		M0P_GPIO->P0OUT_f.P01 = 1
#define	P01_SetLow()		M0P_GPIO->P0OUT_f.P01 = 0
#define	P01_SetInput()		M0P_GPIO->P0DIR_f.P01 = 1
#define	P01_GetValue()		M0P_GPIO->P0IN_f.P01

#define	P02_SetOutput()		M0P_GPIO->P0DIR_f.P02 = 0
#define	P02_SetInput()		M0P_GPIO->P0DIR_f.P02 = 1
#define	P02_SetHigh()		M0P_GPIO->P0OUT_f.P02 = 1
#define	P02_SetLow()		M0P_GPIO->P0OUT_f.P02 = 0
#define	P02_GetValue()		M0P_GPIO->P0IN_f.P02

#define	P03_SetOutput()		M0P_GPIO->P0DIR_f.P03 = 0
#define	P03_SetInput()		M0P_GPIO->P0DIR_f.P03 = 1
#define	P03_SetHigh()		M0P_GPIO->P0OUT_f.P03 = 1
#define	P03_SetLow()		M0P_GPIO->P0OUT_f.P03 = 0
#define	P03_GetValue()		M0P_GPIO->P0IN_f.P03

//--------------------------------------------------------------------------

#define	P14_SetOutput()		M0P_GPIO->P1DIR_f.P14 = 0
#define	P14_SetInput()		M0P_GPIO->P1DIR_f.P14 = 1
#define	P14_SetHigh()		M0P_GPIO->P1OUT_f.P14 = 1
#define	P14_SetLow()		M0P_GPIO->P1OUT_f.P14 = 0
#define	P14_GetValue()		M0P_GPIO->P1IN_f.P14

#define	P15_SetOutput()		M0P_GPIO->P1DIR_f.P15 = 0
#define	P15_SetInput()		M0P_GPIO->P1DIR_f.P15 = 1
#define	P15_SetHigh()		M0P_GPIO->P1OUT_f.P15 = 1
#define	P15_SetLow()		M0P_GPIO->P1OUT_f.P15 = 0
#define	P15_GetValue()		M0P_GPIO->P1IN_f.P15

//--------------------------------------------------------------------------

#define	P23_SetOutput()		M0P_GPIO->P2DIR_f.P23 = 0
#define	P23_SetInput()		M0P_GPIO->P2DIR_f.P23 = 1
#define	P23_SetHigh()		M0P_GPIO->P2OUT_f.P23 = 1
#define	P23_SetLow()		M0P_GPIO->P2OUT_f.P23 = 0
#define	P23_GetValue()		M0P_GPIO->P2IN_f.P23

#define	P24_SetOutput()		M0P_GPIO->P2DIR_f.P24 = 0
#define	P24_SetInput()		M0P_GPIO->P2DIR_f.P24 = 1
#define	P24_SetHigh()		M0P_GPIO->P2OUT_f.P24 = 1
#define	P24_SetLow()		M0P_GPIO->P2OUT_f.P24 = 0
#define	P24_GetValue()		M0P_GPIO->P2IN_f.P24

#define	P25_SetOutput()		M0P_GPIO->P2DIR_f.P25 = 0
#define	P25_SetInput()		M0P_GPIO->P2DIR_f.P25 = 1
#define	P25_SetHigh()		M0P_GPIO->P2OUT_f.P25 = 1
#define	P25_SetLow()		M0P_GPIO->P2OUT_f.P25 = 0
#define	P25_GetValue()		M0P_GPIO->P2IN_f.P25

#define	P26_SetOutput()		M0P_GPIO->P2DIR_f.P26 = 0
#define	P26_SetInput()		M0P_GPIO->P2DIR_f.P26 = 1
#define	P26_SetHigh()		M0P_GPIO->P2OUT_f.P26 = 1
#define	P26_SetLow()		M0P_GPIO->P2OUT_f.P26 = 0
#define	P26_GetValue()		M0P_GPIO->P2IN_f.P26

#define	P27_SetOutput()		M0P_GPIO->P2DIR_f.P27 = 0
#define	P27_SetInput()		M0P_GPIO->P2DIR_f.P27 = 1
#define	P27_SetHigh()		M0P_GPIO->P2OUT_f.P27 = 1
#define	P27_SetLow()		M0P_GPIO->P2OUT_f.P27 = 0
#define	P27_GetValue()		M0P_GPIO->P2IN_f.P27

//--------------------------------------------------------------------------

#define	P31_SetOutput()		M0P_GPIO->P3DIR_f.P31 = 0
#define	P31_SetInput()		M0P_GPIO->P3DIR_f.P31 = 1
#define	P31_SetHigh()		M0P_GPIO->P3OUT_f.P31 = 1
#define	P31_SetLow()		M0P_GPIO->P3OUT_f.P31 = 0
#define	P31_GetValue()		M0P_GPIO->P3IN_f.P31

#define	P32_SetOutput()		M0P_GPIO->P3DIR_f.P32 = 0
#define	P32_SetInput()		M0P_GPIO->P3DIR_f.P32 = 1
#define	P32_SetHigh()		M0P_GPIO->P3OUT_f.P32 = 1
#define	P32_SetLow()		M0P_GPIO->P3OUT_f.P32 = 0
#define	P32_GetValue()		M0P_GPIO->P3IN_f.P32

#define	P33_SetOutput()		M0P_GPIO->P3DIR_f.P33 = 0
#define	P33_SetInput()		M0P_GPIO->P3DIR_f.P33 = 1
#define	P33_SetHigh()		M0P_GPIO->P3OUT_f.P33 = 1
#define	P33_SetLow()		M0P_GPIO->P3OUT_f.P33 = 0
#define	P33_GetValue()		M0P_GPIO->P3IN_f.P33

#define	P34_SetOutput()		M0P_GPIO->P3DIR_f.P34 = 0
#define	P34_SetInput()		M0P_GPIO->P3DIR_f.P34 = 1
#define	P34_SetHigh()		M0P_GPIO->P3OUT_f.P34 = 1
#define	P34_SetLow()		M0P_GPIO->P3OUT_f.P34 = 0
#define	P34_GetValue()		M0P_GPIO->P3IN_f.P34

#define	P35_SetOutput()		M0P_GPIO->P3DIR_f.P35 = 0
#define	P35_SetInput()		M0P_GPIO->P3DIR_f.P35 = 1
#define	P35_SetHigh()		M0P_GPIO->P3OUT_f.P35 = 1
#define	P35_SetLow()		M0P_GPIO->P3OUT_f.P35 = 0
#define	P35_GetValue()		M0P_GPIO->P3IN_f.P35

#define	P36_SetOutput()		M0P_GPIO->P3DIR_f.P36 = 0
#define	P36_SetInput()		M0P_GPIO->P3DIR_f.P36 = 1
#define	P36_SetHigh()		M0P_GPIO->P3OUT_f.P36 = 1
#define	P36_SetLow()		M0P_GPIO->P3OUT_f.P36 = 0
#define	P36_GetValue()		M0P_GPIO->P3IN_f.P36


//==============================================================================

#endif

//==============================================================================
