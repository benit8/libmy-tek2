/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** log / write.c
*/

#include "my/log.h"

static const log_infos_t infos[] = {
	{NULL, NULL},
	{"DEBUG", MAGENTA},
	{"INFO", CYAN},
	{"WARN", YELLOW},
	{"ERROR", RED},
	{"FATAL", BG_BLACK BRED},
	{NULL, NULL}
};

static char *get_formatted_time(void)
{
	static char buff[32];
	time_t t = time(NULL);
	struct tm *lt = localtime(&t);

	buff[strftime(buff, sizeof(buff), "%x %X", lt)] = '\0';
	return (buff);
}

void log_write(const char *format, va_list *ap, log_level_t level)
{
	log_data_t *data = log_get_internal_data();

	if ((level <= LL_ALL || level >= LL_OFF) ||
		(level < data->level || data->fd < 0))
		return;
	dprintf(data->fd, "[%d] ", getpid());
	dprintf(data->fd, "[%s] ", get_formatted_time());
	if (data->fd < 3)
		dprintf(data->fd, infos[level].color);
	dprintf(data->fd, "[%s]", infos[level].name);
	if (data->fd < 3)
		dprintf(data->fd, RESET);
	dprintf(data->fd, " ");
	dprintf(data->fd, "%s: ", __progname);
	vdprintf(data->fd, format, *ap);
	dprintf(data->fd, "\n");
}