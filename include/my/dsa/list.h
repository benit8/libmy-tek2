/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** dsa / list.h
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include <stdbool.h>
#include <stdlib.h>

#include "_types.h"

////////////////////////////////////////////////////////////////////////////////

typedef struct list_node
{
	void *data;

	struct list_node *prev;
	struct list_node *next;
} list_node_t;

typedef struct list
{
	list_node_t *head;
	list_node_t *rear;

	clean_func_t *clean_up;
} list_t;

////////////////////////////////////////////////////////////////////////////////

list_t *list_create(clean_func_t *clean_up);
void list_destroy(list_t *list);

bool list_is_empty(list_t *list);
size_t list_get_size(list_t *list);

void *list_at(list_t *list, size_t at);
void *list_back(list_t *list);
void *list_front(list_t *list);

bool list_push_back(list_t *list, void *data);
void *list_pop_back(list_t *list);
bool list_push_front(list_t *list, void *data);
void *list_pop_front(list_t *list);
bool list_insert(list_t *list, size_t pos, void *data);
void list_erase(list_t *list, size_t pos);
void list_clear(list_t *list);

void list_foreach(list_t *this, void (*callback)(void *data));