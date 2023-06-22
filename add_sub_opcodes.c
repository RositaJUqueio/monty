#include "monty.h"

/**
 * add_func - adds the top and second top elements of the stack
 * @head: head of the stack
 * @line_number: line to be read
 */
void add_func(stack_t **head, unsigned int line_number)
{
	info_t *pg_data = &info;

	(void)line_number;

	if (pg_data->stack_length < 2)
	{
		free_all(pg_data);
		prints_error_message_with_args("L%lu: can't add, stack too short", pg_data);
	}
	add(head);
	pg_data->stack_length -= 1;
}
/**
 * add - adds the top and second top elements of the stack
 * @head: head of the stack
 */
void add(stack_t **head)
{
	stack_t *current = *head;

	if (current == NULL)
		return;

	current->next->n =  current->n + current->next->n;
	pop(head);
}

