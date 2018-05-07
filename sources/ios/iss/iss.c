/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** ios / iss / iss.c
*/

#include "my/ios/iss.h"

iss_t *iss_create(char *input, size_t size)
{
	iss_t *iss;

	if (!input)
		return (NULL);
	iss = calloc(1, sizeof(iss_t));
	if (!iss)
		return (NULL);
	iss->buffer = input;
	iss->size = (size == 0) ? strlen(input) : size;
	iss->fp = fmemopen(iss->buffer, iss->size, "r");
	if (!iss->fp) {
		free(iss);
		return (NULL);
	}
	return (iss);
}

void iss_destroy(iss_t *iss, bool free_buffer)
{
	fclose(iss->fp);
	if (free_buffer)
		free(iss->buffer);
	free(iss);
}