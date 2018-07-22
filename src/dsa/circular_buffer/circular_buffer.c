/*
** EPITECH PROJECT, 2018
** libmy-tek2
** File description:
** dsa / circular_buffer / circular_buffer.c
*/

#include "my/dsa/circular_buffer.h"

circular_buffer_t *cb_create(size_t size)
{
	circular_buffer_t *this = calloc(1, sizeof(circular_buffer_t));

	if (!this)
		return (NULL);
	this->size = (size == 0) ? CBUFFER_DEFAULT_SIZE : size;
	this->buffer = calloc(this->size, sizeof(char));
	if (!this->buffer) {
		free(this);
		return (NULL);
	}
	this->full = false;
	this->empty = true;
	return (this);
}

void cb_destroy(circular_buffer_t *this)
{
	free(this->buffer);
	free(this);
}