#ifndef __HC32LXX_H
#define __HC32LXX_H

#ifdef __cplusplus
 extern "C" {
#endif 
//  
#if defined ( __CC_ARM   )
#pragma anon_unions
#endif
     
     
#define HC32L110X6
#define assert_param(expr) ((void)0)

#if !defined (HC32L110x6)
 //#error "Please select first the target HC32L110X6 device used in your application (in hc32lxx.h file)"
#endif

#if !defined  USE_STDPERIPH_DRIVER

#endif /* USE_STDPERIPH_DRIVER */


#if !defined  (HSE_VALUE)     
#define HSE_VALUE    ((uint32_t)32000000) /*!< Value of the External oscillator in Hz*/
#endif /* HSE_VALUE */

/**
 * @brief In the following line adjust the External High Speed oscillator (HSE) Startup 
   Timeout value 
   */
#if !defined  (HSE_STARTUP_TIMEOUT)
#define HSE_STARTUP_TIMEOUT   ((uint16_t)0x3) /*!< Time out for HSE start up */
#endif /* HSE_STARTUP_TIMEOUT */

/**
 * @brief In the following line adjust the Internal High Speed oscillator (HSI) Startup 
   Timeout value 
   */
#if !defined  (HSI_STARTUP_TIMEOUT)
#define HSI_STARTUP_TIMEOUT   ((uint16_t)0x3) /*!< Time out for HSI start up */
#endif /* HSI_STARTUP_TIMEOUT */

#if !defined  (HSI_VALUE) 
#define HSI_VALUE  ((uint32_t)4000000) /*!< Value of the Internal High Speed oscillator in Hz.
                                             The real value may vary depending on the variations
                                             in voltage and temperature.  */
#endif /* HSI_VALUE */

#if !defined  (HSI14_VALUE) 
#define HSI14_VALUE ((uint32_t)14000000) /*!< Value of the Internal High Speed oscillator for ADC in Hz.
                                             The real value may vary depending on the variations
                                             in voltage and temperature.  */
#endif /* HSI14_VALUE */

#if !defined  (LSI_VALUE) 
#define LSI_VALUE  ((uint32_t)38400)    /*!< Value of the Internal Low Speed oscillator in Hz
                                             The real value may vary depending on the variations
                                             in voltage and temperature.  */
#endif /* LSI_VALUE */

#if !defined  (LSE_VALUE) 
#define LSE_VALUE  ((uint32_t)32768)    /*!< Value of the External Low Speed oscillator in Hz */
#endif /* LSE_VALUE */


/**
 * @brief HC32Lxx Interrupt Number Definition, according to the selected device 
 *        in @ref Library_configuration_section 
 */
 #define __MPU_PRESENT           0 /* No MPU                                        */
#define __NVIC_PRIO_BITS        2 /* M0P uses 2 Bits for the Priority Levels       */
#define __Vendor_SysTickConfig  0 /* Set to 1 if different SysTick Config is used */
#define __VTOR_PRESENT          1


typedef enum IRQn
{
/* -------------------  Cortex-M0+ Processor Exceptions Numbers  ------------------ */
  IRQn_NonMaskableInt           = -14,      /*!<  2 Non Maskable Interrupt          */
  IRQn_HardFault                = -13,      /*!<  3 HardFault Interrupt             */



  IRQn_SVCall                   =  -5,      /*!< 11 SV Call Interrupt               */

  IRQn_PendSV                   =  -2,      /*!< 14 Pend SV Interrupt               */
  SysTick_IRQn                  =  -1,      /*!< 15 System Tick Interrupt           */

/* ----------------------  ARMCM0 Specific Interrupt Numbers  --------------------- */
  IRQn_GPIO_P0                  =   0,      
  IRQn_GPIO_P1                  =   1,     
  IRQn_GPIO_P2                  =   2,     
  IRQn_GPIO_P3                  =   3,      
  IRQn_UART0                    =   6,      
  IRQn_UART1                    =   7,     
  IRQn_UART2                    =   8,     
  IRQn_SPI                      =  10,            
  IRQn_I2C                      =  12,        
  IRQn_BASE_TIMER0              =  14,    
  IRQn_BASE_TIMER1              =  15,     
  IRQn_BASE_TIMER2              =  16,     
  IRQn_BASE_TIMER3              =  17,     
  IRQn_ADV_TIMER0               =  18,      
  IRQn_ADV_TIMER1               =  19,      
  IRQn_ADV_TIMER2               =  20,     
  IRQn_PCA                      =  21,          
  IRQn_WDT                      =  22,    
  IRQn_RTC                      =  23,      
  IRQn_ADC                      =  24,      
//  DAC_IRQn                      =  25,      
  IRQn_VC1                      =  26,      
  IRQn_VC2                      =  27,      
  IRQn_LVD                      =  28,      
//  LCD_IRQn                      =  29,      
  IRQn_RAM_FLASH_FAULT          =  30,      
  IRQn_CLOCK_TRIM               =  31,     
} IRQn_Type;
/*!< Interrupt Number Definition */
/**
  * @}
  */

#include "core_cm0plus.h"
#define SCB_SCR (*(volatile unsigned long *)0XE000ED10)
#include <stdint.h>

/** @addtogroup Exported_types
  * @{
  */  

typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus;

typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;
#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

typedef enum {ERROR = 0, SUCCESS = !ERROR} ErrorStatus;

/** @addtogroup Peripheral_registers_structures
  * @{
  */   

/** 
  * @brief Analog to Digital Converter  
  */
	
#define UART0_BASEADDR       (0x40000000)
#define UART1_BASEADDR       (0x40000100)
#define UART2_BASEADDR       (0x40000200)
#define I2C_BASEADDR       	 (0x40000400)	
#define SPI_BASEADDR         (0x40000800)	
#define BTIMER_BASEADDR      (0x40000C00)
#define BTIMER0_BASEADDR     (0x40000C00)
#define BTIMER1_BASEADDR     (0x40000C20)
#define BTIMER2_BASEADDR     (0x40000C40)
#define BTIMERLP_BASEADDR    (0x40000C60)
#define BTIMERWDT_BASEADDR   (0x40000C80)

#define PCA_BASEADDR         (0x40001000)
#define RTC_BASEADDR         (0x40001400)
#define CLK_TRIM_BASEADDR    (0x40001800)
#define RNG_BASEADDR         (0x40001C00)
#define SYSTEM_CTRL_BASEADDR (0x40002000) 
#define ANALOGCTRL_BASEADDR  (0x40002400)
#define TIM4_BASEADDR        (0x40003000)	
#define TIM5_BASEADDR        (0x40003400)	
#define TIM6_BASEADDR        (0x40003800)	

#define EFLASH_CTRL_BASEADDR (0x40020000)
#define RAM_CTRL_BASEADDR    (0x40020400)
#define DES_BASEADDR         (0x40020800)
#define CRC_BASEADDR         (0x40020900)
#define PORT_CTRL_BASEADDR   (0x40020C00)


//Defines the REG ADDR for UART0
		#define UART0__SBUF         *((volatile unsigned int  *)(UART0_BASEADDR+0x00))
		#define UART0__SCON         *((volatile unsigned int  *)(UART0_BASEADDR+0x04))
		#define UART0__SADDR        *((volatile unsigned int  *)(UART0_BASEADDR+0x08))
		#define UART0__SADEN        *((volatile unsigned int  *)(UART0_BASEADDR+0x0c))
		#define UART0__SFLAG        *((volatile unsigned int  *)(UART0_BASEADDR+0x10))
		#define UART0__SFCLR        *((volatile unsigned int  *)(UART0_BASEADDR+0x14))
			
//Defines the REG ADDR for UART1
		#define UART1__SBUF         *((volatile unsigned int  *)(UART1_BASEADDR+0x00))
		#define UART1__SCON         *((volatile unsigned int  *)(UART1_BASEADDR+0x04))
		#define UART1__SADDR        *((volatile unsigned int  *)(UART1_BASEADDR+0x08))
		#define UART1__SADEN        *((volatile unsigned int  *)(UART1_BASEADDR+0x0c))
		#define UART1__SFLAG        *((volatile unsigned int  *)(UART1_BASEADDR+0x10))
		#define UART1__SFCLR        *((volatile unsigned int  *)(UART1_BASEADDR+0x14))
			
//Defines the REG ADDR for UART2/LPUART
		#define UART2__SBUF         *((volatile unsigned int  *)(UART2_BASEADDR+0x00))
		#define UART2__SCON         *((volatile unsigned int  *)(UART2_BASEADDR+0x04))
		#define UART2__SADDR        *((volatile unsigned int  *)(UART2_BASEADDR+0x08))
		#define UART2__SADEN        *((volatile unsigned int  *)(UART2_BASEADDR+0x0c))
		#define UART2__ISR          *((volatile unsigned int  *)(UART2_BASEADDR+0x10))
		#define UART2__ICR          *((volatile unsigned int  *)(UART2_BASEADDR+0x14))
			
//Defines the REG ADDR for I2C (0x40000400)
		#define I2C__TMRUN          *((volatile unsigned int  *)(I2C_BASEADDR+0x00))
		#define I2C__TM             *((volatile unsigned int  *)(I2C_BASEADDR+0x04))
 		#define I2C__CR             *((volatile unsigned int  *)(I2C_BASEADDR+0x08))
  	    #define I2C__DATA           *((volatile unsigned int  *)(I2C_BASEADDR+0x0c))
 		#define I2C__ADDR           *((volatile unsigned int  *)(I2C_BASEADDR+0x10))
 		#define I2C__STAT           *((volatile unsigned int  *)(I2C_BASEADDR+0x14))			
		
//Defines the REG ADDR for SPI (0x40000800)
		#define SPI__CR             *((volatile unsigned int  *)(SPI_BASEADDR+0x00))
		#define SPI__SSN            *((volatile unsigned int  *)(SPI_BASEADDR+0x04))
		#define SPI__STAT           *((volatile unsigned int  *)(SPI_BASEADDR+0x08))
		#define SPI__DATA           *((volatile unsigned int  *)(SPI_BASEADDR+0x0c))
			
//Defines the REG ADDR for TIM0
		#define TIM0__ARR           *((volatile unsigned int  *)(BTIMER0_BASEADDR+0x00))
		#define TIM0__CNT           *((volatile unsigned int  *)(BTIMER0_BASEADDR+0x04))
		#define TIM0__CNT32         *((volatile unsigned int  *)(BTIMER0_BASEADDR+0x08))
		#define TIM0__CR            *((volatile unsigned int  *)(BTIMER0_BASEADDR+0x0C))			
		#define TIM0__IFR           *((volatile unsigned int  *)(BTIMER0_BASEADDR+0x10))			
		#define TIM0__ICLR          *((volatile unsigned int  *)(BTIMER0_BASEADDR+0x14))	

//DefineS the REG ADDR for TIM1			
		#define TIM1__ARR           *((volatile unsigned int  *)(BTIMER_BASEADDR+0x20))
		#define TIM1__CNT           *((volatile unsigned int  *)(BTIMER_BASEADDR+0x24))
		#define TIM1__CNT32         *((volatile unsigned int  *)(BTIMER_BASEADDR+0x28))
		#define TIM1__CR            *((volatile unsigned int  *)(BTIMER_BASEADDR+0x2C))			
		#define TIM1__IFR           *((volatile unsigned int  *)(BTIMER_BASEADDR+0x30))			
		#define TIM1__ICLR          *((volatile unsigned int  *)(BTIMER_BASEADDR+0x34))	
			
//Defines the REG ADDR for TIM2			
		#define TIM2__ARR           *((volatile unsigned int  *)(BTIMER_BASEADDR+0x40))
		#define TIM2__CNT           *((volatile unsigned int  *)(BTIMER_BASEADDR+0x44))
		#define TIM2__CNT32         *((volatile unsigned int  *)(BTIMER_BASEADDR+0x48))
		#define TIM2__CR            *((volatile unsigned int  *)(BTIMER_BASEADDR+0x4C))			
		#define TIM2__IFR           *((volatile unsigned int  *)(BTIMER_BASEADDR+0x50))			
		#define TIM2__ICLR          *((volatile unsigned int  *)(BTIMER_BASEADDR+0x54))		
		
//Defines the REG ADDR for LPTIM			
		#define LPTIM__CNT          *((volatile unsigned int  *)(BTIMER_BASEADDR+0x60))
		#define LPTIM__ARR          *((volatile unsigned int  *)(BTIMER_BASEADDR+0x64))
		//#define BTIMER__CNTX        *((volatile unsigned int  *)(BTIMER_BASEADDR+0x68))
		#define LPTIM__CR           *((volatile unsigned int  *)(BTIMER_BASEADDR+0x6C))			
		#define LPTIM__IFR          *((volatile unsigned int  *)(BTIMER_BASEADDR+0x70))			
		#define LPTIM__ICLR         *((volatile unsigned int  *)(BTIMER_BASEADDR+0x74))	
			
//Defines the REG ADDR for WDT
		#define WDT__RST            *((volatile unsigned int *)(BTIMER_BASEADDR+0x80))
		#define WDT__CON            *((volatile unsigned int *)(BTIMER_BASEADDR+0x84))

//Defines the REG ADDR for PCA (0x40001000)
		#define PCA__CCON           *((volatile unsigned int  *)(PCA_BASEADDR+0x00))
		#define PCA__CMOD           *((volatile unsigned int  *)(PCA_BASEADDR+0x04))
		#define PCA__CNT            *((volatile unsigned int  *)(PCA_BASEADDR+0x08))
		#define PCA__CL             *((volatile unsigned int  *)(PCA_BASEADDR+0x0C))
		#define PCA__CCAPM0         *((volatile unsigned int  *)(PCA_BASEADDR+0x10))
		#define PCA__CCAPM1         *((volatile unsigned int  *)(PCA_BASEADDR+0x14))
		#define PCA__CCAPM2         *((volatile unsigned int  *)(PCA_BASEADDR+0x18))
		#define PCA__CCAPM3         *((volatile unsigned int  *)(PCA_BASEADDR+0x1c))
		#define PCA__CCAPM4         *((volatile unsigned int  *)(PCA_BASEADDR+0x20))
		#define PCA__CCAP0H         *((volatile unsigned int  *)(PCA_BASEADDR+0x24))
		#define PCA__CCAP0L         *((volatile unsigned int  *)(PCA_BASEADDR+0x28))
		#define PCA__CCAP1H         *((volatile unsigned int  *)(PCA_BASEADDR+0x2c))
		#define PCA__CCAP1L         *((volatile unsigned int  *)(PCA_BASEADDR+0x30))
		#define PCA__CCAP2H         *((volatile unsigned int  *)(PCA_BASEADDR+0x34))
		#define PCA__CCAP2L         *((volatile unsigned int  *)(PCA_BASEADDR+0x38))
		#define PCA__CCAP3H         *((volatile unsigned int  *)(PCA_BASEADDR+0x3c))
		#define PCA__CCAP3L         *((volatile unsigned int  *)(PCA_BASEADDR+0x40))
		#define PCA__CCAP4H         *((volatile unsigned int  *)(PCA_BASEADDR+0x44))
		#define PCA__CCAP4L         *((volatile unsigned int  *)(PCA_BASEADDR+0x48))
		#define PCA__CCAPO          *((volatile unsigned int  *)(PCA_BASEADDR+0x4c))
		#define PCA__CCAP0          *((volatile unsigned int  *)(PCA_BASEADDR+0x50))
		#define PCA__CCAP1          *((volatile unsigned int  *)(PCA_BASEADDR+0x54))
		#define PCA__CCAP2          *((volatile unsigned int  *)(PCA_BASEADDR+0x58))
		#define PCA__CCAP3          *((volatile unsigned int  *)(PCA_BASEADDR+0x5c))
		#define PCA__CCAP4          *((volatile unsigned int  *)(PCA_BASEADDR+0x60))
		
//Defines the REG ADDR for RTC (0x40001400)
		#define RTC__CR0            *((volatile unsigned int  *)(RTC_BASEADDR+0x00))		
		#define RTC__CR1            *((volatile unsigned int  *)(RTC_BASEADDR+0x04))		
		#define RTC__SEC            *((volatile unsigned int  *)(RTC_BASEADDR+0x08))				
		#define RTC__MIN            *((volatile unsigned int  *)(RTC_BASEADDR+0x0C))
		#define RTC__HOUR           *((volatile unsigned int  *)(RTC_BASEADDR+0x10))
		#define RTC__WEEK           *((volatile unsigned int  *)(RTC_BASEADDR+0x14))
		#define RTC__DAY            *((volatile unsigned int  *)(RTC_BASEADDR+0x18))
		#define RTC__MON            *((volatile unsigned int  *)(RTC_BASEADDR+0x1C))
		#define RTC__YEAR           *((volatile unsigned int  *)(RTC_BASEADDR+0x20))
		#define RTC__ALMMIN         *((volatile unsigned int  *)(RTC_BASEADDR+0x24))
		#define RTC__ALMHOUR        *((volatile unsigned int  *)(RTC_BASEADDR+0x28))
		#define RTC__ALMWEEK        *((volatile unsigned int  *)(RTC_BASEADDR+0x2C))
		#define RTC__COMPEN         *((volatile unsigned int  *)(RTC_BASEADDR+0x30))
		
//Defines the REG ADDR FOR CLKTRIM (0x40001800)
		#define CLKTRIM__CR         *((volatile unsigned int  *)(CLK_TRIM_BASEADDR+0x00))		
		#define CLKTRIM__REFCON     *((volatile unsigned int  *)(CLK_TRIM_BASEADDR+0x04))		
		#define CLKTRIM__REFCNT     *((volatile unsigned int  *)(CLK_TRIM_BASEADDR+0x08))		
		#define CLKTRIM__CALCNT     *((volatile unsigned int  *)(CLK_TRIM_BASEADDR+0x0C))	
		#define CLKTRIM__IFR        *((volatile unsigned int  *)(CLK_TRIM_BASEADDR+0x10))		
		#define CLKTRIM__ICLR       *((volatile unsigned int  *)(CLK_TRIM_BASEADDR+0x14))		
		#define CLKTRIM__CALCON     *((volatile unsigned int  *)(CLK_TRIM_BASEADDR+0x18))			

//#define RNG_BASEADDR (0x40001C00)
		#define RNGCtrlReg          *((volatile unsigned int  *)(RNG_BASEADDR+0x00))
		#define RNGModeReg          *((volatile unsigned int  *)(RNG_BASEADDR+0x04))
		#define RNGSeqReg           *((volatile unsigned int  *)(RNG_BASEADDR+0x08))
		#define RNGData0Reg         *((volatile unsigned int  *)(RNG_BASEADDR+0x0c))
		#define RNGData1Reg         *((volatile unsigned int  *)(RNG_BASEADDR+0x10)) 
		
//#define SYSTEM_CTRL_BASEADDR (0x40002000)
		#define SYSTEM_CTRL__SYSCTRL0       *((volatile unsigned int  *)(SYSTEM_CTRL_BASEADDR+0x00))		
		#define SYSTEM_CTRL__SYSCTRL1       *((volatile unsigned int  *)(SYSTEM_CTRL_BASEADDR+0x04))		
		#define SYSTEM_CTRL__SYSCTRL2       *((volatile unsigned int  *)(SYSTEM_CTRL_BASEADDR+0x08))		
		#define SYSTEM_CTRL__RCH_CR         *((volatile unsigned int  *)(SYSTEM_CTRL_BASEADDR+0x0C))		
		#define SYSTEM_CTRL__XTH_CR         *((volatile unsigned int  *)(SYSTEM_CTRL_BASEADDR+0x10))		
		#define SYSTEM_CTRL__RCL_CR         *((volatile unsigned int  *)(SYSTEM_CTRL_BASEADDR+0x14))		
		#define SYSTEM_CTRL__XTL_CR         *((volatile unsigned int  *)(SYSTEM_CTRL_BASEADDR+0x18))		
		#define SYSTEM_CTRL__Reset_flag     *((volatile unsigned int  *)(SYSTEM_CTRL_BASEADDR+0x1C))		
		#define SYSTEM_CTRL__PERI_CLKEN     *((volatile unsigned int  *)(SYSTEM_CTRL_BASEADDR+0x20))		
		#define SYSTEM_CTRL__PREI_RESET     *((volatile unsigned int  *)(SYSTEM_CTRL_BASEADDR+0x28))		
		#define SYSTEM_CTRL__WAKEUP_DPSP    *((volatile unsigned int  *)(SYSTEM_CTRL_BASEADDR+0x30))		
		#define SYSTEM_CTRL__SYSTICK_CR     *((volatile unsigned int  *)(SYSTEM_CTRL_BASEADDR+0x34))		
		#define SYSTEM_CTRL__DEBUG_ACTIVE   *((volatile unsigned int  *)(SYSTEM_CTRL_BASEADDR+0x38))		
		#define SYSTEM_CTRL__LOCKSFR        *((volatile unsigned int  *)(SYSTEM_CTRL_BASEADDR+0x40))		
		#define SYSTEM_CTRL__BOOT0          *((volatile unsigned int  *)(SYSTEM_CTRL_BASEADDR+0x44))		
		#define SYSTEM_CTRL__BOOT1          *((volatile unsigned int  *)(SYSTEM_CTRL_BASEADDR+0x48))		
		#define SYSTEM_CTRL__REMAP          *((volatile unsigned int  *)(SYSTEM_CTRL_BASEADDR+0x4C))		
		#define SYSTEM_CTRL__SECURITY_BYTE  *((volatile unsigned int  *)(SYSTEM_CTRL_BASEADDR+0x50))		

//Defines the REG ADDR for ADC
		#define ADC__CR0                 *((volatile unsigned int  *)(ANALOGCTRL_BASEADDR+0x04))			
		#define ADC__CR1                 *((volatile unsigned int  *)(ANALOGCTRL_BASEADDR+0x08))	
		#define ADC__CR2                 *((volatile unsigned int  *)(ANALOGCTRL_BASEADDR+0x0c))
		#define ADC__result0             *((volatile unsigned int  *)(ANALOGCTRL_BASEADDR+0x30))
		#define ADC__result1             *((volatile unsigned int  *)(ANALOGCTRL_BASEADDR+0x34))
		#define ADC__result2             *((volatile unsigned int  *)(ANALOGCTRL_BASEADDR+0x38))		
		#define ADC__result3             *((volatile unsigned int  *)(ANALOGCTRL_BASEADDR+0x3c))		
		#define ADC__result4             *((volatile unsigned int  *)(ANALOGCTRL_BASEADDR+0x40))		
		#define ADC__result5             *((volatile unsigned int  *)(ANALOGCTRL_BASEADDR+0x44))	
		#define ADC__result6             *((volatile unsigned int  *)(ANALOGCTRL_BASEADDR+0x48))
		#define ADC__result7             *((volatile unsigned int  *)(ANALOGCTRL_BASEADDR+0x4c))	
		#define ADC__result8             *((volatile unsigned int  *)(ANALOGCTRL_BASEADDR+0x50))	
		#define ADC__result_acc          *((volatile unsigned int  *)(ANALOGCTRL_BASEADDR+0x54))			
		#define ADC__HT                  *((volatile unsigned int  *)(ANALOGCTRL_BASEADDR+0x58))	
		#define ADC__LT                  *((volatile unsigned int  *)(ANALOGCTRL_BASEADDR+0x5c))
		#define ADC__IFR                 *((volatile unsigned int  *)(ANALOGCTRL_BASEADDR+0x60))	
		#define ADC__ICLR                *((volatile unsigned int  *)(ANALOGCTRL_BASEADDR+0x64))
		#define ADC__result              *((volatile unsigned int  *)(ANALOGCTRL_BASEADDR+0x68))			
		#define ADC__CR3                 *((volatile unsigned int  *)(ANALOGCTRL_BASEADDR+0x70))

//Defines the REG ADDR for PMU
		#define PMU__CR                  *((volatile unsigned int  *)(ANALOGCTRL_BASEADDR+0x74))

//Defines the REG ADDR for BGR
		#define BGR__CR                  *((volatile unsigned int  *)(ANALOGCTRL_BASEADDR+0x00))
		#define BGR__option              *((volatile unsigned int  *)(ANALOGCTRL_BASEADDR+0x78))

//Defines the REG ADDR for VC
		#define VC__CR                   *((volatile unsigned int  *)(ANALOGCTRL_BASEADDR+0x10))
		#define VC__VC0_CR               *((volatile unsigned int  *)(ANALOGCTRL_BASEADDR+0x14))	
		#define VC__VC1_CR               *((volatile unsigned int  *)(ANALOGCTRL_BASEADDR+0x18))	
		#define VC__VC0_OUT_CFG          *((volatile unsigned int  *)(ANALOGCTRL_BASEADDR+0x1c))			
		#define VC__VC1_OUT_CFG          *((volatile unsigned int  *)(ANALOGCTRL_BASEADDR+0x20))
		#define VC__INT                  *((volatile unsigned int  *)(ANALOGCTRL_BASEADDR+0x24))	
		
//Defines the REG ADDR for LVD
		#define LVD__CR                  *((volatile unsigned int  *)(ANALOGCTRL_BASEADDR+0x28))
		#define LVD__IFR                 *((volatile unsigned int  *)(ANALOGCTRL_BASEADDR+0x2c))
		
	
//Defines the REG ADDR for TIM4 (0x40003000)	
		#define TIM4__CNTER 		     *((volatile unsigned int  *)(TIM4_BASEADDR+0x00))
		#define TIM4__PERAR 		     *((volatile unsigned int  *)(TIM4_BASEADDR+0x04))
		#define TIM4__PERBR 		     *((volatile unsigned int  *)(TIM4_BASEADDR+0x08))
		//#define PERCR 		         *((volatile unsigned int  *)(TIM4_BASEADDR+0x0C))
		#define TIM4__GCMAR 		     *((volatile unsigned int  *)(TIM4_BASEADDR+0x10))
		#define TIM4__GCMBR 		     *((volatile unsigned int  *)(TIM4_BASEADDR+0x14))
		#define TIM4__GCMCR 		     *((volatile unsigned int  *)(TIM4_BASEADDR+0x18))
		#define TIM4__GCMDR 		     *((volatile unsigned int  *)(TIM4_BASEADDR+0x1C))		
		#define TIM4__DTUAR 		     *((volatile unsigned int  *)(TIM4_BASEADDR+0x40))
		#define TIM4__DTDAR 		     *((volatile unsigned int  *)(TIM4_BASEADDR+0x44))
     
		#define TIM4__GCONR 		     *((volatile unsigned int  *)(TIM4_BASEADDR+0x50))	
		#define TIM4__ICONR 		     *((volatile unsigned int  *)(TIM4_BASEADDR+0x54))	
		#define TIM4__PCONR 		     *((volatile unsigned int  *)(TIM4_BASEADDR+0x58))	
		#define TIM4__BCONR 		     *((volatile unsigned int  *)(TIM4_BASEADDR+0x5C))					
		#define TIM4__DCONR 		     *((volatile unsigned int  *)(TIM4_BASEADDR+0x60))
		     
		#define TIM4__FCONR 		     *((volatile unsigned int  *)(TIM4_BASEADDR+0x68))		
		#define TIM4__VPERR 		     *((volatile unsigned int  *)(TIM4_BASEADDR+0x6C))
		#define TIM4__STFLR 		     *((volatile unsigned int  *)(TIM4_BASEADDR+0x70))
		#define TIM4__HSTAR 		     *((volatile unsigned int  *)(TIM4_BASEADDR+0x74))
		#define TIM4__HSTPR 		     *((volatile unsigned int  *)(TIM4_BASEADDR+0x78))
		#define TIM4__HCLRR 		     *((volatile unsigned int  *)(TIM4_BASEADDR+0x7C))
		#define TIM4__HCPAR 		     *((volatile unsigned int  *)(TIM4_BASEADDR+0x80))				
		#define TIM4__HCPBR 		     *((volatile unsigned int  *)(TIM4_BASEADDR+0x84))
		#define TIM4__HCUPR 		     *((volatile unsigned int  *)(TIM4_BASEADDR+0x88))
		#define TIM4__HCDOR 		     *((volatile unsigned int  *)(TIM4_BASEADDR+0x8C))
		//#define GPROR 		         *((volatile unsigned int  *)(TIM4_BASEADDR+0x90))

		#define TIM4__IFR 		         *((volatile unsigned int  *)(TIM4_BASEADDR+0x100))
		#define TIM4__ICLR 		         *((volatile unsigned int  *)(TIM4_BASEADDR+0x104))
		#define TIM4__CR 		         *((volatile unsigned int  *)(TIM4_BASEADDR+0x108))				
		#define TIM4__AOSSR 		     *((volatile unsigned int  *)(TIM4_BASEADDR+0x110))				
		#define TIM4__AOSCL 		     *((volatile unsigned int  *)(TIM4_BASEADDR+0x114))				
		#define TIM4__PTBKS 		     *((volatile unsigned int  *)(TIM4_BASEADDR+0x118))
		#define TIM4__TTRIG 		     *((volatile unsigned int  *)(TIM4_BASEADDR+0x11C))
		#define TIM4__ITRIG 		     *((volatile unsigned int  *)(TIM4_BASEADDR+0x120))
		#define TIM4__PTBKP 		     *((volatile unsigned int  *)(TIM4_BASEADDR+0x124))
	    
		#define TIM4__SSTAR 		     *((volatile unsigned int  *)(TIM4_BASEADDR+0x3F4))	
		#define TIM4__SSTPR 		     *((volatile unsigned int  *)(TIM4_BASEADDR+0x3F8))	
		#define TIM4__SCLRR 		     *((volatile unsigned int  *)(TIM4_BASEADDR+0x3FC))							
	
//Defines the REG ADDR for TIM5 (0x40003400)	
		#define TIM5__CNTER 		     *((volatile unsigned int  *)(TIM5_BASEADDR+0x00))
		#define TIM5__PERAR 		     *((volatile unsigned int  *)(TIM5_BASEADDR+0x04))
		#define TIM5__PERBR 		     *((volatile unsigned int  *)(TIM5_BASEADDR+0x08))
		//#define PERCR 		         *((volatile unsigned int  *)(TIM5_BASEADDR+0x0C))
		#define TIM5__GCMAR 		     *((volatile unsigned int  *)(TIM5_BASEADDR+0x10))
		#define TIM5__GCMBR 		     *((volatile unsigned int  *)(TIM5_BASEADDR+0x14))
		#define TIM5__GCMCR 		     *((volatile unsigned int  *)(TIM5_BASEADDR+0x18))
		#define TIM5__GCMDR 		     *((volatile unsigned int  *)(TIM5_BASEADDR+0x1C))		
		#define TIM5__DTUAR 		     *((volatile unsigned int  *)(TIM5_BASEADDR+0x40))
		#define TIM5__DTDAR 		     *((volatile unsigned int  *)(TIM5_BASEADDR+0x44))
     
		#define TIM5__GCONR 		     *((volatile unsigned int  *)(TIM5_BASEADDR+0x50))	
		#define TIM5__ICONR 		     *((volatile unsigned int  *)(TIM5_BASEADDR+0x54))	
		#define TIM5__PCONR 		     *((volatile unsigned int  *)(TIM5_BASEADDR+0x58))	
		#define TIM5__BCONR 		     *((volatile unsigned int  *)(TIM5_BASEADDR+0x5C))					
		#define TIM5__DCONR 		     *((volatile unsigned int  *)(TIM5_BASEADDR+0x60))
		     
		#define TIM5__FCONR 		     *((volatile unsigned int  *)(TIM5_BASEADDR+0x68))		
		#define TIM5__VPERR 		     *((volatile unsigned int  *)(TIM5_BASEADDR+0x6C))
		#define TIM5__STFLR 		     *((volatile unsigned int  *)(TIM5_BASEADDR+0x70))
		#define TIM5__HSTAR 		     *((volatile unsigned int  *)(TIM5_BASEADDR+0x74))
		#define TIM5__HSTPR 		     *((volatile unsigned int  *)(TIM5_BASEADDR+0x78))
		#define TIM5__HCLRR 		     *((volatile unsigned int  *)(TIM5_BASEADDR+0x7C))
		#define TIM5__HCPAR 		     *((volatile unsigned int  *)(TIM5_BASEADDR+0x80))				
		#define TIM5__HCPBR 		     *((volatile unsigned int  *)(TIM5_BASEADDR+0x84))
		#define TIM5__HCUPR 		     *((volatile unsigned int  *)(TIM5_BASEADDR+0x88))
		#define TIM5__HCDOR 		     *((volatile unsigned int  *)(TIM5_BASEADDR+0x8C))
		//#define GPROR 		         *((volatile unsigned int  *)(TIM5_BASEADDR+0x90))
		 
		#define TIM5__IFR 		         *((volatile unsigned int  *)(TIM5_BASEADDR+0x100))
		#define TIM5__ICLR 		         *((volatile unsigned int  *)(TIM5_BASEADDR+0x104))
		#define TIM5__CR 		         *((volatile unsigned int  *)(TIM5_BASEADDR+0x108))				
		#define TIM5__AOSSR 		     *((volatile unsigned int  *)(TIM5_BASEADDR+0x110))				
		#define TIM5__AOSCL 		     *((volatile unsigned int  *)(TIM5_BASEADDR+0x114))				
		#define TIM5__PTBKS 		     *((volatile unsigned int  *)(TIM5_BASEADDR+0x118))
		#define TIM5__TTRIG 		     *((volatile unsigned int  *)(TIM5_BASEADDR+0x11C))
		#define TIM5__ITRIG 		     *((volatile unsigned int  *)(TIM5_BASEADDR+0x120))
		#define TIM5__PTBKP 		     *((volatile unsigned int  *)(TIM5_BASEADDR+0x124))
	    
		#define TIM5__SSTAR 		     *((volatile unsigned int  *)(TIM5_BASEADDR+0x3F4))	
		#define TIM5__SSTPR 		     *((volatile unsigned int  *)(TIM5_BASEADDR+0x3F8))	
		#define TIM5__SCLRR 		     *((volatile unsigned int  *)(TIM5_BASEADDR+0x3FC))
							
//Defines the REG ADDR for TIM6 (0x40003800)			
		#define TIM6__CNTER 		     *((volatile unsigned int  *)(TIM6_BASEADDR+0x00))
		#define TIM6__PERAR 		     *((volatile unsigned int  *)(TIM6_BASEADDR+0x04))
		#define TIM6__PERBR 		     *((volatile unsigned int  *)(TIM6_BASEADDR+0x08))
		//#define PERCR 		         *((volatile unsigned int  *)(TIM6_BASEADDR+0x0C))
		#define TIM6__GCMAR 		     *((volatile unsigned int  *)(TIM6_BASEADDR+0x10))
		#define TIM6__GCMBR 		     *((volatile unsigned int  *)(TIM6_BASEADDR+0x14))
		#define TIM6__GCMCR 		     *((volatile unsigned int  *)(TIM6_BASEADDR+0x18))
		#define TIM6__GCMDR 		     *((volatile unsigned int  *)(TIM6_BASEADDR+0x1C))		
		#define TIM6__DTUAR 		     *((volatile unsigned int  *)(TIM6_BASEADDR+0x40))
		#define TIM6__DTDAR 		     *((volatile unsigned int  *)(TIM6_BASEADDR+0x44))
     
		#define TIM6__GCONR 		     *((volatile unsigned int  *)(TIM6_BASEADDR+0x50))	
		#define TIM6__ICONR 		     *((volatile unsigned int  *)(TIM6_BASEADDR+0x54))	
		#define TIM6__PCONR 		     *((volatile unsigned int  *)(TIM6_BASEADDR+0x58))	
		#define TIM6__BCONR 		     *((volatile unsigned int  *)(TIM6_BASEADDR+0x5C))					
		#define TIM6__DCONR 		     *((volatile unsigned int  *)(TIM6_BASEADDR+0x60))
		     
		#define TIM6__FCONR 		     *((volatile unsigned int  *)(TIM6_BASEADDR+0x68))		
		#define TIM6__VPERR 		     *((volatile unsigned int  *)(TIM6_BASEADDR+0x6C))
		#define TIM6__STFLR 		     *((volatile unsigned int  *)(TIM6_BASEADDR+0x70))
		#define TIM6__HSTAR 		     *((volatile unsigned int  *)(TIM6_BASEADDR+0x74))
		#define TIM6__HSTPR 		     *((volatile unsigned int  *)(TIM6_BASEADDR+0x78))
		#define TIM6__HCLRR 		     *((volatile unsigned int  *)(TIM6_BASEADDR+0x7C))
		#define TIM6__HCPAR 		     *((volatile unsigned int  *)(TIM6_BASEADDR+0x80))				
		#define TIM6__HCPBR 		     *((volatile unsigned int  *)(TIM6_BASEADDR+0x84))
		#define TIM6__HCUPR 		     *((volatile unsigned int  *)(TIM6_BASEADDR+0x88))
		#define TIM6__HCDOR 		     *((volatile unsigned int  *)(TIM6_BASEADDR+0x8C))
		//#define GPROR 		         *((volatile unsigned int  *)(TIM6_BASEADDR+0x90))
		 
		#define TIM6__IFR 		         *((volatile unsigned int  *)(TIM6_BASEADDR+0x100))
		#define TIM6__ICLR 		         *((volatile unsigned int  *)(TIM6_BASEADDR+0x104))
		#define TIM6__CR 		         *((volatile unsigned int  *)(TIM6_BASEADDR+0x108))				
		#define TIM6__AOSSR 		     *((volatile unsigned int  *)(TIM6_BASEADDR+0x110))				
		#define TIM6__AOSCL 		     *((volatile unsigned int  *)(TIM6_BASEADDR+0x114))				
		#define TIM6__PTBKS 		     *((volatile unsigned int  *)(TIM6_BASEADDR+0x118))
		#define TIM6__TTRIG 		     *((volatile unsigned int  *)(TIM6_BASEADDR+0x11C))
		#define TIM6__ITRIG 		     *((volatile unsigned int  *)(TIM6_BASEADDR+0x120))
		#define TIM6__PTBKP 		     *((volatile unsigned int  *)(TIM6_BASEADDR+0x124))
	    
		#define TIM6__SSTAR 		     *((volatile unsigned int  *)(TIM6_BASEADDR+0x3F4))	
		#define TIM6__SSTPR 		     *((volatile unsigned int  *)(TIM6_BASEADDR+0x3F8))	
		#define TIM6__SCLRR 		     *((volatile unsigned int  *)(TIM6_BASEADDR+0x3FC))

//#define GPIO_BASEADDR (0x40001600)
//		#define GPIO0_DIR         *((volatile unsigned int  *)(GPIO_BASEADDR+0x00))
//		#define GPIO0_REG         *((volatile unsigned int  *)(GPIO_BASEADDR+0x04))
//		#define GPIO0             *((volatile unsigned int  *)(GPIO_BASEADDR+0x08))

//Defines the REG ADDR for FLASH  (0x40020000)
		#define FLASH__TNVS              *((volatile unsigned int  *)(EFLASH_CTRL_BASEADDR+0x00))
		#define FLASH__TPGS              *((volatile unsigned int  *)(EFLASH_CTRL_BASEADDR+0x04))
		#define FLASH__TPROG             *((volatile unsigned int  *)(EFLASH_CTRL_BASEADDR+0x08))
		#define FLASH__TSERASE           *((volatile unsigned int  *)(EFLASH_CTRL_BASEADDR+0x0c))
		#define FLASH__TMERASE           *((volatile unsigned int  *)(EFLASH_CTRL_BASEADDR+0x10))
		#define FLASH__TPRCV             *((volatile unsigned int  *)(EFLASH_CTRL_BASEADDR+0x14))
		#define FLASH__TSRCV             *((volatile unsigned int  *)(EFLASH_CTRL_BASEADDR+0x18))
		#define FLASH__TMRCV             *((volatile unsigned int  *)(EFLASH_CTRL_BASEADDR+0x1c))			
		#define FLASH__CR                *((volatile unsigned int  *)(EFLASH_CTRL_BASEADDR+0x20))
		#define FLASH__IFR               *((volatile unsigned int  *)(EFLASH_CTRL_BASEADDR+0x24))	
        #define FLASH__ICLR              *((volatile unsigned int  *)(EFLASH_CTRL_BASEADDR+0x28))	
		#define FLASH__BYPASS            *((volatile unsigned int  *)(EFLASH_CTRL_BASEADDR+0x2C))
		#define FLASH__SLOCK             *((volatile unsigned int  *)(EFLASH_CTRL_BASEADDR+0x30))
/*
		#define INFO__PL            *((volatile unsigned int  *)(EFLASH_CTRL_BASEADDR+0x34))
		#define FLASH__FCLR         *((volatile unsigned int  *)(EFLASH_CTRL_BASEADDR+0x38))
			  
		#define FLASH_TRIM0         *((volatile unsigned int  *)(EFLASH_CTRL_BASEADDR+0x200))
		#define FLASH_TRIM1         *((volatile unsigned int  *)(EFLASH_CTRL_BASEADDR+0x204))
		#define FLASH_TRIM2         *((volatile unsigned int  *)(EFLASH_CTRL_BASEADDR+0x208))
		#define FLASH_TRIM3         *((volatile unsigned int  *)(EFLASH_CTRL_BASEADDR+0x20c))
		#define FLASH_TRIM4         *((volatile unsigned int  *)(EFLASH_CTRL_BASEADDR+0x210))
		#define FLASH_TRIM5         *((volatile unsigned int  *)(EFLASH_CTRL_BASEADDR+0x214))
		#define FLASH_TRIM6         *((volatile unsigned int  *)(EFLASH_CTRL_BASEADDR+0x218))
		#define FLASH_TRIM7         *((volatile unsigned int  *)(EFLASH_CTRL_BASEADDR+0x21c))
		#define FLASH_TRIM8         *((volatile unsigned int  *)(EFLASH_CTRL_BASEADDR+0x220))
		#define FLASH_TRIM9         *((volatile unsigned int  *)(EFLASH_CTRL_BASEADDR+0x224))
		#define FLASH_TRIM10        *((volatile unsigned int  *)(EFLASH_CTRL_BASEADDR+0x228))
		#define FLASH_TRIM11        *((volatile unsigned int  *)(EFLASH_CTRL_BASEADDR+0x22c))
*/
//Defines the REG ADDR for RAM (0x40020400)
		#define RAM__CR                  *((volatile unsigned int  *)(RAM_CTRL_BASEADDR+0x00))
		#define RAM__ERRADDR             *((volatile unsigned int  *)(RAM_CTRL_BASEADDR+0x04))
		#define RAM__IFR                 *((volatile unsigned int  *)(RAM_CTRL_BASEADDR+0x08))
		#define RAM__ICLR                *((volatile unsigned int  *)(RAM_CTRL_BASEADDR+0x0C))
			
//#define DES_BASEADDR (0x40020800)
		#define CNTRL_REG                *((volatile unsigned int  *)(DES_BASEADDR+0x00))
    	#define RAND_REG0                *((volatile unsigned int  *)(DES_BASEADDR+0x10))
    	#define RAND_REG1                *((volatile unsigned int  *)(DES_BASEADDR+0x14))
    	#define IV_REG0                  *((volatile unsigned int  *)(DES_BASEADDR+0x18))
    	#define IV_REG1                  *((volatile unsigned int  *)(DES_BASEADDR+0x1c))
    	#define DATA_REG0                *((volatile unsigned int  *)(DES_BASEADDR+0x20))
    	#define DATA_REG1                *((volatile unsigned int  *)(DES_BASEADDR+0x24))
    	#define KEY1_REG0                *((volatile unsigned int  *)(DES_BASEADDR+0x28))
    	#define KEY1_REG1                *((volatile unsigned int  *)(DES_BASEADDR+0x2c))
    	#define KEY2_REG0                *((volatile unsigned int  *)(DES_BASEADDR+0x30))
    	#define KEY2_REG1                *((volatile unsigned int  *)(DES_BASEADDR+0x34))
    	#define KEY3_REG0                *((volatile unsigned int  *)(DES_BASEADDR+0x38))
    	#define KEY3_REG1                *((volatile unsigned int  *)(DES_BASEADDR+0x3c))
    
//Defines the REG ADDR for CRC  
		#define CRC__RESULT              *((volatile unsigned int  *)(CRC_BASEADDR+0x04))
		#define CRC__DATA                *((volatile unsigned int  *)(CRC_BASEADDR+0x80))


//Defiens the REG ADDR for GPIO (0x40020C00)
		#define GPIO__P01_SEL            *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x04))
		#define GPIO__P02_SEL            *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x08))
		#define GPIO__P03_SEL            *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x0C))
		#define GPIO__P14_SEL            *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x50))
		#define GPIO__P15_SEL            *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x54))
		#define GPIO__P23_SEL            *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x8C))
		#define GPIO__P24_SEL            *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x90))
		#define GPIO__P25_SEL            *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x94))
		#define GPIO__P26_SEL            *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x98))
		#define GPIO__P27_SEL            *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x9C))
		#define GPIO__P31_SEL            *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0xC4))
		#define GPIO__P32_SEL            *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0xC8))
		#define GPIO__P33_SEL            *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0xCC))
		#define GPIO__P34_SEL            *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0xD0))
		#define GPIO__P35_SEL            *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0xD4))
		#define GPIO__P36_SEL            *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0xD8))
		#define GPIO__P0DIR              *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x100))
		#define GPIO__P0IN               *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x104))
		#define GPIO__P0OUT              *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x108))
		#define GPIO__P0ADS              *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x10C))
	    //#define GPIO__P0_CS              *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x110))
	    //#define GPIO__P0_SR              *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x118))
		#define GPIO__P0DR               *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x11C))
		#define GPIO__P0PU               *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x120))
		#define GPIO__P0PD               *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x124))
		//#define GPIO__P0OS              *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x128))
		#define GPIO__P0OD               *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x12C))
		#define GPIO__P0INTEN0           *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x130))
		#define GPIO__P0INTEN1           *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x134))
		#define GPIO__P0INTEN2           *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x138))
		#define GPIO__P0INTEN3           *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x13C))
		#define GPIO__P0_STAT            *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x200))
		#define GPIO__P0_ICLR            *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x210))
		#define GPIO__P1DIR              *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x140))
		#define GPIO__P1IN               *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x144))
		#define GPIO__P1OUT              *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x148))
		#define GPIO__P1ADS              *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x14C))
		//#define GPIO__P1CS              *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x150))
		//#define GPIO__P1SR              *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x158))
		#define GPIO__P1DR               *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x15C))
		#define GPIO__P1PU               *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x160))
		#define GPIO__P1PD               *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x164))
		//#define GPIO__P1_OS              *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x168))
		#define GPIO__P1OD               *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x16C))
		#define GPIO__P1INTEN0           *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x170))
		#define GPIO__P1INTEN1           *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x174))
		#define GPIO__P1INTEN2           *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x178))
		#define GPIO__P1INTEN3           *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x17C))
		#define GPIO__P1_STAT            *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x240))
		#define GPIO__P1_ICLR            *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x250))
		#define GPIO__P2DIR              *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x180))
		#define GPIO__P2IN               *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x184))
		#define GPIO__P2OUT              *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x188))
		#define GPIO__P2ADS              *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x18C))
		//#define GPIO__P2_CS              *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x190))
		//#define GPIO__P2_SR              *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x198))
		#define GPIO__P2_DR              *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x19C))
		#define GPIO__P2_PU              *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x1A0))
		#define GPIO__P2_PD              *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x1A4))
		//#define GPIO__P2_OS              *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x1A8))
		#define GPIO__P2_OD              *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x1AC))
		#define GPIO__P2INTEN0           *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x1B0))
		#define GPIO__P2INTEN1           *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x1B4))
		#define GPIO__P2INTEN2           *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x1B8))
		#define GPIO__P2INTEN3           *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x1BC))
		#define GPIO__P2_STAT            *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x280))
		#define GPIO__P2_ICLR            *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x290))
		#define GPIO__P3DIR              *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x1C0))
		#define GPIO__P3IN               *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x1C4))
		#define GPIO__P3OUT              *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x1C8))
		#define GPIO__P3ADS              *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x1CC))
		//#define GPIO__P3_CS              *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x1D0))
		//#define GPIO__P3_SR              *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x1D8))
		#define GPIO__P3DR               *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x1DC))
		#define GPIO__P3PU               *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x1E0))
		#define GPIO__P3PD               *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x1E4))
		//#define GPIO__P3OS               *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x1E8))
		#define GPIO__P3OD               *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x1EC))
		#define GPIO__P3INTEN0           *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x1F0))
		#define GPIO__P3INTEN1           *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x1F4))
		#define GPIO__P3INTEN2           *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x1F8))
		#define GPIO__P3INTEN3           *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x1FC))
		#define GPIO__P3_STAT            *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x2C0))
		#define GPIO__P3_ICLR            *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x2D0))
		#define GPIO__GPIO_CTRL0         *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x300))
		#define GPIO__GPIO_CTRL1         *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x304))
		#define GPIO__GPIO_CTRL2         *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x308))
		#define GPIO__GPIO_CTRL3         *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x30C))
		#define GPIO__GPIO_CTRL4         *((volatile unsigned int  *)(PORT_CTRL_BASEADDR+0x310))
		  
#define PPB_BASEADDR      (0xe000e000)  
    	#define NVIC_ISER                *((volatile unsigned int  *)(PPB_BASEADDR+0x100)) 	
    	#define NVIC_ICER                *((volatile unsigned int  *)(PPB_BASEADDR+0x180))	
			   
    	#define SLEEPDEEP                *((volatile unsigned int  *)(PPB_BASEADDR+0xd10)) 
/*
#define NVIC_BASEADDR      (0xe000e000)
    #define NVIC_ISER           *((volatile unsigned int *)(NVIC_BASEADDR+0x100)) 	
    #define NVIC_ICER           *((volatile unsigned int *)(NVIC_BASEADDR+0x180))	
*/			

/*  **********   UART struct    **********  */
typedef struct 
{
	__IO uint32_t SBUF     : 8;
	__IO uint32_t RERSEVED : 24;
}uart_sbuf_field_t;

typedef struct
{
  __IO uint32_t RIEN      : 1; 
  __IO uint32_t TIEN      : 1;	
  __IO uint32_t RB8       : 1;
  __IO uint32_t TB8       : 1;
  __IO uint32_t REN       : 1;
  __IO uint32_t SM2       : 1;
  __IO uint32_t SM01      : 2;
  __IO uint32_t RERSEVED  : 1;
  __IO uint32_t DBAUD     : 1;
  __IO uint32_t RERSEVED1 : 22;       
}uart_scon_field_t; 

typedef struct
{
	__IO uint32_t RIEN    : 1;
	__IO uint32_t TIEN    : 1;
	__IO uint32_t RB8     : 1;
	__IO uint32_t TB8	  : 1;
	__IO uint32_t REN     : 1;
	__IO uint32_t SM2     : 1;
	__IO uint32_t SM01    : 2;
	__IO uint32_t TEEM    : 1;
	__IO uint32_t DBAUD   : 1;
	__IO uint32_t LPMODE  : 1;
	__IO uint32_t SCLKSEL : 2;
	__IO uint32_t PRS     : 3;
	__IO uint32_t RERSEVED : 16;
}lpuart_scon_field_t;

typedef struct
{
	__IO uint32_t SADDR    : 8;
	__IO uint32_t RESERVED : 24;
}uart_saddr_field_t;

typedef struct
{
	__IO uint32_t SADEN     : 8;
	__IO uint32_t RERSEVED  : 24;
}uart_saden_field_t;

typedef struct
{
	__IO uint32_t RI        : 1;
	__IO uint32_t TI        : 1;
	__IO uint32_t FE        : 1;
	__IO uint32_t TE        : 1;
	__IO uint32_t RERSEVED  : 28;
}uart_isr_field_t;

typedef struct
{
	__IO uint32_t RI_CLR        : 1;
	__IO uint32_t TI_CLR        : 1;
	__IO uint32_t FE_CLR        : 1;
	__IO uint32_t RERSEVED      : 29;
}uart_icr_field_t;

typedef struct
{
  union {
  	  __IO  uint32_t SBUF;	
  	  uart_sbuf_field_t SBUF_f;
  };
	
  union {
      __IO  uint32_t SCON;
      uart_scon_field_t SCON_f;
      lpuart_scon_field_t LP_SCON_f;
  };
  
  union {
  	  __IO  uint32_t SADDR;
  	  uart_saddr_field_t SADDR_f;
  };

  union {
  	  __IO  uint32_t SADEN;  
  	  uart_saden_field_t SADEN_f;
  };

  union {
      __IO  uint32_t ISR;
      uart_isr_field_t ISR_f;
  };  
  
  union {
      __IO  uint32_t ICR;
      uart_icr_field_t ICR_f;
  }; 
}UART_REG_TypeDef;

#define L005_UART0           ((UART_REG_TypeDef *)UART0_BASEADDR)
#define L005_UART1           ((UART_REG_TypeDef *)UART1_BASEADDR)
#define L005_UART2           ((UART_REG_TypeDef *)UART2_BASEADDR)


/*  **********   I2C struct    **********  */
	
typedef struct
{
	__IO uint32_t tme	    	    : 1;
	__IO uint32_t RERSEVED	        : 30;	
}i2c_tmr_field_t;

typedef struct
{
	__IO uint32_t tm                : 8;
	__IO uint32_t RERSEVED	        : 24;	
}i2c_tm_field_t;

typedef struct
{
	__IO uint32_t h1m               : 1;
	__IO uint32_t RERSEVED0	        : 1;
	__IO uint32_t aa 				: 1;
	__IO uint32_t si				: 1;
	__IO uint32_t sto				: 1;
	__IO uint32_t sta				: 1;
	__IO uint32_t ens    			: 1;
	__IO uint32_t RERSEVED1	        : 25;
}i2ccon_field_t;

typedef struct 
{
	__IO uint32_t i2cdat            : 8;
	__IO uint32_t RESERVED          : 24;
}i2cdata_field_t;

typedef struct
{
	__IO uint32_t GC				: 1;
	__IO uint32_t i2cadr            : 7;
	__IO uint32_t RERSEVED	        : 24;	
}i2cadr_field_t;

typedef struct
{
	__IO uint32_t i2csta  			: 8;
	__IO uint32_t RERSEVED			: 24;	
}i2cstat_field_t;

typedef struct
{
  union {
	  __IO  uint32_t TMRUN;
	  i2c_tmr_field_t TMRUN_f;
  };
	
  union {
      __IO  uint32_t TM;
      i2c_tm_field_t TM_f;
  };
	
  union {
      __IO  uint32_t CR;
      i2ccon_field_t CR_f;
  };
  
  union {
  	  __IO uint32_t DATA;
  	  i2cdata_field_t DATA_f;
  };
	
  union {
      __IO  uint32_t ADDR;
	  i2cadr_field_t ADDR_f;
  };
	
  union {
      __IO  uint32_t STAT;
      i2cstat_field_t STAT_f;
  };
	
}I2C_REG_TypeDef;	
	
#define L005_I2C            	((I2C_REG_TypeDef *)I2C_BASEADDR)	


/*  **********   SPI struct    **********  */

typedef struct
{
	__IO uint32_t spr0      : 1;
	__IO uint32_t spr1      : 1;	
	__IO uint32_t cpha      : 1;
	__IO uint32_t cpol      : 1;
	__IO uint32_t mstr      : 1;
	__IO uint32_t RERSEVED  : 1;
	__IO uint32_t spen      : 1;
	__IO uint32_t spr2      : 1;
	__IO uint32_t RERSEVED1 : 24;	
}spi_cr_field_t;

typedef struct 
{
	__IO uint32_t ssn       : 1;
	__IO uint32_t RESERVED  : 31;
}spi_ssn_field_t;

typedef struct
{
	__IO uint32_t RERSEVED  : 4;
	__IO uint32_t mdf       : 1;	
	__IO uint32_t sserr     : 1;
	__IO uint32_t wcol      : 1;
	__IO uint32_t spif      : 1;
	__IO uint32_t RERSEVED1 : 24;	
}spi_spsta_field_t;

typedef struct
{
	__IO uint32_t spdat     : 8;
	__IO uint32_t RESERVED  : 24;
}spi_data_field_t;

typedef struct
{
  union {
      __IO  uint32_t CR;
      spi_cr_field_t CR_f;
  };
  
  union {
  	  __IO uint32_t SSN;
  	  spi_ssn_field_t SSN_f;
  };

  union {
      __IO  uint32_t STAT;
      spi_spsta_field_t STAT_f;
  };
  
  union {
  	  __IO  uint32_t DATA;
  	  spi_data_field_t DATA_f;
  };

}SPI_REG_TypeDef;	

#define L005_SPI             ((SPI_REG_TypeDef *)SPI_BASEADDR)	       

/*  **********   BTIMER struct    **********  */

typedef struct
{
	__IO uint32_t ARR      : 16;
	__IO uint32_t RERSEVED : 16;
}btimer_arr_field_t;

typedef struct
{
	__IO uint32_t CNT      : 16;
	__IO uint32_t RERSEVED : 16;
}btimer_cnt_field_t;

typedef struct
{
	__IO uint32_t TR       : 1;	
	__IO uint32_t MD       : 1;	
	__IO uint32_t CT       : 1;	
	__IO uint32_t TOG_EN   : 1;	
	__IO uint32_t PRS      : 3;	
	__IO uint32_t RESERVED : 1;	
	__IO uint32_t GATE     : 1;	
	__IO uint32_t GATE_P   : 1;	
	__IO uint32_t IE       : 1;	
	__IO uint32_t RERSEVED1 : 21;	
	
}btimer_cr_field_t;	

typedef struct
{
	__IO uint32_t TR        : 1;
	__IO uint32_t MD        : 1;
	__IO uint32_t CT        : 1;
	__IO uint32_t TOG_EN    : 1;
	__IO uint32_t TCK_SEL   : 2;
	__IO uint32_t RERSEVED  : 1;
	__IO uint32_t WT_FLAG   : 1;
	__IO uint32_t GATE      : 1;
	__IO uint32_t GATE_P    : 1;
	__IO uint32_t IE        : 1;
	__IO uint32_t RERSEVED1 : 21;
}btimerlp_cr_field_t;

typedef struct
{
	__IO uint32_t TF       : 1;	
	__IO uint32_t RERSEVED : 31;	
	
}btimer_ifr_field_t;


typedef struct
{
	__IO uint32_t TFC       : 1;	
	__IO uint32_t RESERVED  : 31;	
	
}btimer_iclr_field_t;	


typedef struct
{
	union {
		__IO uint32_t ARR;
		btimer_arr_field_t ARR_f;
	};
	union {
		__IO uint32_t CNT;
		btimer_cnt_field_t CNT_f;
	};
	__IO uint32_t CNT32;
	union {
		__IO uint32_t CR;
		btimer_cr_field_t CR_f;
	};
    union {
	    __IO uint32_t IFR;
	    btimer_ifr_field_t IFR_f;
    };
    union {  
	    __IO uint32_t ICLR;
	    btimer_iclr_field_t ICLR_f;
    };
 
}BTIMER_REG_TypeDef;

typedef struct
{
	union {
    	__IO uint32_t CNT;
		btimer_cnt_field_t CNT_f;
	};
	union {
		__IO uint32_t ARR;
		btimer_arr_field_t ARR_f;
	};
	__IO uint32_t RERSEVED;
    union {
  	    __IO uint32_t CR;
  	    btimerlp_cr_field_t CR_f;
    };
    union {
    	__IO uint32_t IFR;
    	btimer_ifr_field_t IFR_f;
    };
    union {
    	__IO uint32_t ICLR;
    	btimer_iclr_field_t ICLR_f;
    };
 
}BTIMERLP_REG_TypeDef;

	 
#define L005_TIM0         ((BTIMER_REG_TypeDef *)BTIMER0_BASEADDR)	 
#define L005_TIM1         ((BTIMER_REG_TypeDef *)BTIMER1_BASEADDR)	 
#define L005_TIM2         ((BTIMER_REG_TypeDef *)BTIMER2_BASEADDR)	 
#define L005_LPTIM        ((BTIMERLP_REG_TypeDef *)BTIMERLP_BASEADDR)	 
 

/*  **********   WDT struct    **********  */

typedef struct
{
	__IO uint32_t WOV       : 4;
	__IO uint32_t WDTR      : 1;
	__IO uint32_t WINT_EN   : 1;
	__IO uint32_t RERSEVED	: 1;
	__IO uint32_t WDINT     : 1;
	__IO uint32_t WCNTL     : 8;
	__IO uint32_t RERSEVED1 : 16;
}wdtcon_field_t;	

typedef struct
{
	__IO uint32_t RST;
    union {
        __IO uint32_t CON;
        wdtcon_field_t CON_f;
    };
}WDT_REG_TypeDef;

#define L005_WDT             ((WDT_REG_TypeDef *)BTIMERWDT_BASEADDR)	
 

/*  **********   PCA struct    **********  */

typedef struct
{
	__IO uint32_t CCF0      : 1;
	__IO uint32_t CCF1      : 1;	
	__IO uint32_t CCF2      : 1;
	__IO uint32_t CCF3      : 1;
	__IO uint32_t CCF4      : 1;
	__IO uint32_t RERSEVED  : 1;
	__IO uint32_t CR        : 1;
	__IO uint32_t CF        : 1;
	__IO uint32_t RERSEVED1 : 24;	
}pca_ccon_field_t;	

typedef struct
{
	__IO uint32_t CCF0      : 1;
	__IO uint32_t CCF1      : 1;	
	__IO uint32_t CCF2      : 1;
	__IO uint32_t CCF3      : 1;
	__IO uint32_t CCF4      : 1;
	__IO uint32_t RERSEVED  : 2;
	__IO uint32_t CF        : 1;
	__IO uint32_t RERSEVED1 : 24;	
}pca_intcl_field_t;	

typedef struct
{
	__IO uint32_t CFIE      : 1;
	__IO uint32_t CPS       : 3;	
	__IO uint32_t RERSEVED0 : 2;
	
	__IO uint32_t WDTE      : 1;
	__IO uint32_t CIDL      : 1;
	__IO uint32_t RERSEVED1 : 24;	
}pca_cmod_field_t;

typedef struct
{
	__IO uint32_t CNT       : 16;
	__IO uint32_t RERSEVED  : 16;
}pca_cnt_field_t;

typedef struct
{
	__IO uint32_t CCIE     : 1;
	__IO uint32_t PWM      : 1;	
	__IO uint32_t TOG      : 1;
	__IO uint32_t MAT      : 1;
	__IO uint32_t CAPN     : 1;
	__IO uint32_t CAPP     : 1;
	__IO uint32_t ECOM     : 1;
	__IO uint32_t RERSEVED : 25;	
}pca_ccapm_field_t;

typedef struct
{
	union{
		__IO uint32_t CCON;
		pca_ccon_field_t CCON_f;
	};
	union{
		__IO uint32_t CMOD;
		pca_cmod_field_t CMOD_f;
	};
	union{
		__IO uint32_t CNT;
		pca_cnt_field_t CNT_f;
	};
	union{
		__IO uint32_t INT_CL;
		pca_intcl_field_t INT_CL_f;
    };
	union{
		__IO uint32_t CCAPM0;
		pca_ccapm_field_t CCAPM0_f;
	};
	union{
		__IO uint32_t CCAPM1;
		pca_ccapm_field_t CCAPM1_f;
	};
	union{
		__IO uint32_t CCAPM2;
		pca_ccapm_field_t CCAPM2_f;
	};
	union{
		__IO uint32_t CCAPM3;
		pca_ccapm_field_t CCAPM3_f;
	};
	union{
		__IO uint32_t CCAPM4;
		pca_ccapm_field_t CCAPM4_f;
	};
	__IO uint32_t CCAP0H;
	__IO uint32_t CCAP0L;
	__IO uint32_t CCAP1H;
	__IO uint32_t CCAP1L;
	__IO uint32_t CCAP2H;
	__IO uint32_t CCAP2L;
	__IO uint32_t CCAP3H;
	__IO uint32_t CCAP3L;
	__IO uint32_t CCAP4H;
	__IO uint32_t CCAP4L;
	__IO uint32_t CCAPO;
	__IO uint32_t CCAP0;
	__IO uint32_t CCAP1;
	__IO uint32_t CCAP2;
	__IO uint32_t CCAP3;
	__IO uint32_t CCAP4;
}PCA_REG_TypeDef;

#define L005_PCA             ((PCA_REG_TypeDef *)PCA_BASEADDR)

/*  **********   RTC struct    **********  */

typedef struct
{
	__IO uint32_t PRDS			: 3;
	__IO uint32_t AMPM			: 1;
	__IO uint32_t RESERVED	    : 1;
	__IO uint32_t HZ1OE	    	: 1;
	__IO uint32_t HZ1SEL	    : 1;
	__IO uint32_t START			: 1;
	__IO uint32_t PRDX          : 6;
	__IO uint32_t PRDSEL        : 1;
	__IO uint32_t RERSEVED1     : 17;
}rtc_cr0_field_t;

typedef struct
{
	__IO uint32_t WAIT			  : 1;
	__IO uint32_t WAITF           :	1;
	__IO uint32_t RESERVED	      : 1;
	__IO uint32_t PRDF			  :	1;
	__IO uint32_t ALMF			  :	1;
	__IO uint32_t RERSEVED1       : 1;
	__IO uint32_t ALMIE 		  :	1;
	__IO uint32_t ALMEN			  : 1;
	__IO uint32_t CKSEL			  : 3;
	__IO uint32_t RERSEVED2       : 21;
}rtc_cr1_field_t;

typedef struct
{
	__IO uint32_t SECL	   : 4;
	__IO uint32_t SECH	   : 3;
	__IO uint32_t RESERVED : 25;

}rtc_sec_field_t;

typedef struct
{
	__IO uint32_t MINL	   : 4;
	__IO uint32_t MINH 	   : 3;
	__IO uint32_t RESERVED : 25;
}rtc_min_field_t;

typedef struct
{
	__IO uint32_t HOURL	   : 4;
	__IO uint32_t HOURH	   : 2;
	__IO uint32_t RESERVED : 26;
}rtc_hour_field_t;

typedef struct
{
	__IO uint32_t DAYL	   : 4;
	__IO uint32_t DAYH	   : 2;
	__IO uint32_t RESERVED : 26;
}rtc_day_field_t;

typedef struct
{
	__IO uint32_t WEEK     : 3;
	__IO uint32_t RESERVED : 29;
}rtc_week_field_t;

typedef struct
{
	__IO uint32_t MON	    : 5;
	__IO uint32_t RESERVED	: 27;
}rtc_mon_field_t;

typedef struct
{
	__IO uint32_t YEARL	   : 4;
	__IO uint32_t YEARH	   : 4;
	__IO uint32_t RESERVED : 24;
}rtc_year_field_t;

typedef struct
{
	__IO uint32_t ALMMINL	: 4;
	__IO uint32_t ALMMINH	: 3;
	__IO uint32_t RESERVED  : 25; 
}rtc_almmin_field_t;

typedef struct
{
	__IO uint32_t ALMHOURL	: 4;
	__IO uint32_t ALMHOURH	: 2;
	__IO uint32_t RESERVED  : 26;
}rtc_almhour_field_t;

typedef struct  
{
	__IO uint32_t ALMWEEK   : 7;
	__IO uint32_t RERSEVED  : 25;
}rtc_almweek_field_t;

typedef struct
{
	__IO uint32_t CR		: 9;
	__IO uint32_t RESERVED	: 6;
	__IO uint32_t EN		: 1;
	__IO uint32_t RERSEVED1 : 16;
}rtc_compen_field_t;

typedef struct
{
	union {
		__IO uint32_t CR0;
		rtc_cr0_field_t CR0_f;
	};
	
	union {
		__IO uint32_t CR1;
		rtc_cr1_field_t	CR1_f;
	};
	
	union {
		__IO uint32_t SEC;
		rtc_sec_field_t SEC_f;
	};
	
	union {
		__IO uint32_t MIN;
		rtc_min_field_t	MIN_f;
	};
	
	union {
		__IO uint32_t HOUR;
		rtc_hour_field_t HOUR_f;
	};
	
	union {
		__IO uint32_t WEEK;
		rtc_week_field_t WEEK_f;
	};
	
	union {
		__IO uint32_t DAY;
		rtc_day_field_t DAY_f;
	};
	
	union {
		__IO uint32_t MON;
		rtc_mon_field_t MON_f;
	};

	union {
		__IO uint32_t YEAR;
		rtc_year_field_t YEAR_f;
	};
	
	union {
		__IO uint32_t ALMMIN;
		rtc_almmin_field_t ALMMIN_f;
	};
	
	union {
		__IO uint32_t ALMHOUR;
		rtc_almhour_field_t ALMHOUR_f;
	};
	
	union {
		__IO uint32_t ALMWEEK;
		rtc_almweek_field_t ALMWEEK_f;
	};
	
	union {
		__IO uint32_t COMPEN;
		rtc_compen_field_t COMPEN_f;
	};
}RTC_REG_TypeDef;

#define L005_RTC				 			((RTC_REG_TypeDef *)RTC_BASEADDR)


/*  **********   CLK_TRIM struct    **********  */

typedef struct
{
  __IO uint32_t trim_star      : 1;
  __IO uint32_t refclk_sel     : 3;   
  __IO uint32_t calclk_sel     : 2;   
  __IO uint32_t mon_en         : 1;
  __IO uint32_t IE             : 1;
  __IO uint32_t RERSEVED       : 24;         
}clk_trim_trimcon_field_t; 

typedef struct
{
  __IO uint32_t stop           : 1;         
  __IO uint32_t calcnt_of      : 1;         
  __IO uint32_t xtal32k_fault  : 1;   
  __IO uint32_t xtal32m_fault  : 1;   
  __IO uint32_t RERSEVED       : 28;         
}clk_trim_trimflg_field_t; 

typedef struct
{
  __IO uint32_t stop_clr           : 1;         
  __IO uint32_t calcnt_off_clr     : 1;   
  __IO uint32_t xtal32k_fault_clr  : 1;   
  __IO uint32_t xtal32m_fault_clr  : 1;
  __IO uint32_t RERSEVED           : 28;         
}clk_trim_trimclr_field_t; 

typedef struct
{
  union {
      __IO  uint32_t CR;
      clk_trim_trimcon_field_t CR_f;
  };

  __IO  uint32_t REFCON;
  __IO  uint32_t REFCNT;
  __IO  uint32_t CALCNT;  
  
  union {
	  __IO  uint32_t IFR;
      clk_trim_trimflg_field_t IFR_f;
  };
  
  union {
	  __IO  uint32_t ICLR;
      clk_trim_trimclr_field_t ICLR_f;
  };
  __IO  uint32_t CALCON;
}CLK_TRIM_REG_TypeDef;

#define L005_CLKTRIM     ((CLK_TRIM_REG_TypeDef *)CLK_TRIM_BASEADDR)


/*  **********   SYS_CTRL struct    **********  */

typedef struct
{
	__IO uint32_t RCH_EN       		: 1;
	__IO uint32_t XTH_EN           	: 1;
	__IO uint32_t RCL_EN       		: 1;
	__IO uint32_t XTL_EN         	: 1;	
	__IO uint32_t Clk_sw4_sel       : 2;		
	__IO uint32_t HCLK_PRS          : 3;		
	__IO uint32_t PCLK_PRS          : 2;		
	__IO uint32_t RERSEVED          : 4;	
	__IO uint32_t wakeup_byRCH   	: 1;	
	__IO uint32_t RERSEVED1         : 16;	
}sysctrl0_field_t;

typedef struct
{
	__IO uint32_t RERSEVED0             : 1;	
	__IO uint32_t EXTH_EN 	            : 1;	
	__IO uint32_t EXTL_EN 	            : 1;	
	__IO uint32_t XTL_ALWAYS_ON 	    : 1;	
	__IO uint32_t CLOCK_FAULT_EN        : 1;	
	__IO uint32_t RTC_LPW               : 1;	
	__IO uint32_t LOCKUP_EN             : 1;	
	__IO uint32_t RESET_USE_IO          : 1;	
	__IO uint32_t SWD_USE_IO            : 1;	
	__IO uint32_t RTC_FREQ_ADJUST       : 3;	
	__IO uint32_t FLASH_PARA_AUTOADJUST : 1;	
	__IO uint32_t RERSEVED1             : 19;	
}sysctrl1_field_t;

//typedef struct
//{
//	__IO uint32_t LOCK               : 1;
//	__IO uint32_t RERSEVED           : 31;	
//}sysctrl2_field_t;

typedef struct
{
	__IO uint32_t TRIM           : 9;
	__IO uint32_t FSEL           : 2;
	__IO uint32_t stable         : 1;	
	__IO uint32_t RERSEVED       : 20;		
}RCH_CR_field_t;

typedef struct
{
	__IO uint32_t Driver         : 4;
	__IO uint32_t Startup        : 2;	
	__IO uint32_t stable         : 1;	
	__IO uint32_t RERSEVED       : 25;		
}XTH_CR_field_t;

typedef struct
{
	__IO uint32_t TRIM           : 9;
	__IO uint32_t FSEL           : 1;
	__IO uint32_t Startup        : 2;	
	__IO uint32_t stable         : 1;	
	__IO uint32_t RERSEVED       : 19;		
}RCL_CR_field_t;

typedef struct
{
	__IO uint32_t Driver         : 4;
	__IO uint32_t Startup        : 2;	
	__IO uint32_t stable         : 1;	
	__IO uint32_t RERSEVED       : 25;		
}XTL_CR_field_t;

typedef struct
{
	__IO uint32_t POR5V              : 1;
	__IO uint32_t POR15V             : 1;
	__IO uint32_t LVD            : 1;
	__IO uint32_t WDT            : 1;
	__IO uint32_t PCA            : 1;
	__IO uint32_t Lockup         : 1;
	__IO uint32_t Sysreq         : 1;
	__IO uint32_t RSTB               : 1;
//	__IO uint32_t fLASH_OVERFLOW     : 1;
//	__IO uint32_t RERSEVED           : 23;		
	__IO uint32_t RERSEVED           : 24;		
}Reset_flag_field_t;

typedef struct
{
  __IO uint32_t UART0              : 1;   
  __IO uint32_t UART1              : 1;   
  __IO uint32_t LPUART             : 1;   
  __IO uint32_t RERSEVED0          : 1;   
  __IO uint32_t I2C                : 1;   
  __IO uint32_t RERSEVED1          : 1;   
  __IO uint32_t SPI                : 1;   
  __IO uint32_t RERSEVED2          : 1;   
  __IO uint32_t BASETIM            : 1;   
  __IO uint32_t LPTIM              : 1;   
  __IO uint32_t ADVTIM             : 1;   
  __IO uint32_t RERSEVED3          : 3;   
  __IO uint32_t PCA                : 1;   
  __IO uint32_t WDT                : 1;   
  __IO uint32_t ADC                : 1;   
  __IO uint32_t VC                 : 1;   
  __IO uint32_t RERSEVED4          : 2;   
  __IO uint32_t RTC                : 1;   
  __IO uint32_t clk_trim           : 1;  
  __IO uint32_t RERSEVED5          : 2;   
  //__IO uint32_t BOOT               : 1;  
  __IO uint32_t SYSTICK            : 1;  
  __IO uint32_t SWD                : 1;  
  __IO uint32_t CRC                : 1;  
  __IO uint32_t RERSEVED6          : 1;   
  __IO uint32_t GPIO               : 1;  
  __IO uint32_t RERSEVED7          : 2;   
  //__IO uint32_t RAM                : 1;  
  __IO uint32_t FLASH              : 1;  
}PERI_CLKEN_field_t;     

typedef struct
{
  __IO uint32_t UART0              : 1;   
  __IO uint32_t UART1              : 1;   
  __IO uint32_t LPUART             : 1;   
  __IO uint32_t RERSEVED0          : 1;   
  __IO uint32_t I2C                : 1;   
  __IO uint32_t RERSEVED1          : 1;   
  __IO uint32_t SPI                : 1;   
  __IO uint32_t RERSEVED2          : 1;   
  __IO uint32_t BASETIM            : 1;   
  __IO uint32_t LPTIM              : 1;   
  __IO uint32_t ADVTIM             : 1;   
  __IO uint32_t RERSEVED3          : 3;   
  __IO uint32_t PCA                : 1;   
  __IO uint32_t WDT                : 1;   
  __IO uint32_t ADC                : 1;   
  __IO uint32_t VC                 : 1;   
  __IO uint32_t RERSEVED4          : 2;   
  __IO uint32_t RTC                : 1;   
  __IO uint32_t Trim               : 1;  
  __IO uint32_t RERSEVED5          : 2;   
  //__IO uint32_t RERSEVED8          : 1;   
  __IO uint32_t SYSTICK            : 1;  
  __IO uint32_t SWD                : 1;  
  __IO uint32_t CRC                : 1;  
  __IO uint32_t RERSEVED6          : 1;   
  __IO uint32_t GPIO               : 1;  
  __IO uint32_t RERSEVED7          : 2;   
  //__IO uint32_t RAM                : 1;  
  __IO uint32_t FLASH              : 1;  
}PREI_RESET_field_t;

typedef struct
{
  __IO uint32_t STCALIB             : 24;   
  __IO uint32_t SKEW                : 1;  
  __IO uint32_t NOREF               : 1;  
  __IO uint32_t CLK_SEL             : 2;  
  __IO uint32_t RERSEVED            : 4;		
}SYSTICK_CR_field_t;

typedef struct
{
  __IO uint32_t P0                  : 1;   
  __IO uint32_t P1                  : 1;   
  __IO uint32_t P2                  : 1;   
  __IO uint32_t P3                  : 1;   
  __IO uint32_t LPUART              : 1;   
  __IO uint32_t LPTIM               : 1;   
  __IO uint32_t WDT                 : 1;   
  __IO uint32_t RTC                 : 1;   
  __IO uint32_t VC0                 : 1;   
  __IO uint32_t VC1                 : 1;   
  __IO uint32_t LVD                 : 1;  
  __IO uint32_t CLK_FAULT           : 1;  
  __IO uint32_t Wakep_dpsp_mode     : 1;   
  __IO uint32_t RERSEVED            : 19;		
}wakeup_dpsp_field_t;

typedef struct
{
  __IO uint32_t TIM0                : 1;   
  __IO uint32_t TIM1                : 1;   
  __IO uint32_t TIM2                : 1;   
  __IO uint32_t LPTIM               : 1;   
  __IO uint32_t TIM4                : 1;   
  __IO uint32_t TIM5                : 1;   
  __IO uint32_t TIM6                : 1;   
  __IO uint32_t PCA                 : 1;   
  __IO uint32_t WDT                 : 1;   
  __IO uint32_t RTC                 : 1;   
//  __IO uint32_t CLK_TRIM            : 1;   
  __IO uint32_t TICK                : 1;   
  __IO uint32_t RERSEVED            : 21;  
}debug_active_field_t;

typedef struct
{
  __IO uint32_t RCH_stable_sel       : 3;   
  __IO uint32_t auto_switch_lpm      : 1;  
  __IO uint32_t CFG_RAM              : 2;  
  __IO uint32_t CFG_flash            : 2;  
  __IO uint32_t swd_enable           : 1;  
  __IO uint32_t RTC_XTL_enable       : 1;  
  __IO uint32_t debug_en             : 1;  
  __IO uint32_t fix_resetpad         : 1;  
  __IO uint32_t Test_adc             : 1;  
  __IO uint32_t XTL_STARTUP_EN       : 1;  
  __IO uint32_t XTH_STARTUP_EN       : 1;    
  __IO uint32_t RERSEVED0            : 17;		
}boot0_field_t;

typedef struct
{
  __IO uint32_t XTL_TEST            : 6;   
  __IO uint32_t XTH_TEST            : 6;  
  __IO uint32_t RCL                 : 2;  
  __IO uint32_t RCH_TEST            : 2;  
  __IO uint32_t RCH_ITC             : 4;  
  __IO uint32_t RCH_ns_enb          : 1;  
  __IO uint32_t XTH_ns_enb          : 1;  
  __IO uint32_t RCL_ns_enb          : 1;  
  __IO uint32_t XTL_ns_enb          : 1;  
  __IO uint32_t RERSEVED            : 8;		
}boot1_field_t;

typedef struct
{
  __IO uint32_t Security            : 8;   
  __IO uint32_t RERSEVED            : 24;		
}security_byte_field_t;

typedef struct 
{
	union {
		__IO uint32_t SYSCTRL0;
		sysctrl0_field_t SYSCTRL0_f;
	};
	union {
		__IO uint32_t SYSCTRL1;
		sysctrl1_field_t SYSCTRL1_f;
	};
	__IO uint32_t SYSCTRL2;
	union {
		__IO uint32_t RCH_CR;
		RCH_CR_field_t RCH_CR_f;
	};
	union {
		__IO uint32_t XTH_CR;
		XTH_CR_field_t XTH_CR_f;
	};	
	union {
		__IO uint32_t RCL_CR;
		RCL_CR_field_t RCL_CR_f;
	};
	union {
		__IO uint32_t XTL_CR;
		XTL_CR_field_t XTL_CR_f;
	};
	union {
		__IO uint32_t Reset_flag;
		Reset_flag_field_t Reset_flag_f;
	};
	union {
		__IO uint32_t PERI_CLKEN;
		PERI_CLKEN_field_t PERI_CLKEN_f;
	};	
	__IO uint32_t RESERVED0;
	union {
		__IO uint32_t PREI_RESET;
    PREI_RESET_field_t PREI_RESET_f;
	};	
	__IO uint32_t RESERVED1;
	union {
		__IO uint32_t WAKEUP_DPSP;
    wakeup_dpsp_field_t WAKEUP_DPSP_f;
	};	
	union {
		__IO uint32_t SYSTICK_CR;
    SYSTICK_CR_field_t SYSTICK_CR_f;
	};	
	union {
		__IO uint32_t DEBUG_ACTIVE;
    debug_active_field_t DEBUG_ACTIVE_f;
	};	
	__IO uint32_t RESERVED2;
	__IO uint32_t LOCKSFR;
	union {
		__IO uint32_t BOOT0;
		boot0_field_t BOOT0_f;
	};
	union {
		__IO uint32_t BOOT1;
		boot1_field_t BOOT1_f;
	};
	__IO uint32_t REMAP;
	union {
		__IO uint32_t SECURITY_BYTE;
		security_byte_field_t SECURITY_BYTE_f;
	};
}SYSTEM_CTRL_REG_TypeDef;

//#define SYSTEM_CTRL_BASEADDR (0x40002000) 
#define L005_SystemCtrl		((SYSTEM_CTRL_REG_TypeDef *)SYSTEM_CTRL_BASEADDR)


/*  ***********   PMU struct  ***********  */

typedef struct{
	__IO uint32_t TRIM_V1P5   : 7;
	__IO uint32_t BIAS_SEL    : 6;	
	__IO uint32_t RERSEVED    : 19;
}pmu_field_t;

typedef struct
{
	union {
		__IO uint32_t PMU;
		pmu_field_t PMU_f;
	};	
}PMU_REG_TypeDef;

#define L005_PMU                ((PMU_REG_TypeDef *)(ANALOGCTRL_BASEADDR+0x74))


/*  ***********   BGR struct  ***********  */

typedef struct{
	__IO uint32_t BGR_EN      : 1;
	__IO uint32_t TS_EN       : 1;	
	__IO uint32_t RERSEVED    : 30;
}bgr_cr_field_t;

typedef struct{
	__IO uint32_t BGR_TRIM    : 6;
	__IO uint32_t BGR_TEST    : 1;	
	__IO uint32_t RERSEVED    : 25;
}bgr_option_field_t;

typedef struct
{
	union {
		__IO uint32_t CR;
		bgr_cr_field_t CR_f;
	};

	__IO uint32_t RESERVED[29];

	union {
		__IO uint32_t option;
		bgr_option_field_t option_f;
	};
	
}BGR_REG_TypeDef;

#define L005_BGR                ((BGR_REG_TypeDef *)ANALOGCTRL_BASEADDR)


/*  ***********   LVD struct  ***********  */
typedef struct{	
	__IO uint32_t LVDEN                    : 1;			
	__IO uint32_t Sel_rst                  : 1;		
	__IO uint32_t Source_sel               : 2;		
	__IO uint32_t LEVEL                    : 4;	
	__IO uint32_t FLTEN                    : 1;		
	__IO uint32_t Debounce_time            : 3;		
	__IO uint32_t Falling                  : 1;		
	__IO uint32_t Rising                   : 1;		
	__IO uint32_t Level                    : 1;		
	__IO uint32_t IE                       : 1;
	__IO uint32_t RERSEVED                 : 16;
}lvd_cr_field_t;

typedef struct{
	__IO uint32_t INTF                     : 1;		
	__IO uint32_t RERSEVED                 : 31;	
}lvd_ifr_field_t;

typedef struct
{
	union {
		__IO uint32_t CR;
		lvd_cr_field_t CR_f;
	};	
	
	union {
		__IO uint32_t IFR;
		lvd_ifr_field_t IFR_f;
	};	
}LVD_REG_TypeDef;

#define L005_LVD                ((LVD_REG_TypeDef *)(ANALOGCTRL_BASEADDR+0x28))


/*  ***********   VC struct   ***********  */
typedef struct{	
	__IO uint32_t VC_DIV                   : 6;		
	__IO uint32_t VC_DIV_EN                : 1;
	__IO uint32_t VC_REF2P5_SEL            : 1;
	__IO uint32_t VC0_BIAS_SEL             : 2;
	__IO uint32_t VC0_HYS_SEL              : 2;
	__IO uint32_t VC1_BIAS_SEL             : 2;
	__IO uint32_t VC1_HYS_SEL              : 2;	
	__IO uint32_t RERSEVED                 : 16;
}vc_cr_field_t;

typedef struct{	
	__IO uint32_t EN                       : 1;		
	__IO uint32_t p_sel                    : 3;
	__IO uint32_t n_sel                    : 4;
	__IO uint32_t FLTEN                    : 1;	
	__IO uint32_t debounce_time            : 3;		
	__IO uint32_t falling                  : 1;
	__IO uint32_t rising                   : 1;
	__IO uint32_t level                    : 1;
	__IO uint32_t IE                       : 1;		
	__IO uint32_t RERSEVED                 : 16;
}vc0_cr_field_t;

typedef struct{	
	__IO uint32_t EN                       : 1;		
	__IO uint32_t p_sel                    : 3;
	__IO uint32_t n_sel                    : 4;
	__IO uint32_t FLTEN                    : 1;	
	__IO uint32_t debounce_time            : 3;	
	__IO uint32_t falling                  : 1;
	__IO uint32_t rising                   : 1;
	__IO uint32_t level                    : 1;	
	__IO uint32_t IE                       : 1;		
	__IO uint32_t RERSEVED                 : 16;
}vc1_cr_field_t;

typedef struct{	
	__IO uint32_t INV_Timer                : 1;		
	__IO uint32_t TM0G                     : 1;	
	__IO uint32_t TM1G                     : 1;		
	__IO uint32_t TM2G                     : 1;		
	__IO uint32_t TM3G                     : 1;	
	__IO uint32_t TM3ECLK                  : 1;		
	__IO uint32_t INV_PCA                  : 1;		
	__IO uint32_t PCACAP0                  : 1;		
	__IO uint32_t PCAECI                   : 1;		
	__IO uint32_t Inv_TIM4                 : 1;	
	__IO uint32_t TIM4                     : 1;		
	__IO uint32_t Inv_TIM5                 : 1;	
	__IO uint32_t TIM5                     : 1;	
	__IO uint32_t inv_TIM6                 : 1;	
	__IO uint32_t TIM6                     : 1;		
	__IO uint32_t brake                    : 1;	
	__IO uint32_t RERSEVED                 : 16;
}vc0_out_cfg_field_t;

typedef struct{	
	__IO uint32_t INV_Timer                : 1;		
	__IO uint32_t TM0G                     : 1;	
	__IO uint32_t TM1G                     : 1;		
	__IO uint32_t TM2G                     : 1;		
	__IO uint32_t TM3G                     : 1;	
	__IO uint32_t TM3ECLK                  : 1;		
	__IO uint32_t INV_PCA                  : 1;		
	__IO uint32_t PCACAP0                  : 1;		
	__IO uint32_t PCAECI                   : 1;		
	__IO uint32_t Inv_TIM4                 : 1;	
	__IO uint32_t TIM4                     : 1;		
	__IO uint32_t Inv_TIM5                 : 1;	
	__IO uint32_t TIM5                     : 1;	
	__IO uint32_t inv_TIM6                 : 1;	
	__IO uint32_t TIM6                     : 1;		
	__IO uint32_t brake                    : 1;	
	__IO uint32_t RERSEVED                 : 16;
}vc1_out_cfg_field_t;

typedef struct{
	__IO uint32_t VC0_INTF                 : 1;
	__IO uint32_t VC1_INTF                 : 1;		
	__IO uint32_t VC0_filter               : 1;		
	__IO uint32_t VC1_filter               : 1;	
	__IO uint32_t RERSEVED                 : 28;
}vc_int_field_t;

typedef struct
{
	union {
		__IO uint32_t CR;
		vc_cr_field_t CR_f;
	};

	union {
		__IO uint32_t VC0_CR;
		vc0_cr_field_t VC0_CR_f;
	};

	union {
		__IO uint32_t VC1_CR;
		vc1_cr_field_t VC1_CR_f;
	};
	
	union {
		__IO uint32_t VC0_OUT_CFG;
		vc0_out_cfg_field_t VC0_OUT_CFG_f;
	};	
	
	union {
		__IO uint32_t VC1_OUT_CFG;
		vc1_out_cfg_field_t VC1_OUT_CFG_f;
	};	

	union {
		__IO uint32_t INT;
		vc_int_field_t INT_f;
	};		
}VC_REG_TypeDef;

#define L005_VC                 ((VC_REG_TypeDef *)(ANALOGCTRL_BASEADDR+0X10))



/*  ***********   ADC struct  ***********  */
typedef struct{
	__IO uint32_t ADCEN         : 1;		
	__IO uint32_t START         : 1;		
	__IO uint32_t CLKSEL        : 2;		
	__IO uint32_t SEL           : 4;		
	__IO uint32_t SREF          : 2;		
	__IO uint32_t BUFEN         : 1;	
	__IO uint32_t SAM           : 2;
	__IO uint32_t RERSEVED      : 1;
	__IO uint32_t IE            : 1;	
	__IO uint32_t RERSEVED1     : 17;
}adccr0_field_t;

typedef struct{
	__IO uint32_t TRIGS0                  : 5;		
	__IO uint32_t TRIGS1                  : 5;		
	__IO uint32_t CT                      : 1;		
	__IO uint32_t RACC_EN                 : 1;		
	__IO uint32_t LLT_IE                  : 1;		
	__IO uint32_t HHT_IE                  : 1;
	__IO uint32_t REG_IE                  : 1;	
	__IO uint32_t RACC_CLR                : 1;
	__IO uint32_t RERSEVED                : 16;
}adccr1_field_t;

typedef struct{	
	__IO uint32_t CH0EN                    : 1;		
	__IO uint32_t CH1EN                    : 1;
	__IO uint32_t CH2EN                    : 1;
	__IO uint32_t CH3EN                    : 1;
	__IO uint32_t CH4EN                    : 1;
	__IO uint32_t CH5EN                    : 1;
	__IO uint32_t CH6EN                    : 1;
	__IO uint32_t CH7EN                    : 1;
	__IO uint32_t ADCCNT                   : 8;		
	__IO uint32_t RERSEVED                 : 16;
}adccr2_field_t;

typedef struct{
	__IO uint32_t LLT_INTF                 : 1;
	__IO uint32_t HHT_INTF                 : 1;	
	__IO uint32_t REG_INTF                 : 1;	
	__IO uint32_t CONT_INTF                : 1;	
	__IO uint32_t RERSEVED                 : 28;
}adc_int_field_t;

typedef struct{
	__IO uint32_t LLT_INTC                 : 1;
	__IO uint32_t HHT_INTC                 : 1;	
	__IO uint32_t REG_INTC                 : 1;	
	__IO uint32_t CONT_INTC                : 1;	
	__IO uint32_t RERSEVED                 : 28;
}adc_int_clr_field_t;

typedef struct{	
	__IO uint32_t ADC_OPT2P5               : 4;		
	__IO uint32_t ADC_OPT1P5               : 4;
	__IO uint32_t ADC_CLK_Delay            : 3;
	__IO uint32_t VCM_S                    : 2;
	__IO uint32_t PRE_S                    : 2;
	__IO uint32_t Vreftrim                 : 1;	
	__IO uint32_t ADC_CLK_SEL_EXT          : 1;
	__IO uint32_t ADC_CLK_S                : 1;
	__IO uint32_t ADC_CLK_TEST             : 1;
	__IO uint32_t RERSEVED                 : 13;
}adccr3_field_t;

typedef struct
{
	__IO uint32_t RERSEVED;
	
	union {
		__IO uint32_t CR0;
		adccr0_field_t CR0_f;
	};		
	
	union {
		__IO uint32_t CR1;
		adccr1_field_t CR1_f;
	};		
	
	union {
		__IO uint32_t CR2;
		adccr2_field_t CR2_f;
	};	

	__IO uint32_t RERSEVED1[8];
	__IO uint32_t result0;
	__IO uint32_t result1;
	__IO uint32_t result2;
	__IO uint32_t result3;
	__IO uint32_t result4;
	__IO uint32_t result5;
	__IO uint32_t result6;
	__IO uint32_t result7;
	__IO uint32_t result8;
	__IO uint32_t result_acc;
	__IO uint32_t HT;
	__IO uint32_t LT;	
	
	union {
		__IO uint32_t IFR;
		adc_int_field_t IFR_f;
	};	

	union {
		__IO uint32_t ICLR;
		adc_int_clr_field_t ICLR_f;
	};	

	__IO uint32_t result;
	__IO uint32_t RESERVED2;

	union {
		__IO uint32_t CR3;
		adccr3_field_t CR3_f;
	};	

}ADC_REG_TypeDef;


#define L005_ADC                ((ADC_REG_TypeDef *)ANALOGCTRL_BASEADDR)

/*  **********   TIMER6 struct    **********  */

typedef struct
{
	__IO uint32_t START      : 1;
	__IO uint32_t MODE       : 3;
	__IO uint32_t CKDIV      : 3;
	__IO uint32_t RERSEVED   : 1;	
	__IO uint32_t DIR        : 1;
	__IO uint32_t RERSEVED1  : 7;	
	__IO uint32_t ZMSKREV    : 1; 
	__IO uint32_t ZMSKPOS    : 1; 
	__IO uint32_t ZMSK       : 2; 
	__IO uint32_t RERSEVED3  : 12; 	

}tim6_gconr_field_t;	

typedef struct
{
	__IO uint32_t INTENA      : 1;
	__IO uint32_t INTENB      : 1;
	__IO uint32_t INTENC      : 1;
	__IO uint32_t INTEND      : 1;
	__IO uint32_t RERSEVED    : 2;	
	__IO uint32_t INTENOVF    : 1;//add @1207
	__IO uint32_t INTENUDF    : 1;//add @1207
	__IO uint32_t INTENDE     : 1;
	__IO uint32_t RERSEVED1   : 23;	
}tim6_iconr_field_t;	
typedef struct
{
	__IO uint32_t CAPCA      : 1;
	__IO uint32_t STACA      : 1;
	__IO uint32_t STPCA      : 1;
	__IO uint32_t STASTPSA   : 1;
	__IO uint32_t CMPCA      : 2;
	__IO uint32_t PERCA      : 2;
	__IO uint32_t OUTENA     : 1;
	__IO uint32_t DISSELA    : 2;
	__IO uint32_t DISVALA    : 2;
	__IO uint32_t RERSEVED   : 3;
	__IO uint32_t CAPCB      : 1;
	__IO uint32_t STACB      : 1;
	__IO uint32_t STPCB      : 1;
	__IO uint32_t STASTPSB   : 1;
	__IO uint32_t CMPCB      : 2;
	__IO uint32_t PERCB      : 2;
	__IO uint32_t OUTENB     : 1;
	__IO uint32_t DISSELB    : 2;
	__IO uint32_t DISVALB    : 2;
	__IO uint32_t RERSEVED1  : 3;
}tim6_pconr_field_t;	
typedef struct
{
	__IO uint32_t BENA      : 1;
	__IO uint32_t RERSEVED1 : 1;
	__IO uint32_t BENB      : 1;
	__IO uint32_t RERSEVED2 : 5;
	__IO uint32_t BENP      : 1;
	__IO uint32_t RERSEVED3 : 23;	
}tim6_bconr_field_t;	
typedef struct
{
	__IO uint32_t DTCEN      : 1;
	__IO uint32_t RERSEVED   : 7;		//add @1207
	__IO uint32_t SEPA       : 1;	
	__IO uint32_t RERSEVED1  : 23;	
}tim6_dconr_field_t;	
typedef struct
{
	__IO uint32_t RERSEVED1  : 32;	
}tim6_cconr_field_t;	
typedef struct
{
	__IO uint32_t NOFIENGA   : 1;	//add @1207..
	__IO uint32_t NOFICKGA   : 2;
	__IO uint32_t RERSEVED1  : 1;

	__IO uint32_t NOFIENGB   : 1;	//add @1207..
	__IO uint32_t NOFICKGB   : 2;

	__IO uint32_t RERSEVED2  : 9;	

	__IO uint32_t NOFIENTA   : 1;	//add @1207..
	__IO uint32_t NOFICKTA   : 2;
	__IO uint32_t RERSEVED3  : 1;	
	__IO uint32_t NOFIENTB   : 1;	//add @1207..
	__IO uint32_t NOFICKTB   : 2;
	__IO uint32_t RERSEVED4  : 1;	

	__IO uint32_t NOFIENTC   : 1;	//add @1207..
	__IO uint32_t NOFICKTC   : 2;
	__IO uint32_t RERSEVED5  : 1;	
	__IO uint32_t NOFIENTD   : 1;	//add @1207..
	__IO uint32_t NOFICKTD   : 2;
	__IO uint32_t RERSEVED6  : 1;		
	
}tim6_fconr_field_t;	
typedef struct
{
	__IO uint32_t GEPERIA   : 1;
	__IO uint32_t GEPERIB   : 1;	
	__IO uint32_t GEPERIC   : 1;
	__IO uint32_t GEPERID   : 1;
	__IO uint32_t RERSEVED  : 12;
	__IO uint32_t PCNTE     : 2;
	__IO uint32_t PCNTS     : 3;
	__IO uint32_t RERSEVED2 : 11;
}tim6_vperr_field_t;	
typedef struct
{
	__IO uint32_t CMAF       : 1;
	__IO uint32_t CMBF       : 1;
	__IO uint32_t CMCF       : 1;
	__IO uint32_t CMDF       : 1;
	__IO uint32_t RERSEVED   : 2;	
	__IO uint32_t OVFF       : 1;
	__IO uint32_t UDFF       : 1;
	__IO uint32_t DTEF       : 1;
	__IO uint32_t RERSEVED1  : 12;		
	__IO uint32_t VPERNUM    : 3;	//ADD @1207
	__IO uint32_t RERSEVED2  : 7;		
	__IO uint32_t DIRF       : 1;	
}tim6_stflr_field_t;	
typedef struct
{
	__IO uint32_t HSTA0      : 1;
	__IO uint32_t HSTA1      : 1;
	__IO uint32_t HSTA2      : 1;
	__IO uint32_t HSTA3      : 1;
	__IO uint32_t HSTA4      : 1;
	__IO uint32_t HSTA5      : 1;
	__IO uint32_t HSTA6      : 1;
	__IO uint32_t HSTA7      : 1;
	__IO uint32_t HSTA8      : 1;
	__IO uint32_t HSTA9      : 1;
	__IO uint32_t HSTA10     : 1;
	__IO uint32_t HSTA11     : 1;
	__IO uint32_t HSTA12     : 1;
	__IO uint32_t HSTA13     : 1;
	__IO uint32_t HSTA14     : 1;
	__IO uint32_t HSTA15     : 1;
	__IO uint32_t RERSEVED   : 15;	
	__IO uint32_t STARTS     : 1;
}tim6_hstar_field_t;	
typedef struct
{
	__IO uint32_t HSTP0      : 1;
	__IO uint32_t HSTP1      : 1;
	__IO uint32_t HSTP2      : 1;
	__IO uint32_t HSTP3      : 1;
	__IO uint32_t HSTP4      : 1;
	__IO uint32_t HSTP5      : 1;
	__IO uint32_t HSTP6      : 1;
	__IO uint32_t HSTP7      : 1;
	__IO uint32_t HSTP8      : 1;
	__IO uint32_t HSTP9      : 1;
	__IO uint32_t HSTP10     : 1;
	__IO uint32_t HSTP11     : 1;
	__IO uint32_t HSTP12     : 1;
	__IO uint32_t HSTP13     : 1;
	__IO uint32_t HSTP14     : 1;
	__IO uint32_t HSTP15     : 1;
	__IO uint32_t RERSEVED   : 15;	
	__IO uint32_t STOPS      : 1;
}tim6_hstpr_field_t;	
typedef struct
{
	__IO uint32_t HCLE0      : 1;
	__IO uint32_t HCLE1      : 1;
	__IO uint32_t HCLE2      : 1;
	__IO uint32_t HCLE3      : 1;
	__IO uint32_t HCLE4      : 1;
	__IO uint32_t HCLE5      : 1;
	__IO uint32_t HCLE6      : 1;
	__IO uint32_t HCLE7      : 1;
	__IO uint32_t HCLE8      : 1;
	__IO uint32_t HCLE9      : 1;
	__IO uint32_t HCLE10     : 1;
	__IO uint32_t HCLE11     : 1;
	__IO uint32_t HCLE12     : 1;
	__IO uint32_t HCLE13     : 1;
	__IO uint32_t HCLE14     : 1;
	__IO uint32_t HCLE15     : 1;
	//__IO uint32_t HCLE16     : 1;
	//__IO uint32_t HCLE17     : 1;
	//__IO uint32_t HCLE18     : 1;
	//__IO uint32_t HCLE19     : 1;
	__IO uint32_t RERSEVED   : 15;	
	__IO uint32_t CLEARS     : 1;
}tim6_hclrr_field_t;	
typedef struct
{
	__IO uint32_t HCPA0      : 1;
	__IO uint32_t HCPA1      : 1;
	__IO uint32_t HCPA2      : 1;
	__IO uint32_t HCPA3      : 1;
	__IO uint32_t HCPA4      : 1;
	__IO uint32_t HCPA5      : 1;
	__IO uint32_t HCPA6      : 1;
	__IO uint32_t HCPA7      : 1;
	__IO uint32_t HCPA8      : 1;
	__IO uint32_t HCPA9      : 1;
	__IO uint32_t HCPA10     : 1;
	__IO uint32_t HCPA11     : 1;
	__IO uint32_t HCPA12     : 1;
	__IO uint32_t HCPA13     : 1;
	__IO uint32_t HCPA14     : 1;
	__IO uint32_t HCPA15     : 1;
	//__IO uint32_t HCPA16     : 1;
	//__IO uint32_t HCPA17     : 1;
	//__IO uint32_t HCPA18     : 1;
	//__IO uint32_t HCPA19     : 1;
	__IO uint32_t RERSEVED   : 16;	
}tim6_hcpar_field_t;	
typedef struct
{
	__IO uint32_t HCPB0      : 1;
	__IO uint32_t HCPB1      : 1;
	__IO uint32_t HCPB2      : 1;
	__IO uint32_t HCPB3      : 1;
	__IO uint32_t HCPB4      : 1;
	__IO uint32_t HCPB5      : 1;
	__IO uint32_t HCPB6      : 1;
	__IO uint32_t HCPB7      : 1;
	__IO uint32_t HCPB8      : 1;
	__IO uint32_t HCPB9      : 1;
	__IO uint32_t HCPB10     : 1;
	__IO uint32_t HCPB11     : 1;
	__IO uint32_t HCPB12     : 1;
	__IO uint32_t HCPB13     : 1;
	__IO uint32_t HCPB14     : 1;
	__IO uint32_t HCPB15     : 1;
	//__IO uint32_t HCPB16     : 1;
	//__IO uint32_t HCPB17     : 1;
	//__IO uint32_t HCPB18     : 1;
	//__IO uint32_t HCPB19     : 1;
	__IO uint32_t RERSEVED   : 16;	
}tim6_hcpbr_field_t;	
typedef struct
{
	__IO uint32_t HCUP0      : 1;
	__IO uint32_t HCUP1      : 1;
	__IO uint32_t HCUP2      : 1;
	__IO uint32_t HCUP3      : 1;
	__IO uint32_t HCUP4      : 1;
	__IO uint32_t HCUP5      : 1;
	__IO uint32_t HCUP6      : 1;
	__IO uint32_t HCUP7      : 1;
	__IO uint32_t HCUP8      : 1;
	__IO uint32_t HCUP9      : 1;
	__IO uint32_t HCUP10     : 1;
	__IO uint32_t HCUP11     : 1;
	__IO uint32_t HCUP12     : 1;
	__IO uint32_t HCUP13     : 1;
	__IO uint32_t HCUP14     : 1;
	__IO uint32_t HCUP15     : 1;
	__IO uint32_t HCUP16     : 1;
	__IO uint32_t HCUP17     : 1;
	__IO uint32_t HCUP18     : 1;
	__IO uint32_t HCUP19     : 1;
	__IO uint32_t RERSEVED   : 12;	
}tim6_hcupr_field_t;	
typedef struct
{
	__IO uint32_t HCDO0      : 1;
	__IO uint32_t HCDO1      : 1;
	__IO uint32_t HCDO2      : 1;
	__IO uint32_t HCDO3      : 1;
	__IO uint32_t HCDO4      : 1;
	__IO uint32_t HCDO5      : 1;
	__IO uint32_t HCDO6      : 1;
	__IO uint32_t HCDO7      : 1;
	__IO uint32_t HCDO8      : 1;
	__IO uint32_t HCDO9      : 1;
	__IO uint32_t HCDO10     : 1;
	__IO uint32_t HCDO11     : 1;
	__IO uint32_t HCDO12     : 1;
	__IO uint32_t HCDO13     : 1;
	__IO uint32_t HCDO14     : 1;
	__IO uint32_t HCDO15     : 1;
	__IO uint32_t HCDO16     : 1;
	__IO uint32_t HCDO17     : 1;
	__IO uint32_t HCDO18     : 1;
	__IO uint32_t HCDO19     : 1;
	__IO uint32_t RERSEVED   : 12;	
}tim6_hcdor_field_t;	
typedef struct
{
	__IO uint32_t WP         : 1;
	__IO uint32_t RERSEVED   : 7;
	__IO uint32_t PROKEY     : 8;
	__IO uint32_t RERSEVED1  : 16;
}tim6_gpror_field_t;	
typedef struct
{
	__IO uint32_t CMAF       : 1;
	__IO uint32_t CMBF       : 1;
	__IO uint32_t CMCF       : 1;
	__IO uint32_t CMDF       : 1;
	__IO uint32_t RERSEVED   : 2;
	__IO uint32_t OVFF       : 1;
	__IO uint32_t UDFF       : 1;
	
	__IO uint32_t DTEF       : 1;
	__IO uint32_t RERSEVED1  : 5;
	__IO uint32_t SAMLF      : 1;
	__IO uint32_t SAMHF      : 1;
	
	__IO uint32_t RERSEVED2  : 16;
}tim6_intfr_field_t;	
typedef struct
{
	__IO uint32_t CMAC       : 1;
	__IO uint32_t CMBC       : 1;
	__IO uint32_t CMCC       : 1;
	__IO uint32_t CMDC       : 1;
	__IO uint32_t RERSEVED   : 2;
	__IO uint32_t OVFC       : 1;
	__IO uint32_t UDFC       : 1;
	
	__IO uint32_t DTEC       : 1;
	__IO uint32_t RERSEVED1  : 5;
	__IO uint32_t SAMLC      : 1;
	__IO uint32_t SAMHC      : 1;
	
	__IO uint32_t RERSEVED2  : 16;
}tim6_intcr_field_t;	
typedef struct
{
	__IO uint32_t CMAE       : 1;
	__IO uint32_t CMBE       : 1;
	__IO uint32_t CMCE       : 1;
	__IO uint32_t CMDE       : 1;
	__IO uint32_t RERSEVED   : 2;
	__IO uint32_t OVFE       : 1;
	__IO uint32_t UDFE       : 1;
	
	__IO uint32_t DITENA     : 1;
	__IO uint32_t DITENB     : 1;
	__IO uint32_t DITENS     : 1;
	__IO uint32_t RERSEVED2  : 21;
}tim6_ctrlr_field_t;
typedef struct
{
	__IO uint32_t FBRAKE     : 1;			
	__IO uint32_t FSAME      : 1;	
	__IO uint32_t BFILTS     : 2;	
	__IO uint32_t BFILTEN    : 1;
	__IO uint32_t RERSEVED1  : 2;
	__IO uint32_t SOFTB      : 1;
	__IO uint32_t SML0       : 1;
	__IO uint32_t SML1       : 1;
	__IO uint32_t SML2       : 1;
	__IO uint32_t SMH0       : 1;
	__IO uint32_t SMH1       : 1;
	__IO uint32_t SMH2       : 1;
	__IO uint32_t RERSEVED2  : 18;
}tim6_aossr_field_t;
typedef struct
{
	__IO uint32_t FBRAKE  : 1;			
	__IO uint32_t FSAME  : 1;	
		
	__IO uint32_t RERSEVED2  : 30;
}tim6_aoscl_field_t;
typedef struct
{
	__IO uint32_t TRIGAS  : 4;
	__IO uint32_t TRIGBS  : 4;
	__IO uint32_t TRIGCS  : 4;
	__IO uint32_t TRIGDS  : 4;
	__IO uint32_t RERSEVED2  : 16;
}tim6_tmtrig_field_t;
typedef struct
{
	__IO uint32_t IAOS0S  : 4;
	__IO uint32_t IAOS1S  : 4;
	__IO uint32_t IAOS2S  : 4;
	__IO uint32_t IAOS3S  : 4;
	__IO uint32_t RERSEVED2  : 16;
}tim6_itrig_field_t;
typedef struct
{
	__IO uint32_t EN0  : 1;
	__IO uint32_t EN1  : 1;
	__IO uint32_t EN2  : 1;
	__IO uint32_t EN3  : 1;
	__IO uint32_t EN4  : 1;
	__IO uint32_t EN5  : 1;
	__IO uint32_t EN6  : 1;
	__IO uint32_t EN7  : 1;
	__IO uint32_t EN8  : 1;
	__IO uint32_t EN9  : 1;
	__IO uint32_t EN10  : 1;
	__IO uint32_t EN11  : 1;
	__IO uint32_t EN12  : 1;
	__IO uint32_t EN13  : 1;
	__IO uint32_t EN14  : 1;
	__IO uint32_t EN15  : 1;
	__IO uint32_t RERSEVED  : 16;
}tim6_ptbks_field_t;
typedef struct
{
	__IO uint32_t POL0  : 1;
	__IO uint32_t POL1  : 1;
	__IO uint32_t POL2  : 1;
	__IO uint32_t POL3  : 1;
	__IO uint32_t POL4  : 1;
	__IO uint32_t POL5  : 1;
	__IO uint32_t POL6  : 1;
	__IO uint32_t POL7  : 1;
	__IO uint32_t POL8  : 1;
	__IO uint32_t POL9  : 1;
	__IO uint32_t POL10  : 1;
	__IO uint32_t POL11  : 1;
	__IO uint32_t POL12  : 1;
	__IO uint32_t POL13  : 1;
	__IO uint32_t POL14  : 1;
	__IO uint32_t POL15  : 1;
	__IO uint32_t RERSEVED2  : 16;
}tim6_ptbkpol_field_t;
typedef struct 
{
	__IO uint32_t SSTA0    : 1;
	__IO uint32_t SSTA1    : 1;
	__IO uint32_t SSTA2    : 1;
	__IO uint32_t RERSEVED : 29;
	
}tim6_sstar_field_t;
typedef struct
{
	__IO uint32_t SSTP0    : 1;
	__IO uint32_t SSTP1    : 1;
	__IO uint32_t SSTP2    : 1;
	__IO uint32_t RERSEVED : 29;
}tim6_sstpr_field_t;
typedef struct
{
	__IO uint32_t SCLR0    : 1;
	__IO uint32_t SCLR1    : 1;
	__IO uint32_t SCLR2    : 1;
	__IO uint32_t RERSEVED : 29;
}tim6_sclrr_field_t;
typedef struct
{
	__IO uint32_t CNTER;          
	__IO uint32_t PERAR;          
	__IO uint32_t PERBR;         
	__IO uint32_t RERSEVED0;     

	__IO uint32_t GCMAR;          
	__IO uint32_t GCMBR;          
	__IO uint32_t GCMCR;          
	__IO uint32_t GCMDR;         

	__IO uint32_t RERSEVED1[8];

	__IO uint32_t DTUAR;          
	__IO uint32_t DTDAR;         
	__IO uint32_t RERSEVED2[2];  
								   
    union{
		__IO uint32_t GCONR;
		tim6_gconr_field_t GCONR_f;
	};
	union{
		__IO uint32_t ICONR;
		tim6_iconr_field_t ICONR_f;
	};
	union{
		__IO uint32_t PCONR;
		tim6_pconr_field_t PCONR_f;
	};
	union{
		__IO uint32_t BCONR;
		tim6_bconr_field_t BCONR_f;
	};

	union{
		__IO uint32_t DCONR;
		tim6_dconr_field_t DCONR_f;
	};

	__IO uint32_t RERSEVED3;     
	union{
		__IO uint32_t FCONR;
		tim6_fconr_field_t FCONR_f;
	};

	union{
		__IO uint32_t VPERR;
		tim6_vperr_field_t VPERR_f;
	};

	union{
		__IO uint32_t STFLR;
		tim6_stflr_field_t STFLR_f;
	};

	union{
		__IO uint32_t HSTAR;
		tim6_hstar_field_t HSTAR_f;
	};

	union{
		__IO uint32_t HSTPR;
		tim6_hstpr_field_t HSTPR_f;
	};

	union{
		__IO uint32_t HCLRR;
		tim6_hclrr_field_t HCLRR_f;
	};

	union{
		__IO uint32_t HCPAR;
		tim6_hcpar_field_t HCPAR_f;
	};

 	union{
		__IO uint32_t HCPBR;
		tim6_hcpbr_field_t HCPBR_f;
	};

	union{
		__IO uint32_t HCUPR;
		tim6_hcupr_field_t HCUPR_f;
	};

	union{
		__IO uint32_t HCDOR;
		tim6_hcdor_field_t HCDOR_f;
	};

	__IO uint32_t RERSEVED4[28];

	union{
		__IO uint32_t IFR;
		tim6_intfr_field_t IFR_f;
	};

	union{
		__IO uint32_t ICLR;
		tim6_intcr_field_t ICLR_f;
	};	
	
	union{
		__IO uint32_t CR;
		tim6_ctrlr_field_t CR_f;
	};

	__IO uint32_t RERSEVED5;     

	union{
		__IO uint32_t AOSSR;
		tim6_aossr_field_t AOSSR_f;
	};	

	union{
		__IO uint32_t AOSCL;
		tim6_aoscl_field_t AOSCL_f;
	};

	union{
		__IO uint32_t PTBKS;
		tim6_ptbks_field_t PTBKS_f;
	};

	union{
		__IO uint32_t TTRIG;
		tim6_tmtrig_field_t TTRIG_f;
	};	

	union{
		__IO uint32_t ITRIG;
		tim6_itrig_field_t ITRIG_f;
	};	

	union{
		__IO uint32_t PTBKP;
		tim6_ptbkpol_field_t PTBKP_f;
	};	
	
	__IO uint32_t RERSEVED6[179];							

	union{
		__IO uint32_t SSTAR;          
		tim6_sstar_field_t SSTAR_f;
	};
	union{
		__IO uint32_t SSTPR;        
		tim6_sstpr_field_t SSTPR_f;
	};
	union{
		__IO uint32_t SCLRR;         
		tim6_sclrr_field_t SCLRR_f;
	};

}ADV_TIM_REG_TypeDef;

#define L005_TIM4           ((ADV_TIM_REG_TypeDef *)TIM4_BASEADDR)	
#define L005_TIM5           ((ADV_TIM_REG_TypeDef *)TIM5_BASEADDR)		
#define L005_TIM6           ((ADV_TIM_REG_TypeDef *)TIM6_BASEADDR)	

/*  **********   FLASH_CTRL struct    **********  */
typedef struct
{
	__IO uint32_t TNVS                   : 9;
	__IO uint32_t RERSEVED               : 23;
}flash_tnvs_field_t;

typedef struct
{
	__IO uint32_t TPGS                   : 8;
	__IO uint32_t RERSEVED               : 24;
}flash_tpgs_field_t;

typedef struct
{
	__IO uint32_t TPROG                  : 8;
	__IO uint32_t RERSEVED               : 24;
}flash_tprog_field_t;

typedef struct
{
	__IO uint32_t TSERASE                : 18;
	__IO uint32_t RERSEVED               : 14;
}flash_tserase_field_t;

typedef struct
{
	__IO uint32_t TMERASE                : 21;
	__IO uint32_t RERSEVED               : 11;
}flash_tmerase_field_t;

typedef struct
{
	__IO uint32_t TPRCV                  : 12;
	__IO uint32_t RERSEVED               : 20;
}flash_tprcv_field_t;

typedef struct
{
	__IO uint32_t TSRCV                  : 12;
	__IO uint32_t RERSEVED               : 20;
}flash_tsrcv_field_t;

typedef struct
{
	__IO uint32_t TMRCV                  : 13;
	__IO uint32_t RERSEVED               : 19;
}flash_tmrcv_field_t;
typedef struct
{
	__IO uint32_t OP    				 : 2;
	__IO uint32_t WAIT				     : 1;
	__IO uint32_t RERSEVED               : 1;
	__IO uint32_t BUSY                   : 1;
	__IO uint32_t IE                     : 2;
	__IO uint32_t RERSEVED1              : 25;
}flash_ctrl_field_t;

typedef struct
{
	__IO uint32_t IF0                    : 1;
	__IO uint32_t IF1       			 : 1;
    __IO uint32_t RERSEVED1              : 30;
}flash_ifr_field_t;

typedef struct
{
	__IO uint32_t ICLR0		             : 1;
	__IO uint32_t ICLR1				     : 1;
	__IO uint32_t RERSEVED               : 30;
}flash_iclr_field_t;

typedef struct 
{
	__IO uint32_t BYSEQ                  : 16;
	__IO uint32_t RERSEVED               : 16;
}flash_bypass_field_t;

typedef struct 
{
	__IO uint32_t SLOCK                  : 16;
	__IO uint32_t RERSEVED               : 16;
}flash_slock_field_t;

typedef struct
{
	union{
		__IO uint32_t TNVS;
		flash_tnvs_field_t TNVS_f;
	};
	union{
		__IO uint32_t TPGS;
		flash_tpgs_field_t TPGS_f;
	};
	union{
		__IO uint32_t TPROG;
		flash_tprog_field_t TPROG_f;
	};
	union{
		__IO uint32_t TSERASE;
		flash_tserase_field_t TSERASE_f;
	};
	union{
		__IO uint32_t TMERASE;
		flash_tmerase_field_t TMERASE_f;
	};
	union{
		__IO uint32_t TPRCV;
		flash_tprcv_field_t TPRCV_f;
	};
	union{
		__IO uint32_t TSRCV;
		flash_tsrcv_field_t TSRCV_f;
	};
	union{
		__IO uint32_t TMRCV;
		flash_tmrcv_field_t TMRCV_f;
	};
	union{
		__IO uint32_t CR;
		flash_ctrl_field_t CR_f;
	};
	union{
		__IO uint32_t IFR;
		flash_ifr_field_t IFR_f;
	};
	union{
		__IO uint32_t ICLR;
		flash_iclr_field_t ICLR_f;
	};
	union{
		__IO uint32_t BYPASS;
		flash_bypass_field_t BYPASS_f;
	};
	union{
		__IO uint32_t SLOCK;
		flash_slock_field_t SLOCK_f;
	};
}EFLASH_REG_TypeDef;

#define L005_FLASH           ((EFLASH_REG_TypeDef *)EFLASH_CTRL_BASEADDR)

/*  **********   RAM_CTRL struct    **********  */

typedef struct
{
	__IO uint32_t CHKEN         	: 1;
	__IO uint32_t IE        		: 1;
	__IO uint32_t RERSEVED          : 30;
}ram_ctrl_field_t;

typedef struct
{
	__IO uint32_t ERRADDR           : 12;
	__IO uint32_t RERSEVED          : 20;
}ram_erraddr_field_t;

typedef struct
{
	__IO uint32_t ERR               : 1;
	__IO uint32_t RERSEVED          : 31;
}ram_ifr_field_t;

typedef struct
{
	__IO uint32_t ERRCLR            : 1;
	__IO uint32_t RERSEVED          : 31;
}ram_iclr_field_t;
typedef struct
{
	union {
		__IO uint32_t CR;
		ram_ctrl_field_t CR_f;
	};
	union {
		__IO uint32_t ERRADDR;
		ram_erraddr_field_t ERRADDR_f;
	};
	union {
		__IO uint32_t IFR;
		ram_ifr_field_t IFR_f;
	};
	union {
		__IO uint32_t ICLR;
		ram_iclr_field_t ICLR_f;
	};
	
}RAM_REG_TypeDef;

#define L005_RAM             ((RAM_REG_TypeDef *)RAM_CTRL_BASEADDR)

/*  **********   DES struct    **********  */


/*  **********   CRC struct    **********  */

typedef struct
{
	__IO uint32_t RESULT    	    : 16;
	__IO uint32_t FLAG				: 1;
	__IO uint32_t RERSEVED          : 15;
}crc_resultreg_field_t;

typedef struct
{
	__IO uint32_t RERSEVED0;
	
	union {
		__IO uint32_t RESULT;
		crc_resultreg_field_t RESULT_f;
	};
	
	__IO uint32_t RERSEVED1[30];
	
	union {
		__IO uint32_t DATA_WORD;
		__IO uint16_t DATA_HALFWORD;
		__IO uint8_t  DATA_BYTE;
	};
}CRC_REG_TypeDef;

#define L005_CRC							((CRC_REG_TypeDef *)CRC_BASEADDR)

/*  **********   PORT_CTRL struct    **********  */

typedef struct
{
	__IO uint32_t RERSEVED  : 1;
	__IO uint32_t P0DIR1	: 1;
	__IO uint32_t P0DIR2	: 1;
	__IO uint32_t P0DIR3	: 1;
}p0dir_field_t;

typedef struct
{
	__IO uint32_t P0IN0	    : 1;
	__IO uint32_t P0IN1	    : 1;
	__IO uint32_t P0IN2	    : 1;
	__IO uint32_t P0IN3	    : 1;
}p0in_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 1;
	__IO uint32_t P0OUT1	: 1;
	__IO uint32_t P0OUT2	: 1;
	__IO uint32_t P0OUT3	: 1;
}p0out_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 1;
	__IO uint32_t P0ADS1	: 1;
	__IO uint32_t P0ADS2	: 1;
	__IO uint32_t P0ADS3	: 1;
}p0ads_field_t;

