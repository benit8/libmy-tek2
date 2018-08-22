/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** dsa / list / list.c
*/

#include "my/dsa/list.h"

static void dummy_clean_up(void *data)
{
	(void)data;
}

list_t *list_create(clean_func_t *clean_up)
{
	list_t *this = calloc(1, sizeof(list_t));

	if (this) {
		this->clean_up = (clean_up ? clean_up : dummy_clean_up);
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