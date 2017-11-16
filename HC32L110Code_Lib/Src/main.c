
//===================================================================================
#include "hc32lxx.h"
#include "hc32l110_gpio.h"
#include "hc32l110_rcc.h"
#include "stdio.h"
#include "SlaveMcu.h"
#include "Def_Err.h"
//===================================================================================
//TEST Option
#define PERON                     1
#define PEROFF                    0
#define NOP_EN                    1
#define NOP_OFF                   0

#define ACTIVE_PERON_RCH4M         1
#define ACTIVE_PERON_NOP_RCH4M     2
#define ACTIVE_PERON_RCH8M         3
#define ACTIVE_PERON_NOP_RCH8M     4
#define ACTIVE_PERON_RCH16M        5
#define ACTIVE_PERON_NOP_RCH16M    6
#define ACTIVE_PERON_RCH24M        7
#define ACTIVE_PERON_NOP_RCH24M    8

#define ACTIVE_PEROFF_RCH4M        9
#define ACTIVE_PEROFF_NOP_RCH4M    10
#define ACTIVE_PEROFF_RCH8M        11
#define ACTIVE_PEROFF_NOP_RCH8M    12
#define ACTIVE_PEROFF_RCH16M       13
#define ACTIVE_PEROFF_NOP_RCH16M   14
#define ACTIVE_PEROFF_RCH24M       15
#define ACTIVE_PEROFF_NOP_RCH24M   16

#define SLEEP_PERON_RCH4M          17
#define SLEEP_PERON_RCH8M          18
#define SLEEP_PERON_RCH16M         19
#define SLEEP_PERON_RCH24M         20

#define SLEEP_PEROFF_RCH4M         21
#define SLEEP_PEROFF_RCH8M         22
#define SLEEP_PEROFF_RCH16M        23
#define SLEEP_PEROFF_RCH24M        24

#define ACTIVE_PERON_XTL32K        25
#define ACTIVE_PERON_NOP_XTL32K    26
#define ACTIVE_PEROFF_XTL32K       27
#define ACTIVE_PEROFF_NOP_XTL32K   28
#define SLEEP_LPtimer_RTC_XTL32K   29
#define SLEEP_PERON_XTL32K         30

#define DEEPSLEEP_RTC_WDT_LPT      31
#define DEEPSLEEP_LPTIMER_X32K     32
#define DEEPSLEEP_RTC              33
#define DEEPSLEEP_X32K             34
#define DEEPSLEEP_IRC32K           35
#define DEEPSLEEP_WDT              36
#define DEEPSLEEP				   37


//===================================================================================

#define IccTest_Active_1	1	// 在Flash中执行While(1) loop程序，外设的时钟由宏PeriClkON指定。CLK=RC4M - RC24M， 由宏RCH_SEL指定
#define IccTest_Active_2	2	// 在Flash中执行While(1) loop程序，外设的时钟由宏PeriClkON指定。CLK=XT4M - XT32M, 更换晶振实现
#define IccTest_Active_3	3	// 在Flash中执行While(1) loop程序，外设的时钟由宏PeriClkON指定。CLK=RC32K - RC38K, 由宏RCL_SEL指定
#define IccTest_Active_4	4	// 在Flash中执行While(1) loop程序，外设的时钟由宏PeriClkON指定。CLK=XT32K

#define IccTest_Sleep_1		11	// Sleep，外设的时钟由宏PeriClkON指定。CLK=RC4M - RC24M 由宏RCH_SEL指定
#define IccTest_Sleep_2		12	// Sleep，外设的时钟由宏PeriClkON指定。CLK=XT4M - XT32M 更换晶振实现
#define IccTest_Sleep_3		13	// Sleep，外设的时钟由宏PeriClkON指定。CLK=RC32K - RC38K 由宏RCL_SEL指定
#define IccTest_Sleep_4		14	// Sleep，外设的时钟由宏PeriClkON指定。CLK=XT32K

#define IccTest_DeepSleep_1	21	// DeepSleep, NoIP work
#define IccTest_DeepSleep_2	22	// deepSleep, RtcOn,  由宏RTC_SEL指定RTC时钟
#define IccTest_DeepSleep_3	23  // deepSleep, LpUartOn , RC38.4K
#define IccTest_DeepSleep_4	24  // deepSleep, LpTimerOn , RC32k or rc38k , 由宏RCL_SEL指定 ，唤醒时间由宏WakeUpTime指定



//===================================================================================

#define	RCL32K	0
#define	RCL38K	1

#define RCH4M	0
#define RCH8M	1
#define RCH16M	2
#define RCH24M	3

#define	RTC_XT32K 0
#define	RTC_RC32K 2


//===================================================================================

#define CurTestCase  	ACTIVE_PERON_RCH4M
#define PeriClkON		0xffffffff         //该值直接写入 PERI_CLKEN 寄存器
#define PeriClkOFF		0x00000000         //该值直接写入 PERI_CLKEN 寄存器
#define RCL_SEL			RCL32K
#define RCH_SEL 		RCH8M
#define RTC_SEL			RTC_XT32K
#define WakeUpTime		500					//以MS为单位