typedef struct
{
	__IO uint32_t P0CS0	    : 1;
	__IO uint32_t P0CS1	    : 1;
	__IO uint32_t P0CS2	    : 1;
	__IO uint32_t P0CS3	    : 1;
}p0cs_field_t;

typedef struct
{
	__IO uint32_t P0IE0	    : 1;
	__IO uint32_t P0IE1	    : 1;
	__IO uint32_t P0IE2	    : 1;
	__IO uint32_t P0IE3	    : 1;
}p0ie_field_t;

typedef struct
{
	__IO uint32_t P0SR0	    : 1;
	__IO uint32_t P0SR1	    : 1;
	__IO uint32_t P0SR2	    : 1;
	__IO uint32_t P0SR3	    : 1;
}p0sr_field_t;

typedef struct
{
	__IO uint32_t RERSEVED  : 1;
	__IO uint32_t P0DR1	    : 1;
	__IO uint32_t P0DR2	    : 1;
	__IO uint32_t P0DR3	    : 1;
}p0dr_field_t;

typedef struct
{
	__IO uint32_t RERSEVED  : 1; 
	__IO uint32_t P0PU1	    : 1;
	__IO uint32_t P0PU2	    : 1;
	__IO uint32_t P0PU3	    : 1;
}p0pu_field_t;

