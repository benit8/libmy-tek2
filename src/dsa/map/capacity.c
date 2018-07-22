/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** capacity.c
*/

#include "my/dsa/map.h"

bool map_is_empty(map_t *map)
{
	return (map != NULL && map->head == NULL);
}

size_t map_get_size(map_t *map)
{
	size_t size = 0;

	if (!map)
		return (0);
	for (map_node_t *curr = map->head; curr != NULL; curr = curr->next)
		++size;
	return (size);
}