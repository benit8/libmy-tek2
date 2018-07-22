/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** regex / match.c
*/

#include "my/regex.h"

ssize_t regex_match(const char *pat, char *sbj)
{
	regex_t reg;
	regmatch_t mat = {0, 0};
	ssize_t n = 0;

	if (!pat || !sbj)
		return (-1);
	if (!regex_create(&reg, pat))
		return (-1);
	while (*sbj && regexec(&reg, sbj, 1, &mat, 0) != REG_NOMATCH) {
		if (mat.rm_so == 0 && mat.rm_eo == 0)
			sbj++;
		else {
			sbj += mat.rm_eo;
			++n;
		}
	}
	regfree(&reg);
	return (n);
}