typedef struct
{
	__IO uint32_t RERSEVED  : 1;
	__IO uint32_t P0PD1	    : 1;
	__IO uint32_t P0PD2	    : 1;
	__IO uint32_t P0PD3	    : 1;
}p0pd_field_t;

typedef struct
{
	__IO uint32_t P0OS0	    : 1;
	__IO uint32_t P0OS1	    : 1;
	__IO uint32_t P0OS2	    : 1;
	__IO uint32_t P0OS3	    : 1;
}p0os_field_t;

typedef struct
{
	__IO uint32_t RERSEVED  : 1;
	__IO uint32_t P0OD1	    : 1;
	__IO uint32_t P0OD2	    : 1;
	__IO uint32_t P0OD3	    : 1;
}p0od_field_t;

typedef struct
{
	__IO uint32_t P0HIE0    : 1;
	__IO uint32_t P0HIE1    : 1;
	__IO uint32_t P0HIE2    : 1;
	__IO uint32_t P0HIE3    : 1;
}p0inten0_field_t;

typedef struct
{
	__IO uint32_t P0LIE0    : 1;
	__IO uint32_t P0LIE1    : 1;
	__IO uint32_t P0LIE2    : 1;
	__IO uint32_t P0LIE3    : 1;
}p0inten1_field_t;

