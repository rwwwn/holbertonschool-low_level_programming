#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * safe_close - closes a file descriptor and checks for errors
 * @fd: file descriptor
 */
void safe_close(int fd)
{
if (close(fd) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(100);
}
}

/**
 * open_file_from - opens a source file
 * @filename: name of the file
 * Return: file descriptor
 */
int open_file_from(const char *filename)
{
int fd = open(filename, O_RDONLY);
if (fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
exit(98);
}
return (fd);
}

/**
 * open_file_to - opens a destination file
 * @filename: name of the file
 * Return: file descriptor
 */
int open_file_to(const char *filename)
{
int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
exit(99);
}
return (fd);
}

/**
 * copy_file - copies content of one file to another
 * @file_from_name: source file name
 * @file_to_name: destination file name
 */
void copy_file(const char *file_from_name, const char *file_to_name)
{
int file_from = open_file_from(file_from_name);
int file_to = open_file_to(file_to_name);
char buffer[BUFFER_SIZE];
int r, w;

r = read(file_from, buffer, BUFFER_SIZE);
while (r > 0)
{
w = write(file_to, buffer, r);
if (w != r)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to_name);
safe_close(file_from);
safe_close(file_to);
exit(99);
}
r = read(file_from, buffer, BUFFER_SIZE);
}
if (r == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from_name);
safe_close(file_from);
safe_close(file_to);
exit(98);
}

safe_close(file_from);
safe_close(file_to);
}

/**
 * main - checks argument count and calls file copy
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

copy_file(argv[1], argv[2]);
return (0);
}
