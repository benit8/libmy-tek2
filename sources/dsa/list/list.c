/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** list.c
*/

#include "my/dsa/list.h"

list_t *list_create(clean_func_t *clean_up)
{
	list_t *this = calloc(1, sizeof(list_t));

	if (this) {
		this->head = NULL;
		this->rear = NULL;
		this->clean_up = clean_up;
	}
	return (this);
}

void list_destroy(list_t *this)
{
	if (!this)
		return;
	list_clear(this);
	free(this);
}