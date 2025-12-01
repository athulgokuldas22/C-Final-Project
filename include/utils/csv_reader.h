#ifndef CSV_READER_H
#define CSV_READER_H

#include <stddef.h>

size_t csv_read_floats(const char *path, float *buffer, size_t max_count);

#endif