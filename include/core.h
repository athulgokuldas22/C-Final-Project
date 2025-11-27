#ifndef CORE_H
#define CORE_H

#include <pthread.h>
#include "sensors/temperature.h"
#include "sensors/humidity.h"
#include "sensors/light_sensor.h"
#include "sensors/motion.h"
#include "sensors/door.h"

typdef_struct
{
    TemperatureSensor temperature;
    HumiditySensor humidity;
    LightSensor light;
    MotionSensor motion;
    DoorSensor door;

    pthread_t temperature_thread;
    pthread_t humidity_thread;
    pthread_t light_thread;
    pthread_t motion_thread;
    pthread_t door_thread;

    int running;
} SmartHome;

void smart_home_init(SmartHome *home);

void smart_home_start(SmartHome *home);

void smart_home_shutdown(SmartHome *home);

#endif