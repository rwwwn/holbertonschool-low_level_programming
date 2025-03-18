#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - Prints anything based on format specifier.
 * @format: List of argument types.
 */
void print_all(const char * const format, ...)
{
va_list args;
int i = 0;
char *str, *sep = "";
char type;

va_start(args, format);

while (format && format[i])
{
type = format[i];

if (type == 'c' || type == 'i' || type == 'f' || type == 's')
{
printf("%s", sep);
sep = ", ";

if (type == 'c')
printf("%c", va_arg(args, int));
if (type == 'i')
printf("%d", va_arg(args, int));
if (type == 'f')
printf("%f", va_arg(args, double));
if (type == 's')
{
str = va_arg(args, char *);
printf("%s", str ? str : "(nil)");
}
}
i++;
}
printf("\n");
va_end(args);
}
