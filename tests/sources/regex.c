/*
** EPITECH PROJECT, 2018
** libmy tests
** File description:
** regex
*/

#include <criterion/criterion.h>
#include "my/regex.h"

////////////////////////////////////////////////////////////////////////////////

Test(Regex, Match)
{
	cr_expect_eq(regex_match("Hello World!", ".*"), 1);
}