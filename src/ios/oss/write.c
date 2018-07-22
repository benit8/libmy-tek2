/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** ios / oss / read_delim.c
*/

#include "my/ios/oss.h"

bool oss_write(oss_t *oss, const void *buffer, size_t length)
{
	size_t wrote = fwrite(buffer, 1, length, oss->fp);

	fflush(oss->fp);
	return (wrote == length);
}

bool oss_writef(oss_t *oss, const char *format, ...)
{
	int n = 0;
	va_list ap;

	va_start(ap, format);
	n = vfprintf(oss->fp, format, ap);
	va_end(ap);
	fflush(oss->fp);
	return (n >= 0);
}