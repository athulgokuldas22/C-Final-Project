#include <stdio.h>
#include "door.h"
#include "../utils/random_gen.h"   
void door_init(DoorSensor *door)
{
    if (!door) return;
    door->locked = 1;  
}

void door_update(DoorSensor *door)
{
    if (!door) return;

    door->locked = random_int(0, 1);
}

void door_print(const DoorSensor *door)
{
    if (!door) return;

    if (door->locked)
        printf("Door: locked\n");
    else
        printf("Door: unlocked\n");
}

