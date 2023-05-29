#include "monty.h"

/**
 * _err - Error handling
 * @status: Error status
 */
void _err(int status, ...)
{
	va_list args;
	int line_num;
	char *opcode;

	va_start(args, status);
	switch (status)
	{
		case 0:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 1:
			fprintf(stderr, "USAGE: monty file %s\n", va_arg(args, char *));
			break;
		case 2:
			line_num = va_arg(args, int);
			opcode = va_arg(args, char*);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
			break;
		case 3:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(args, int));
			break;
		case 6:
			fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(args, int));
			break;
	}
	va_end(args);
	exit(EXIT_FAILURE);
}
