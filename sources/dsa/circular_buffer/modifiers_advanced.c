/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** dsa / circular_buffer / modifiers_advanced.c
*/

#include "my/dsa/circular_buffer.h"

bool cb_push_string(circular_buffer_t *this, char *string)
{
	for (size_t i = 0; string[i]; ++i) {
		if (this->full)
			return (false);
		cb_push(this, string[i]);
	}
	return (true);
}

char *cb_get_line(circular_buffer_t *this)
{
	size_t len = 0;
	char *line = NULL;

	if (this->empty)
		return (NULL);
	for (size_t peek_pos = 0; ; ++len) {
		peek_pos = (this->head + len) % this->size;
		if (peek_pos == this->tail)
			return (NULL);
		else if (this->buffer[peek_pos] == '\n')
			break;
	}
	line = calloc(len + 1, sizeof(char));
	if (!line)
		return (NULL);
	for (size_t j = 0; j < len; ++j)
		line[j] = cb_pop(this);
	cb_pop(this);
	return (line);
}