//N8
//#define RCH_24M_TRIM  	( 0x16C )
//#define RCH_16M_TRIM  	( 0x16F )
//#define RCH_8M_TRIM  	( 0x16D )
//#define RCH_4M_TRIM  	( 0x16B )
//#define RCL_32K_TRIM  	( 0x0E3 )
//#define RCL_38K_TRIM  	( 0x0E4 )
//#define PMU_1V5_TRIM    ( 0x027)
//N11
//#define RCH_24M_TRIM  	( 0x166 )
//#define RCH_16M_TRIM  	( 0x168 )
//#define RCH_8M_TRIM  	( 0x167 )
//#define RCH_4M_TRIM  	( 0x163 )
//#define RCL_32K_TRIM  	( 0x0E6 )
//#define RCL_38K_TRIM  	( 0x0E7 )
//#define PMU_1V5_TRIM    ( 0x026)
//N7
//#define RCH_24M_TRIM  	( 0x168 )
//#define RCH_16M_TRIM  	( 0x16b )
//#define RCH_8M_TRIM  	( 0x168 )
//#define RCH_4M_TRIM  	( 0x165 )
//#define RCL_32K_TRIM  	( 0x0E8 )
//#define RCL_38K_TRIM  	( 0x0E7 )
//#define PMU_1V5_TRIM    ( 0x02B)
////N14
//#define RCH_24M_TRIM  	( 0x168 )
//#define RCH_16M_TRIM  	( 0x16C )
//#define RCH_8M_TRIM  	( 0x16A )
//#define RCH_4M_TRIM  	( 0x166 )
//#define RCL_32K_TRIM  	( 0x0E8 )
//#define RCL_38K_TRIM  	( 0x0E8 )
//#define PMU_1V5_TRIM    ( 0x031)
//N5
//#define RCH_24M_TRIM  	( 0x14A )
//#define RCH_16M_TRIM  	( 0x14D )
//#define RCH_8M_TRIM  	( 0x14A )
//#define RCH_4M_TRIM  	( 0x146 )
//#define RCL_32K_TRIM  	( 0x0DB )
//#define RCL_38K_TRIM  	( 0x0DC )
//#define PMU_1V5_TRIM    ( 0x02A)
//N29
#define RCH_24M_TRIM  	( 0x166 )
#define RCH_16M_TRIM  	( 0x169 )
#define RCH_8M_TRIM  	( 0x167 )
#define RCH_4M_TRIM  	( 0x165 )
#define RCL_32K_TRIM  	( 0x0EE )
#define RCL_38K_TRIM  	( 0x0EE )
#define PMU_1V5_TRIM    ( 0x031)
//N24
//#define RCH_24M_TRIM  	( 0x162 )
//#define RCH_16M_TRIM  	( 0x165 )
//#define RCH_8M_TRIM  	( 0x162 )
//#define RCH_4M_TRIM  	( 0x15c )
//#define RCL_32K_TRIM  	( 0x0E3 )
//#define RCL_38K_TRIM  	( 0x0E4 )
//#define PMU_1V5_TRIM    ( 0x020)
//Y98
//#define RCH_24M_TRIM  	( 0x15B )
//#define RCH_16M_TRIM  	( 0x163 )
//#define RCH_8M_TRIM  	( 0x160 )
//#define RCH_4M_TRIM  	( 0x15A )
//#define RCL_32K_TRIM  	( 0x0E7 )
//#define RCL_38K_TRIM  	( 0x0E8 )
//#define PMU_1V5_TRIM    ( 0x02E)
//Y48
//#define RCH_24M_TRIM  	( 0x15C )
//#define RCH_16M_TRIM  	( 0x163 )
//#define RCH_8M_TRIM  	( 0x163 )
//#define RCH_4M_TRIM  	( 0x15C )
//#define RCL_32K_TRIM  	( 0x0E7 )
//#define RCL_38K_TRIM  	( 0x0E8 )
//#define PMU_1V5_TRIM    ( 0x07F)
//==============================================================================

uint8_t	PcOutBuf[256];
uint8_t PcOutCnt;
uint8_t	PcInBuf[256];
uint8_t PcInCnt;

uint32_t gWriteAddr = 0x0000;
uint32_t gWriteData = 0x0000;
uint16_t gMcuIns	= 0x0000;

//===================================================================================

void DoIccTest_ActiveOrSleep_1( uint8_t CpuMode, uint8_t Per_switch, uint8_t nop_switch, uint8_t RCH_Clk);
void DoIccTest_ActiveOrSleep_4( uint8_t CpuMode, uint8_t Per_switch, uint8_t nop_switch, uint32_t Other_Per);
void DoIccTest_ActiveOrSleep_3( uint8_t CpuMode );
void DoIccTest_DeepSleep_1(uint8_t Test_Option );


void DoIccTest_DeepSleep_2( void );
void DoIccTest_DeepSleep_3( void );
void DoIccTest_DeepSleep_4( void );

