/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** ios / iss / read_long.c
*/

#include "my/ios/iss.h"

long iss_read_long(iss_t *iss)
{
	long value = 0;

	if (fscanf(iss->fp, "%ld", &value) < 1) {
		fprintf(stderr, "iss_read_long() failed\n");
		return (0);
	}
	return (value);
}

int64_t iss_read_i64(iss_t *iss)
{
	int64_t value = 0;

	if (fscanf(iss->fp, "%" SCNi64, &value) < 1) {
		fprintf(stderr, "iss_read_i64() failed\n");
		return (0);
	}
	return (value);
}

unsigned long iss_read_ulong(iss_t *iss)
{
	unsigned long value = 0;

	if (fscanf(iss->fp, "%lu", &value) < 1) {
		fprintf(stderr, "iss_read_ulong() failed\n");
		return (0);
	}
	return (value);
}

uint64_t iss_read_u64(iss_t *iss)
{
	uint64_t value = 0;

	if (fscanf(iss->fp, "%" SCNu64, &value) < 1) {
		fprintf(stderr, "iss_read_u64() failed\n");
		return (0);
	}
	return (value);
}