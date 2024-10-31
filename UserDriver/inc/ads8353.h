#ifndef __ads8353_H__
#define __ads8353_H__

#include <stdint.h>

void ads8353_init(void);
void ads8353_write_reg(uint8_t address, uint8_t val);
uint16_t ads8353_read_adc(void);

#endif //__ads8353_H__