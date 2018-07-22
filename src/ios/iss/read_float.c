/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** ios / iss / read_float.c
*/

#include "my/ios/iss.h"

float iss_read_float(iss_t *iss)
{
	float value = 0;

	if (fscanf(iss->fp, "%f", &value) < 1) {
		fprintf(stderr, "iss_read_float() failed\n");
		return (0);
	}
	return (value);
}

double iss_read_double(iss_t *iss)
{
	double value = 0;

	if (fscanf(iss->fp, "%lf", &value) < 1) {
		fprintf(stderr, "iss_read_double() failed\n");
		return (0);
	}
	return (value);
}