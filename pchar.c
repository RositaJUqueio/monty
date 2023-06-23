#include "monty.h"

/**
 * pchar_func - handles pchar opcode
 * @stack: head of stack data structure
 * @line_number: line number of instructi
 */
void pchar_func(stack_t **stack, unsigned int line_number)
{
	info_t *pg_data = &info;
	int x;

	(void) line_number;

	if (*stack == NULL)
	{
		prints_error_message_with_args("L%u: can't pchar, stack empty", pg_data);
		exit(EXIT_FAILURE);
	}

	x = (*stack)->n;

	if (x < 0 || x > 127)
	{
		prints_error_message_with_args("L%u: can't pchar, value out of range", pg_data);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (char)x);
}

