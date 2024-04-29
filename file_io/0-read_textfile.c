
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>


/**
 * read_textfile - function that reads a text file and prints it to the
 * POSIX standard output
 * @filename: the name of the file
 * @letters: the number of letters it could read and print
 * Return: actual number of letters it could read and print
*/

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd; /*File descriptor*/
	char *buffer;
	ssize_t bytesRead, bytesWritten;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY); /*Open the file for reading*/
	if (fd == -1)
		return (0);

	buffer = malloc(letters + 1); /*Allocate memory for buffer to read the file*/
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}

	bytesRead = read(fd, buffer, letters); /*Read from the file*/
	if (bytesRead == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	buffer[bytesRead] = '\0'; /*Null-terminate the buffer*/

	bytesWritten = write(STDOUT_FILENO, buffer, bytesRead);/*write to std output*/
	if (bytesWritten == -1 || bytesWritten != bytesRead)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	free(buffer); /*Clean up resources*/
	close(fd);

	return (bytesRead);
}