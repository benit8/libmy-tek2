/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** ios / iss / read_size.c
*/

#include "my/ios/iss.h"

ssize_t iss_read_ssize(iss_t *iss)
{
	ssize_t value = 0;

	if (fscanf(iss->fp, "%zd", &value) < 1) {
		fprintf(stderr, "iss_read_ssize() failed\n");
		return (0);
	}
	return (value);
}

size_t iss_read_size(iss_t *iss)
{
	size_t value = 0;

	if (fscanf(iss->fp, "%zu", &value) < 1) {
		fprintf(stderr, "iss_read_size() failed\n");
		return (0);
	}
	return (value);
}