void BTIMERLP_init(uint8_t Test_Option );
void GPIO_SetLowpowerMode( void );
void XSPI_Task( void );
void Fun_WriteRegAndExeIns( void );
void SystemClk_Switch( uint8_t ClkSource  , uint8_t EnDis );
uint8_t Fun_CLA10(uint8_t *PcOutBuf , uint8_t PcOutCnt , uint8_t *pPcInBuf , uint8_t *pPcInCnt);

//===================================================================================



void Test()
{

	P03_SetOutput();
	L005_GPIO->P0DIR_f.P0DIR3 = 0;
	while(1)
	{
	P03_SetHigh();
	McuDelay(40000);
	P03_SetLow();
	McuDelay(200000);
	}
    
    
}

void Run_Show(uint8_t cnt)
{
	while(cnt--)
	{
		P03_SetHigh();
		McuDelay(40000);
		P03_SetLow();
		McuDelay(200000);
	}
}
void Key_Init(void)
{
	L005_GPIO->P2ADS = 0X00;
	L005_GPIO->P2DIR = 0xff;
	L005_GPIO->P2PU  = 0xff;
	L005_GPIO->P3ADS = 0X00;
	L005_GPIO->P3DIR = 0XFF;
	L005_GPIO->P3PU = 0XFF;
}


uint8_t  Key_Scan(void)
{
	uint8_t key_p2 = 0;
	uint8_t key_p3 = 0;
	Key_Init();
	McuDelay(1000);
	key_p2 = ~L005_GPIO->P2IN;
	key_p3 = ~L005_GPIO->P3IN;
	return (key_p2 >> 3) | ((key_p3 >> 1) << 5) ;
}

int main(void)
{
	uint8_t TestIdx = ACTIVE_PERON_RCH24M;
	L005_SystemCtrl->PERI_CLKEN = 0xffffffff;
	L005_SystemCtrl->BOOT0_f.auto_switch_lpm = 1;
	L005_PMU->PMU_f.TRIM_V1P5 = PMU_1V5_TRIM;
	
	P03_SetLow();
	P03_SetOutput();
	//TestIdx = Key_Scan();
	
	GPIO_SetLowpowerMode();
	
	McuDelay( 1000 );  //处理按键没有按下却读到低的情况（当外接示波器时，可能出现该情况）
	
    GPIO_Test();
    
	switch( TestIdx )
	{
		case ACTIVE_PERON_RCH4M:      DoIccTest_ActiveOrSleep_1( 1, PERON, NOP_EN, RCH4M);	    break;
		case ACTIVE_PERON_NOP_RCH4M:  DoIccTest_ActiveOrSleep_1( 1, PERON, NOP_OFF, RCH4M);	    break;    
		case ACTIVE_PERON_RCH8M:      DoIccTest_ActiveOrSleep_1( 1, PERON, NOP_EN, RCH8M);	    break;
		case ACTIVE_PERON_NOP_RCH8M:  DoIccTest_ActiveOrSleep_1( 1, PERON, NOP_OFF, RCH8M);	    break;
		case ACTIVE_PERON_RCH16M:     DoIccTest_ActiveOrSleep_1( 1, PERON, NOP_EN, RCH16M);	    break;
		case ACTIVE_PERON_NOP_RCH16M: DoIccTest_ActiveOrSleep_1( 1, PERON, NOP_OFF, RCH16M);    break;
		case ACTIVE_PERON_RCH24M:     DoIccTest_ActiveOrSleep_1( 1, PERON, NOP_EN, RCH24M);	    break;
		case ACTIVE_PERON_NOP_RCH24M: DoIccTest_ActiveOrSleep_1( 1, PERON, NOP_OFF, RCH24M);    break;
		
		case ACTIVE_PEROFF_RCH4M:      DoIccTest_ActiveOrSleep_1( 1, PEROFF, NOP_EN, RCH4M);	break;
		case ACTIVE_PEROFF_NOP_RCH4M:  DoIccTest_ActiveOrSleep_1( 1, PEROFF, NOP_OFF, RCH4M);	break;    
		case ACTIVE_PEROFF_RCH8M:      DoIccTest_ActiveOrSleep_1( 1, PEROFF, NOP_EN, RCH8M);	break;
		case ACTIVE_PEROFF_NOP_RCH8M:  DoIccTest_ActiveOrSleep_1( 1, PEROFF, NOP_OFF, RCH8M);	break;
		case ACTIVE_PEROFF_RCH16M:     DoIccTest_ActiveOrSleep_1( 1, PEROFF, NOP_EN, RCH16M);	break;
		case ACTIVE_PEROFF_NOP_RCH16M: DoIccTest_ActiveOrSleep_1( 1, PEROFF, NOP_OFF, RCH16M);  break;
		case ACTIVE_PEROFF_RCH24M:     DoIccTest_ActiveOrSleep_1( 1, PEROFF, NOP_EN, RCH24M);	break;
		case ACTIVE_PEROFF_NOP_RCH24M: DoIccTest_ActiveOrSleep_1( 1, PEROFF, NOP_OFF, RCH24M);  break;
		
		case SLEEP_PERON_RCH4M:        DoIccTest_ActiveOrSleep_1( 0, PERON, NOP_OFF, RCH4M);	break;
		case SLEEP_PERON_RCH8M:        DoIccTest_ActiveOrSleep_1( 0, PERON, NOP_OFF, RCH8M);	break;
		case SLEEP_PERON_RCH16M:       DoIccTest_ActiveOrSleep_1( 0, PERON, NOP_OFF, RCH16M);	break;
		case SLEEP_PERON_RCH24M:       DoIccTest_ActiveOrSleep_1( 0, PERON, NOP_OFF, RCH24M);	break;
		
		case SLEEP_PEROFF_RCH4M:       DoIccTest_ActiveOrSleep_1( 0, PEROFF, NOP_OFF, RCH4M);	break;
		case SLEEP_PEROFF_RCH8M:       DoIccTest_ActiveOrSleep_1( 0, PEROFF, NOP_OFF, RCH8M);	break;
		case SLEEP_PEROFF_RCH16M:      DoIccTest_ActiveOrSleep_1( 0, PEROFF, NOP_OFF, RCH16M);	break;
		case SLEEP_PEROFF_RCH24M:      DoIccTest_ActiveOrSleep_1( 0, PEROFF, NOP_OFF, RCH24M);	break;

		case ACTIVE_PERON_XTL32K:      DoIccTest_ActiveOrSleep_4( 1, PERON, NOP_OFF, 0); break;
		case ACTIVE_PEROFF_XTL32K:     DoIccTest_ActiveOrSleep_4( 1, PEROFF, NOP_OFF, 0); break;
		case SLEEP_LPtimer_RTC_XTL32K: DoIccTest_ActiveOrSleep_4( 0, PEROFF, NOP_OFF, ((1<<9) | (1<< 20))); break;
        case SLEEP_PERON_XTL32K:       DoIccTest_ActiveOrSleep_4( 0, PERON, NOP_OFF, 0); break;
		
		case DEEPSLEEP_RTC_WDT_LPT:    DoIccTest_DeepSleep_1(DEEPSLEEP_RTC_WDT_LPT); break;
		case DEEPSLEEP_LPTIMER_X32K:   DoIccTest_DeepSleep_1(DEEPSLEEP_LPTIMER_X32K); break;
		case DEEPSLEEP_RTC:            DoIccTest_DeepSleep_1(DEEPSLEEP_RTC); break;
		case DEEPSLEEP_X32K:           DoIccTest_DeepSleep_1(DEEPSLEEP_X32K); break;
		case DEEPSLEEP_IRC32K:         DoIccTest_DeepSleep_1( DEEPSLEEP_IRC32K ); break; 
		case DEEPSLEEP_WDT:            DoIccTest_DeepSleep_1(DEEPSLEEP_WDT); break; 
		case DEEPSLEEP:				   DoIccTest_DeepSleep_1(DEEPSLEEP); break;
		
		//add test case
		case ACTIVE_PERON_NOP_XTL32K:  DoIccTest_ActiveOrSleep_4( 1, PERON, NOP_EN, 0);	break;
		case ACTIVE_PEROFF_NOP_XTL32K: DoIccTest_ActiveOrSleep_4( 1, PEROFF, NOP_EN, 0);	break;
	
		default: Test(); break;
	}
	
	while(1);
	
}


