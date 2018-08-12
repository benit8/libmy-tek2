/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** dsa / queue.h
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include <stdbool.h>
#include <stdlib.h>

#include "_types.h"
#include "list.h"

////////////////////////////////////////////////////////////////////////////////

typedef list_node_t queue_node_t;
typedef list_t queue_t;

////////////////////////////////////////////////////////////////////////////////

queue_t *queue_create(clean_func_t *clean_up);
void queue_destroy(queue_t *queue);
void queue_clear(queue_t *queue);

bool queue_is_empty(queue_t *queue);
size_t queue_get_size(queue_t *queue);

bool queue_push(queue_t *queue, void *data);
void *queue_pop(queue_t *queue);
void *queue_peek(queue_t *queue);