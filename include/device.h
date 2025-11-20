#ifndef DEVICE_H
#define DEVICE_H
#include <stdatomic.h>
#include "queue.h"

typedef struct {
  device_type_t type;
  int           id;
  double        rate_hz;     // per-sensor rate
  queue_t*      q;
  atomic_int*   running;     // C11 atomic stop flag
} device_params_t;

void* device_thread(void* arg);

#endif
