#include "monty.h"

/**
 * stack_push - Responsible for pushing new node into stack
 * @new_node: Node to push
 * @line_num: Line number from bytecode file
 */
void stack_push(stack_t **new_node, unsigned int line_num)
{
	stack_t *current;

	(void) line_num;
	if (new_node == NULL  || *new_node == NULL)
		exit(EXIT_FAILURE);

	if (head == NULL)
	{
		head = *new_node;
		return;
	}

	current = head;
	head = *new_node;
	head->next = current;
	current->prev = head;
}

/**
 * stack_display - To display contents of a stack
 * @stack: Pointer to pointer to head of stack
 * @line_num: Line number from bytecode file
 */
void stack_display(stack_t **stack, unsigned int line_num)
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

/**
 * stack_top - Prints value at the top of the stack
 * @stack: Pointer to pointer to head of stack
 * @line_num: Line number from bytecode file
 */
void stack_top(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
		_err(5, line_num);
	printf("%d\n", (*stack)->n);
}

/**
 * stack_pop - Removes the top element of the stack
 * @stack: Pointer to pointer to head of stack
 * @line_num: Line number from bytecode file
 */
void stack_pop(stack_t **stack, unsigned int line_num)
{
	stack_t *top;

	if (stack == NULL || *stack == NULL)
		_err(6, line_num);
	top = *stack;
	*stack = top->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(top);
}

/**
 * stack_swap - Swaps the top two elements of the stack
 * @stack: Pointer to pointer to head of stack
 * @line_num: Line number from bytecode file
 */
void stack_swap(stack_t **stack, unsigned int line_num)
{
	stack_t *current;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		_err(7, line_num);

	current = (*stack)->next;
	(*stack)->next = current->next;

	if (current->next != NULL)
		current->next->prev = *stack;
	current->next = *stack;
	(*stack)->prev = current;
	current->prev = NULL;
	*stack = current;
}
