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

	num1 = current->n;
	num2 = current->next->n;

	result = num2 * num1;
	current->next->n = result;
	removes_from_top(head);
	st_len -= 1;
}

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
		free_line_tokens(info);
		prints_error_message_with_args("L%lu: division by zero", info);
	}

	tmp2->n = tmp2->n / (*tmp1)->n;

	removes_from_top(tmp1);
	info->stack_length -= 1;
}