typedef struct
{
	__IO uint32_t P0RIE0	: 1;
	__IO uint32_t P0RIE1	: 1;
	__IO uint32_t P0RIE2	: 1;
	__IO uint32_t P0RIE3	: 1;
}p0inten2_field_t;

typedef struct
{
	__IO uint32_t P0FIE0 	: 1;
	__IO uint32_t P0FIE1 	: 1;
	__IO uint32_t P0FIE2 	: 1;
	__IO uint32_t P0FIE3 	: 1;
}p0inten3_field_t;

typedef struct
{
	__IO uint32_t P0STA0	: 1;
	__IO uint32_t P0STA1	: 1;
	__IO uint32_t P0STA2	: 1;
	__IO uint32_t P0STA3	: 1;
}p0stat_field_t;

typedef struct
{
	__IO uint32_t P0CLR0	: 1;
	__IO uint32_t P0CLR1	: 1;
	__IO uint32_t P0CLR2	: 1;
	__IO uint32_t P0CLR3	: 1;
}p0iclr_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 4;
	__IO uint32_t P1DIR4	: 1;
	__IO uint32_t P1DIR5	: 1;
}p1dir_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 4;
	__IO uint32_t P1IN4	: 1;
	__IO uint32_t P1IN5	: 1;
}p1in_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 4;
	__IO uint32_t P1OUT4	: 1;
	__IO uint32_t P1OUT5	: 1;
}p1out_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 4;
	__IO uint32_t P1ADS4	: 1;
	__IO uint32_t P1ADS5	: 1;
}p1ads_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 4;
	__IO uint32_t P1CS4	: 1;
	__IO uint32_t P1CS5	: 1;
}p1cs_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 4;
	__IO uint32_t P1IE4	: 1;
	__IO uint32_t P1IE5	: 1;
}p1ie_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 4;
	__IO uint32_t P1SR4	: 1;
	__IO uint32_t P1SR5	: 1;
}p1sr_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 4;
	__IO uint32_t P1DR4	: 1;
	__IO uint32_t P1DR5	: 1;
}p1dr_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 4;
	__IO uint32_t P1PU4	: 1;
	__IO uint32_t P1PU5	: 1;
}p1pu_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 4;
	__IO uint32_t P1PD4	: 1;
	__IO uint32_t P1PD5	: 1;
}p1pd_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 4;
	__IO uint32_t P1OS4	: 1;
	__IO uint32_t P1OS5	: 1;
}p1os_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 4;
	__IO uint32_t P1OD4	: 1;
	__IO uint32_t P1OD5	: 1;
}p1od_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 4;
	__IO uint32_t P1HIE4	: 1;
	__IO uint32_t P1HIE5	: 1;
}p1inten0_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 4;
	__IO uint32_t P1LIE4	: 1;
	__IO uint32_t P1LIE5	: 1;
}p1inten1_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 4;
	__IO uint32_t P1RIE4	: 1;
	__IO uint32_t P1RIE5	: 1;
}p1inten2_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 4;
	__IO uint32_t P1FIE4	: 1;
	__IO uint32_t P1FIE5	: 1;
}p1inten3_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 4;
	__IO uint32_t P1STA4	: 1;
	__IO uint32_t P1STA5	: 1;
}p1stat_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 4;
	__IO uint32_t P1CLR4	: 1;
	__IO uint32_t P1CLR5	: 1;
}p1iclr_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 3;
	__IO uint32_t P2DIR3	: 1;
	__IO uint32_t P2DIR4	: 1;
	__IO uint32_t P2DIR5	: 1;
	__IO uint32_t P2DIR6	: 1;
	__IO uint32_t P2DIR7	: 1;
}p2dir_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 3;
	__IO uint32_t P2IN3	: 1;
	__IO uint32_t P2IN4	: 1;
	__IO uint32_t P2IN5	: 1;
	__IO uint32_t P2IN6	: 1;
	__IO uint32_t P2IN7	: 1;
}p2in_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 3;
	__IO uint32_t P2OUT3	: 1;
	__IO uint32_t P2OUT4	: 1;
	__IO uint32_t P2OUT5	: 1;
	__IO uint32_t P2OUT6	: 1;
	__IO uint32_t P2OUT7	: 1;
}p2out_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 3;
	__IO uint32_t P2ADS3	: 1;
	__IO uint32_t P2ADS4	: 1;
	__IO uint32_t P2ADS5	: 1;
	__IO uint32_t P2ADS6	: 1;
	__IO uint32_t P2ADS7	: 1;
}p2ads_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 3;
	__IO uint32_t P2CS3	: 1;
	__IO uint32_t P2CS4	: 1;
	__IO uint32_t P2CS5	: 1;
	__IO uint32_t P2CS6	: 1;
	__IO uint32_t P2CS7	: 1;
}p2cs_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 3;
	__IO uint32_t P2IE3	: 1;
	__IO uint32_t P2IE4	: 1;
	__IO uint32_t P2IE5	: 1;
	__IO uint32_t P2IE6	: 1;
	__IO uint32_t P2IE7	: 1;
}p2ie_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 3;
	__IO uint32_t P2SR3	: 1;
	__IO uint32_t P2SR4	: 1;
	__IO uint32_t P2SR5	: 1;
	__IO uint32_t P2SR6	: 1;
	__IO uint32_t P2SR7	: 1;
}p2sr_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 3;
	__IO uint32_t P2DR3	: 1;
	__IO uint32_t P2DR4	: 1;
	__IO uint32_t P2DR5	: 1;
	__IO uint32_t P2DR6	: 1;
	__IO uint32_t P2DR7	: 1;
}p2dr_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 3;
	__IO uint32_t P2PU3	: 1;
	__IO uint32_t P2PU4	: 1;
	__IO uint32_t P2PU5	: 1;
	__IO uint32_t P2PU6	: 1;
	__IO uint32_t P2PU7	: 1;
}p2pu_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 3;
	__IO uint32_t P2PD3	: 1;
	__IO uint32_t P2PD4	: 1;
	__IO uint32_t P2PD5	: 1;
	__IO uint32_t P2PD6	: 1;
	__IO uint32_t P2PD7	: 1;
}p2pd_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 3;
	__IO uint32_t P2OS3	: 1;
	__IO uint32_t P2OS4	: 1;
	__IO uint32_t P2OS5	: 1;
	__IO uint32_t P2OS6	: 1;
	__IO uint32_t P2OS7	: 1;
}p2os_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 3;
	__IO uint32_t P2OD3	: 1;
	__IO uint32_t P2OD4	: 1;
	__IO uint32_t P2OD5	: 1;
	__IO uint32_t P2OD6	: 1;
	__IO uint32_t P2OD7	: 1;
}p2od_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 3;
	__IO uint32_t P2HIE3	: 1;
	__IO uint32_t P2HIE4	: 1;
	__IO uint32_t P2HIE5	: 1;
	__IO uint32_t P2HIE6	: 1;
	__IO uint32_t P2HIE7	: 1;
}p2inten0_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 3;
	__IO uint32_t P2LIE3	: 1;
	__IO uint32_t P2LIE4	: 1;
	__IO uint32_t P2LIE5	: 1;
	__IO uint32_t P2LIE6	: 1;
	__IO uint32_t P2LIE7	: 1;
}p2inten1_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 3;
	__IO uint32_t P2RIE3	: 1;
	__IO uint32_t P2RIE4	: 1;
	__IO uint32_t P2RIE5	: 1;
	__IO uint32_t P2RIE6	: 1;
	__IO uint32_t P2RIE7	: 1;
}p2inten2_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 3;
	__IO uint32_t P2FIE3	: 1;
	__IO uint32_t P2FIE4	: 1;
	__IO uint32_t P2FIE5	: 1;
	__IO uint32_t P2FIE6	: 1;
	__IO uint32_t P2FIE7	: 1;
}p2inten3_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 3;
	__IO uint32_t P2STA3	: 1;
	__IO uint32_t P2STA4	: 1;
	__IO uint32_t P2STA5	: 1;
	__IO uint32_t P2STA6	: 1;
	__IO uint32_t P2STA7	: 1;
}p2stat_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 3;
	__IO uint32_t P2CLR3	: 1;
	__IO uint32_t P2CLR4	: 1;
	__IO uint32_t P2CLR5	: 1;
	__IO uint32_t P2CLR6	: 1;
	__IO uint32_t P2CLR7	: 1;
}p2iclr_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 1;
	__IO uint32_t P3DIR1	: 1;
	__IO uint32_t P3DIR2	: 1;
	__IO uint32_t P3DIR3	: 1;
	__IO uint32_t P3DIR4	: 1;
	__IO uint32_t P3DIR5	: 1;
	__IO uint32_t P3DIR6	: 1;
}p3dir_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 1;
	__IO uint32_t P3IN1	: 1;
	__IO uint32_t P3IN2	: 1;
	__IO uint32_t P3IN3	: 1;
	__IO uint32_t P3IN4	: 1;
	__IO uint32_t P3IN5	: 1;
	__IO uint32_t P3IN6	: 1;
}p3in_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 1;
	__IO uint32_t P3OUT1	: 1;
	__IO uint32_t P3OUT2	: 1;
	__IO uint32_t P3OUT3	: 1;
	__IO uint32_t P3OUT4	: 1;
	__IO uint32_t P3OUT5	: 1;
	__IO uint32_t P3OUT6	: 1;
}p3out_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 1;
	__IO uint32_t P3ADS1	: 1;
	__IO uint32_t P3ADS2	: 1;
	__IO uint32_t P3ADS3	: 1;
	__IO uint32_t P3ADS4	: 1;
	__IO uint32_t P3ADS5	: 1;
	__IO uint32_t P3ADS6	: 1;
}p3ads_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 1;
	__IO uint32_t P3CS1	: 1;
	__IO uint32_t P3CS2	: 1;
	__IO uint32_t P3CS3	: 1;
	__IO uint32_t P3CS4	: 1;
	__IO uint32_t P3CS5	: 1;
	__IO uint32_t P3CS6	: 1;
}p3cs_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 1;
	__IO uint32_t P3IE1	: 1;
	__IO uint32_t P3IE2	: 1;
	__IO uint32_t P3IE3	: 1;
	__IO uint32_t P3IE4	: 1;
	__IO uint32_t P3IE5	: 1;
	__IO uint32_t P3IE6	: 1;
}p3ie_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 1;
	__IO uint32_t P3SR1	: 1;
	__IO uint32_t P3SR2	: 1;
	__IO uint32_t P3SR3	: 1;
	__IO uint32_t P3SR4	: 1;
	__IO uint32_t P3SR5	: 1;
	__IO uint32_t P3SR6	: 1;
}p3sr_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 1;
	__IO uint32_t P3DR1	: 1;
	__IO uint32_t P3DR2	: 1;
	__IO uint32_t P3DR3	: 1;
	__IO uint32_t P3DR4	: 1;
	__IO uint32_t P3DR5	: 1;
	__IO uint32_t P3DR6	: 1;
}p3dr_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 1;
	__IO uint32_t P3PU1	: 1;
	__IO uint32_t P3PU2	: 1;
	__IO uint32_t P3PU3	: 1;
	__IO uint32_t P3PU4	: 1;
	__IO uint32_t P3PU5	: 1;
	__IO uint32_t P3PU6	: 1;
}p3pu_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 1;
	__IO uint32_t P3PD1	: 1;
	__IO uint32_t P3PD2	: 1;
	__IO uint32_t P3PD3	: 1;
	__IO uint32_t P3PD4	: 1;
	__IO uint32_t P3PD5	: 1;
	__IO uint32_t P3PD6	: 1;
}p3pd_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 1;
	__IO uint32_t P3OS1	: 1;
	__IO uint32_t P3OS2	: 1;
	__IO uint32_t P3OS3	: 1;
	__IO uint32_t P3OS4	: 1;
	__IO uint32_t P3OS5	: 1;
	__IO uint32_t P3OS6	: 1;
}p3os_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 1;
	__IO uint32_t P3OD1	: 1;
	__IO uint32_t P3OD2	: 1;
	__IO uint32_t P3OD3	: 1;
	__IO uint32_t P3OD4	: 1;
	__IO uint32_t P3OD5	: 1;
	__IO uint32_t P3OD6	: 1;
}p3od_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 1;
	__IO uint32_t P3HIE1	: 1;
	__IO uint32_t P3HIE2	: 1;
	__IO uint32_t P3HIE3	: 1;
	__IO uint32_t P3HIE4	: 1;
	__IO uint32_t P3HIE5	: 1;
	__IO uint32_t P3HIE6	: 1;
}p3inten0_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 1;
	__IO uint32_t P3LIE1	: 1;
	__IO uint32_t P3LIE2	: 1;
	__IO uint32_t P3LIE3	: 1;
	__IO uint32_t P3LIE4	: 1;
	__IO uint32_t P3LIE5	: 1;
	__IO uint32_t P3LIE6	: 1;
}p3inten1_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 1;
	__IO uint32_t P3RIE1	: 1;
	__IO uint32_t P3RIE2	: 1;
	__IO uint32_t P3RIE3	: 1;
	__IO uint32_t P3RIE4	: 1;
	__IO uint32_t P3RIE5	: 1;
	__IO uint32_t P3RIE6	: 1;
}p3inten2_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 1;
	__IO uint32_t P3FIE1	: 1;
	__IO uint32_t P3FIE2	: 1;
	__IO uint32_t P3FIE3	: 1;
	__IO uint32_t P3FIE4	: 1;
	__IO uint32_t P3FIE5	: 1;
	__IO uint32_t P3FIE6	: 1;
}p3inten3_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 1;
	__IO uint32_t P3STA1	: 1;
	__IO uint32_t P3STA2	: 1;
	__IO uint32_t P3STA3	: 1;
	__IO uint32_t P3STA4	: 1;
	__IO uint32_t P3STA5	: 1;
	__IO uint32_t P3STA6	: 1;
}p3stat_field_t;

