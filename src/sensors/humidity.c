#include <stdio.h>
#include "humidity.h"
#include "../utils/random_gen.h"   


void humidity_init(HumiditySensor *sensor)
{
    if (!sensor) return;

    sensor->current = 0.0f;
    sensor->count = 0;

    for (size_t i = 0; i < 100; i++) {
        sensor->history[i] = 0.0f;
    }
}

void humidity_update(HumiditySensor *sensor)
{
    if (!sensor) return;

    sensor->current = random_float(30.0f, 70.0f);


    if (sensor->count < 100) {
        sensor->history[sensor->count++] = sensor->current;
    } else {

        for (size_t i = 1; i < 100; i++) {
            sensor->history[i - 1] = sensor->history[i];
        }
        sensor->history[99] = sensor->current;
    }
}

void humidity_print(const HumiditySensor *sensor)
{
    if (!sensor) return;
    printf("Humidity: %.1f%%\n", sensor->current);
}