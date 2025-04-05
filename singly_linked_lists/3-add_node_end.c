#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: pointer to pointer to head of the list
 * @str: string to be duplicated and stored in the new node
 *
 * Return: address of the new element or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
list_t *new;
list_t *temp;
unsigned int len = 0;

new = malloc(sizeof(list_t));
if (new == NULL)
return (NULL);

while (str[len])
len++;

new->str = strdup(str);
if (new->str == NULL)
{
free(new);
return (NULL);
}

new->len = len;
new->next = NULL;

if (*head == NULL)
{
*head = new;
return (new);
}

temp = *head;
while (temp->next)
temp = temp->next;
temp->next = new;

return (new);
}
