/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** dsa / stack / stack.c
*/

#include "my/dsa/stack.h"

stack_t *stack_create(clean_func_t *clean_up)
{
	return ((stack_t *)list_create(clean_up));
}

void stack_destroy(stack_t *stack)
{
	list_destroy((list_t *)stack);
}