/* Authors: Rosita Uqueio, Israel Nanor */
#include "monty.h"

/**
 * pop_func - handles pop opcode.
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

	removes_from_top(stack);
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

/**
 * pint_func - handles pint opcode
 * @stack: head of stack data structure
 * @line_number: line number of instruction
 */
void pint_func(stack_t **stack, unsigned int line_number)
{
	info_t *pg_data;

	pg_data = &info;
	(void)line_number;

	if (*stack == NULL)
	{
		prints_error_message_with_args("L%lu: can't pint, stack empty", pg_data);
		exit(EXIT_FAILURE);
	}

	pint(*stack);
}

/**
 * pint - prints the value at the top of the stack
 * @top: top of the stack
 */
void pint(stack_t *top)
{
	printf("%d\n", top->n);
}
