#include <stdio.h>
#include "csv_reader.h"

// Reads floats from a CSV file (one value per line).
// Returns how many values were actually read.
size_t csv_read_floats(const char *path, float *buffer, size_t max_count)
{
    if (!path || !buffer || max_count == 0)
        return 0;

    FILE *file = fopen(path, "r");
    if (!file) {
        printf("Error: could not open %s for reading.\n", path);
        return 0;
    }

    size_t count = 0;
    while (count < max_count && fscanf(file, "%f", &buffer[count]) == 1) {
        count++;
    }

    fclose(file);
    return count;
}
