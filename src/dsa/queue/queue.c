/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** queue.c
*/

#include "my/dsa/queue.h"

queue_t *queue_create(clean_func_t *clean_up)
{
	return ((queue_t *)list_create(clean_up));
}

void queue_destroy(queue_t *queue)
{
	list_destroy((list_t *)queue);
}