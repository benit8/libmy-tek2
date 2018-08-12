/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** dsa / vector / access.c
*/

#include "my/dsa/vector.h"

void *vector_at(vector_t *this, size_t pos)
{
	if (!this)
		return (NULL);
	else if (pos >= vector_get_size(this))
		return (NULL);
	else
		return (this->data[pos]);
}

void *vector_front(vector_t *this)
{
	if (!this)
		return (NULL);
	else if (vector_get_size(this) == 0)
		return (NULL);
	return (this->data[0]);
}

void *vector_back(vector_t *this)
{
	if (!this)
		return (NULL);
	else if (vector_get_size(this) == 0)
		return (NULL);
	return (vector_at(this, vector_get_size(this) - 1));
}