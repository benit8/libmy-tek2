/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** dsa / map / modifiers.c
*/

#include "my/dsa/map.h"

static bool map_insert_new_node(map_t *map, map_node_t *prev, const char *key,
	void *data)
{
	map_node_t *node = calloc(1, sizeof(map_node_t));

	if (!node)
		return (false);
	node->key = strdup(key);
	if (!node->key) {
		free(node);
		return (false);
	}
	node->data = data;
	node->next = NULL;
	if (map->head == NULL)
		map->head = node;
	else
		prev->next = node;
	return (true);
}

static void map_remove_node(map_t *map, map_node_t *cur, map_node_t *prev)
{
	if (map->clean_up)
		(*map->clean_up)(cur->data);
	if (prev == NULL)
		map->head = cur->next;
	else
		prev->next = cur->next;
	free(cur->key);
	free(cur);
}

bool map_insert(map_t *map, const char *key, void *data)
{
	map_node_t *prev = NULL;

	if (!map)
		return (false);
	for (map_node_t *cur = map->head; cur != NULL; cur = cur->next) {
		if (strcmp(cur->key, key) == 0) {
			if (map->clean_up)
				(*map->clean_up)(cur->data);
			cur->data = data;
			return (true);
		}
		prev = cur;
	}
	return (map_insert_new_node(map, prev, key, data));
}

void map_remove(map_t *map, const char *key)
{
	map_node_t *prev = NULL;

	if (!map)
		return;
	for (map_node_t *cur = map->head; cur != NULL; cur = cur->next) {
		if (strcmp(cur->key, key) == 0) {
			map_remove_node(map, cur, prev);
			return;
		}
		prev = cur;
	}
}

void map_clear(map_t *map)
{
	map_node_t *next = NULL;

	if (!map)
		return;
	for (map_node_t *curr = map->head; curr != NULL; curr = next) {
		next = curr->next;
		if (map->clean_up)
			map->clean_up(curr->data);
		free(curr->key);
		free(curr);
	}
	map->head = NULL;
}