//==========================================================
// 在Flash中执行While(1) loop程序，外设的时钟由宏PeriClkON指定。CLK=RC4M - RC24M
// CpuMode=0 代表sleep , CpuMode=1 代表Active
void DoIccTest_ActiveOrSleep_1( uint8_t CpuMode, uint8_t Per_switch, uint8_t nop_switch, uint8_t RCH_Clk)
{
	//切24M
	L005_SystemCtrl->RCH_CR_f.FSEL = RCH_Clk;
	if( L005_SystemCtrl->RCH_CR_f.FSEL == RCH24M ) { L005_SystemCtrl->RCH_CR_f.TRIM = RCH_24M_TRIM; }
	if( L005_SystemCtrl->RCH_CR_f.FSEL == RCH16M ) { L005_SystemCtrl->RCH_CR_f.TRIM = RCH_16M_TRIM; }
	if( L005_SystemCtrl->RCH_CR_f.FSEL == RCH8M )  { L005_SystemCtrl->RCH_CR_f.TRIM = RCH_8M_TRIM; }
	if( L005_SystemCtrl->RCH_CR_f.FSEL == RCH4M )  { L005_SystemCtrl->RCH_CR_f.TRIM = RCH_4M_TRIM; }
	L005_SystemCtrl->SYSCTRL2 = 0X5A5A;
	L005_SystemCtrl->SYSCTRL2 = 0XA5A5;
	L005_SystemCtrl->SYSCTRL0_f.RCH_EN = 1;
	//L005_FLASH->CR_f.WAIT = 1;//
    
	while( L005_SystemCtrl->RCH_CR_f.stable == 0);
	L005_SystemCtrl->SYSCTRL2 = 0X5A5A;
	L005_SystemCtrl->SYSCTRL2 = 0XA5A5;
	L005_SystemCtrl->SYSCTRL0_f.Clk_sw4_sel = 0x00;
	
        P24_SetOutput();
	L005_GPIO->P24_SEL = 0X03;
	L005_GPIO->GPIO_CTRL1_f.hclk_sel = 0X03;
	L005_GPIO->GPIO_CTRL1_f.hclk_en = 1;
    
	L005_SystemCtrl->PERI_CLKEN = PeriClkON;  	//打开指定的CLK
	if(Per_switch == PERON)
		L005_SystemCtrl->PERI_CLKEN = PeriClkON;
	else if(Per_switch == PEROFF)
		L005_SystemCtrl->PERI_CLKEN = PeriClkOFF;

	if( CpuMode == 0x00 )
	{
		SCB_SCR = 0x00;	//sleep
		__WFI();
		while(1);
	}
	else
	{
		if(nop_switch == NOP_EN)
		{	
			while( 1 );
		}
		else
		{
			__NOP();
			while( 1 );
		}		
	}
	
}

