#include "monty.h"


void push_func(stack_t **stack, unsigned int line_number)
{
	info_t *pg_data = &info;
	int is_digit, str_len, big_number, push_num;
	
	(void)line_number;
	if (pg_data->line_tokens[1])
	{
		str_len = strlen(pg_data->line_tokens[1]);
		is_digit = _isdigit(pg_data->line_tokens[1]);
		push_num = atoi(pg_data->line_tokens[1]);
		big_number = push_num > (int)INT_MAX;

		if (!is_digit || str_len > 10 || big_number)
		{
			prints_error_message_with_args("L%lu: usage: push integer", pg_data);
		}
		push(stack, push_num);
	}
	else
	{
		 prints_error_message_with_args("L%lu: usage: push integer", pg_data);
	}
}

void pall_func(stack_t **stack, unsigned int line_number)
{	
        printf("Hey did a pall\n");
	pall(stack, line_number);
}

void push(stack_t **head, int num)
{
	printf("hey this is a push\n");
	insert_at_list_start(head, num);
}

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
