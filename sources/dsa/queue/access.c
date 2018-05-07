/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** access.c
*/

#include "my/dsa/queue.h"

void *queue_peek(queue_t *queue)
{
	return (list_front((list_t *)queue));
}