//==========================================================
// 在Flash中执行While(1) loop程序，外设的时钟由宏PeriClkON指定。CLK=RC4M - XT32M
// CpuMode=0 代表sleep , CpuMode=1 代表Active
void DoIccTest_ActiveOrSleep_2( uint8_t CpuMode )
{
//	L005_SystemCtrl->BOOT1_f.XTH_TEST |= 0X1;//别忘了重新上电
	//切32M
	L005_GPIO->P0ADS_f.P0ADS1 = 1;
	L005_GPIO->P0ADS_f.P0ADS2 = 1;
	L005_SystemCtrl->XTH_CR_f.Driver = 0xf;
	L005_SystemCtrl->XTH_CR_f.Startup = 3;//默认为2
	L005_SystemCtrl->SYSCTRL2 = 0X5A5A;
	L005_SystemCtrl->SYSCTRL2 = 0XA5A5;
	L005_SystemCtrl->SYSCTRL0_f.XTH_EN = 1;
	L005_FLASH->CR_f.WAIT = 1;//当从低速时钟切换到外部高速时钟时需要设置flash读等待周期为1
	
	while( L005_SystemCtrl->XTH_CR_f.stable == 0);
	L005_SystemCtrl->SYSCTRL2 = 0X5A5A;
	L005_SystemCtrl->SYSCTRL2 = 0XA5A5;
	L005_SystemCtrl->SYSCTRL0_f.Clk_sw4_sel = 0x01;   //0=RCH , 1=XTH , 2=RCL , 3=XTL
	
	//关RCH
	L005_SystemCtrl->SYSCTRL2 = 0X5A5A;
	L005_SystemCtrl->SYSCTRL2 = 0XA5A5;
	L005_SystemCtrl->SYSCTRL0_f.RCH_EN = 0;
	
	L005_SystemCtrl->PERI_CLKEN = PeriClkON;  			  //打开指定的CLK
	if( CpuMode == 0x00 )
	{
		SCB_SCR = 0x00;	//sleep
		__WFI();
	}
	while(1)
	{
		if(P03_GetValue() == 0)
		{	
			while( 1 );
		}
		else
		{
			while( 1 );
		}
	}
}


//==========================================================
// 在Flash中执行While(1) loop程序，外设的时钟由宏PeriClkON指定。CLK=RC32K - RC38K
// CpuMode=0 代表sleep , CpuMode=1 代表Active
void DoIccTest_ActiveOrSleep_3( uint8_t CpuMode )
{
	//切rc32k
	L005_SystemCtrl->RCL_CR_f.FSEL = RCL_SEL;
	if( L005_SystemCtrl->RCL_CR_f.FSEL == RCL32K ) { L005_SystemCtrl->RCL_CR_f.TRIM = RCL_32K_TRIM; }
	if( L005_SystemCtrl->RCL_CR_f.FSEL == RCL38K ) { L005_SystemCtrl->RCL_CR_f.TRIM = RCL_38K_TRIM; }
	L005_SystemCtrl->SYSCTRL2 = 0X5A5A;
	L005_SystemCtrl->SYSCTRL2 = 0XA5A5;
	L005_SystemCtrl->SYSCTRL0_f.RCL_EN = 1;
	
	while( L005_SystemCtrl->RCL_CR_f.stable == 0);
	L005_SystemCtrl->SYSCTRL2 = 0X5A5A;
	L005_SystemCtrl->SYSCTRL2 = 0XA5A5;
	L005_SystemCtrl->SYSCTRL0_f.Clk_sw4_sel = 0x02;   //0=RCH , 1=XTH , 2=RCL , 3=XTL
	L005_SystemCtrl->PERI_CLKEN = PeriClkON;  		//打开指定的CLK
	
	//关RCH
	L005_SystemCtrl->SYSCTRL2 = 0X5A5A;
	L005_SystemCtrl->SYSCTRL2 = 0XA5A5;
	L005_SystemCtrl->SYSCTRL0_f.RCH_EN = 0;
	
		
	P24_SetOutput();
	L005_GPIO->P24_SEL = 0X03;
	L005_GPIO->GPIO_CTRL1_f.hclk_sel = 0X00;
	L005_GPIO->GPIO_CTRL1_f.hclk_en = 1;
//	while( P32_GetValue() );
//	P24_SetInput();
//	L005_GPIO->P24_SEL =  0x00;
//	L005_GPIO->GPIO_CTRL1_f.hclk_en = 0;
//	
//	L005_SystemCtrl->PERI_CLKEN = PeriClkON;  			  //打开指定的CLK
	if( CpuMode == 0x00 )
	{
		SCB_SCR = 0x00;	//sleep
		__WFI();
	}
	while( 1 );
	

}

