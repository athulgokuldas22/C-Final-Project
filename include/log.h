#ifndef LOG_H
#define LOG_H
#include <stdio.h>
#include "common.h"

FILE* open_sensor_bin(const char* dir, device_type_t t, int write_header,
                      const bin_header_t* hdr_in);
int   write_sensor_header(FILE* f, const bin_header_t* hdr);
int   read_sensor_header(FILE* f, bin_header_t* hdr_out);
int   write_sensor_record(FILE* f, const bin_record_t* rec);
const char* sensor_filename(device_type_t t); // "therm.bin", etc.

#endif
