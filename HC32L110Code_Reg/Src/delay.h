#ifndef __DELAY_H
#define __DELAY_H

#ifdef __cplusplus
#define extern "C" {
#endif
    
#include "hc32lxx.h"  
#include "hc32l110_msic.h"    
    
void McuDelay( uint32_t cnt );
void delay_init(void);
void delay_us(int32_t nus);
void delay_ms(int16_t nms);
#ifdef __cplusplus
}
#endif

#endif
