/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** string / str_toupper.c
*/

#include "my/string.h"

char *str_toupper(char *str)
{
	if (!str)
		return (NULL);
	for (char *s = str; *s; ++s)
		*s = toupper(*s);
	return (str);
}