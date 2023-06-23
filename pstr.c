#include "monty.h"

/**
 * pstr_func - handles pstr opcode
 * @stack: head of stack data structure
 * @line_number: line numbe
 */
void pstr_func(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node = *stack;

	(void)line_number;

	while (current_node != NULL && current_node->n > 0 && current_node->n <= 127)
	{
		if (current_node->n == 0)
			break;

		printf("%c", (char)(current_node->n));
		current_node = current_node->next;
	}

	printf("\n");
}