//==========================================================
// 在Flash中执行While(1) loop程序，外设的时钟由宏PeriClkON指定。CLK= RCH - XT32K
// CpuMode=0 代表sleep , CpuMode=1 代表Active
void DoIccTest_ActiveOrSleep_4( uint8_t CpuMode, uint8_t Per_switch, uint8_t nop_switch, uint32_t Other_Per)
{
	L005_SystemCtrl->PERI_CLKEN = PeriClkON;  			  //打开指定的CLK
	//切32768
	L005_GPIO->P1ADS_f.P1ADS4 = 1;
	L005_GPIO->P1ADS_f.P1ADS5 = 1;
	L005_SystemCtrl->XTL_CR_f.Driver = 0x0;
	L005_SystemCtrl->SYSCTRL2 = 0X5A5A;
	L005_SystemCtrl->SYSCTRL2 = 0XA5A5;
	L005_SystemCtrl->SYSCTRL0_f.XTL_EN = 1;
	
	while( L005_SystemCtrl->XTL_CR_f.stable == 0 );
	L005_SystemCtrl->SYSCTRL2 = 0X5A5A;
	L005_SystemCtrl->SYSCTRL2 = 0XA5A5;
	L005_SystemCtrl->SYSCTRL0_f.Clk_sw4_sel = 0x03;   //0=RCH , 1=XTH , 2=RCL , 3=XTL
	
	//关RCH
	L005_SystemCtrl->SYSCTRL2 = 0X5A5A;
	L005_SystemCtrl->SYSCTRL2 = 0XA5A5;
	L005_SystemCtrl->SYSCTRL0_f.RCH_EN = 0;

	if(Per_switch == PERON)
		L005_SystemCtrl->PERI_CLKEN = PeriClkON;
	else if(Per_switch == PEROFF)
		L005_SystemCtrl->PERI_CLKEN = PeriClkOFF;
	
	if( CpuMode == 0x00 )
	{
		L005_SystemCtrl->PERI_CLKEN |= Other_Per;
		SCB_SCR = 0x00;	//sleep
		__WFI();
	}
	if(nop_switch)
	{
		while( 1 );
	}
	else
	{
		while(1);
	}
		

}



//==========================================================
void IRC32K(void);
void X32_init(void);
void RTC_init(void);
void WDT_init(void);
// DeepSleep, NoIP work
void DoIccTest_DeepSleep_1(uint8_t Test_Option )
{
	L005_SystemCtrl->PERI_CLKEN = 0xffffffff;
	switch(Test_Option)
	{
		case DEEPSLEEP_RTC_WDT_LPT://29 ok...
			X32_init();
			BTIMERLP_init(0);
			RTC_init();
			WDT_init();
			break;
		case DEEPSLEEP_LPTIMER_X32K://30 ok...
			X32_init();
			BTIMERLP_init(0);
			break;
		case DEEPSLEEP_RTC://31 ok...
			X32_init();
			RTC_init();
			break;
		case DEEPSLEEP_X32K://32 ok...
			X32_init();
			break;
		case DEEPSLEEP_IRC32K://33 ok
			IRC32K();
			break;
		case DEEPSLEEP_WDT://34 ok...
			WDT_init();
			break;
		case DEEPSLEEP://35 ok...
			L005_SystemCtrl->PERI_CLKEN = 0x0;	
			break;
		default: 
			break;
	}

	//deepsleep
	SCB_SCR = 0x01<<2 ;
	__WFI();
	__WFI();
	while( 1 );
}

//==========================================================
//deepSleep, RtcOn,  由宏RTC_SEL指定RTC时钟
void DoIccTest_DeepSleep_2( void )
{
}

//==========================================================
// deepSleep, LpUartOn , RC38.4K
void DoIccTest_DeepSleep_3( void )
{
}

