#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define MAX_LINE_LENGTH 1024

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

/**
 *  struct info_s - global variables
 *  @fd:  file descriptor
 *  @line_tokens:  array to store line tokens
 *  @line: buffer to hold line read from file
 *  @fd: stream descriptor for open files
 *  @line_number: line number to be read
 *  @stack: stack data structure
 *  @stack_length: the number of elements in the stack
 *  Description - global vars
*/
typedef struct info_s
{
	FILE *fd;
	char **line_tokens;
	char line[MAX_LINE_LENGTH];
	unsigned int line_number;
	stack_t *stack;
	unsigned int stack_length;
} info_t;
info_t info;
/* Function Prototypes*/

int main(int argc, char *argv[]);
void initialize_infos(info_t *info);
void process_file(const char *file_path, info_t *info);
void line_parser(info_t *info, char *line);
void prints_error_message(const char *message);
void process_instructions(info_t *info);
int _isdigit(const char *str);
void free_all(info_t *info);
void free_line_tokens(info_t *info);
/* push & pall*/

void pall_func(stack_t **stack, unsigned int line_number);
void push_func(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, int num);
void pall(stack_t **stack, int num);

/* linked list */
void print_list(stack_t *head);
stack_t *insert_at_list_start(stack_t **head, int num);
void free_dlistint(stack_t *head);
void removes_from_top(stack_t **head);

/*pop & pint*/
void pop_func(stack_t **stack, unsigned int line_number);
void pop(stack_t **head);
void pint(stack_t *top);
void pint_func(stack_t **stack, unsigned int line_number);

/* add and sub */
void add(stack_t **stack, unsigned int stack_len);
void add_func(stack_t **head, unsigned int line_number);
void sub(stack_t **stack, unsigned int stack_len);
void sub_func(stack_t **head, unsigned int line_number);

/* mul & div*/
void mul(stack_t **stack, unsigned int stack_len);
void mul_func(stack_t **head, unsigned int line_number);
/* erros */
void prints_error_message_with_args(const char *error_message, info_t *info);
#endif /*MONTY_H*/
