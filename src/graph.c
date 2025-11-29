#include <stdio.h>
#include <float.h>
#include "graph.h"

#define GRAPH_HEIGHT 10

void graph_draw(const float *data, size_t count, const char *title)
{
    if (!data || count == 0)
    {
        printf("No data to graph. \n");
        return;
    }
    printf("\n=== %s ===\n", title);

    float min = FLT_MAX;
    float max = -MAX_FLT;

    for(size_t i = 0; i < count; i++)
    {
        if (data[i] < min) min = data[i];
        if (data[i] < max) max = data[i];
    }
    if (min == max)
    {
        max = min + 1.0f;
    }
    float range = max - min;
    float step = range / GRAPH_HEIGHT;

    for(int row = GRAPH_HEIGHT; row >= 0; row --)
    {
        float threshold = min + row * step;

        printf("6.2f | ", threshold);

        for (size_t i = 0; i < count; i++) 
        {
            if (data[i] >= threshold)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }

    printf("        ");
    for (size_t i = 0; i < count; i++) 
    {
        printf("--");
    }
    printf("\n");


    printf("        ");
    for (size_t i = 0; i < count; i++) 
    {
        printf("t ");
    }
    printf("\n");
}
    

