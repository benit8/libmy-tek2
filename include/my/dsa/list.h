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

	struct list_node *next;
} list_node_t;

typedef struct list
{
	list_node_t *head;

	clean_func_t *clean_up;
} list_t;

////////////////////////////////////////////////////////////////////////////////

list_t *list_create(clean_func_t *clean_up);
void list_destroy(list_t *list);

bool list_is_empty(list_t *list);
size_t list_get_size(list_t *list);

void *list_at(list_t *list, size_t pos);
void *list_front(list_t *list);
void *list_back(list_t *list);

void list_clear(list_t *list);
bool list_insert(list_t *list, size_t pos, void *data);
void list_erase(list_t *list, size_t pos);
void list_remove(list_t *list, void *value);

bool list_push_front(list_t *list, void *data);
void *list_pop_front(list_t *list);
bool list_push_back(list_t *list, void *data);
void *list_pop_back(list_t *list);

void list_merge(list_t *list, list_t *other, comp_func_t *cmp);
void list_reverse(list_t *list);
void list_unique(list_t *list, comp_func_t *comp);
void list_sort(list_t *list, comp_func_t *comp);
void list_foreach(list_t *list, void (*callback)(void *data));