/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** ios / iss / read_bool.c
*/

#include "my/ios/iss.h"

bool iss_read_bool(iss_t *iss)
{
	char value = false;

	if (fscanf(iss->fp, "%c", &value) < 1) {
		fprintf(stderr, "iss_read_bool() failed\n");
		return (false);
	}
	return (isgraph(value) && value != '0');
}