/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** file_get_contents.c
*/

#include "my/fs.h"

char *file_get_contents(const char *file)
{
	size_t size = 0;
	char *buffer = NULL;
	int fd = open(file, O_RDONLY);

	if (fd < 0)
		return (NULL);
	size = filesize_fd(fd);
	buffer = calloc(size + 1, sizeof(char));
	if (!buffer) {
		if (read(fd, buffer, sizeof(char) * size) == -1) {
			free(buffer);
			buffer = NULL;
		}
	}
	close(fd);
	return (buffer);
}