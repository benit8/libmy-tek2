/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** ios / oss / oss.c
*/

#include "my/ios/oss.h"

oss_t *oss_create(void)
{
	oss_t *oss = calloc(1, sizeof(oss_t));

	if (!oss)
		return (NULL);
	oss->buffer = NULL;
	oss->size = 0;
	oss->fp = open_memstream(&oss->buffer, &oss->size);
	if (!oss->fp) {
		free(oss);
		return (NULL);
	}
	return (oss);
}

void oss_destroy(oss_t *oss)
{
	fclose(oss->fp);
	free(oss->buffer);
	free(oss);
}