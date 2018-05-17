/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** ios / oss / write_bool.c
*/

#include "my/ios/oss.h"

bool oss_write_bool(oss_t *oss, bool value)
{
	if (fprintf(oss->fp, "%d", value) < 0) {
		fprintf(stderr, "oss_write_bool() failed\n");
		return (false);
	}
	fflush(oss->fp);
	return (true);
}