#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_char - Prints a char
 * @args: Argument list
 */
void print_char(va_list args)
{
    printf("%c", va_arg(args, int));
}

/**
 * print_int - Prints an integer
 * @args: Argument list
 */
void print_int(va_list args)
{
    printf("%d", va_arg(args, int));
}

/**
 * print_float - Prints a float
 * @args: Argument list
 */
void print_float(va_list args)
{
    printf("%f", va_arg(args, double));
}

/**
 * print_string - Prints a string
 * @args: Argument list
 */
void print_string(va_list args)
{
    char *str = va_arg(args, char *);

    if (!str)
        str = "(nil)";
    printf("%s", str);
}

/**
 * print_all - Prints anything based on format specifier.
 * @format: List of argument types.
 */
void print_all(const char * const format, ...)
{
    va_list args;
    int i = 0, j;
    char *sep = "";
    void (*funcs[])(va_list) = {print_char, print_int, print_float, print_string};
    char types[] = "cifs";

    va_start(args, format);

    while (format && format[i])
    {
        j = 0;
        while (types[j])
        {
            if (format[i] == types[j])
            {
                printf("%s", sep);
                funcs[j](args);
                sep = ", ";
                break;
            }
            j++;
        }
        i++;
    }
    printf("\n");
    va_end(args);
}
