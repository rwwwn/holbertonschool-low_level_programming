#include "main.h"

/**
 * binary_to_uint - converts a binary string to unsigned int
 * @b: pointer to a string of 0 and 1 chars
 *
 * Return: converted number, or 0 if b is NULL or invalid
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	if (b == 0)
		return (0);

	while (*b)
	{
		if (*b != '0' && *b != '1')
			return (0);
		result = (result << 1) | (*b - '0');
		b++;
	}

	return (result);
}
