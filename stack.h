/*
 * stack.h
 *
 *  Created on: Jun 7, 2021
 *      Author: parallels
 */

#ifndef STACK_H_
#define STACK_H_

#include <stddef.h>
#include <stdbool.h>

typedef struct {
	unsigned int size;
	int pointer;
	void* data;
	size_t type_size;
} stack_t;

stack_t* stack_init(size_t type_size);
void stack_free(stack_t* p);
void stack_push(stack_t* p, void* el);
void* stack_pop(stack_t* p);
void* stack_peek(stack_t* p);
bool stack_is_empty(stack_t* p);

#endif /* STACK_H_ */
