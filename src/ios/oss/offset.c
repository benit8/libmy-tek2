/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** ios / oss / offset.c
*/

#include "my/ios/oss.h"

long oss_tell(oss_t *oss)
{
	return (ftell(oss->fp));
}

int oss_seek(oss_t *oss, long offset, int whence)
{
	return (fseek(oss->fp, offset, whence));
}