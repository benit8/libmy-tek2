/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** foreach.c
*/

#include "my/dsa/map.h"

void map_foreach(map_t *map, void (*callback)(const char *key, void *data))
{
	if (!map)
		return;
	for (map_node_t *cur = map->head; cur != NULL; cur = cur->next) {
		(*callback)(cur->key, cur->data);
	}
}