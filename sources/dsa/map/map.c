/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** map.c
*/

#include "my/dsa/map.h"

map_t *map_create(clean_func_t *clean_up)
{
	map_t *map = calloc(1, sizeof(map_t));

	if (map) {
		map->head = NULL;
		map->clean_up = clean_up;
	}
	return (map);
}

void map_destroy(map_t *map)
{
	if (!map)
		return;
	map_clear(map);
	free(map);
}