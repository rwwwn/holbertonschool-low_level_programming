#include "main.h"

/**
 * main - Check the code
 *
 * Return: Always 0
 */
int main(void)
{
    int r;

    print_last_digit(98); /* Expected output: 8 */
    print_last_digit(0);  /* Expected output: 0 */
    r = print_last_digit(-1024); /* Expected output: 4 */
    _putchar('0' + r);
    _putchar('\n');

    return (0);
}
