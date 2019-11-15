#include "shell.h"

/**
 * add_node_end - Adds a new node at the end of a list
 * @head: The first node
 * @token: A string
 *
 * Return: The address of the new element or NULL
 */
s_list *add_node_end(s_list **head, const char *token)
{
	unsigned int len = 0, i = 0;
	s_list *last = *head;
	s_list *new = malloc(sizeof(s_list));

	if (new == NULL)
		return (NULL);

	if (*head != NULL)
	{
		for (; last->next != NULL; i++)
			last = last->next;
		last->next = new;
	}
	else
		*head = new;

	new->token = strdup(token);
	new->next = NULL;

	return (new);
}

/**
 * free_list - Frees a list
 * @head: The first node
 */
void free_list(s_list *head)
{
	if (head)
	{
		free(head->token);
		free_list(head->next);
		free(head);
	}
}
