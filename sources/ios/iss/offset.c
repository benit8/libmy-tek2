/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** ios / iss / offset.c
*/

#include "my/ios/iss.h"

long iss_tell(iss_t *iss)
{
	return (ftell(iss->fp));
}

int iss_seek(iss_t *iss, long offset, int whence)
{
	return (fseek(iss->fp, offset, whence));
}