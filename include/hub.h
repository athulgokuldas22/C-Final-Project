#ifndef HUB_H
#define HUB_H
#include <stdatomic.h>
#include "queue.h"
#include "log.h"

typedef struct {
  queue_t*     q;
  atomic_int*  running;   // C11 atomic stop flag
  const char*  out_dir;   // e.g., "logs"
} hub_params_t;

void* hub_thread(void* arg);

#endif
