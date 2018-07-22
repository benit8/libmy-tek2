/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** log / file.c
*/

#include "my/log.h"

bool log_set_file(const char *filepath)
{
	static const mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	static const int flags = O_CREAT | O_WRONLY | O_APPEND;
	log_data_t *data = log_get_internal_data();
	int fd = open(filepath, flags, mode);

	if (fd < 0)
		return (false);
	data->fd = fd;
	return (true);
}

bool log_set_file_fd(int fd)
{
	log_data_t *data = log_get_internal_data();
	int r = 0;

	if (fd < 0)
		return (false);
	r = fcntl(fd, F_GETFL);
	if (r == -1)
		return (false);
	if (!(r & O_WRONLY))
		return (false);
	data->fd = fd;
	return (true);
}

void log_close_file(void)
{
	log_data_t *data = log_get_internal_data();

	if (data->fd < 3)
		return;
	close(data->fd);
	data->fd = -1;
}