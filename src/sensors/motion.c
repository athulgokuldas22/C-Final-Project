#include <stdio.h>
#include "motion.h"
#include "../utils/random_gen.h"   

void motion_init(MotionSensor *sensor)
{
    if (!sensor) return;
    sensor->detected = 0;
}

void motion_update(MotionSensor *sensor)
{
    if (!sensor) return;
    sensor->detected = random_int(0, 1);
}

void motion_print(const MotionSensor *sensor)
{
    if (!sensor) return;

    if (sensor->detected)
        printf("Motion: detected\n");
    else
        printf("Motion: no motion\n");
}

