/* Authors:  Rosita Uqueio & Israel Nanor */
#include "monty.h"

/**
 * print_list - prints list content
 * @head: head of list to be printed
 * Return: nothing
 */
void print_list(stack_t *head)
{
	stack_t *current = head;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * insert_at_list_start - inserts nodes at the top of the stack
 * @head: head of list to be inserted
 * @num: number to be inserted
 * Return:  the address of the new node
 */
stack_t *insert_at_list_start(stack_t **head, int num)
{
	stack_t *current = *head;
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		return (NULL);
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
 * removes_from_top - removes the first node from the list
 * @head: head of list
 */
void removes_from_top(stack_t **head)
{
	if (*head != NULL)
	{
		stack_t *temp = *head;
		*head = (*head)->next;

		if (*head != NULL)
			(*head)->prev = NULL;

		free(temp);
	}
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

