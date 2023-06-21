#include "monty.h"

void print_list(stack_t *head)
{
	stack_t *current = head;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

stack_t *insert_at_list_start(stack_t **head, int num)
{
	stack_t *current = *head;
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		return NULL;
	}
	new_node->n = num;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (current == NULL)
	{
		new_node->next = *head;
		*head = new_node;
	} 
	else 
	{
		while (current != NULL)
		{
			current = current->next;
		}
		if (current == NULL)
		{
			(*head)->prev = new_node;
			new_node->next = *head;
			*head = new_node;
		}
	}

	return (new_node);
}

/**
 * free_dlistint - free a `dlistint_t` doubly linked list
 * @head: head of LL
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp = head;
	stack_t *next;

	while (tmp != NULL)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}