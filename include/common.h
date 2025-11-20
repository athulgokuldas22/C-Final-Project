#ifndef COMMON_H
#define COMMON_H
#include <time.h>

typedef enum { DEV_THERM, DEV_LIGHT, DEV_FAN, DEV_DOOR, DEV_SMOKE, DEV_COUNT } device_type_t;
typedef enum { MSG_TELEMETRY, MSG_EVENT, MSG_ALERT } msg_type_t;

#define MSG_TEXT_MAX 64

typedef struct {
  msg_type_t    type;
  device_type_t src;
  double        value;          // numeric reading (or 0/1)
  char          text[MSG_TEXT_MAX]; // free-form (e.g., "door opened")
  struct timespec ts;           // CLOCK_MONOTONIC
} message_t;

// Binary log format (fixed-size record) suggestion:
typedef struct {
  long   epoch_ms;  // write in hub using CLOCK_REALTIME (or converted from MONOTONIC + t0)
  double value;
  char   text[MSG_TEXT_MAX]; // optional metadata
} bin_record_t;

typedef struct {
  long   t0_epoch_ms;  // first sample wallclock (ms)
  long   period_ms;    // sampling period for this sensor
  int    record_size;  // sizeof(bin_record_t)
  int    version;      // format version (e.g., 1)
} bin_header_t;

#endif