typedef struct
{
	__IO uint32_t RERSEVED	: 1;
	__IO uint32_t P3CLR1	: 1;
	__IO uint32_t P3CLR2	: 1;
	__IO uint32_t P3CLR3	: 1;
	__IO uint32_t P3CLR4	: 1;
	__IO uint32_t P3CLR5	: 1;
	__IO uint32_t P3CLR6	: 1;
}p3iclr_field_t;

typedef struct
{
	__IO uint32_t ext_clk_sel	: 4;
	__IO uint32_t ssn_sel		: 4;
	__IO uint32_t pclk_sel		: 2;
	__IO uint32_t hclk_sel		: 2;
	__IO uint32_t pclk_en		: 1;
	__IO uint32_t hclk_en		: 1;
	__IO uint32_t ir_pol		: 1;
}gpio_ctrl1_field_t;

typedef struct
{
	__IO uint32_t pca_cap0_sel	: 2;
	__IO uint32_t pca_cap1_sel	: 2;
	__IO uint32_t pca_cap2_sel	: 2;
	__IO uint32_t pca_cap3_sel	: 2;
	__IO uint32_t pca_cap4_sel	: 2;
}gpio_ctrl2_field_t;

typedef struct
{
	__IO uint32_t tm6_b0_sel	: 2;
	__IO uint32_t tm6_b1_sel	: 2;
	__IO uint32_t tm6_b2_sel	: 2;
	__IO uint32_t tm6_a0_sel	: 2;
	__IO uint32_t tm6_a1_sel	: 2;
	__IO uint32_t tm6_a2_sel	: 2;
}gpio_ctrl3_field_t;

