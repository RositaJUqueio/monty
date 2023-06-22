#include "monty.h"

/**
 * swap_func - swaps top two elements
 * @head: head of stack
 * @line_number: number of stack elements
 */
void swap_func(stack_t **head, unsigned int line_number)
{
	info_t *pg_data = &info;

	(void)line_number;

	if (pg_data->stack_length < 2)
	{
		free_all(pg_data);
		prints_error_message_with_args("L%lu: can't swap, stack too short", pg_data);
	}
	swap(head);
}

/**
 * swap - handles swaps top two nodes
 * @head: head of stack
 */
void swap(stack_t **head)
{
	stack_t *current = *head;
	int tmp;

	if (current == NULL)
		return;

	tmp = current->n;
	current->n = current->next->n;
	current->next->n = tmp;
}

