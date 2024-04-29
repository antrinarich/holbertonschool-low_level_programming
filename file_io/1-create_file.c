#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * create_file - function that creates a file
 * @filename: the name of the file to create
 * @text_content: Null terminated string to write to the file
 * Return: 1 on success, -1 in case failure
*/

int create_file(const char *filename, char *text_content)
{
	int fd; /*File descriptor*/
	ssize_t bytesWritten;
	size_t length = 0;

	if (filename == NULL) /*Check if filename is NULL*/
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		while (text_content[length])
			length++;
	}

	/*Open the file for writing*/
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)/*Check if text_content is NULL*/
	{
		bytesWritten = write(fd, text_content, length); /*write*/
		if (bytesWritten == -1)
		{
			close(fd);
			return (-1);
		}
		if ((size_t)bytesWritten != length) /*Check if all data has been written*/
		{
			close(fd);
			return (-1);
		}
	}

	/*Close the file*/
	if (close(fd) == -1)
		return (-1);
	return (1);
}