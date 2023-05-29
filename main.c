#include "monty.h"
stack_t *head = NULL;

/**
 * main - Entry point
 * @ac: Argument count
 * @av: Array of 0 or more arguments
 *
 * Return: Always 0
 */
int main(int ac, char **av)
{
	if (ac != 2)
		_err(0);

	/* Read file contents */
	openfile(av[1]);
	return (0);
}

/**
 * create_node - Responsible for creating new node
 * @val: Value to include in new node
 *
 * Return: Pointer to new node
 */
stack_t *create_node(int val)
{
	stack_t *new_node;

	new_node = malloc(sizeof(size_t));

	if (new_node == NULL)
		_err(4);
	new_node->n = val;
	new_node->next = NULL;
	new_node->prev = NULL;

	return (new_node);
}
