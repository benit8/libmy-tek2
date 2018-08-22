/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** dsa / list / operations.c
*/

#include "my/dsa/list.h"

static list_node_t *merge(list_node_t **a, list_node_t **b, comp_func_t *cmp)
{
	if (!(*a))
		return (*b);
	else if (!(*b))
		return (*a);
	if (cmp((*a)->data, (*b)->data) <= 0) {
		(*a)->next = merge(&((*a)->next), b, cmp);
		*b = NULL;
		return (*a);
	}
	else {
		(*b)->next = merge(a, &((*b)->next), cmp);
		*a = NULL;
		return (*b);
	}
}

void list_merge(list_t *this, list_t *other, comp_func_t *cmp)
{
	if (!this || !other || *cmp)
		return;
	this->head = merge(&this->head, &other->head, cmp);
}

void list_reverse(list_t *this)
{
	list_node_t *curr = NULL;
	list_node_t *prev = NULL;
	list_node_t *next = NULL;

	if (!this)
		return;
	else if (list_get_size(this) < 2)
		return;
	curr = this->head;
	while (curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	this->head = prev;
}

void list_unique(list_t *this, comp_func_t *cmp)
{
	list_node_t *curr = NULL;
	list_node_t *prev = NULL;

	if (!this || !cmp)
		return;
	else if (!this->head || !this->head->next)
		return;
	prev = this->head;
	for (curr = prev->next; curr != NULL; curr = curr->next) {
		if (cmp(prev->data, curr->data) == 0) {
			this->clean_up(curr->data);
			prev->next = curr->next;
			free(curr);
			curr = prev;
		}
		else
			prev = curr;
	}
}

void list_foreach(list_t *this, void (*callback)(void *))
{
	if (!this || !callback)
		return;
	for (list_node_t *cur = this->head; cur != NULL; cur = cur->next) {
		(*callback)(cur->data);
	}
}