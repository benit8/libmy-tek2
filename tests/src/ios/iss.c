/*
** EPITECH PROJECT, 2018
** libmy tests
** File description:
** ios / iss.c
*/

#include <criterion/criterion.h>
#include "my/ios/iss.h"

////////////////////////////////////////////////////////////////////////////////

char *buffer = "HTTP/1.1 200 OK\n"
"Date: Mon, 07 May 2018 00:20:42 GMT\n"
"Content-Type: text/html; charset=utf-8\n"
"Content-Length: 14\n"
"X-Powered-By: Express\n"
"x-cloud-trace-context: d0e20f4c5d9281f12016a03f23b06b77/5031427424151996993;o=0\n"
"Access-Control-Allow-Origin: *\n"
"Via: 1.1 google\n"
"\n"
"86.253.103.71";

iss_t *iss = NULL;

////////////////////////////////////////////////////////////////////////////////

Test(InputOutputStream_InputStringStream, SanityCheck)
{
	iss = iss_create(NULL, 0);
	cr_assert_null(iss);
}

////////////////////////////////////////////////////////////////////////////////

static void init(void)
{
	iss = iss_create(buffer, 0);
	cr_assert_not_null(iss);
	cr_assert_not_null(iss->buffer);
	cr_assert_not_null(iss->fp);
	cr_assert_gt(iss->size, 0);
}

static void done(void)
{
	iss_destroy(iss, false);
}

////////////////////////////////////////////////////////////////////////////////

Test(InputOutputStream_InputStringStream, No_operation, .init = init, .fini = done)
{
}

Test(InputOutputStream_InputStringStream, Read_delim, .init = init, .fini = done)
{
	char *a = iss_read_delim(iss, '/');
	cr_assert_not_null(a);
	cr_assert_str_eq(a, "HTTP");
	free(a);
}

Test(InputOutputStream_InputStringStream, Read_line, .init = init, .fini = done)
{
	char *a = iss_read_line(iss);
	cr_assert_not_null(a);
	cr_assert_str_eq(a, "HTTP/1.1 200 OK");
	free(a);
}

Test(InputOutputStream_InputStringStream, Read_bool, .init = init, .fini = done)
{
	iss_ignore(iss, 100, '0');

	// Reads last '0' from "200"
	bool a = iss_read_bool(iss);
	cr_assert_eq(a, false);

	// Reads ' ' in "200 OK"
	a = iss_read_bool(iss);
	cr_assert_eq(a, false);

	// Reads 'O' from "OK"
	a = iss_read_bool(iss);
	cr_assert_eq(a, true);
}

Test(InputOutputStream_InputStringStream, Read_int, .init = init, .fini = done)
{
	iss_ignore(iss, 100, ' ');

	int a = iss_read_int(iss);
	cr_assert_eq(a, 200);
}

Test(InputOutputStream_InputStringStream, Read_double, .init = init, .fini = done)
{
	iss_ignore(iss, 100, '/');

	double a = iss_read_double(iss);
	cr_assert_float_eq(a, 1.1, 1e-8);
}

Test(InputOutputStream_InputStringStream, Reach_end_of_file, .init = init, .fini = done)
{
	iss_ignore(iss, 1000, 255);

	cr_assert_not(iss_is_good(iss));
}