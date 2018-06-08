/*
** EPITECH PROJECT, 2018
** libmy tests
** File description:
** dsa / circular_buffer.c
*/

#include <ctype.h>
#include <stdio.h>
#include <criterion/criterion.h>
#include "my/dsa/circular_buffer.h"

////////////////////////////////////////////////////////////////////////////////

circular_buffer_t *cb = NULL;

////////////////////////////////////////////////////////////////////////////////

Test(DSA_CircularBuffer, SanityCheck)
{
	circular_buffer_t *cb = cb_create(0);

	cr_assert_not_null(cb);
	cr_assert_eq(cb->size, CBUFFER_DEFAULT_SIZE);

	cb_destroy(cb);
}

Test(DSA_CircularBuffer, CustomSize)
{
	circular_buffer_t *cb = cb_create(64);

	cr_assert_not_null(cb);
	cr_assert_eq(cb->size, 64);

	cb_destroy(cb);
}

Test(DSA_CircularBuffer, Push)
{
	circular_buffer_t *cb = cb_create(8);

	cr_assert_not_null(cb);
	cr_assert_eq(cb->size, 8);

	const char *str = "Hello";
	for (size_t i = 0; i < strlen(str); ++i)
		cr_expect(cb_push(cb, str[i]));

	cr_expect_eq(cb->tail, 5);

	cb_destroy(cb);
}

Test(DSA_CircularBuffer, PushTooMuch)
{
	// In this test, we add more elements than the buffer size.
	// Since we don't pop any elements, the tail is meant to go back to 0
	// and don't push anything else.

	circular_buffer_t *cb = cb_create(8);

	cr_assert_not_null(cb);
	cr_assert_eq(cb->size, 8);

	const char *str = "Hello World!";
	for (size_t i = 0; i < strlen(str); ++i) {
		bool w = cb_push(cb, str[i]);
		if (i < cb->size)
			cr_expect(w, "str[%zu]=%c", i, str[i]);
		else
			cr_expect_not(w, "str[%zu]=%c", i, str[i]);
	}

	cr_assert(cb_is_full(cb));

	cb_destroy(cb);
}

Test(DSA_CircularBuffer, Peek)
{
	circular_buffer_t *cb = cb_create(16);

	cr_assert_not_null(cb);
	cr_assert_eq(cb->size, 16);

	const char *str = "Hello World!";
	for (size_t i = 0; i < strlen(str); ++i)
		cr_expect(cb_push(cb, str[i]), "str[%zu]=%c", i, str[i]);

	char c = cb_peek(cb);
	cr_expect_eq(c, 'H', "peek()='%c' (%d)", isprint(c) ? c : ' ', c);
	cr_expect_eq(c, 'H', "peek()='%c' (%d)", isprint(c) ? c : ' ', c);

	cb_destroy(cb);
}

Test(DSA_CircularBuffer, Pop)
{
	circular_buffer_t *cb = cb_create(16);

	cr_assert_not_null(cb);
	cr_assert_eq(cb->size, 16);

	const char *str = "Hello World!";
	for (size_t i = 0; i < strlen(str); ++i)
		cr_expect(cb_push(cb, str[i]), "str[%zu]=%c", i, str[i]);

	for (size_t i = 0; i < strlen(str); ++i) {
		char c = cb_pop(cb);
		cr_expect_eq(c, str[i], "pop()='%c' (%d)", isprint(c) ? c : ' ', c);
	}

	cr_assert(cb_is_empty(cb));

	cb_destroy(cb);
}