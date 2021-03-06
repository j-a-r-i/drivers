#ifndef __DS18B20_H
#define __DS18B20_H

#include <stdint.h>
    
#define ERR_NONE      0
#define ERR_NOT_FOUND 1

#define DS1820_ROM_SIZE 8

//
// http://datasheets.maximintegrated.com/en/ds/DS18S20.pdf
// http://datasheets.maximintegrated.com/en/ds/DS18B20.pdf

#define DS1820_CMD_CONVERT           0x44
#define DS1820_CMD_WRITE_SCRATCHPAD  0x4E
#define DS1820_CMD_READ_SCRATCHPAD   0xBE
#define DS1820_CMD_MATCH_ROM         0x55
#define DS1820_CMD_SKIP_ROM          0xCC
#define DS1820_CMD_SEARCH            0xF0


typedef struct {
    int8_t  lastDiscrepancy;
    int8_t  lastFamilyDiscrepancy;
    int8_t  lastDeviceFlag;
} ds1820_search_t;

extern void ds1820_init(uint8_t pin);
extern void ds1820_write(uint8_t pin, uint8_t data);
extern uint8_t ds1820_measure(uint8_t pin);
extern uint8_t ds1820_read_temp(uint8_t pin);
extern uint8_t ds1820_search(uint8_t pin, ds1820_search_t *data, uint8_t *romNo);

#endif
