#include "lists.h"
#include <stdlib.h>

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list
 * @head: pointer to the head pointer
 * @n: value for the new node
 * Return: address of new node or NULL if failure
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
dlistint_t *new, *temp;

new = malloc(sizeof(dlistint_t));
if (!new)
return (NULL);

new->n = n;
new->next = NULL;

if (*head == NULL)
{
new->prev = NULL;
*head = new;
return (new);
}

temp = *head;
while (temp->next)
temp = temp->next;

temp->next = new;
new->prev = temp;

return (new);
}
