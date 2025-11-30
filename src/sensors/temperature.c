#include <stdio.h>
#include "temperature.h"
#include "../utils/random_gen.h"   


void temperature_init(TemperatureSensor *sensor)
{
    if (!sensor) return;

    sensor->current = 0.0f;
    sensor->count = 0;

    for (size_t i = 0; i < 100; i++) {
        sensor->history[i] = 0.0f;
    }
}

void temperature_update(TemperatureSensor *sensor)
{
    if (!sensor) return;

    sensor->current = random_float(18.0f, 30.0f);


    if (sensor->count < 100) {
        sensor->history[sensor->count++] = sensor->current;
    } else {

        for (size_t i = 1; i < 100; i++) {
            sensor->history[i - 1] = sensor->history[i];
        }
        sensor->history[99] = sensor->current;
    }
}

void temperature_print(const TemperatureSensor *sensor)
{
    if (!sensor) return;
    printf("Temperature: %.2f °C\n", sensor->current);
}