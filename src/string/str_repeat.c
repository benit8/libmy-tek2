/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** string / str_repeat.c
*/

#include "my/string.h"

char *str_repeat(char *str, size_t times)
{
	char *output = NULL;
	size_t len = 0;

	if (!str)
		return (NULL);
	len = strlen(str);
	if (len == 0 || times == 0)
		return (strdup(""));
	output = calloc(len * times + 1, sizeof(char));
	if (!output)
		return (NULL);
	for (size_t i = 0; i < times; ++i)
		output = strcat(output, str);
	return (output);
}