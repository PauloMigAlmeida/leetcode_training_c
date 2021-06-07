/*
 * stack.c
 *
 *  Created on: Jun 7, 2021
 *      Author: Paulo Miguel Almeida
 */

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 16
#define MAX_LOAD_FACTOR 0.75f

float get_load_factor(stack_t* p);
bool stack_is_empty(stack_t* p);

stack_t* stack_init(size_t type_size) {
	stack_t *stack = malloc(sizeof(stack_t));
	stack->size = INITIAL_SIZE;
	stack->pointer = -1;
	stack->data = malloc(type_size * INITIAL_SIZE);
	stack->type_size = type_size;
	return stack;
}

void stack_free(stack_t *p) {
	free(p->data);
	p->data = NULL;
	free(p);
	p = NULL;
}


void stack_push(stack_t* p, void* el) {
//	printf("get_load_factor(p): %f\n", get_load_factor(p));
	if(get_load_factor(p) > MAX_LOAD_FACTOR){
		p->size = p->size * 2;
		p->data = realloc(p->data, p->type_size * p->size);
	}
	p->pointer++;
	char* tmp_pointer = ((char*)p->data) + p->pointer * p->type_size;
	memcpy(tmp_pointer, el, p->type_size);
}

void* stack_peek(stack_t* p){
	if(stack_is_empty(p))
		return NULL;
	char* tmp_pointer = ((char*)p->data) + p->pointer * p->type_size;
	return tmp_pointer;
}

void* stack_pop(stack_t* p){
	if(stack_is_empty(p))
		return NULL;
	char* tmp_pointer = ((char*)p->data) + p->pointer * p->type_size;
	p->pointer--;
	return tmp_pointer;
}

bool stack_is_empty(stack_t* p){
	return p->pointer == -1;
}

float get_load_factor(stack_t* p) {
	return (float)(p->pointer+1)/p->size;
}
