/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** fs / filesize.c
*/

#include "my/fs.h"

size_t filesize(const char *filepath)
{
	stat_t buf;

	if (stat(filepath, &buf) == -1)
		return ((size_t)-1);
	return (buf.st_size);
}

size_t filesize_fd(const int fd)
{
	stat_t buf;

	if (fstat(fd, &buf) == -1)
		return ((size_t)-1);
	return (buf.st_size);
}