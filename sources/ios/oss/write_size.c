/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** ios / oss / write_long.c
*/

#include "my/ios/oss.h"

bool oss_write_ssize(oss_t *oss, ssize_t value)
{
	if (fprintf(oss->fp, "%zd", value) < 0) {
		fprintf(stderr, "oss_write_ssize() failed\n");
		return (false);
	}
	fflush(oss->fp);
	return (true);
}

bool oss_write_size(oss_t *oss, size_t value)
{
	if (fprintf(oss->fp, "%zu", value) < 0) {
		fprintf(stderr, "oss_write_size() failed\n");
		return (false);
	}
	fflush(oss->fp);
	return (true);
}