/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** string.h
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

////////////////////////////////////////////////////////////////////////////////

char **explode(char *string, const char *delim);
char *implode(char **array, const char *glue);

bool str_empty(const char *string);
char *str_pad(const char *string, const char *pad, size_t padlen);
char *str_padl(const char *string, const char *pad, size_t padlen);
char *str_padr(const char *string, const char *pad, size_t padlen);
char *str_repeat(char *string, size_t times);
char *str_tolower(char *string);
char *str_toupper(char *string);
char *str_trim(char *str);