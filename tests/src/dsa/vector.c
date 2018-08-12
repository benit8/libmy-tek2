/*
** EPITECH PROJECT, 2018
** libmy tests
** File description:
** dsa / vector.c
*/

#include <criterion/criterion.h>
#include "my/dsa/vector.h"

////////////////////////////////////////////////////////////////////////////////

vector_t *v = NULL;

static void init(void)
{
	v = vector_create(NULL);
	cr_assert_not_null(v);
	cr_assert_null(v->data);
	cr_assert_eq(v->size, 0);
	cr_assert_eq(v->capacity, 0);
}

static void done(void)
{
	vector_destroy(v);
}

////////////////////////////////////////////////////////////////////////////////

Test(DSA_Vector, Sanity)
{
}

////////////////////////////////////////////////////////////////////////////////

Test(DSA_Vector, Reserve, .init = init, .fini = done)
{
	vector_reserve(v, 100);

	cr_assert_not_null(v->data);
	cr_assert_eq(v->size, 0);
	cr_assert_eq(v->capacity, 121);
}

Test(DSA_Vector, ShrinkToFit, .init = init, .fini = done)
{
	char *a = "a";

	vector_push_back(v, a);
	vector_shrink_to_fit(v);

	cr_assert_not_null(v->data);
	cr_assert_eq(v->size, 1);
	cr_assert_eq(v->capacity, 1);
}

////////////////////////////////////////////////////////////////////////////////

Test(DSA_Vector, SimplePush, .init = init, .fini = done)
{
	char *a = "a";

	vector_push_back(v, a);

	cr_assert_not_null(v->data);
	cr_assert_eq(v->size, 1);
	cr_assert_eq(v->capacity, VECTOR_MIN_SIZE);
}

Test(DSA_Vector, MultiplePush, .init = init, .fini = done)
{
	for (uintptr_t i = 0; i < 100; ++i)
		vector_push_back(v, (ptr_t *)i);

	cr_assert_not_null(v->data);
	cr_assert_eq(v->size, 100);
	cr_assert_eq(v->capacity, 121);
}

////////////////////////////////////////////////////////////////////////////////

Test(DSA_Vector, At, .init = init, .fini = done)
{
	for (uintptr_t i = 0; i < 100; ++i)
		vector_push_back(v, (ptr_t *)(i + 20));
	cr_assert_not_null(v->data);
	cr_assert_eq(v->size, 100);
	cr_assert_eq(v->capacity, 121);

	for (uintptr_t i = 0; i < 100; ++i) {
		uintptr_t *e = vector_at(v, i);
		cr_assert_eq(e, i + 20);
	}
}

Test(DSA_Vector, Front, .init = init, .fini = done)
{
	for (uintptr_t i = 0; i < 100; ++i)
		vector_push_back(v, (ptr_t *)(i + 20));
	cr_assert_not_null(v->data);
	cr_assert_eq(v->size, 100);
	cr_assert_eq(v->capacity, 121);

	uintptr_t *a = vector_front(v);
	uintptr_t *b = vector_at(v, 0);
	cr_assert_eq(a, 20);
	cr_assert_eq(a, b);
}

Test(DSA_Vector, Back, .init = init, .fini = done)
{
	for (uintptr_t i = 0; i < 100; ++i)
		vector_push_back(v, (ptr_t *)(i + 20));
	cr_assert_not_null(v->data);
	cr_assert_eq(v->size, 100);
	cr_assert_eq(v->capacity, 121);

	uintptr_t *a = vector_back(v);
	uintptr_t *b = vector_at(v, 99);
	cr_assert_eq(a, 119);
	cr_assert_eq(a, b);
}