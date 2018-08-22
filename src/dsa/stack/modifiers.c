/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** dsa / stack / modifiers.c
*/

#include "my/dsa/stack.h"

bool stack_push(stack_t *stack, void *data)
{
	return (list_push_front((list_t *)stack, data));
}

void *stack_pop(stack_t *stack)
{
	return (list_pop_front((list_t *)stack));
}

void stack_clear(stack_t *stack)
{
	list_clear((list_t *)stack);
}