/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** ios / iss / read_char.c
*/

#include "my/ios/iss.h"

char iss_read_char(iss_t *iss)
{
	char value = 0;

	if (fscanf(iss->fp, "%c", &value) < 1) {
		fprintf(stderr, "iss_read_char() failed\n");
		return (0);
	}
	return (value);
}

int8_t iss_read_i8(iss_t *iss)
{
	int8_t value = 0;

	if (fscanf(iss->fp, "%c", &value) < 1) {
		fprintf(stderr, "iss_read_i8() failed\n");
		return (0);
	}
	return (value);
}

unsigned char iss_read_uchar(iss_t *iss)
{
	unsigned char value = 0;

	if (fscanf(iss->fp, "%hhu", &value) < 1) {
		fprintf(stderr, "iss_read_uchar() failed\n");
		return (0);
	}
	return (value);
}

uint8_t iss_read_u8(iss_t *iss)
{
	uint8_t value = 0;

	if (fscanf(iss->fp, "%hhu", &value) < 1) {
		fprintf(stderr, "iss_read_u8() failed\n");
		return (0);
	}
	return (value);
}