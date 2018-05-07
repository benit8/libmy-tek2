/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** ios / iss / read_int.c
*/

#include "my/ios/iss.h"

int iss_read_int(iss_t *iss)
{
	int value = 0;

	if (fscanf(iss->fp, "%d", &value) < 1) {
		fprintf(stderr, "iss_read_int() failed\n");
		return (0);
	}
	return (value);
}

int32_t iss_read_i32(iss_t *iss)
{
	int32_t value = 0;

	if (fscanf(iss->fp, "%d", &value) < 1) {
		fprintf(stderr, "iss_read_i32() failed\n");
		return (0);
	}
	return (value);
}

unsigned int iss_read_uint(iss_t *iss)
{
	unsigned int value = 0;

	if (fscanf(iss->fp, "%u", &value) < 1) {
		fprintf(stderr, "iss_read_uint() failed\n");
		return (0);
	}
	return (value);
}

uint32_t iss_read_u32(iss_t *iss)
{
	uint32_t value = 0;

	if (fscanf(iss->fp, "%u", &value) < 1) {
		fprintf(stderr, "iss_read_u32() failed\n");
		return (0);
	}
	return (value);
}