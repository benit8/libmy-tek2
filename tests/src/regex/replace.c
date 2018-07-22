/*
** EPITECH PROJECT, 2018
** libmy tests
** File description:
** regex / replace.c
*/

#include <criterion/criterion.h>
#include "my/regex.h"

////////////////////////////////////////////////////////////////////////////////

void testReplace(char *pat, char *rep, char *sbj, char *exp)
{
	char *got = regex_replace(pat, rep, sbj);

	if (!got)
		fprintf(stderr, "Error\n");
	else {
		cr_expect_str_eq(got, exp, "Replacement differs: expected \"%s\", got \"%s\"", exp, got);
		free(got);
	}
}

////////////////////////////////////////////////////////////////////////////////

Test(Regex, Replace_Sanity)
{
	cr_assert_null(regex_replace(NULL, NULL, NULL));
	cr_assert_null(regex_replace("p[aeiouy]ttern", NULL, NULL));
	cr_assert_null(regex_replace("p[aeiouy]ttern", "subject", NULL));
	cr_assert_null(regex_replace("p[aeiouy]ttern", NULL, "a"));
	cr_assert_null(regex_replace(NULL, "subject", NULL));
	cr_assert_null(regex_replace(NULL, "subject", "a"));
	cr_assert_null(regex_replace(NULL, NULL, "a"));
}

Test(Regex, Replace)
{
	testReplace(".*", "", "Hello World!", "");
	testReplace(".*", "a", "Hello World!", "a");

	testReplace("[a-zA-Z]+", "foo", "Hello World!", "foo foo!");
	testReplace("[a-zA-Z ]+", "bar", "Hello World!", "bar!");
}