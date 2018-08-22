/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** dsa / map / access.c
*/

#include "my/dsa/map.h"

bool map_has_key(map_t *map, const char *key)
{
	if (!map)
		return (false);
	for (map_node_t *cur = map->head; cur != NULL; cur = cur->next) {
		if (strcmp(cur->key, key) == 0)
			return (true);
	}
	return (false);
}

void *map_at(map_t *map, const char *key)
{
	if (!map)
		return (NULL);
	for (map_node_t *cur = map->head; cur != NULL; cur = cur->next) {
		if (strcmp(cur->key, key) == 0)
			return (cur->data);
	}
	return (NULL);
}

char **map_get_keys(map_t *map)
{
	size_t i = 0;
	size_t size = 0;
	char **keys = NULL;

	if (!map)
		return (NULL);
	size = map_get_size(map);
	keys = calloc(size + 1, sizeof(char *));
	if (!keys)
		return (NULL);
	for (map_node_t *cur = map->head; cur != NULL; cur = cur->next)
		keys[i++] = strdup(cur->key);
	return (keys);
}