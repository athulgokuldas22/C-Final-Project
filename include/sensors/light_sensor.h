#ifndef LIGHT_SENSOR_H
#define LIGHT_SENSOR_H

#include <stddef.h>


typedef_struct
{
    int current;
    float history[100];
    size_t count;

}LightSensor;


void light_sensor_init(LightSensor *sensor);

void light_sensor_update(LightSensor *sensor);

void light_sensor_print(const LightSensor *sensor);

#endif