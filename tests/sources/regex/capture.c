/*
** EPITECH PROJECT, 2018
** libmy tests
** File description:
** regex / capture.c
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

void testCapture(char *pat, char *sbj, size_t t, ...)
{
	va_list ap;
	size_t len = 0;
	char **cap = regex_capture(pat, sbj);

	cr_assert(cap, "regex_capture() failed");
	len = tablen(cap);
	cr_assert_eq(len, t, "Captured %zu spans instead of %zu", len, t);
	va_start(ap, t);
	for (size_t i = 0; i < len; ++i) {
		char *s = va_arg(ap, char *);
		cr_assert_str_eq(cap[i], s, "Span n°%zu differs: \"%s\" != \"%s\"", i, cap[i], s);
		free(cap[i]);
	}
	va_end(ap);
	free(cap);
}

////////////////////////////////////////////////////////////////////////////////

Test(Regex, Capture_Sanity)
{
	cr_assert_null(regex_capture(NULL, NULL));
	cr_assert_null(regex_capture(NULL, "subject"));
	cr_assert_null(regex_capture("p[aeiouy]ttern", NULL));
}

Test(Regex, Capture)
{
	testCapture("[0-9]*", "Hello World!", 0);
	testCapture("[a-zA-Z]*", "Hello World!", 2, "Hello", "World");
}