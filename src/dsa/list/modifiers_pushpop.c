/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** data.c
*/

#include "my/dsa/list.h"

bool list_push_back(list_t *this, void *data)
{
	list_node_t *node = NULL;

	if (!this)
		return (false);
	node = calloc(1, sizeof(list_node_t));
	if (!node)
		return (false);
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	if (!this->head && !this->rear) {
		this->head = node;
		this->rear = node;
		return (true);
	}
	node->prev = this->rear;
	this->rear->next = node;
	this->rear = node;
	return (true);
}

void *list_pop_back(list_t *this)
{
	list_node_t *last = NULL;
	void *data = NULL;

	if (!this || !this->head)
		return (NULL);
	last = this->rear;
	data = last->data;
	if (!this->head->next)
		this->head = NULL;
	else
		this->rear->prev->next = NULL;
	this->rear = this->rear->prev;
	free(last);
	return (data);
}

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
	node->prev = NULL;
	if (!this->head && !this->rear) {
		this->head = node;
		this->rear = node;
		return (true);
	}
	this->head->prev = node;
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
	if (!this->head->next)
		this->rear = NULL;
	else
		this->head->next->prev = NULL;
	this->head = this->head->next;
	free(first);
	return (data);
}