#ifndef QUERY_H
#define QUERY_H
#include "common.h"

// Returns 0 on success; fills out with nearest reading to target_epoch_ms within tolerance_ms
int query_exact_or_nearest(const char* bin_path,
                           long target_epoch_ms,
                           long tolerance_ms,
                           bin_record_t* out,
                           long* diff_ms /* out: signed offset */);

#endif
