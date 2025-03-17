#include "main.h"

/**
 * check_prime - Checks if a number is prime
 * @n: The number to check
 * @div: The divisor
 *
 * Return: 1 if prime, 0 otherwise
 */
int check_prime(int n, int div)
{
if (n <= 1)
return (0);
if (div * div > n)
return (1);
if (n % div == 0)
return (0);
return (check_prime(n, div + 1));
}

/**
 * is_prime_number - Returns 1 if a number is prime, 0 otherwise
 * @n: The number to check
 *
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_number(int n)
{
return (check_prime(n, 2));
}
