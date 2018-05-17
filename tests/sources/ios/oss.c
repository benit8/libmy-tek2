/*
** EPITECH PROJECT, 2018
** libmy tests
** File description:
** ios / oss.c
*/

#include <criterion/criterion.h>
#include "my/ios/oss.h"

////////////////////////////////////////////////////////////////////////////////

oss_t *oss = NULL;

////////////////////////////////////////////////////////////////////////////////

static void init(void)
{
	oss = oss_create();
	cr_assert_not_null(oss);
	cr_assert_not_null(oss->fp);
}

static void done(void)
{
	oss_destroy(oss);
}

////////////////////////////////////////////////////////////////////////////////

Test(InputOutputStream_OutputStringStream, No_operation, .init = init, .fini = done)
{
}

Test(InputOutputStream_OutputStringStream, Get_as_string, .init = init, .fini = done)
{
	char *str = oss_str(oss);
	cr_assert_not_null(str);
	free(str);
}

Test(InputOutputStream_OutputStringStream, Write_char, .init = init, .fini = done)
{
	cr_assert(oss_write_char(oss, 'b'));

	char *str = oss_str(oss);
	cr_assert_not_null(str);
	cr_expect_str_eq(str, "b");
	free(str);
}

Test(InputOutputStream_OutputStringStream, Write_int, .init = init, .fini = done)
{
	cr_assert(oss_write_int(oss, 68462138));

	char *str = oss_str(oss);
	cr_assert_not_null(str);
	cr_expect_str_eq(str, "68462138");
	free(str);
}

Test(InputOutputStream_OutputStringStream, Write_format, .init = init, .fini = done)
{
	cr_assert(oss_writef(oss, "% 10s0123", "hello"));

	char *str = oss_str(oss);
	cr_assert_not_null(str);
	cr_expect_str_eq(str, "     hello0123");
	free(str);
}

Test(InputOutputStream_OutputStringStream, Tell_position, .init = init, .fini = done)
{
	cr_expect_eq(oss_tell(oss), 0);
	cr_assert(oss_writef(oss, "% 10s0123", "hello"));
	cr_expect_eq(oss_tell(oss), 14);
}

Test(InputOutputStream_OutputStringStream, Seek_position, .init = init, .fini = done)
{
	cr_assert(oss_writef(oss, "aaaaaaaaaaa"));
	cr_expect_eq(oss_seek(oss, 5, SEEK_SET), 0);
	cr_assert(oss_writef(oss, "bbbbbb"));
	cr_expect_eq(oss_seek(oss, 0, SEEK_SET), 0);

	char *str = oss_str(oss);
	cr_assert_not_null(str);
	cr_expect_str_eq(str, "aaaaabbbbbb");
	free(str);
}