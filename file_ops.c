#include "monty.h"
#define MAX_LINE_LEN 100

/**
 * openfile - Responsible for opening file for reading
 * @filepath: Path to specified file
 */
void openfile(char *filepath)
{
	FILE *stream;

	if (filepath == NULL)
		_err(1, filepath);

	/* Check if pathname exists or is readable */
	if (access(filepath, R_OK) == -1)
		_err(1, filepath);
	stream = fopen(filepath, "r");

	if (stream == NULL)
		_err(1, filepath);
	readfile(stream);
	fclose(stream);
}

/**
 * readfile - Reads content of file
 * @stream: file descriptor
 */
void readfile(FILE *stream)
{
	int line_number = 1;
	char line[MAX_LINE_LEN];

	while (fgets(line, sizeof(line), stream) != NULL)
	{
		processline(line, line_number);
		line_number++;
	}
}

/**
 * processline - Checks content of file for processing
 * @line: Line of data from file
 * @line_number: Current line number on file
 */
void processline(char *line, int line_number)
{
	char *opcode, *value, *delim;

	if (line == NULL)
		_err(4);
	delim = " \n";
	opcode = strtok(line, delim);

	if (opcode == NULL)
		return;
	value = strtok(NULL, delim);

	/* Get matching function */
	get_op(line_number, opcode, value);
}

/**
 * get_op - Selects appropriate operation based on opcode
 * @line_number: Current line number on file
 * @opcode: opcode on said line
 * @value: The value to be pushed (in case of "push" opcode)
 */
void get_op(int line_number, char *opcode, char *value)
{
	int i;

	instruction_t ops[] = {
		{"push", stack_push},
		{"pall", stack_display},
		{"pint", stack_top},
		{"pop", stack_pop},
		{NULL, NULL}
	};

	for (i = 0; ops[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, ops[i].opcode) == 0)
		{
			get_func(ops[i].f, line_number, opcode, value);
			return;
		}
	}
	_err(2, line_number, opcode);
}

/**
 * get_func - Call specific function based on opcode
 * @func: Function to be called
 * @line_num: Line number in bytecode file
 * @opcode: The opcode
 * @value: String value
 */
void get_func(func_t func, int line_num, char *opcode, char *value)
{
	stack_t *new_node;
	int i;

	/* If opcode is "push" */
	if (strcmp(opcode, "push") == 0)
	{
		/* Check if argument was provided */
		if (value == NULL)
			_err(3, line_num);

		/* Make sure the value contains only digits */
		for (i = 0; value[i] != '\0'; i++)
		{
			if (!isdigit(value[i]))
				_err(3, line_num);
		}

		/* Create new node */
		new_node  = create_node(atoi(value));

		/* Add node to stack */
		func(&new_node, line_num);
	}
	else
	{
		/* If opcode is not "push" */
		func(&head, line_num);
	}
}