typedef struct
{
	__IO uint32_t tm0_gate_sel	: 2;
	__IO uint32_t tm1_gate_sel	: 2;
	__IO uint32_t tm2_gate_sel	: 2;
	__IO uint32_t tm3_gate_sel	: 2;
}gpio_ctrl4_field_t;

typedef struct
{
	__IO uint32_t RERSEVED0;
	
	__IO uint32_t P01_SEL;
	__IO uint32_t P02_SEL;
	__IO uint32_t P03_SEL;
	
	__IO uint32_t RERSEVED1[0x10];
	
	__IO uint32_t P14_SEL;
	__IO uint32_t P15_SEL;
	
	__IO uint32_t RERSEVED2[0xd];
	
	__IO uint32_t P23_SEL;
	__IO uint32_t P24_SEL;
	__IO uint32_t P25_SEL;
	__IO uint32_t P26_SEL;
	__IO uint32_t P27_SEL;
	
	__IO uint32_t RERSEVED3[0x9];
	
	__IO uint32_t P31_SEL;
	__IO uint32_t P32_SEL;
	__IO uint32_t P33_SEL;
	__IO uint32_t P34_SEL;
	__IO uint32_t P35_SEL;
	__IO uint32_t P36_SEL;
	
	__IO uint32_t RERSEVED4[0x9];
	
	union {
		__IO uint32_t P0DIR;
		p0dir_field_t P0DIR_f;
	};
	
	union {
		__IO uint32_t P0IN;
		p0in_field_t P0IN_f;
	};
	
	union {
		__IO uint32_t P0OUT;
		p0out_field_t P0OUT_f;
	};
	
	union {
		__IO uint32_t P0ADS;
		p0ads_field_t P0ADS_f;
	};
	
//	union {
//		__IO uint32_t P0CS;
//		p0cs_field_t P0CS_f;
//	};
	
	__IO uint32_t RERSEVED5[3];
	
//	union {
//		__IO uint32_t P0SR;
//		p0sr_field_t P0SR_f;
//	};
	
	union {
		__IO uint32_t P0DR;
		p0dr_field_t P0DR_f;
	};
	
	union {
		__IO uint32_t P0PU;
		p0pu_field_t P0PU_f;
	};
	
	union {
		__IO uint32_t P0PD;
		p0pd_field_t P0PD_f;
	};
	
	__IO uint32_t RERSEVED6;
//	union {
//		__IO uint32_t P0OS;
//		p0os_field_t P0OS_f;
//	};
	
	union {
		__IO uint32_t P0OD;
		p0od_field_t P0OD_f;
	};
	
	union {
		__IO uint32_t P0INTEN0;
		p0inten0_field_t P0INTEN0_f;
	};
	
	union {
		__IO uint32_t P0INTEN1;
		p0inten1_field_t P0INTEN1_f;
	};
	
	union {
		__IO uint32_t P0INTEN2;
		p0inten2_field_t P0INTEN2_f;
	};
	
	union {
		__IO uint32_t P0INTEN3;
		p0inten3_field_t P0INTEN3_f;
	};
	
	union {
		__IO uint32_t P1DIR;
		p1dir_field_t P1DIR_f;
	};
	
	union {
		__IO uint32_t P1IN;
		p1in_field_t P1IN_f;
	};
	
	union {
		__IO uint32_t P1OUT;
		p1out_field_t P1OUT_f;
	};
	
	union {
		__IO uint32_t P1ADS;
		p1ads_field_t P1ADS_f;
	};
	
//	union {
//		__IO uint32_t P1CS;
//		p1cs_field_t P1CS_f;
//	};
	
	__IO uint32_t RERSEVED7[3];
	
//	union {
//		__IO uint32_t P1SR;
//		p1sr_field_t P1SR_f;
//	};
	
	union {
		__IO uint32_t P1DR;
		p1dr_field_t P1DR_f;
	};
	
	union {
		__IO uint32_t P1PU;
		p1pu_field_t P1PU_f;
	};
	
	union {
		__IO uint32_t P1PD;
		p1pd_field_t P1PD_f;
	};
	
	__IO uint32_t RERSEVED8;
//	union {
//		__IO uint32_t P1OS;
//		p1os_field_t P1OS_f;
//	};
	
	union {
		__IO uint32_t P1OD;
		p1od_field_t P1OD_f;
	};
	
	union {
		__IO uint32_t P1INTEN0;
		p1inten0_field_t P1INTEN0_f;
	};
	
	union {
		__IO uint32_t P1INTEN1;
		p1inten1_field_t P1INTEN1_f;
	};
	
	union {
		__IO uint32_t P1INTEN2;
		p1inten2_field_t P1INTEN2_f;
	};
	
	union {
		__IO uint32_t P1INTEN3;
		p1inten3_field_t P1INTEN3_f;
	};
	
	union {
		__IO uint32_t P2DIR;
		p2dir_field_t P2DIR_f;
	};
	
	union {
		__IO uint32_t P2IN;
		p2in_field_t P2IN_f;
	};
	
	union {
		__IO uint32_t P2OUT;
		p2out_field_t P2OUT_f;
	};
	
	union {
		__IO uint32_t P2ADS;
		p2ads_field_t P2ADS_f;
	};
	
//	union {
//		__IO uint32_t P2CS;
//		p2cs_field_t P2CS_f;
//	};
	
	__IO uint32_t RERSEVED9[3];
	
//	union {
//		__IO uint32_t P2SR;
//		p2sr_field_t P2SR_f;
//	};
	
	union {
		__IO uint32_t P2DR;
		p2dr_field_t P2DR_f;
	};
	
	union {
		__IO uint32_t P2PU;
		p2pu_field_t P2PU_f;
	};
	
	union {
		__IO uint32_t P2PD;
		p2pd_field_t P2PD_f;
	};
	
	__IO uint32_t RERSEVED10;
//	union {
//		__IO uint32_t P2OS;
//		p2os_field_t P2OS_f;
//	};
	
	union {
		__IO uint32_t P2OD;
		p2od_field_t P2OD_f;
	};
	
	union {
		__IO uint32_t P2INTEN0;
		p2inten0_field_t P2INTEN0_f;
	};
	
	union {
		__IO uint32_t P2INTEN1;
		p2inten1_field_t P2INTEN1_f;
	};
	
	union {
		__IO uint32_t P2INTEN2;
		p2inten2_field_t P2INTEN2_f;
	};
	
	union {
		__IO uint32_t P2INTEN3;
		p2inten3_field_t P2INTEN3_f;
	};
	
	union {
		__IO uint32_t P3DIR;
		p3dir_field_t P3DIR_f;
	};
	
	union {
		__IO uint32_t P3IN;
		p3in_field_t P3IN_f;
	};
	
	union {
		__IO uint32_t P3OUT;
		p3out_field_t P3OUT_f;
	};
	
	union {
		__IO uint32_t P3ADS;
		p3ads_field_t P3ADS_f;
	};
	
//	union {
//		__IO uint32_t P3CS;
//		p3cs_field_t P3CS_f;
//	};
	
	__IO uint32_t RERSEVED11[3];
	
//	union {
//		__IO uint32_t P3SR;
//		p3sr_field_t P3SR_f;
//	};
	
	union {
		__IO uint32_t P3DR;
		p3dr_field_t P3DR_f;
	};
	
	union {
		__IO uint32_t P3PU;
		p3pu_field_t P3PU_f;
	};
	
	union {
		__IO uint32_t P3PD;
		p3pd_field_t P3PD_f;
	};
	
	__IO uint32_t RERSEVED12;
//	union {
//		__IO uint32_t P3OS;
//		p3os_field_t P3OS_f;
//	};
	
	union {
		__IO uint32_t P3OD;
		p3od_field_t P3OD_f;
	};
	
	union {
		__IO uint32_t P3INTEN0;
		p3inten0_field_t P3INTEN0_f;
	};
	
	union {
		__IO uint32_t P3INTEN1;
		p3inten1_field_t P3INTEN1_f;
	};
	
	union {
		__IO uint32_t P3INTEN2;
		p3inten2_field_t P3INTEN2_f;
	};
	
	union {
		__IO uint32_t P3INTEN3;
		p3inten3_field_t P3INTEN3_f;
	};
	
	union {
		__IO uint32_t P0_STAT;
		p0stat_field_t P0_STAT_f;
	};
	
	__IO uint32_t RERSEVED13[3];
	
	union {
		__IO uint32_t P0_ICLR;
		p0iclr_field_t P0_ICLR_f;
	};
	
	__IO uint32_t RERSEVED14[0xb];
	
	union {
		__IO uint32_t P1_STAT;
		p1stat_field_t P1_STAT_f;
	};
	
	__IO uint32_t RERSEVED15[3];
	
	union {
		__IO uint32_t P1_ICLR;
		p1iclr_field_t P1_ICLR_f;
	};
	
	__IO uint32_t RERSEVED16[0xb];
	
	union {
		__IO uint32_t P2_STAT;
		p2stat_field_t P2_STAT_f;
	};
	
	__IO uint32_t RERSEVED17[3];
	
	union {
		__IO uint32_t P2_ICLR;
		p2iclr_field_t P2_ICLR_f;
	};
	
	__IO uint32_t RERSEVED18[0xb];
	
	union {
		__IO uint32_t P3_STAT;
		p3stat_field_t P3_STAT_f;
	};
	
	__IO uint32_t RERSEVED19[3];
	
	union {
		__IO uint32_t P3_ICLR;
		p3iclr_field_t P3_ICLR_f;
	};
	
	__IO uint32_t RERSEVED20[0xb];
	
	__IO uint32_t GPIO_CTRL0;
	
	union {
		__IO uint32_t GPIO_CTRL1;
		gpio_ctrl1_field_t GPIO_CTRL1_f;
	};
	
	union {
		__IO uint32_t GPIO_CTRL2;
		gpio_ctrl2_field_t GPIO_CTRL2_f;
	};
	
	union {
		__IO uint32_t GPIO_CTRL3;
		gpio_ctrl3_field_t GPIO_CTRL3_f;
	};
	
	union {
		__IO uint32_t GPIO_CTRL4;
		gpio_ctrl4_field_t GPIO_CTRL4_f;
	};
}PORT_CTRL_REG_TypeDef;

