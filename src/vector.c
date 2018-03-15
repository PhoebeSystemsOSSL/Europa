/***
 * Copyright (c) 2018 Phoebe Systems, All rights reserved.
 * BSD licensed
 * @Summary: Vector datatype for the C language, used as basis in many other datatypes on this project.
 * @Maintainer: CodeAlkemist(Matheus Xavier)
 */
#include <stdlib.h>
#include "vector.h"
#ifdef DEBUG_ON
#include <stdio.h>
#endif


void vector_init(vector *v, int size){
    v->capacity = size < 0 ? SIZE:(unsigned int)size;
    v->size = 0;
    v->position = 0;
    v->contents = malloc(v->capacity);
}

int vector_total(vector *v){
	return v->size;
}

static void vector_resize(vector *v, unsigned int capacity){
#ifdef DEBUG_ON
	printf("vector resized: %d to %d\n", v->capacity, capacity);
#endif
	void **contents = realloc(v->contents, sizeof(void *) * capacity);
	if(contents){
		v->contents = contents;
		v->capacity = capacity;
	}
}

void vector_add(vector *v, void *content){
	if(v->capacity == v->size)
		vector_resize(v, v->capacity * RESIZE_FACTOR);
	v->contents[v->size++] = content;
}

void vector_set(vector *v, int index, void *content){
	if(index >= 0 && index < v->size){
		v->contents[index] = content;
	}else if(index < 0 && (index * -1) < v->size){
		v->contents[v->size + index] = content;
	}else
		return;
}

void *vector_get(vector *v, int index){
	if(index >= 0 && index < v->size){
		return v->contents[index];
	}else if(index < 0 && (index * -1) < v->size){
		return v->contents[v->size + index];
	}else
		return NULL;
}

void vector_delete(vector *v, int index){
	if(index >= v->size)
		return;
	if(index < 0){
		v->contents[v->size + index] = NULL;
		for(int i = v->size + index; i > v->size + 1; i--){
			v->contents[i] = v->contents[i + 1];
			v->contents[i + 1] = NULL;
		}
	}else{
		v->contents[index] = NULL;
		for(int i = index; i < v->size - 1; i++){
			v->contents[i] = v->contents[i + 1];
			v->contents[i + 1] = NULL;
		}
	}
	v->size--;
	if(v->size > 0 && v->size == v->capacity / 2 * RESIZE_FACTOR)
		vector_resize(v, v->capacity / RESIZE_FACTOR);
}

void vector_free(vector *v){
	free(v->contents);
}
