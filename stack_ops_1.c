#include "monty.h"

/**
 * stack_add - Adds the top two elements of the stack
 * @stack: Pointer to pointer to head of stack
 * @line_num: Line number from bytecode file
 */
void stack_add(stack_t **stack, unsigned int line_num)
{
	int sum = 0;

	if (stack == NULL  || *stack == NULL || (*stack)->next == NULL)
		_err(8, line_num);

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * stack_nop - Does nothing.
 * @stack: Pointer to pointer to head of stack
 * @line_num: Line number from bytecode file
 */
void stack_nop(stack_t **stack, unsigned int line_num)
{
	(void)stack, (void)line_num;
}
