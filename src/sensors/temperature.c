#include <stdio.h>
#include "temperature.h"
#include "../utils/random_gen.h"   // for random_float()

// Initializes the temperature sensor.
void temperature_init(TemperatureSensor *sensor)
{
    if (!sensor) return;

    sensor->current = 0.0f;
    sensor->count = 0;

    // Clear history
    for (size_t i = 0; i < 100; i++) {
        sensor->history[i] = 0.0f;
    }
}

// Updates the temperature value and stores it in the history buffer.
void temperature_update(TemperatureSensor *sensor)
{
    if (!sensor) return;

    // Simulate a realistic temperature range (18–30°C)
    sensor->current = random_float(18.0f, 30.0f);

    // Store in history
    if (sensor->count < 100) {
        sensor->history[sensor->count++] = sensor->current;
    } else {
        // Shift left if full (simple ring buffer logic)
        for (size_t i = 1; i < 100; i++) {
            sensor->history[i - 1] = sensor->history[i];
        }
        sensor->history[99] = sensor->current;
    }
}

// Prints the current temperature reading.
void temperature_print(const TemperatureSensor *sensor)
{
    if (!sensor) return;
    printf("Temperature: %.2f °C\n", sensor->current);
}