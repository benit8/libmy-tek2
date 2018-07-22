/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** ios / iss / ignore.c
*/

#include "my/ios/iss.h"

void iss_ignore(iss_t *iss, size_t n, int d)
{
	int c;

	for (size_t i = 0; i < n; ++i) {
		c = fgetc(iss->fp);
		if (c == EOF || c == d)
			break;
	}
}