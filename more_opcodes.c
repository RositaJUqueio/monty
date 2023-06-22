/* Authors: Rosita Uqueio, Israel Nanor */
#include "monty"

/**
 * pop_func - handles pop opcode
 * @stack: head of stack data structure
 * @line_number: line number of instruction
 */
void pop_func(stack_t **stack, unsigned int line_number)
{
	info_t *pg_data = &info;

	(void)line_number;

	if (*stack == NULL)
	{
		prints_error_message_with_args("L%lu: can't pop an empty stack", pg_data);
		exit(EXIT_FAILURE);
	}

	pop(stack);
}

/**
 * pop - removes top element of the stack
 * @head: head of stack data structure
 */
void pop(stack_t **head)
{
	stack_t *temp;

	temp = *head;
	*head = (*head)->next;
	if (*head != NULL)
		(*head)->prev = NULL;
	free(temp);
}
