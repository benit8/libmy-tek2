/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** string / str_tolower.c
*/

#include "my/string.h"

char *str_tolower(char *str)
{
	if (!str)
		return (NULL);
	for (char *s = str; *s; ++s)
		*s = tolower(*s);
	return (str);
}