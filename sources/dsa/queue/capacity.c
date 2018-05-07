/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** capacity.c
*/

#include "my/dsa/queue.h"

bool queue_is_empty(queue_t *queue)
{
	return (list_is_empty((list_t *)queue));
}

size_t queue_get_size(queue_t *queue)
{
	return (list_get_size((list_t *)queue));
}