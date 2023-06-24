#include "monty.h"

/**
 * push_func - handles push opcodes
 * @stack: head of stack data structure
 * @line_number: line number of instruction
 */
void push_func(stack_t **stack, unsigned int line_number)
{
	info_t *pg_data = &info;
	int is_digit, str_len, big_number, push_num;

	(void)line_number;
	if (pg_data->line_tokens[1])
	{
		str_len = strlen(pg_data->line_tokens[1]);
		is_digit = _isdigit(pg_data->line_tokens[1]);
		if (is_digit)
			push_num = atoi(pg_data->line_tokens[1]);
		big_number = push_num > (int)INT_MAX;

		if (!is_digit || str_len > 10 || big_number)
		{
			free_all(pg_data);
			prints_error_message_with_args("L%lu: usage: push integer", pg_data);
			return;
		}

		push(stack, push_num, pg_data->is_queue);
		pg_data->stack_length += 1;
	}
	else
	{
		free_all(pg_data);
		prints_error_message_with_args("L%lu: usage: push integer", pg_data);
	}
}
/**
 * pall_func - handles pall opcodes
 * @line_number: line number of instruction
 * @stack: head of stack data structure
 */
void pall_func(stack_t **stack, unsigned int line_number)
{
	pall(stack, line_number);
}
/**
 * push - performs push of values onto the stack
 * @num: number to push to stack
 * @head: head of stack data structure
 * @is_queue: switch between stack and queue modes
 */
void push(stack_t **head, int num, unsigned int is_queue)
{
	if (is_queue == 1)
	{
		insert_at_end(head, num);
	}
	else
	{
		insert_at_list_start(head, num);
	}
}
/**
 * pall - performs pall operations
 * @num: stack depth to list
 * @head: head of stack data structure
 */
void pall(stack_t **head, int num)
{
	stack_t *current = *head;
	int idx = 0;

	while (current != NULL && idx < num)
	{
		printf("%d\n", current->n);
		current = current->next;
		idx++;
	}
}
