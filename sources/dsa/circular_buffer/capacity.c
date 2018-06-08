/*
** EPITECH PROJECT, 2018
** libmy-tek2
** File description:
** dsa / circular_buffer / capacity.c
*/

#include "my/dsa/circular_buffer.h"

bool cb_is_full(circular_buffer_t *this)
{
	if (!this)
		return (false);
	return (this->head == (this->tail + 1) % this->size);
}

bool cb_is_empty(circular_buffer_t *this)
{
	if (!this)
		return (false);
	return (this->head == this->tail);
}