#include "monty.h"

/**
 * div_func - divides top two stack element
 * @head: head of stack
 * @line_number: number of element in stack
 */
void div_func(stack_t **head, unsigned int line_number)
{
	info_t *pg_data = &info;

	(void)line_number;
	(void)head;

	if (pg_data->stack_length < 2)
	{
		free_all(pg_data);
		prints_error_message_with_args("L%lu: can't div, stack too short", pg_data);
	}
	__div__(pg_data);
}
/**
 * __div__ - divides top two stack element
 * @info: global var
 */
void __div__(info_t *info)
{
	stack_t **tmp1, *tmp2;

	tmp1 = &info->stack;
	tmp2 = (*tmp1)->next;
	if ((*tmp1)->n == 0)
	{
		free_all(info);
		prints_error_message_with_args("L%lu: division by zero", info);
	}

	tmp2->n = tmp2->n / (*tmp1)->n;

	removes_from_top(tmp1);
	info->stack_length -= 1;
}
