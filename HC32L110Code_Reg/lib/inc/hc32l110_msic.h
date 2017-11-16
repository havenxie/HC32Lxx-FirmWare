#ifndef __HC32L110_MSIC_H
#define __HC32L110_MSIC_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "hc32lxx.h"

#define SysTick_CLKSource_HCLK_Div8    ((uint32_t)0xFFFFFFFB)
#define SysTick_CLKSource_HCLK         ((uint32_t)0x00000004)
#define IS_SYSTICK_CLK_SOURCE(SOURCE) (((SOURCE) == SysTick_CLKSource_HCLK) || \
                                       ((SOURCE) == SysTick_CLKSource_HCLK_Div8))
void SysTick_CLKSourceConfig(uint32_t SysTick_CLKSource);     
#ifdef __cplusplus
}
#endif

#endif /* __STM32F0XX_GPIO_H */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
