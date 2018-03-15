/***
 * Copyright (c) 2018 Phoebe Systems, All rights reserved.
 * BSD licensed
 * @Summary: Queue datatype for the C language.
 * @Maintainer: CodeAlkemist(Matheus Xavier)
 */

#ifndef EURO_QUEUE
#define EURO_QUEUE
#include "vector.h"

#define QUEUE_INIT(que, size) que queue; queue_init(&que, size)
#define QUEUE_PUT(que, item) queue_put(&que, (void *))
#define QUEUE_POP(que, type) (type) queue_pop(&que)
#define QUEUE_INSPECT(que) (type) queue_inspect(&que)
#define QUEUE_FREE(que) queue_free(&que)

struct __eu_queue_base__{
    vector v;
    unsigned int size;
};

typedef struct __eu_queue_base__ queue;

void queue_init(queue *, int size);
void queue_put(queue *, void *);
void *queue_pop(queue *);
void *queue_inspect(queue *);
void queue_free(queue *);

#endif /* EURO_QUEUE */
