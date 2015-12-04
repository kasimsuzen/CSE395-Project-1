#include <stdint.h>

#ifndef COMPASS_H
#define COMPASS_H

void * headingAngle(void * p);
void writeMagReg(uint8_t reg, uint8_t value);
void readBlock(uint8_t command, uint8_t size, uint8_t *data);
void readMAG(int * m);

#endif