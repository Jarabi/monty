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
 * stack_nop - To display contents of a stack
 * @stack: Pointer to pointer to head of stack
 * @line_num: Line number from bytecode file
 */
void stack_nop(stack_t **stack, unsigned int line_num)
{
	stack_t *current;

	(void) line_num;
	if (stack == NULL)
		exit(EXIT_FAILURE);

	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
