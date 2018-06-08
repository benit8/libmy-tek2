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
	this->full = false;
	this->empty = true;
	bzero(this->buffer, this->size);
}

bool cb_push(circular_buffer_t *this, char data)
{
	if (!this)
		return (false);
	if (this->full)
		return (false);
	this->empty = false;
	this->buffer[this->tail] = data;
	this->tail = (this->tail + 1) % this->size;
	if (this->tail == this->head)
		this->full = true;
	return (true);
}

char cb_pop(circular_buffer_t *this)
{
	char data = 0;

	if (!this)
		return (0);
	if (this->empty)
		return (0);
	this->full = false;
	data = this->buffer[this->head];
	this->head = (this->head + 1) % this->size;
	if (this->head == this->tail)
		this->empty = true;
	return (data);
}

char cb_peek(circular_buffer_t *this)
{
	if (!this)
		return (0);
	if (this->empty)
		return (0);
	return (this->buffer[this->head]);
}