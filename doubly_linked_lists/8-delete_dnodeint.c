#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - deletes the node at given index
 * @head: pointer to head pointer of list
 * @index: index of node to delete
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
dlistint_t *temp = *head;
unsigned int i = 0;

if (!head || !*head)
return (-1);

if (index == 0)
{
*head = temp->next;
if (temp->next)
temp->next->prev = NULL;
free(temp);
return (1);
}

while (temp && i < index)
{
temp = temp->next;
i++;
}

if (!temp)
return (-1);

if (temp->prev)
temp->prev->next = temp->next;
if (temp->next)
temp->next->prev = temp->prev;

free(temp);
return (1);
}
