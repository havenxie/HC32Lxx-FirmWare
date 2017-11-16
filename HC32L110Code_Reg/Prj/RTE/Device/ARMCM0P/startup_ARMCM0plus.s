;/**************************************************************************//**
; * @file     startup_ARMCM0plus.s
; * @brief    CMSIS Core Device Startup File for
; *           ARMCM0plus Device Series
; * @version  V1.01
; * @date     23. November 2012
; *
; * @note
; *
; ******************************************************************************/
;/* Copyright (c) 2012 ARM LIMITED
;
;   All rights reserved.
;   Redistribution and use in source and binary forms, with or without
;   modification, are permitted provided that the following conditions are met:
;   - Redistributions of source code must retain the above copyright
;     notice, this list of conditions and the following disclaimer.
;   - Redistributions in binary form must reproduce the above copyright
;     notice, this list of conditions and the following disclaimer in the
;     documentation and/or other materials provided with the distribution.
;   - Neither the name of ARM nor the names of its contributors may be used
;     to endorse or promote products derived from this software without
;     specific prior written permission.
;   *
;   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
;   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
;   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
;   ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS AND CONTRIBUTORS BE
;   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
;   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
;   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
;   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
;   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
;   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
;   POSSIBILITY OF SUCH DAMAGE.
;   ---------------------------------------------------------------------------*/
;/*
;//-------- <<< Use Configuration Wizard in Context Menu >>> ------------------
;*/


; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Stack_Size      EQU     0x00000200

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Heap_Size       EQU     0x00000000

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit


                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset

                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size

__Vectors       DCD     __initial_sp              ; Top of Stack
                DCD     Reset_Handler             ; Reset Handler
                DCD     NMI_Handler               ; NMI Handler
                DCD     HardFault_Handler         ; Hard Fault Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     SVC_Handler               ; SVCall Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     PendSV_Handler            ; PendSV Handler
                DCD     SysTick_Handler           ; SysTick Handler

                ; External Interrupts
                DCD     GPIO_P0_IRQHandler                ;  0:  GPIO PO
                DCD     GPIO_P1_IRQHandler                ;  1:  GPIO P1
                DCD     GPIO_P2_IRQHandler                ;  2:  GPIO P2
                DCD     GPIO_P3_IRQHandler                ;  3:  GPIO P3
                DCD     0                                 ;  4:  GPIO P4, not use
                DCD     0                                 ;  5:  GPIO P5, not use
                DCD     UART0_IRQHandler                  ;  6:  UART0 
                DCD     UART1_IRQHandler                  ;  7:  UART1 					
                DCD     UART2_IRQHandler                  ;  8:  UART2
                DCD     0                                 ;  9:  UART3, not use
                DCD     SPI_IRQHandler                    ; 10:  SPI0
                DCD     0                                 ; 11:  SPI1, not use
                DCD     I2C_IRQHandler                    ; 12:  I2C0
                DCD     0                                 ; 13:  I2C1, not use
                DCD     BASE_TIMER0_IRQHandler            ; 14:  Base Timer0
                DCD     BASE_TIMER1_IRQHandler            ; 15:  Base Timer1
                DCD     BASE_TIMER2_IRQHandler            ; 16:  Base Timer2
                DCD     BASE_TIMER3_IRQHandler            ; 17:  Base Timer3
                DCD     ADV_TIMER0_IRQHandler             ; 18:  Advance Timer3
                DCD     ADV_TIMER1_IRQHandler             ; 19:  Advance Timer4
                DCD     ADV_TIMER2_IRQHandler             ; 20:  Advance Timer5
				DCD     PCA_IRQHandler                    ; 21:  PCA			
				DCD     WDT_IRQHandler                    ; 22:  WDT
				DCD     RTC_IRQHandler                    ; 23:  RTC	
				DCD     ADC_IRQHandler                    ; 24:  ADC
				DCD     0                                 ; 25:  DAC, not use    
				DCD     VC0_IRQHandler                    ; 26:  VC0
				DCD     VC1_IRQHandler                    ; 27:  VC1	
				DCD     LVD_IRQHandler                    ; 28:  LVD
				DCD     0                                 ; 29:  LCD, not use		
				DCD     RAM_FLASH_FAULT_IRQHandler        ; 30:  ram/flash fault
				DCD     CLOCK_TRIM_IRQHandler             ; 31:  clock trim

