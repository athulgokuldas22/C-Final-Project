#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>
#include <stddef.h>
#include "common.h"

typedef struct queue queue_t;

queue_t* queue_create(size_t capacity);
void     queue_destroy(queue_t* q);
bool     queue_push(queue_t* q, const message_t* m); // false if shutting down
bool     queue_pop(queue_t* q, message_t* out);      // false if shutdown & empty
void     queue_shutdown(queue_t* q);

#endif
