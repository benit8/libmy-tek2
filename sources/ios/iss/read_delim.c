/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** ios / iss / read_delim.c
*/

#include "my/ios/iss.h"

char *iss_read_line(iss_t *iss)
{
	char *line = NULL;
	size_t size = 0;
	ssize_t read = getline(&line, &size, iss->fp);

	if (read < 0) {
		free(line);
		return (NULL);
	}
	line[read - 1] = '\0';
	return (line);
}

char *iss_read_delim(iss_t *iss, int delim)
{
	char *line = NULL;
	size_t size = 0;
	ssize_t read = getdelim(&line, &size, delim, iss->fp);

	if (read < 0) {
		free(line);
		return (NULL);
	}
	line[read - 1] = '\0';
	return (line);
}