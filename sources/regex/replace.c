/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** regex / replace.c
*/

#include "my/regex.h"

char *regex_replace(const char *p, const char *rp, char *s)
{
	regex_t r;
	regmatch_t m;
	size_t size = 0;
	char *str = NULL;
	FILE *ss = open_memstream(&str, &size);

	if (!ss)
		return (NULL);
	if (!regex_create(&r, p)) {
		fclose(ss);
		return (NULL);
	}
	for (; regexec(&r, s, 1, &m, 0) != REG_NOMATCH; s += m.rm_eo) {
		fwrite(s, 1, m.rm_so, ss);
		fwrite(rp, 1, strlen(rp), ss);
	}
	regfree(&r);
	fwrite(s, 1, strlen(s), ss);
	fclose(ss);
	return (str);
}