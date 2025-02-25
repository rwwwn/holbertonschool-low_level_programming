#include "main.h"

/**
 * print_alphabet_x10 - Prints the alphabet in lowercase 10 times
 */
void print_alphabet_x10(void)
{
	int i;
	char ch;

	for (i = 0; i < 10; i++) /* Repeat 10 times */
	{
		for (ch = 'a'; ch <= 'z'; ch++)
			_putchar(ch);

		_putchar('\n'); /* Print newline */
	}
}
