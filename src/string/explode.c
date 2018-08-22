/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** string / explode.c
*/

#include "my/string.h"

static bool explode_append(char ***tabp, size_t *sizep, char *token)
{
	char **ntab = realloc(*tabp, sizeof(char *) * ((*sizep) + 2));

	if (!ntab)
		return (false);
	ntab[(*sizep)] = strdup(token);
	if (!ntab[(*sizep)])
		return (false);
	ntab[++(*sizep)] = NULL;
	*tabp = ntab;
	return (true);
}

char **explode(char *original, const char *delim)
{
	size_t tokens = 0;
	char *token;
	char *copy = strdup(original);
	char *c = copy;
	char **tab;

	if (!copy)
		return (NULL);
	tab = calloc(1, sizeof(char *));
	if (!tab) {
		free(copy);
		return (NULL);
	}
	while ((token = strsep(&c, delim)) != NULL) {
		if (!explode_append(&tab, &tokens, token))
			break;
	}
	free(copy);
	return (tab);
}