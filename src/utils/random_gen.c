#include <stdlib.h>
#include <time.h>
#include "random_gen.h"


void random_init(void)
{
    srand((unsigned int)time(NULL));
}

float random_float(float min, float max)
{
    float scale = rand() / (float)RAND_MAX; 
    return min + scale * (max - min);
}


int random_int(int min, int max)
{
    if (max < min) return min;  
    return min + rand() % (max - min + 1);
}