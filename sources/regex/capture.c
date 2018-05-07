/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** regex / capture.c
*/

#include "my/regex.h"

static bool append(char ***oldp, size_t *n, char **sp, regmatch_t *match)
{
	size_t spanlen = 0;
	char **new = realloc(*oldp, sizeof(char *) * ((*n) + 2));

	if (!new)
		return (false);
	spanlen = match->rm_eo - match->rm_so;
	new[*n] = strndup(*sp + match->rm_so, spanlen);
	if (new[*n] == NULL)
		return (false);
	*oldp = new;
	(*n)++;
	*sp += match->rm_eo;
	return (true);
}

char **regex_capture(const char *pattern, char *subject)
{
	regex_t regex;
	regmatch_t match;
	size_t n = 0;
	char **array = NULL;

	if (!pattern || !subject)
		return (NULL);
	if (!regex_create(&regex, pattern))
		return (NULL);
	while (regexec(&regex, subject, 1, &match, 0) != REG_NOMATCH) {
		if (!append(&array, &n, &subject, &match)) {
			regfree(&regex);
			return (array);
		}
	}
	regfree(&regex);
	return (array);
}