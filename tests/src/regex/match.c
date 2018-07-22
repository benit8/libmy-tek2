/*
** EPITECH PROJECT, 2018
** libmy tests
** File description:
** regex / match.c
*/

#include <criterion/criterion.h>
#include "my/regex.h"

////////////////////////////////////////////////////////////////////////////////

void testMatch(char *p, char *s, int t)
{
	ssize_t m = regex_match(p, s);

	if (m < 0)
		fprintf(stderr, "Error\n");
	else
		cr_expect_eq(m, t, "\"%s\" matches /%s/ %zd time%s (expected %d)", s, p, m, (m != 1) ? "s" : "", t);
}

////////////////////////////////////////////////////////////////////////////////

Test(Regex, Match_Sanity)
{
	cr_assert_eq(regex_match(NULL, NULL), -1);
	cr_assert_eq(regex_match(NULL, "subject"), -1);
	cr_assert_eq(regex_match("p[aeiouy]ttern", NULL), -1);
}

Test(Regex, Match)
{
	testMatch(".*", "", 0);
	testMatch(".*", "a", 1);

	testMatch("[a-zA-Z]+", "Hello World!", 2);
	testMatch("[a-zA-Z ]+", "Hello World!", 1);
}