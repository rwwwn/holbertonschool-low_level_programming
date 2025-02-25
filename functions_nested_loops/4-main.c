#include "main.h"

/**
 * main - Check the code
 *
 * Return: Always 0
 */
int main(void)
{
    int r;

    r = _isalpha('H');
    _putchar(r + '0'); /* Expected output: 1 */
    r = _isalpha('o');
    _putchar(r + '0'); /* Expected output: 1 */
    r = _isalpha(108); /* ASCII for 'l' */
    _putchar(r + '0'); /* Expected output: 1 */
    r = _isalpha(';');
    _putchar(r + '0'); /* Expected output: 0 */
    _putchar('\n');
    return (0);
}
