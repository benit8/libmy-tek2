/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** dsa / vector / capacity.c
*/

#include "my/dsa/vector.h"

bool vector_is_empty(vector_t *this)
{
	if (!this)
		return (false);
	return (this->size == 0);
}

size_t vector_get_size(vector_t *this)
{
	if (!this)
		return (0);
	return (this->size);
}

size_t vector_get_capacity(vector_t *this)
{
	if (!this)
		return (0);
	return (this->capacity);
}

void vector_reserve(vector_t *this, size_t new_cap)
{
	size_t goal = 0;
	void *new = NULL;

	if (!this)
		return;
	if (new_cap <= this->capacity)
		return;
	goal = MAX(VECTOR_MIN_SIZE, this->capacity);
	for (; goal < new_cap; goal *= VECTOR_GROTH_FACTOR);
	new = calloc(goal, sizeof(ptr_t));
	if (!new)
		return;
	memcpy(new, this->data, this->size * sizeof(ptr_t));
	free(this->data);
	this->data = new;
	this->capacity = goal;
}

void vector_shrink_to_fit(vector_t *this)
{
	void *new = NULL;

	if (!this)
		return;
	if (this->capacity == 0 || this->size == this->capacity)
		return;
	new = calloc(this->size, sizeof(ptr_t));
	if (!new)
		return;
	memcpy(new, this->data, this->size * sizeof(ptr_t));
	free(this->data);
	this->data = new;
	this->capacity = this->size;
}