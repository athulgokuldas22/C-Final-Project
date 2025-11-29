#include <stdio.h>
#include "humidity.h"
#include "../utils/random_gen.h"   // for random_float()

// Initializes the humidity sensor.
void humidity_init(HumiditySensor *sensor)
{
    if (!sensor) return;

    sensor->current = 0.0f;
    sensor->count = 0;

    // Clear history
    for (size_t i = 0; i < 100; i++) {
        sensor->history[i] = 0.0f;
    }
}

// Updates the humidity value and stores it in the history buffer.
void humidity_update(HumiditySensor *sensor)
{
    if (!sensor) return;

    // Simulate a realistic humidity range (30–70%)
    sensor->current = random_float(30.0f, 70.0f);

    // Store in history
    if (sensor->count < 100) {
        sensor->history[sensor->count++] = sensor->current;
    } else {
        // Shift left when full
        for (size_t i = 1; i < 100; i++) {
            sensor->history[i - 1] = sensor->history[i];
        }
        sensor->history[99] = sensor->current;
    }
}

// Prints the current humidity value.
void humidity_print(const HumiditySensor *sensor)
{
    if (!sensor) return;
    printf("Humidity: %.1f%%\n", sensor->current);
}