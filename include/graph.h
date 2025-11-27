#ifndef GRAPH_H
#define GRAPH_H

#include <stddef.h>

/*
    Draws an ASCII line graph of the values stored in 'data'
    - 'data'    : array of float values to graph
    - 'count'   : how many values are in the array
    - 'title'   : title to display above the graph (e.g., "Temperature (C)")

    Works for both:
    - in-memory history arrays
    - values loaded from CSV
*/

void graph_draw(const float *data, size_t count, const char *title);

#endif