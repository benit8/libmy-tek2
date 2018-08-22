/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** dsa / list / pushpop.c
*/

#include "my/dsa/list.h"

bool list_push_front(list_t *this, void *data)
{
	list_node_t *node = NULL;

	if (!this)
		return (false);
	node = calloc(1, sizeof(list_node_t));
	if (!node)
		return (false);
	node->data = data;
	node->next = NULL;
	if (!this->head) {
		this->head = node;
		return (true);
	}
	node->next = this->head;
	this->head = node;
	return (true);
}

void *list_pop_front(list_t *this)
{
	list_node_t *first = NULL;
	void *data = NULL;

	if (!this || !this->head)
		return (NULL);
	first = this->head;
	data = first->data;
	free(first);
	this->head = this->head->next;
	return (data);
}

bool list_push_back(list_t *this, void *data)
{
	list_node_t *node = NULL;
	list_node_t *rear = NULL;

	if (!this)
		return (false);
	node = calloc(1, sizeof(list_node_t));
	if (!node)
		return (false);
	node->data = data;
	node->next = NULL;
	if (!this->head) {
		this->head = node;
		return (true);
	}
	for (rear = this->head; rear->next; rear = rear->next);
	rear->next = node;
	return (true);
}

void *list_pop_back(list_t *this)
{
	list_node_t *last = NULL;
	void *data = NULL;

	if (!this || !this->head)
		return (NULL);
	for (last = this->head; last->next; last = last->next);
	data = last->data;
	free(last);
	if (!this->head->next)
		this->head = NULL;
	return (data);
}