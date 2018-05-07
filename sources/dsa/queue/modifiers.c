/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** modifiers.c
*/

#include "my/dsa/queue.h"

bool queue_push(queue_t *queue, void *data)
{
	return (list_push_back((list_t *)queue, data));
}

void *queue_pop(queue_t *queue)
{
	return (list_pop_front((list_t *)queue));
}

void queue_clear(queue_t *queue)
{
	list_clear((list_t *)queue);
}