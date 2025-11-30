#include <stdio.h>
#include "light_sensor.h"
#include "../utils/random_gen.h"   

void light_sensor_init(LightSensor *sensor)
{
    if (!sensor) return;

    sensor->current = 0;
    sensor->count = 0;

    for (size_t i = 0; i < 100; i++) {
        sensor->history[i] = 0.0f;
    }
}

void light_sensor_update(LightSensor *sensor)
{
    if (!sensor) return;

    sensor->current = random_int(0, 100);

    float value = (float)sensor->current;

    if (sensor->count < 100) {
        sensor->history[sensor->count++] = value;
    } else {
        for (size_t i = 1; i < 100; i++) {
            sensor->history[i - 1] = sensor->history[i];
        }
        sensor->history[99] = value;
    }
}


void light_sensor_print(const LightSensor *sensor)
{
    if (!sensor) return;
    printf("Ambient light: %d/100\n", sensor->current);
}

