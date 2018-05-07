/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** access.c
*/

#include "my/dsa/list.h"

void *list_at(list_t *this, size_t at)
{
	list_node_t *cur = NULL;

	if (!this || !this->head)
		return (NULL);
	cur = this->head;
	for (size_t i = 0; i < at; ++i) {
		if (!cur)
			return (NULL);
		cur = cur->next;
	}
	return (cur->data);
}

void *list_back(list_t *this)
{
	if (!this || !this->rear)
		return (NULL);
	return (this->rear->data);
}

void *list_front(list_t *this)
{
	if (!this || !this->head)
		return (NULL);
	return (this->head->data);
}