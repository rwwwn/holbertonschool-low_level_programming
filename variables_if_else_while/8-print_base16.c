#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int num;
	char letter;

	for (num = 0; num < 10; num++)
		putchar(num + '0'); /* Print digits 0-9 */

	for (letter = 'a'; letter <= 'f'; letter++)
		putchar(letter); /* Print letters a-f */

	putchar('\n'); /* Print newline */

	return (0);
}
