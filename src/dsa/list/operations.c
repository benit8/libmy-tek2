/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** operations.c
*/

#include "my/dsa/list.h"

void list_foreach(list_t *this, void (*callback)(void *))
{
	if (!this || !callback)
		return;
	for (list_node_t *cur = this->head; cur != NULL; cur = cur->next) {
		(*callback)(cur->data);
	}
}