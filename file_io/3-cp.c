#include "main.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, exit with error code otherwise
 */
int main(int argc, char *argv[])
{
int file_from, file_to, r, w;
char *buffer;

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

buffer = malloc(sizeof(char) * BUFFER_SIZE);
if (!buffer)
return (1);

file_from = open(argv[1], O_RDONLY);
if (file_from == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
free(buffer);
exit(98);
}

file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (file_to == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
free(buffer);
close(file_from);
exit(99);
}

while ((r = read(file_from, buffer, BUFFER_SIZE)) > 0)
{
w = write(file_to, buffer, r);
if (w != r)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
free(buffer);
close(file_from);
close(file_to);
exit(99);
}
}

if (r == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
free(buffer);
close(file_from);
close(file_to);
exit(98);
}

if (close(file_from) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
free(buffer);
exit(100);
}

if (close(file_to) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
free(buffer);
exit(100);
}

free(buffer);
return (0);
}