//===================================================================================
void GPIO_SetLowpowerMode( void )
{
	L005_SystemCtrl->SYSCTRL2 = 0X5A5A;
	L005_SystemCtrl->SYSCTRL2 = 0XA5A5;
	L005_SystemCtrl->SYSCTRL1 |= (1<<8); // swd as io
	
	L005_GPIO->P0ADS = 0X00;
	L005_GPIO->P1ADS = 0X00;
	L005_GPIO->P2ADS = 0X00;
	L005_GPIO->P3ADS = 0X00;
	
	L005_GPIO->P0DIR = 0xff;//输入
	L005_GPIO->P1DIR = 0xff;
	L005_GPIO->P2DIR = 0xff;
	L005_GPIO->P3DIR = 0xff;
	
	L005_GPIO->P0PU  = 0x00;
	L005_GPIO->P1PU  = 0x00;
	L005_GPIO->P2PU  = 0x00;
	L005_GPIO->P3PU  = 0x00;
	
	L005_GPIO->P0PD = 0xff;
	L005_GPIO->P1PD = 0xff;
	L005_GPIO->P2PD = 0xff;
	L005_GPIO->P3PD = 0xff;
	
}
void X32_init(void)
{
   //切32768
	L005_GPIO->P1ADS_f.P1ADS4=1;
	L005_GPIO->P1ADS_f.P1ADS5=1;
	L005_SystemCtrl->SYSCTRL2=0x5A5A;
	L005_SystemCtrl->SYSCTRL2=0xA5A5;		
	L005_SystemCtrl->SYSCTRL0_f.XTL_EN = 1;
	while(L005_SystemCtrl->XTL_CR_f.stable==0);

}
void IRC32K(void)
{
	L005_SystemCtrl->RCL_CR_f.FSEL = RCL32K;
	L005_SystemCtrl->RCL_CR_f.TRIM = RCL_32K_TRIM;
	L005_SystemCtrl->RCL_CR_f.Startup = 3;
	L005_SystemCtrl->SYSCTRL2 = 0X5A5A;
	L005_SystemCtrl->SYSCTRL2 = 0XA5A5;
	L005_SystemCtrl->SYSCTRL0_f.RCL_EN = 1;
	while(L005_SystemCtrl->RCL_CR_f.stable == 0);
	
//	L005_SystemCtrl->SYSCTRL2 = 0X5A5A;
//	L005_SystemCtrl->SYSCTRL2 = 0XA5A5;
//	L005_SystemCtrl->SYSCTRL0_f.Clk_sw4_sel = 0x02;   //0=RCH , 1=XTH , 2=RCL , 3=XTL
//	L005_SystemCtrl->PERI_CLKEN = PeriClkON;  		//打开指定的CLK
//	
//	//关RCH
//	L005_SystemCtrl->SYSCTRL2 = 0X5A5A;
//	L005_SystemCtrl->SYSCTRL2 = 0XA5A5;
//	L005_SystemCtrl->SYSCTRL0_f.RCH_EN = 0;
//	
//	P24_SetOutput();
//	L005_GPIO->P24_SEL = 0X03;
//	L005_GPIO->GPIO_CTRL1_f.hclk_sel = 0X00;
//	L005_GPIO->GPIO_CTRL1_f.hclk_en = 1;
//	while(1);
}
void WDT_init(void)
{

	WDT__CON=0X0f; // use wdt reset, overflow 50s @10k
	WDT__RST=0X01E;
	WDT__RST=0X0E1;

}
void RTC_init(void)
{
	L005_SystemCtrl->SYSCTRL2=0x5A5A;
	L005_SystemCtrl->SYSCTRL1=0x0188; //reset swd use io
	L005_SystemCtrl->PERI_CLKEN_f.RTC = 1;
	
	L005_RTC->SEC=0X59;	//99-12-31-23-59-59
	L005_RTC->CR0_f.AMPM=1;
	L005_RTC->MIN=0X59;
	L005_RTC->HOUR=0X23;
	L005_RTC->DAY=0X31;
	L005_RTC->WEEK=0X6;
	L005_RTC->MON=0X12;
	L005_RTC->YEAR=0X99;
	L005_RTC->ALMMIN=0X00;
	L005_RTC->ALMHOUR=0X00;
	L005_RTC->ALMWEEK=0X7F;
	
	L005_RTC->CR0_f.PRDS=1;
	L005_RTC->CR0_f.HZ1SEL = 1;
	L005_RTC->CR0_f.HZ1OE=1;
	L005_RTC->CR1_f.ALMEN=1;
	L005_RTC->CR0_f.START=1;

	L005_RTC->CR1_f.WAIT=1;
	while(L005_RTC->CR1_f.WAITF==0);
	L005_RTC->CR1_f.WAIT=0;
	while(L005_RTC->CR1_f.WAITF==1);
	
//	L005_GPIO->P32_SEL=0X07; //rtc_1hz -> P32
//	L005_GPIO->P3DIR_f.P3DIR2 = 0;
	
	L005_SystemCtrl->BOOT0=0X6FF8;
}

void BTIMERLP_init(uint8_t TM3_togger)
{
	NVIC_ClearPendingIRQ(IRQn_BASE_TIMER3);
	NVIC_SetPriority(IRQn_BASE_TIMER3, 1);
	//NVIC_EnableIRQ(IRQn_BASE_TIMER3);
	L005_SystemCtrl->PERI_CLKEN_f.LPTIM = 1;
	
	L005_LPTIM->CR_f.TCK_SEL = 0X2;//选择PCLK作为LpTimer时钟00:PCLK 10：XIL32K 11：IRC32K

	L005_LPTIM->CR_f.IE = 1;
	L005_LPTIM->CR_f.TR=0;
	while(L005_LPTIM->CR_f.WT_FLAG==0);
	L005_LPTIM->ARR=0Xe000;
	L005_LPTIM->CNT=0Xe000;
//	L005_LPTIM->ARR=0XFF90;
//	L005_LPTIM->CNT=0XFF90;
	L005_LPTIM->CR_f.MD=1;
	L005_LPTIM->CR_f.TR=1;
	//2HZ
	L005_LPTIM->CR_f.TR=1;
	
	//设置P31输出LPTimer定时器信号
//	L005_GPIO->P3ADS_f.P3ADS1 = 0;
//	L005_GPIO->P31_SEL = 1;
//	L005_GPIO->P3DIR_f.P3DIR1 = 0;
}
//===================================================================================

