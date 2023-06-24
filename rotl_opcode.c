#include "monty.h"

/**
 * rotl_func - inserts the top nodes at the bottom of the stack
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

/**
 * rotr_func - inserts the top nodes at the bottom of the stack
 * @head: head of list to be inserted
 * @line_number: number to be inserted
 * Return:  nothing
 */
void rotr_func(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head, *second_last;

	(void)line_number;
	if (*head == NULL || (*head)->next == NULL)
		return;

	while (current->next != NULL)
	{
		second_last = current;
		current = current->next;
	}
	second_last->next = NULL;
	current->next = *head;
	*head = current;
}

