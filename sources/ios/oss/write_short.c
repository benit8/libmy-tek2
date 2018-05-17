/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** ios / oss / write_short.c
*/

#include "my/ios/oss.h"

bool oss_write_short(oss_t *oss, short value)
{
	if (fprintf(oss->fp, "%hd", value) < 0) {
		fprintf(stderr, "oss_write_short() failed\n");
		return (false);
	}
	fflush(oss->fp);
	return (true);
}

bool oss_write_i16(oss_t *oss, int16_t value)
{
	if (fprintf(oss->fp, "%" PRIi16, value) < 0) {
		fprintf(stderr, "oss_write_i16() failed\n");
		return (false);
	}
	fflush(oss->fp);
	return (true);
}

bool oss_write_ushort(oss_t *oss, unsigned short value)
{
	if (fprintf(oss->fp, "%hu", value) < 0) {
		fprintf(stderr, "oss_write_ushort() failed\n");
		return (false);
	}
	fflush(oss->fp);
	return (true);
}

bool oss_write_u16(oss_t *oss, uint16_t value)
{
	if (fprintf(oss->fp, "%" PRIu16, value) < 0) {
		fprintf(stderr, "oss_write_u16() failed\n");
		return (false);
	}
	fflush(oss->fp);
	return (true);
}