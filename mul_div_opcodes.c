#include "monty.h"

/**
 * mul_func - multiplies the top two stack elements
 * @head: head of stack
 * @line_number: number of element in stack
 */
void mul_func(stack_t **head, unsigned int line_number)
{
	info_t *pg_data = &info;

	(void)line_number;

	if (pg_data->stack_length < 2)
	{
		free_all(pg_data);
		prints_error_message_with_args("L%lu: can't mul, stack too short", pg_data);
	}
	mul(head, pg_data->stack_length);
}
/**
 * mul - multiplies the top two stack elements
 * @head: head of stack
 * @st_len: number of element in stack
 */
void mul(stack_t **head, unsigned int st_len)
{
	stack_t *current = *head;
	int num1, num2, result = 0;

	if (current == NULL)
		return;

	num1 = current->n;
	num2 = current->next->n;

	result = num2 * num1;
	current->next->n = result;
	removes_from_top(head);
	st_len -= 1;
}

