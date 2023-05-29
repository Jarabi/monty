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
