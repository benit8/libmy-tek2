/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** dsa / list / modifiers.c
*/

#include "my/dsa/list.h"

static bool list_create_insert_node(void *data, list_node_t *prev,
	list_node_t *next)
{
	list_node_t *new = NULL;

	new = calloc(1, sizeof(list_node_t));
	if (!new)
		return (false);
	new->data = data;
	new->next = next;
	prev->next = new;
	return (true);
}

bool list_insert(list_t *this, size_t pos, void *data)
{
	list_node_t *cur = NULL;

	if (!this || !this->head)
		return (false);
	if (pos > list_get_size(this))
		return (false);
	if (pos == 0)
		return (list_push_front(this, data));
	else if (pos == list_get_size(this))
		return (list_push_back(this, data));
	else {
		cur = this->head;
		for (size_t i = 0; i < pos - 1; ++i, cur = cur->next);
		return (list_create_insert_node(data, cur, cur->next));
	}
	return (false);
}

void list_erase(list_t *this, size_t pos)
{
	list_node_t *it = NULL;
	list_node_t *to_del = NULL;

	if (!this)
		return;
	else if (!this->head || pos >= list_get_size(this))
		return;
	if (pos == 0)
		this->clean_up(list_pop_front(this));
	else if (pos == list_get_size(this) - 1)
		this->clean_up(list_pop_back(this));
	else {
		it = this->head;
		for (size_t i = 0; i < pos - 1; ++i, it = it->next);
		to_del = it->next;
		it->next = to_del->next;
		this->clean_up(to_del->data);
		free(to_del);
	}
}

void list_clear(list_t *this)
{
	list_node_t *next = NULL;

	if (!this)
		return;
	for (list_node_t *curr = this->head; curr != NULL; curr = next) {
		next = curr->next;
		this->clean_up(curr->data);
		free(curr);
	}
	this->head = NULL;
}