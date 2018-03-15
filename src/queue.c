/***
 * Copyright (c) 2018 Phoebe Systems, All rights reserved.
 * BSD licensed
 * @Summary: Queue datatype for the C language.
 * @Maintainer: CodeAlkemist(Matheus Xavier)
 */

#include <stdlib.h>
#include "queue.h"

void queue_init(queue *q, int size){
    vector v;
    VECTOR_INIT(v, size);
    q->v = v;
    q->size = 0;
    VECTOR_FREE(v);
}

void queue_put(queue *q, void *item){
    VECTOR_ADD(q->v, item);
}

void *queue_pop(queue *q){
    void *temp = vector_get(&q->v, 0);
    vector_delete(&q->v, 0);
    return temp;
}

void *queue_inspect(queue *q){
    return vector_get(&q->v, 0);
}

void queue_free(queue *q){
    VECTOR_FREE(q->v);
}