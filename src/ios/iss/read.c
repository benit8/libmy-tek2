/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** ios / iss / read_delim.c
*/

#include "my/ios/iss.h"

char *iss_read(iss_t *iss, size_t n)
{
	char buff[n];
	size_t read = 0;

	bzero(&buff[0], n);
	read = fread(buff, 1, n, iss->fp);
	if (read == 0) {
		fprintf(stderr, "iss_read() failed\n");
		return (NULL);
	}
	return (strndup(buff, read));
}

int iss_readf(iss_t *iss, const char *format, ...)
{
	int n = 0;
	va_list ap;

	va_start(ap, format);
	n = vfscanf(iss->fp, format, ap);
	va_end(ap);
	return (n);
}