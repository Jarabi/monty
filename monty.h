#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

extern stack_t *head;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function type definition */
typedef void (*func_t)(stack_t **, unsigned int);

void _err(int status, ...);
int _write(char *s);
void openfile(char *filepath);
void readfile(FILE *stream);
void processline(char *line, int line_number);
void get_op(int line_number, char *opcode, char *value);
void get_func(func_t func, int line_num, char *opcode, char *value);
void print_err(int status, va_list args, char *msg, size_t msg_size);
stack_t *create_node(int val);
void stack_push(stack_t **new_node, unsigned int line_num);
void stack_display(stack_t **stack, unsigned int line_num);
void stack_top(stack_t **stack, unsigned int line_num);
void stack_pop(stack_t **new_node, unsigned int line_num);

#endif /* MONTY_H */
