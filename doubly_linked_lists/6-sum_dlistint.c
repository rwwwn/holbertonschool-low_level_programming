#include "lists.h"

/**
 * sum_dlistint - sums all the data (n) in a doubly linked list
 * @head: pointer to the head of the list
 * Return: the sum of all data (n), or 0 if empty
 */
int sum_dlistint(dlistint_t *head)
{
int sum = 0;

while (head)
{
sum += head->n;
head = head->next;
}
return (sum);
}
