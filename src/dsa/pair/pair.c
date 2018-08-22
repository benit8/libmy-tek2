/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** dsa / pair / pair.c
*/

#include "my/dsa/pair.h"

pair_t *pair_create(void *first, void *second)
{
	pair_t *this = calloc(1, sizeof(pair_t));

	if (this) {
		this->first = first;
		this->second = second;
	}
	return (this);
}

void pair_destroy(pair_t *this)
{
	if (!this)
		return;
	free(this);
}