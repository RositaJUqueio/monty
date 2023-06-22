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
	add(head, pg_data->stack_length);
}
/**
 * add - adds the top and second top elements of the stack
 * @head: head of the stack
 * @stack_length: number of stack elements
 */
void add(stack_t **head, unsigned int stack_length)
{
	stack_t *current = *head;

	if (current == NULL)
		return;

	current->next->n = current->n + current->next->n;
	*head = current->next;
	removes_from_top(&current);
	stack_length -= 1;
}

/**
 * sub_func - subtracts the top two elements
 * of the stack
 * @head: head of the stack
 * @line_number: length of the line
 */
void sub_func(stack_t **head, unsigned int line_number)
{
	info_t *pg_data = &info;

	(void)line_number;

	if (pg_data->stack_length < 2)
	{
		free_all(pg_data);
		prints_error_message_with_args("L%lu: can't sub, stack too short", pg_data);
	}
	sub(head, pg_data->stack_length);
}
/**
 * sub - subtracts the top two elements
 * of the stack
 * @head: head of the stack
 * @stack_length: length of the stack
 */
void sub(stack_t **head, unsigned int stack_length)
{
	stack_t *current = *head;
	int num1, num2, result = 0;

	if (current == NULL)
		return;

	num1 = current->n;
	num2 = current->next->n;

	result = num2 - num1;
	current->next->n = result;
	removes_from_top(head);
	stack_length -= 1;
}

/**
 * mod - mod top two stack element
 * @info: global var
 */
void mod(info_t *info)
{
	stack_t **tmp1, *tmp2;

	tmp1 = &info->stack;
	tmp2 = (*tmp1)->next;
	if ((*tmp1)->n == 0)
	{
		free_all(info);
		prints_error_message_with_args("L%lu: division by zero", info);
	}

	tmp2->n = tmp2->n % (*tmp1)->n;

	removes_from_top(tmp1);
	info->stack_length -= 1;
}
