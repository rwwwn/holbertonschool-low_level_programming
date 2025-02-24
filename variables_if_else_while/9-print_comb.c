#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int num;

	for (num = 0; num < 10; num++)
	{
		putchar(num + '0'); /* Convert int to ASCII and print */

		if (num < 9) /* If not the last number, print comma and space */
		{
			putchar(',');
			putchar(' ');
		}
	}

	putchar('\n'); /* Print newline */

	return (0);
}
