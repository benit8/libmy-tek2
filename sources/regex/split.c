/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** regex / split.c
*/

#include "my/regex.h"

static bool append(char ***oldp, size_t *n, const char *data, size_t len)
{
	char **new = realloc(*oldp, sizeof(char *) * (*n + 2));

	if (!new)
		return (false);
	new[*n] = strndup(data, len);
	if (!new[*n])
		return (false);
	(*n)++;
	*oldp = new;
	return (true);
}

char **regex_split(char *pattern, char *subject)
{
	regex_t regex;
	regmatch_t match;
	size_t n = 0;
	char **array = NULL;

	if (!regex_create(&regex, pattern))
		return (NULL);
	while (regexec(&regex, subject, 1, &match, 0) != REG_NOMATCH) {
		if (!append(&array, &n, subject, match.rm_so)) {
			regfree(&regex);
			return (array);
		}
		subject += match.rm_eo;
	}
	regfree(&regex);
	append(&array, &n, subject, match.rm_so - 1);
	return (array);
}