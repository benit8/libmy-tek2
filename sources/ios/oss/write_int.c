/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** ios / oss / write_int.c
*/

#include "my/ios/oss.h"

bool oss_write_int(oss_t *oss, int value)
{
	if (fprintf(oss->fp, "%d", value) < 0) {
		fprintf(stderr, "oss_write_int() failed\n");
		return (false);
	}
	fflush(oss->fp);
	return (true);
}

bool oss_write_i32(oss_t *oss, int32_t value)
{
	if (fprintf(oss->fp, "%" PRIi32, value) < 0) {
		fprintf(stderr, "oss_write_i32() failed\n");
		return (false);
	}
	fflush(oss->fp);
	return (true);
}

bool oss_write_uint(oss_t *oss, unsigned int value)
{
	if (fprintf(oss->fp, "%u", value) < 0) {
		fprintf(stderr, "oss_write_uint() failed\n");
		return (false);
	}
	fflush(oss->fp);
	return (true);
}

bool oss_write_u32(oss_t *oss, uint32_t value)
{
	if (fprintf(oss->fp, "%" PRIu32, value) < 0) {
		fprintf(stderr, "oss_write_u32() failed\n");
		return (false);
	}
	fflush(oss->fp);
	return (true);
}