__Vectors_End

__Vectors_Size  EQU     __Vectors_End - __Vectors

                AREA    |.text|, CODE, READONLY


; Reset Handler

Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]
                IMPORT  SystemInit
                IMPORT  __main
				;IMPORT  main
                ;LDR     R0, =SystemInit
                ;BLX     R0
                LDR     R0, =__main
				;LDR     R0, =main
                BX      R0
                ENDP


; Dummy Exception Handlers (infinite loops which can be modified)

NMI_Handler     PROC
                EXPORT  NMI_Handler               [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler         [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler               [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler            [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler           [WEAK]
                B       .
                ENDP

Default_Handler PROC

                EXPORT  GPIO_P0_IRQHandler        [WEAK]
                EXPORT  GPIO_P1_IRQHandler        [WEAK]
                EXPORT  GPIO_P2_IRQHandler        [WEAK]
                EXPORT  GPIO_P3_IRQHandler        [WEAK]
                EXPORT  UART0_IRQHandler          [WEAK]
                EXPORT  UART1_IRQHandler          [WEAK]
                EXPORT  UART2_IRQHandler          [WEAK]
                EXPORT  SPI_IRQHandler            [WEAK]
                EXPORT  I2C_IRQHandler            [WEAK]
                EXPORT  BASE_TIMER0_IRQHandler    [WEAK]
                EXPORT  BASE_TIMER1_IRQHandler    [WEAK]
                EXPORT  BASE_TIMER2_IRQHandler    [WEAK]
                EXPORT  BASE_TIMER3_IRQHandler    [WEAK]
                EXPORT  ADV_TIMER0_IRQHandler     [WEAK]
                EXPORT  ADV_TIMER1_IRQHandler     [WEAK]
                EXPORT  ADV_TIMER2_IRQHandler     [WEAK]
                EXPORT  PCA_IRQHandler            [WEAK]
                EXPORT  WDT_IRQHandler            [WEAK]
                EXPORT  RTC_IRQHandler	          [WEAK]
                EXPORT  ADC_IRQHandler            [WEAK]
                EXPORT  DAC_IRQHandler            [WEAK]
                EXPORT  VC0_IRQHandler            [WEAK]
                EXPORT  VC1_IRQHandler            [WEAK]
                EXPORT  LVD_IRQHandler            [WEAK]
                EXPORT  LCD_IRQHandler	          [WEAK]
                EXPORT  RAM_FLASH_FAULT_IRQHandler[WEAK]
                EXPORT  CLOCK_TRIM_IRQHandler     [WEAK]

GPIO_P0_IRQHandler        
GPIO_P1_IRQHandler        
GPIO_P2_IRQHandler        
GPIO_P3_IRQHandler        
UART0_IRQHandler          
UART1_IRQHandler          
UART2_IRQHandler          
SPI_IRQHandler            
I2C_IRQHandler            
BASE_TIMER0_IRQHandler    
BASE_TIMER1_IRQHandler    
BASE_TIMER2_IRQHandler    
BASE_TIMER3_IRQHandler    
ADV_TIMER0_IRQHandler     
ADV_TIMER1_IRQHandler     
ADV_TIMER2_IRQHandler     
PCA_IRQHandler 			      
WDT_IRQHandler            
RTC_IRQHandler	          
ADC_IRQHandler            
DAC_IRQHandler            
VC0_IRQHandler            
VC1_IRQHandler            
LVD_IRQHandler            
LCD_IRQHandler	          
RAM_FLASH_FAULT_IRQHandler
CLOCK_TRIM_IRQHandler    
                B       .

                ENDP


                ALIGN


; User Initial Stack & Heap

                IF      :DEF:__MICROLIB

                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit

                ELSE

                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap

__user_initial_stackheap PROC
                LDR     R0, =  Heap_Mem
                LDR     R1, =(Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem +  Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR
                ENDP

                ALIGN

                ENDIF


                END
