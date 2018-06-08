/*
** EPITECH PROJECT, 2018
** libmy-tek2
** File description:
** dsa / circular_buffer / modifiers.c
*/

#include "my/dsa/circular_buffer.h"

void cb_clear(circular_buffer_t *this)
{
	if (!this)
		return;
	this->head = 0;
	this->tail = 0;
	bzero(this->buffer, this->size);
}

bool cb_push(circular_buffer_t *this, char data)
{
	if (!this)
		return (false);
	if (cb_is_full(this))
		return (false);
	this->tail = (this->tail + 1) % this->size;
	this->buffer[this->tail] = data;
	return (true);
}

char cb_pop(circular_buffer_t *this)
{
	char data = 0;

	if (!this)
		return (0);
	if (cb_is_empty(this))
		return (0);
	data = this->buffer[this->head];
	this->head = (this->head + 1) % this->size;
	return (data);
}

char cb_peek(circular_buffer_t *this)
{
	if (!this)
		return (0);
	if (cb_is_empty(this))
		return (0);
	return (this->buffer[this->head]);
}