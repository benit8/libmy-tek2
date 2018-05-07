/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** file_get_lines.c
*/

#include "my/fs.h"

char **file_get_lines(const char *filepath)
{
	char *content = file_get_contents(filepath);
	char **array = NULL;

	if (!content)
		return (NULL);
	array = explode("\n", content);
	free(content);
	return (array);
}