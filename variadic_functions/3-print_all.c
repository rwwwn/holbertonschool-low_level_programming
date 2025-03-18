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

va_start(args, format);

while (format && format[i])
{
if (format[i] == 'c')
printf("%s%c", sep, va_arg(args, int));
else if (format[i] == 'i')
printf("%s%d", sep, va_arg(args, int));
else if (format[i] == 'f')
printf("%s%f", sep, va_arg(args, double));
else if (format[i] == 's')
{
str = va_arg(args, char *);
if (!str)
str = "(nil)";
printf("%s%s", sep, str);
}
sep = ", ";
i++;
}

printf("\n");
va_end(args);
}
