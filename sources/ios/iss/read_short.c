/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** ios / iss / read_short.c
*/

#include "my/ios/iss.h"

short iss_read_short(iss_t *iss)
{
	short value = 0;

	if (fscanf(iss->fp, "%hd", &value) < 1) {
		fprintf(stderr, "iss_read_short() failed\n");
		return (0);
	}
	return (value);
}

int16_t iss_read_i16(iss_t *iss)
{
	int16_t value = 0;

	if (fscanf(iss->fp, "%hd", &value) < 1) {
		fprintf(stderr, "iss_read_i16() failed\n");
		return (0);
	}
	return (value);
}

unsigned short iss_read_ushort(iss_t *iss)
{
	unsigned short value = 0;

	if (fscanf(iss->fp, "%hu", &value) < 1) {
		fprintf(stderr, "iss_read_ushort() failed\n");
		return (0);
	}
	return (value);
}

uint16_t iss_read_u16(iss_t *iss)
{
	uint16_t value = 0;

	if (fscanf(iss->fp, "%hu", &value) < 1) {
		fprintf(stderr, "iss_read_u16() failed\n");
		return (0);
	}
	return (value);
}