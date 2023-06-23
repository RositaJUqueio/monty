#include "monty.h"

/**
 * modu_func - computes the modulus of two numbers
 * @head: stack head
 * @line_num: number of stack elements
 */
void modu_func(stack_t **head, unsigned int line_num)
{
	info_t *pg_data = &info;
	stack_t *tmp1, *tmp2;

	(void)head;
	(void)line_num;
	if (pg_data->stack_length < 2)
	{
		free_all(pg_data);
		prints_error_message_with_args("L%lu: can't mod, stack too short", pg_data);
	}

	tmp1 = *head;
	tmp2 = tmp1->next;
	if ((tmp1)->n == 0)
	{
		prints_error_message_with_args("L%lu: division by zero", pg_data);
	}
	tmp2->n %= tmp1->n;
	pop(&tmp1);
	pg_data->stack_length -= 1;
}

