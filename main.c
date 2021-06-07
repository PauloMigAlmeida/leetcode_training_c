/*
 * main.c
 *
 *  Created on: Jun 7, 2021
 *      Author: parallels
 */

#include <stdlib.h>
#include <assert.h>
#include "stack.h"

int main(void){
	stack_t* stack = stack_init(sizeof(int));

	int content = 1;
	stack_push(stack, &content);

	content = 2;
	stack_push(stack, &content);

	content = 10;
	stack_push(stack, &content);

	int* pop = stack_pop(stack);
	assert(*pop == 10);

	pop = stack_pop(stack);
	assert(*pop == 2);

	pop = stack_pop(stack);
	assert(*pop == 1);

	stack_free(stack);
	return EXIT_SUCCESS;
}
