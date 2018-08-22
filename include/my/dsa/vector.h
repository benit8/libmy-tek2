/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** dsa / vector.h
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "../utils.h"
#include "_types.h"

////////////////////////////////////////////////////////////////////////////////

#define VECTOR_MIN_SIZE		16
#define VECTOR_GROTH_FACTOR	1.5f

////////////////////////////////////////////////////////////////////////////////

typedef struct vector
{
	ptr_t *data;
	size_t size;
	size_t capacity;
	clean_func_t *clean_up;
} vector_t;

////////////////////////////////////////////////////////////////////////////////

vector_t *vector_create(clean_func_t *clean_up);
void vector_destroy(vector_t *vector);

bool vector_is_empty(vector_t *vector);
size_t vector_get_size(vector_t *vector);
size_t vector_get_capacity(vector_t *vector);
void vector_reserve(vector_t *vector, size_t new_cap);
void vector_shrink_to_fit(vector_t *vector);

void *vector_at(vector_t *vector, size_t pos);
void *vector_front(vector_t *vector);
void *vector_back(vector_t *vector);

void vector_clear(vector_t *vector);
void vector_insert(vector_t *vector, size_t pos, void *data);
void vector_push_back(vector_t *vector, void *data);
void vector_erase(vector_t *vector, size_t pos);
void vector_pop_back(vector_t *vector);
void vector_resize(vector_t *vector, size_t size);

void vector_foreach(vector_t *vector, void (*callback)(void *data));