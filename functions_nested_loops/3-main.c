#include "main.h"

/**
 * main - Check the code
 *
 * Return: Always 0
 */
int main(void)
{
    int r;

    r = _islower('H');
    _putchar(r + '0'); /* Expected output: 0 */
    r = _islower('o');
    _putchar(r + '0'); /* Expected output: 1 */
    r = _islower(108); /* ASCII for 'l' */
    _putchar(r + '0'); /* Expected output: 1 */
    _putchar('\n');
    return (0);
}
