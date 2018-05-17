/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** ios / oss / write_char.c
*/

#include "my/ios/oss.h"

bool oss_write_char(oss_t *oss, char value)
{
	if (fprintf(oss->fp, "%c", value) < 0) {
		fprintf(stderr, "oss_write_char() failed\n");
		return (false);
	}
	fflush(oss->fp);
	return (true);
}

bool oss_write_i8(oss_t *oss, int8_t value)
{
	if (fprintf(oss->fp, "%" PRIi8, value) < 0) {
		fprintf(stderr, "oss_write_i8() failed\n");
		return (false);
	}
	fflush(oss->fp);
	return (true);
}

bool oss_write_uchar(oss_t *oss, unsigned char value)
{
	if (fprintf(oss->fp, "%u", value) < 0) {
		fprintf(stderr, "oss_write_uchar() failed\n");
		return (false);
	}
	fflush(oss->fp);
	return (true);
}

bool oss_write_u8(oss_t *oss, uint8_t value)
{
	if (fprintf(oss->fp, "%" PRIu8, value) < 0) {
		fprintf(stderr, "oss_write_u8() failed\n");
		return (false);
	}
	fflush(oss->fp);
	return (true);
}