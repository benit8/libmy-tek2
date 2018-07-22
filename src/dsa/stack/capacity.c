/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** get.c
*/

#include "my/dsa/stack.h"

bool stack_is_empty(stack_t *stack)
{
	return (list_is_empty((list_t *)stack));
}

size_t stack_get_size(stack_t *stack)
{
	return (list_get_size((list_t *)stack));
}