/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** regex / split.c
*/

#include "my/regex.h"

static bool append(char ***oldp, size_t *n, char *data, size_t len)
{
	char **new = NULL;

	if (len == 0)
		return (false);
	new = realloc(*oldp, sizeof(char *) * ((*n) + 2));
	if (!new)
		return (false);
	new[*n] = strndup(data, len);
	if (!new[*n])
		return (false);
	new[(*n) + 1] = NULL;
	(*n)++;
	*oldp = new;
	return (true);
}

static void split_loop(regex_t *reg, char *sbj, char ***array)
{
	regmatch_t mat = {0, 0};
	size_t n = 0;

	while (*sbj && regexec(reg, sbj, 1, &mat, 0) != REG_NOMATCH) {
		if (mat.rm_so == 0 && mat.rm_eo == 0) {
			sbj++;
			continue;
		}
		else if (!append(array, &n, sbj, MAX(1, mat.rm_so)))
			return;
		sbj += mat.rm_eo;
	}
	append(array, &n, sbj, strlen(sbj));
}

char **regex_split(const char *pat, char *sbj)
{
	regex_t reg;
	char **array = NULL;

	if (!pat || !sbj)
		return (NULL);
	else if (pat[0] == '\0')
		pat = ".{1}";
	if (!regex_create(&reg, pat))
		return (NULL);
	split_loop(&reg, sbj, &array);
	regfree(&reg);
	return (array);
}