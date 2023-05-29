#include "monty.h"

/**
 * _write - Outputs to stderr
 * @s: String to print
 *
 * Return: Characters printed
 */
int _write(char *s)
{
	return (write(2, s, strlen(s)));
}
