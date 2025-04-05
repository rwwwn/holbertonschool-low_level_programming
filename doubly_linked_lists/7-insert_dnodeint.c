#include "lists.h"
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - inserts a new node at a given index
 * @h: pointer to the head of the list
 * @idx: index where new node should be inserted
 * @n: data for new node
 * Return: address of new node or NULL if failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
dlistint_t *new, *temp = *h;
unsigned int i = 0;

if (idx == 0)
return (add_dnodeint(h, n));

while (temp && i < idx - 1)
{
temp = temp->next;
i++;
}
if (!temp || (!temp->next && i + 1 < idx))
return (NULL);

if (!temp->next)
return (add_dnodeint_end(h, n));

new = malloc(sizeof(dlistint_t));
if (!new)
return (NULL);

new->n = n;
new->next = temp->next;
new->prev = temp;
temp->next->prev = new;
temp->next = new;

return (new);
}
