#include "monty.h"

/**
 * main - Entry point
 * @ac: Number of arguments
 * @av: Array of arguments passed
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file.\n");
		exit(EXIT_FAILURE);
	}
	read_file(av[1]);
	return (0);
}
