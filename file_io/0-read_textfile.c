#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output.
 * @filename: Name of the file to read.
 * @letters: Number of letters it should read and print.
 *
 * Return: Actual number of letters read and printed. 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
 ssize_t fd, r, w;
 char *buffer;

 if (filename == NULL)
  return (0);

 buffer = malloc(sizeof(char) * letters);
 if (buffer == NULL)
  return (0);

 fd = open(filename, O_RDONLY);
 if (fd == -1)
 {
  free(buffer);
  return (0);
 }

 r = read(fd, buffer, letters);
 if (r == -1)
 {
  free(buffer);
  close(fd);
  return (0);
 }

 w = write(STDOUT_FILENO, buffer, r);
 free(buffer);
 close(fd);

 if (w == -1 || w != r)
  return (0);

 return (w);
}
