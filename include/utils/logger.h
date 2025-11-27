#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>

/*
    Appends a single float value to a CSV file

    - 'path'  : path to the CSV file (e.g., DATA_DIR "/temperature.csv")
    - 'value' : the reading to append

*/

void logger_append_float(const char *path, float value);

#endif