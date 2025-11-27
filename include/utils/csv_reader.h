#ifndef CSV_READER_H
#define CSV_READER_H

#include <stddef.h>

/*
    Loads float values from a CSV file into the provided buffer.
    - 'path'      : path to the CSV file (e.g., DATA_DIR "/temperature.csv")
    - 'buffer'    : array where the values will be stored
    - 'max_count' : maximum number of values that can fit in the buffer

    Returns the number of values actually read.
*/

size_t csv_read_floats(const char *path, float *buffer, size_t max_count);

#endif