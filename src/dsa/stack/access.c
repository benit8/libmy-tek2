/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** dsa / stack / access.c
*/

#include "my/dsa/stack.h"

void *stack_peek(stack_t *stack)
{
	return (list_front((list_t *)stack));
}