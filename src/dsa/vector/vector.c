/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** dsa / vector / vector.c
*/

#include "my/dsa/vector.h"

vector_t *vector_create(clean_func_t *clean_up)
{
	vector_t *this = calloc(1, sizeof(vector_t));

	if (!this)
		return (NULL);
	this->clean_up = clean_up;
	return (this);
}

void vector_destroy(vector_t *this)
{
	if (!this)
		return;
	vector_clear(this);
	if (this->data)
		free(this->data);
	free(this);
}