/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** regex / replace.c
*/

#include "my/regex.h"

static void replace_loop(regex_t *reg, FILE *ss, char *sbj, const char *rep)
{
	regmatch_t mat = {0, 0};

	while (*sbj && regexec(reg, sbj, 1, &mat, 0) != REG_NOMATCH) {
		if (mat.rm_so == 0 && mat.rm_eo == 0) {
			sbj++;
			continue;
		}
		fprintf(ss, "%.*s%s", mat.rm_so, sbj, rep);
		sbj += mat.rm_eo;
	}
	fprintf(ss, sbj);
	fflush(ss);
}

static bool prepare_regex(FILE *ss, const char *pat, const char *rep, char *sbj)
{
	regex_t reg;

	if (!regex_create(&reg, pat))
		return (false);
	replace_loop(&reg, ss, sbj, rep);
	regfree(&reg);
	return (true);
}

char *regex_replace(const char *pat, const char *rep, char *sbj)
{
	bool ret = false;
	size_t size = 0;
	char *str = NULL;
	FILE *ss = NULL;

	if ((!pat || !rep) || !sbj)
		return (NULL);
	ss = open_memstream(&str, &size);
	if (!ss)
		return (NULL);
	ret = prepare_regex(ss, pat, rep, sbj);
	fclose(ss);
	return (ret ? str : NULL);
}