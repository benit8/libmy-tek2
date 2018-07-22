/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** ios / oss / write_float.c
*/

#include "my/ios/oss.h"

bool oss_write_float(oss_t *oss, float value)
{
	if (fprintf(oss->fp, "%f", value) < 0) {
		fprintf(stderr, "oss_write_float() failed\n");
		return (false);
	}
	fflush(oss->fp);
	return (true);
}

bool oss_write_double(oss_t *oss, double value)
{
	if (fprintf(oss->fp, "%f", value) < 0) {
		fprintf(stderr, "oss_write_double() failed\n");
		return (false);
	}
	fflush(oss->fp);
	return (true);
}