#include <stdio.h>
#include "logger.h"

void logger_append_float(const char *path, float value)
{
    if (!path) return;

    FILE *file = fopen(path, "a");
    if (!file) {
        printf("Error: could not open %s for writing.\n", path);
        return;
    }

    fprintf(file, "%.3f\n", value);
    fclose(file);
}
