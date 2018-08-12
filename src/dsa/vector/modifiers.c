/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** dsa / vector / modifiers.c
*/

#include "my/dsa/vector.h"

void vector_clear(vector_t *this)
{
	if (!this)
		return;
	for (size_t i = 0; i < this->size; ++i) {
		if (this->clean_up)
			this->clean_up(this->data[i]);
		this->data[i] = NULL;
	}
	this->size = 0;
}

void vector_insert(vector_t *this, size_t pos, void *data)
{
	if (!this)
		return;
	if (pos < this->size) {
		if (this->size == this->capacity)
			vector_reserve(this, this->capacity + 1);
		for (size_t i = this->size; i >= 1 && i >= pos; --i)
			this->data[i] = this->data[i - 1];
	}
	else if (pos >= this->capacity)
		vector_reserve(this, pos + 1);
	this->data[pos] = data;
	this->size++;
}

void vector_push_back(vector_t *this, void *data)
{
	if (!this)
		return;
	vector_insert(this, this->size, data);
}

void vector_erase(vector_t *this, size_t pos)
{
	if (!this)
		return;
	else if (pos >= this->size)
		return;
	if (this->clean_up)
		this->clean_up(this->data[pos]);
	for (size_t i = pos; i < this->size && i < this->capacity - 1; ++i)
		this->data[i] = this->data[i + 1];
	this->size--;
}

void vector_resize(vector_t *this, size_t size)
{
	if (!this)
		return;
	if (size == this->size)
		return;
	else if (size > this->size) {
		vector_reserve(this, size);
		return;
	}
	for (size_t i = size; i < this->size; ++i) {
		if (this->clean_up)
			this->clean_up(this->data[i]);
	}
}