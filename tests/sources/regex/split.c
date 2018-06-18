/*
** EPITECH PROJECT, 2018
** libmy tests
** File description:
** regex / split.c
*/

#include <criterion/criterion.h>
#include "my/regex.h"

////////////////////////////////////////////////////////////////////////////////

static size_t tablen(char **tab)
{
	size_t len = 0;

	for (; tab[len] != NULL; ++len);
	return (len);
}

void testSplit(char *pat, char *sbj, size_t t, ...)
{
	va_list ap;
	size_t len = 0;
	char **tokens = regex_split(pat, sbj);

	cr_assert(tokens, "regex_split(\"%s\", \"%s\") failed", pat, sbj);
	len = tablen(tokens);
	cr_assert_eq(len, t, "Splited %zu spans instead of %zu", len, t);
	va_start(ap, t);
	for (size_t i = 0; i < len; ++i) {
		char *s = va_arg(ap, char *);
		cr_assert_str_eq(tokens[i], s, "Span n°%zu differs: \"%s\" != \"%s\"", i, tokens[i], s);
		free(tokens[i]);
	}
	va_end(ap);
	free(tokens);
}

////////////////////////////////////////////////////////////////////////////////

Test(Regex, Split_Sanity)
{
	cr_assert_null(regex_split(NULL, NULL));
	cr_assert_null(regex_split(NULL, "subject"));
	cr_assert_null(regex_split("p[aeiouy]ttern", NULL));
}

Test(Regex, Split)
{
	testSplit("", "Hello World!", 12, "H", "e", "l", "l", "o", " ", "W", "o", "r", "l", "d", "!");
	testSplit("[[:space:]]{1,}", "ls   -l 	-a", 3, "ls", "-l", "-a");
}