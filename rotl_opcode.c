#include "monty.h"

/**
 * rotl_func - inserts nodes at the top of the stack
 * @head: head of list to be inserted
 * @line_number: number to be inserted
 * Return:  nothing
 */
void rotl_func(stack_t **head, unsigned int line_number)
{
	(void)line_number;
	if (*head == NULL || (*head)->next == NULL)
		return;

	insert_at_end(head, (*head)->n);
	removes_from_top(head);
}

