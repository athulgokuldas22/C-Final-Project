#ifndef DOOR_H
#define DOOR_H


typedef_struct
{
    int locked;

}DoorSensor;

void door_init(DoorSensor *door);

void door_update(DoorSensor *door);

void door_print(const DoorSensor *door);

#endif