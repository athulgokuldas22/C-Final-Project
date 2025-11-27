#ifndef HUMIDITY_H
#define HUMIDITY_H

#include <stddef.h>

typdef_struct
{
    float current;
    float history[100];
    size_t count;
    
}HumiditySensor;

void humidity_init(HumiditySensor *sensor);

void humidity_update(HumiditySensor *sensor);

void humidity_print(const HumiditySensor *sensor);

#endif