#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

/**
 * append_text_to_file - function that appends text at the end of a file.
 * @filename: the name of the file
 * @text_content: string to add at the end of the file
 * Return: 1 on success and -1 on failure
*/

int append_text_to_file(const char *filename, char *text_content)
{
	int fd; /* file descriptor */
	ssize_t bytesWritten;
	size_t length = 0;

	/* Check if filename is NULL */
	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
		return (1);

	/* Calculate the length of text_content */
	while (text_content[length])
		length++;

	/* Open the file for appending */
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	/*Write text_content to the file */
	bytesWritten = write(fd, text_content, length);
	if (bytesWritten == -1)
	{
		close(fd);
		return (-1);
	}

	/* Close the file */
	if (close(fd) == -1)
		return (-1);

	return (1);
}
