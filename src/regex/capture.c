/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** regex / capture.c
*/

#include "my/regex.h"

static bool append(char ***oldp, size_t *n, char **subjp, regmatch_t *match)
{
	char **new = realloc(*oldp, sizeof(char *) * ((*n) + 2));

	if (!new)
		return (false);
	new[*n] = strndup(*subjp + match->rm_so, match->rm_eo - match->rm_so);
	if (!new[*n])
		return (false);
	new[(*n) + 1] = NULL;
	*oldp = new;
	(*n)++;
	return (true);
}

static void capture_loop(regex_t *reg, char *sbj, char ***array)
{
	regmatch_t mat = {0, 0};
	size_t n = 0;

	while (*sbj && regexec(reg, sbj, 1, &mat, 0) != REG_NOMATCH) {
		if (mat.rm_so == 0 && mat.rm_eo == 0) {
			sbj++;
			continue;
		}
		if (!append(array, &n, &sbj, &mat)) {
			regfree(reg);
			return;
		}
		sbj += mat.rm_eo;
	}
}

char **regex_capture(const char *pat, char *sbj)
{
	regex_t reg;
	char **array = NULL;

	if (!pat || !sbj)
		return (NULL);
	if (!regex_create(&reg, pat))
		return (NULL);
	array = calloc(1, sizeof(char *));
	if (!array) {
		regfree(&reg);
		return (NULL);
	}
	capture_loop(&reg, sbj, &array);
	regfree(&reg);
	return (array);
}