#ifndef PLOT_H
#define PLOT_H
#include <stddef.h>
#include "common.h"

// Load all bin records from a sensor file.
// Returns number of records loaded (>=0), or -1 on error.
// Allocates arrays (out_ts_sec, out_vals) that caller must free.
long load_records(const char* bin_path, double** out_ts_sec, double** out_vals);

// Write a simple line plot to PPM file (RGB, P6).
// ts_sec[]: seconds (epoch or relative), vals[]: y-values
// n: number of points
// y_min/y_max: if y_min>=y_max, auto-scale is used
int write_ppm_lineplot(const char* out_path,
                       const double* ts_sec, const double* vals, size_t n,
                       int width, int height,
                       double y_min, double y_max,
                       const char* title);

#endif
