/***
 * Copyright (c) 2018 Phoebe Systems, All rights reserved.
 * BSD licensed
 * @Summary: Vector datatype for the C language, used as basis in many other datatypes on this project.
 * @Maintainer: CodeAlkemist(Matheus Xavier)
 */

#ifndef EURO_VECTOR
#define EURO_VECTOR

/***
 * To change the default size override this size macro by setting VECTOR_SIZE_CONSTANT_OVERRIDE
 */
#ifndef VECT_SIZE_CONST_OVRD
#define SIZE 10
#endif

#ifndef VECT_RESIZE_FACTOR_CONST_OVRD
#define RESIZE_FACTOR 2
#endif

#define VECTOR_INIT(vect, size) vector vect; vector_init(&vect, size)
#define VECTOR_ADD(vect, item) vector_add(&vect, (void *) item)
#define VECTOR_SET(vect, id, item) vector_set(&vect, id, (void *) item)
#define VECTOR_GET(vect, type, id) (type) vector_get(&vect, id)
#define VECTOR_DELETE(vect, id) vector_delete(&vect, id)
#define VECTOR_TOTAL(vect) vector_total(&vect)
#define VECTOR_FREE(vect) vector_free(&vect)

struct __eu_vect_base__{
    unsigned long int size;
    unsigned long int capacity;
    unsigned long int position;
    void **contents;
};

typedef struct __eu_vect_base__ vector;
/***
 * Set size to -1 to use the SIZE macro for sizing
 */
void vector_init(vector *, int);
int vector_total(vector *);
void vector_add(vector *, void *);
void vector_set(vector *, int, void *);
void *vector_get(vector *, int);
void vector_delete(vector *, int);
void vector_free(vector *);

#endif /*EURO_VECTOR*/