//#define PORT_CTRL_BASEADDR	 (0x40020C00)
#define L005_GPIO				((PORT_CTRL_REG_TypeDef *)PORT_CTRL_BASEADDR)

typedef struct
{
    __IO uint32_t SEL[8];
//  __IO uint32_t RERSEVED0;
//	__IO uint32_t Px1_SEL;
//	__IO uint32_t Px2_SEL;
//	__IO uint32_t Px3_SEL;
//    __IO uint32_t Px4_SEL;
//    __IO uint32_t Px5_SEL;
//    __IO uint32_t Px6_SEL;
//    __IO uint32_t Px7_SEL;
	
	__IO uint32_t RERSEVED1[56];
    union {
		__IO uint32_t PxDIR;
		p0dir_field_t PxDIR_f;
	};
	
	union {
		__IO uint32_t PxIN;
		p0in_field_t PxIN_f;
	};
	
	union {
		__IO uint32_t PxOUT;
		p0out_field_t PxOUT_f;
	};
	
	union {
		__IO uint32_t PxADS;
		p0ads_field_t PxADS_f;
	};
	
//	union {
//		__IO uint32_t P0CS;
//		p0cs_field_t P0CS_f;
//	};
	
	__IO uint32_t RERSEVED5[3];
	
//	union {
//		__IO uint32_t P0SR;
//		p0sr_field_t P0SR_f;
//	};
	
	union {
		__IO uint32_t PxDR;
		p0dr_field_t PxDR_f;
	};
	
	union {
		__IO uint32_t PxPU;
		p0pu_field_t PxPU_f;
	};
	
	union {
		__IO uint32_t PxPD;
		p0pd_field_t PxPD_f;
	};
	
	__IO uint32_t RERSEVED6;
//	union {
//		__IO uint32_t P0OS;
//		p0os_field_t P0OS_f;
//	};
	
	union {
		__IO uint32_t PxOD;
		p0od_field_t PxOD_f;
	};
	
	union {
		__IO uint32_t PxINTEN0;
		p0inten0_field_t PxINTEN0_f;
	};
	
	union {
		__IO uint32_t PxINTEN1;
		p0inten1_field_t PxINTEN1_f;
	};
	
	union {
		__IO uint32_t PxINTEN2;
		p0inten2_field_t PxINTEN2_f;
	};
	
	union {
		__IO uint32_t PxINTEN3;
		p0inten3_field_t PxINTEN3_f;
	};
}GPIO_TypeDef;
#define GPIO0               ((GPIO_TypeDef *)(PORT_CTRL_BASEADDR))
#define GPIO1               ((GPIO_TypeDef *)(PORT_CTRL_BASEADDR + 0x40))
#define GPIO2               ((GPIO_TypeDef *)(PORT_CTRL_BASEADDR + 0x80))
#define GPIO3               ((GPIO_TypeDef *)(PORT_CTRL_BASEADDR + 0xC0))

