#ifndef __NOISEN_H
#define __NOISEN_H

extern uint8_t usart2_rec_buf[10];
extern uint8_t usart2_rec_flag;

uint32_t get_noise(void);

#endif
