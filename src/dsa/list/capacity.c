/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** dsa / list / capacity.c
*/

#include "my/dsa/list.h"

bool list_is_empty(list_t *this)
{
	if (!this)
		return (false);
	return (!this->head);
}

size_t list_get_size(list_t *this)
{
	size_t size = 0;

	if (!this)
		return (0);
	for (list_node_t *it = this->head; it != NULL; it = it->next)
		++size;
	return (size);
}