#define RCC_AHBENR_UART0                 ((uint32_t)0x00000001)
#define RCC_AHBENR_UART1                 ((uint32_t)0x00000002)
#define RCC_AHBENR_LPUART                ((uint32_t)0x00000004)
#define RCC_AHBENR_I2C                   ((uint32_t)0x00000010)
#define RCC_AHBENR_SPI                   ((uint32_t)0x00000040)
#define RCC_AHBENR_BASETIME              ((uint32_t)0x00000100)
#define RCC_AHBENR_LPTIME                ((uint32_t)0x00000200)
#define RCC_AHBENR_ADVTIME               ((uint32_t)0x00000400)
#define RCC_AHBENR_PCA                   ((uint32_t)0x00004000)
#define RCC_AHBENR_WDT                   ((uint32_t)0x00008000)
#define RCC_AHBENR_ADC                   ((uint32_t)0x00010000)
#define RCC_AHBENR_VC                    ((uint32_t)0x00020000)
#define RCC_AHBENR_RTC                   ((uint32_t)0x00100000)
#define RCC_AHBENR_CLKTRIM               ((uint32_t)0x00200000)
#define RCC_AHBENR_BOOT                  ((uint32_t)0x00800000)
#define RCC_AHBENR_SYSTICK               ((uint32_t)0x01000000)
#define RCC_AHBENR_SWD                   ((uint32_t)0x02000000)
#define RCC_AHBENR_CRC                   ((uint32_t)0x04000000)
#define RCC_AHBENR_GPIO                  ((uint32_t)0x10000000)        /*!< GPIO clock enable */
#define RCC_AHBENR_FLASH                 ((uint32_t)0x80000000)


#define UART_SCON_RIEN                   ((uint32_t)0x00000001)
#define UART_SCON_TIEN                   ((uint32_t)0x00000002)
#define UART_SCON_RB8                    ((uint32_t)0x00000004)
#define UART_SCON_TB8                    ((uint32_t)0x00000008)
#define UART_SCON_REN                    ((uint32_t)0x00000010)
#define UART_SCON_SM2                    ((uint32_t)0x00000020)
#define UART_SCON_SM01_1                 ((uint32_t)0x00000040)
#define UART_SCON_SM01_2                 ((uint32_t)0x00000080)
#define UART_SCON_SM01_3                 ((uint32_t)0x000000B0)
#define UART_SCON_DBAUD                  ((uint32_t)0x00000200)


#ifdef USE_STDPERIPH_DRIVER
  //#include "stm32f0xx_conf.h"
#endif

/** @addtogroup Exported_macro
  * @{
  */
/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __HC32L0XX_H */


