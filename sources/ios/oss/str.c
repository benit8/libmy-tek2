/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** ios / oss / str.c
*/

#include "my/ios/oss.h"

char *oss_str(oss_t *oss)
{
	return (strdup(oss->buffer ? oss->buffer : ""));
}