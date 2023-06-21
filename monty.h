#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
 *  @fd: - file descriptor
 *  @line_tokens - array to store line tokens
 *  Description - global vars
*/
typedef struct info_s
{
	FILE *fd;
	char *line_tokens;
	char line[MAX_LINE_LENGTH];
} info_t;
info_t info;
/* Function Prototypes*/

int main(int argc, char *argv[]);
void initialize_infos(info_t *info);
void process_file(const char *file_path, info_t *info);
void prints_error_message(const char *message);
void push_opcode(stack_t **stack, unsigned int line_number);
void pall_opcode(stack_t **stack, unsigned int line_number);

#endif /*MONTY_H*/
