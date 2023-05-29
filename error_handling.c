#include "monty.h"

/**
 * _err - Handles error status
 * @status: Error status
 */
void _err(int status, ...)
{
	va_list args;
	char *msg;
	size_t msg_size = 100;

	va_start(args, status);
	msg = malloc(msg_size);

	if (msg == NULL)
	{
		_write("Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	print_err(status, args, msg, msg_size);
	free(msg);
	exit(EXIT_FAILURE);
}

/**
 * print_err - Prints error message to stdout
 * @status: Error status
 * @args: Error status arguments
 * @msg: Error message
 * @msg_size: Error message size
 */
void print_err(int status, va_list args, char *msg, size_t msg_size)
{
	char line_num_str[20];

	switch (status)
	{
		case 0:
			strncpy(msg, "USAGE: monty file", msg_size);
			break;
		case 1:
			strncpy(msg, "Error: Can't open file ", msg_size);
			strncat(msg, va_arg(args, char *), msg_size - strlen(msg) - 1);
			break;
		case 2:
			/* strncat expects a string, not an int. Converting */
			/* line number <int> to string representation. */
			sprintf(line_num_str, "%d", va_arg(args, int));
			strncpy(msg, "L", msg_size);
			strncat(msg, line_num_str, msg_size - strlen(msg) - 1);
			strcat(msg, ": unknown instruction ");
			strncat(msg, va_arg(args, char *), msg_size - strlen(msg) - 1);
			break;
		case 3:
			sprintf(line_num_str, "%d", va_arg(args, int));
			strncpy(msg, "L", msg_size);
			strncat(msg, line_num_str, msg_size - strlen(msg) - 1);
			strcat(msg, ": usage: push integer");
			break;
		case 4:
			strncpy(msg, "Error: malloc failed", msg_size);
			break;
	}
	va_end(args);
	_write(msg);
	putchar('\n');
}
