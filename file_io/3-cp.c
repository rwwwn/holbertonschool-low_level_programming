#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * print_error - Prints error message and exits
 * @code: exit code
 * @message: format string message
 * @arg: string argument to print
 */
void print_error(int code, const char *message, const char *arg)
{
dprintf(STDERR_FILENO, message, arg);
exit(code);
}

/**
 * main - Copies content of file_from to file_to
 * @argc: number of arguments
 * @argv: argument values
 * Return: 0 on success, exits with error codes on failure
 */
int main(int argc, char *argv[])
{
int fd_from, fd_to;
ssize_t r, w;
char buf[1024];

if (argc != 3)
print_error(97, "Usage: %s file_from file_to\n", argv[0]);

fd_from = open(argv[1], O_RDONLY);
if (fd_from == -1)
print_error(98, "Error: Can't read from file %s\n", argv[1]);

fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
if (fd_to == -1)
{
close(fd_from);
print_error(99, "Error: Can't write to %s\n", argv[2]);
}

while ((r = read(fd_from, buf, 1024)) > 0)
{
w = write(fd_to, buf, r);
if (w != r)
{
close(fd_from);
close(fd_to);
print_error(99, "Error: Can't write to %s\n", argv[2]);
}
}
if (r == -1)
{
close(fd_from);
close(fd_to);
print_error(98, "Error: Can't read from file %s\n", argv[1]);
}

if (close(fd_from) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
exit(100);
}
if (close(fd_to) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
exit(100);
}

return (0);
}
