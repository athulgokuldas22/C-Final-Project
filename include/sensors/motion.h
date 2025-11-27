#ifndef MOTION_H
#define MOTION_H


typedef_struct
{
    int detected;
    
}MotionSensor;

void motion_init(MotionSensor *sensor);

void motion_update(MotionSensor *sensor);

void motion_print(const MotionSensor *sensor);

#endif