void XSPI_Task( void )
{
	uint8_t ErrFlag;
	
	if ( XSPI_RecvMsgFromHostMcu( PcOutBuf , &PcOutCnt ) == CRR_PASS )
	{
		switch ( PcOutBuf[0] )
		{
			case 0x10:
			{
				ErrFlag = Fun_CLA10(PcOutBuf , PcOutCnt , PcInBuf , &PcInCnt);
				break;
			}
		  
			default  :
			{
				PcInCnt=0x00 ;
				ErrFlag=ERR_Cla;
				break;
			}
		}
	  
		XSPI_SendMsgToMasterMcu( PcInBuf ,  PcInCnt ,  ErrFlag);
		Fun_WriteRegAndExeIns();
	}
}

//===================================================================================


uint8_t Fun_CLA10(uint8_t *PcOutBuf , uint8_t PcOutCnt , uint8_t *pPcInBuf , uint8_t *pPcInCnt)
{
	uint8_t ErrFlag;
	uint16_t tmp16;
	uint32_t addr32 , tmp32;


	switch ( PcOutBuf[1] )
	{
			//1020 INS
		case 0x20:	//执行MCU指令
		{
			gMcuIns  = (((uint32_t)PcOutBuf[2])<<8) | (((uint32_t)PcOutBuf[3])<<0);
			if ( gMcuIns==0xBF30 || gMcuIns== 0xBF20)
			{
				ErrFlag = CRR_PASS;
			}
			else
			{
				ErrFlag = ERR_INS;
			}
			*pPcInCnt = 0x00;
			break;
		}

		//1028 A3A2A1A0 V3V2V1V0 insh insl
		case 0x28:
		{
			addr32 = (((uint32_t)PcOutBuf[2])<<24) | (((uint32_t)PcOutBuf[3])<<16) | (((uint32_t)PcOutBuf[4])<<8) | (((uint32_t)PcOutBuf[5])<<0);
			tmp32  = (((uint32_t)PcOutBuf[6])<<24) | (((uint32_t)PcOutBuf[7])<<16) | (((uint32_t)PcOutBuf[8])<<8) | (((uint32_t)PcOutBuf[9])<<0);
			tmp16  = (((uint32_t)PcOutBuf[10])<<8) | (((uint32_t)PcOutBuf[11])<<0);
			if ( PcOutCnt == 10 )
			{
				*((volatile uint32_t * )addr32) = tmp32;		//??????
				gMcuIns = 0x0000;
				gWriteAddr = 0X0000;
			}
			else
			{
				gWriteAddr = addr32;				//?????MCU??????????
				gWriteData = tmp32;
				gMcuIns = tmp16;
			}

			*pPcInCnt = 0x00;
			ErrFlag = CRR_PASS;
			break;
		}
		//1029 A3 A2 A1 A0
		case 0x29:
		{
			addr32 = (((uint32_t)PcOutBuf[2])<<24) | (((uint32_t)PcOutBuf[3])<<16) | (((uint32_t)PcOutBuf[4])<<8) | (((uint32_t)PcOutBuf[5])<<0);
			tmp32  = *((volatile uint32_t * )addr32);
			pPcInBuf[0] = (uint8_t)((tmp32>>24) & 0xff);
			pPcInBuf[1] = (uint8_t)((tmp32>>16) & 0xff);
			pPcInBuf[2] = (uint8_t)((tmp32>>8) & 0xff);
			pPcInBuf[3] = (uint8_t)((tmp32>>0) & 0xff);
			*pPcInCnt = 0x04;
			ErrFlag = CRR_PASS;
			break;
		}
		default:
		{
			PcInCnt=0x00;
			ErrFlag=ERR_INS;
			break;
		}
	}

	return( ErrFlag );

}

//==============================================================================

void Fun_WriteRegAndExeIns( void )
{
	if ( gWriteAddr )
	{
		*((volatile uint32_t * )gWriteAddr) = gWriteData;
	}

	switch ( gMcuIns )
	{
		case 0xBF30:
		{
			//gWriteData = *((volatile unsigned int*)(0x40035200UL));
			__WFI();
			break;
		}
		case 0xBF20:
		{
			//gWriteData = *((volatile unsigned int*)(0x40035200UL));
			__WFE();
			break;
		}
		default:	break;
	}

	gMcuIns = 0x0000;
	gWriteAddr = 0x0000;

}







//===================================================================================

