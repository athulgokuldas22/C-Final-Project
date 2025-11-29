#include <stdio.h>
#include <unistd.h>
#include "core.h"
#include "utils/logger.h"



static void *temperature_thread_fn(void *arg)
{
    SmartHome *home = (SmartHome *)arg;
    while (home -> running)
    {
        temperature_update(&home -> temperature);
        logger_append_float(DATA_DIR "/temperature.csv", home -> temperature.current);
        sleep(1);
    }
    return NULL;
}

static void *humidity_thread_fn(void *arg)
{
    SmartHome *home = (SmartHome *)arg;
    while (home -> running)
    {
        humidity_update(&home -> humidity);
        logger_append_float(DATA_DIR "/humidity.csv", home -> humidity.current);
        sleep(1);
    }
    return NULL;
}
static void *light_thread_fn(void *arg)
{
    SmartHome *home = (SmartHome *)arg;
    while (home -> running)
    {
        light_sensor_update(&home -> light);
        logger_append_float(DATA_DIR "/light.csv", (float)home -> light.current);
        sleep(1);
    }
    return NULL;
}
static void *motion_thread_fn(void *arg)
{
    SmartHome *home = (SmartHome *)arg;
    while (home -> running)
    {
        motion_update(&home -> motion);
        logger_append_float(DATA_DIR "/motion.csv", (float)home -> motion.detected);
        sleep(1);
    }
    return NULL;
}
static void *door_thread_fn(void *arg)
{
    SmartHome *home = (SmartHome *)arg;
    while (home -> running)
    {
        door_update(&home -> door);
        logger_append_float(DATA_DIR "/door.csv", home -> door.locked);
        sleep(2);
    }
    return NULL;
}
void smart_home_init(SmartHome *home)
{
    if(!home) return;

    temperature_init(&home -> temperature);
    humidity_init(&home -> humidity);
    light_sensor_init(&home -> light);
    motion_init(&home -> motion);
    door_init(&home -> door);

    home -> running = 1;
}
void smart_home_start(SmartHome *home)
{
    if (!home) return;

    pthread_create(&home->temperature_thread, NULL, temperature_thread_fn, home);
    pthread_create(&home->humidity_thread,    NULL, humidity_thread_fn,    home);
    pthread_create(&home->light_thread,       NULL, light_thread_fn,       home);
    pthread_create(&home->motion_thread,      NULL, motion_thread_fn,      home);
    pthread_create(&home->door_thread,        NULL, door_thread_fn,        home);
}

void smart_home_shutdown(SmartHome *home)
{
    if (!home) return;

    home->running = 0;
    
    pthread_join(home->temperature_thread, NULL);
    pthread_join(home->humidity_thread,    NULL);
    pthread_join(home->light_thread,       NULL);
    pthread_join(home->motion_thread,      NULL);
    pthread_join(home->door_thread,        NULL);

    printf("All sensor threads stopped.\n");
}
