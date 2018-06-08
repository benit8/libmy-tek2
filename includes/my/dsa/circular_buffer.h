/*
** EPITECH PROJECT, 2018
** libmy-tek2
** File description:
** dsa / circular_buffer.h
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

////////////////////////////////////////////////////////////////////////////////

#define CBUFFER_DEFAULT_SIZE 512

////////////////////////////////////////////////////////////////////////////////

typedef struct circular_buffer
{
	char *buffer;
	size_t size;
	size_t head;
	size_t tail;
	bool full;
	bool empty;
} circular_buffer_t;

////////////////////////////////////////////////////////////////////////////////

circular_buffer_t *cb_create(size_t size);
void cb_destroy(circular_buffer_t *this);

bool cb_is_full(circular_buffer_t *this);
bool cb_is_empty(circular_buffer_t *this);

void cb_clear(circular_buffer_t *this);
bool cb_push(circular_buffer_t *this, char data);
char cb_pop(circular_buffer_t *this);
char cb_peek(circular_buffer_t *this);