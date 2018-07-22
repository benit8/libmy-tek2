/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** ios / iss / is_good.c
*/

#include "my/ios/iss.h"

bool iss_is_good(iss_t *iss)
{
	return (feof(iss->fp) == 0);
}