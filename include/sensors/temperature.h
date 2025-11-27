#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <stddef.h>


typdef_struct
{
    float current;
    float history[100];
    size_t count;

}TemperatureSensor;

void temperature_init(TemperatureSensor *sensor);

void temperature_update(TemperatureSensor *sensor);

void temperature_print(const TemperatureSensor *sensor);

#endif