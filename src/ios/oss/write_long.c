/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** ios / oss / write_long.c
*/

#include "my/ios/oss.h"

bool oss_write_long(oss_t *oss, long value)
{
	if (fprintf(oss->fp, "%ld", value) < 0) {
		fprintf(stderr, "oss_write_long() failed\n");
		return (false);
	}
	fflush(oss->fp);
	return (true);
}

bool oss_write_i64(oss_t *oss, int64_t value)
{
	if (fprintf(oss->fp, "%" PRIi64, value) < 0) {
		fprintf(stderr, "oss_write_i64() failed\n");
		return (false);
	}
	fflush(oss->fp);
	return (true);
}

bool oss_write_ulong(oss_t *oss, unsigned long value)
{
	if (fprintf(oss->fp, "%lu", value) < 0) {
		fprintf(stderr, "oss_write_ulong() failed\n");
		return (false);
	}
	fflush(oss->fp);
	return (true);
}

bool oss_write_u64(oss_t *oss, uint64_t value)
{
	if (fprintf(oss->fp, "%" PRIu64, value) < 0) {
		fprintf(stderr, "oss_write_u64() failed\n");
		return (false);
	}
	fflush(oss->fp);
	return (true);
}