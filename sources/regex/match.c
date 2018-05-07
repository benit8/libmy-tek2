/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** regex / match.c
*/

#include "my/regex.h"

ssize_t regex_match(const char *pattern, char *subject)
{
	regex_t regex;
	regmatch_t match;
	ssize_t n = 0;

	if (!pattern || !subject)
		return (-1);
	if (!regex_create(&regex, pattern))
		return (-1);
	for (n = 0; regexec(&regex, subject, 1, &match, 0) != REG_NOMATCH; ++n)
		subject += match.rm_eo;
	regfree(&regex);
	return (n);
}