/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** regex.h
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

////////////////////////////////////////////////////////////////////////////////

bool regex_create(regex_t *regex, const char *pattern);

ssize_t regex_match(const char *pattern, char *subject);
char *regex_replace(const char *pattern, const char *repl, char *subject);
char **regex_capture(const char *pattern, char *subject);
char **regex_split(char *pattern, char *subject);