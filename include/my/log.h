/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** log.h
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include <fcntl.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "my/term_colors.h"

////////////////////////////////////////////////////////////////////////////////

typedef enum log_level
{
	LL_ALL,
	LL_DEBUG,
	LL_INFO,
	LL_WARN,
	LL_ERROR,
	LL_FATAL,
	LL_OFF
} log_level_t;

typedef struct log_data
{
	log_level_t level;
	int fd;
} log_data_t;

typedef struct log_infos
{
	char *name;
	char *color;
} log_infos_t;

////////////////////////////////////////////////////////////////////////////////

log_data_t *log_get_internal_data(void);

void log_set_level(log_level_t level);
log_level_t log_get_level(void);

bool log_set_file(const char *filepath);
bool log_set_file_fd(int fd);
void log_close_file(void);

void log_write(const char *format, va_list *ap, log_level_t lvl);
void log_fatal(const char *format, ...)
	__attribute__((__format__(__printf__, 1, 2)));
void log_error(const char *format, ...)
	__attribute__((__format__(__printf__, 1, 2)));
void log_warn(const char *format, ...)
	__attribute__((__format__(__printf__, 1, 2)));
void log_info(const char *format, ...)
	__attribute__((__format__(__printf__, 1, 2)));
void log_debug(const char *format, ...)
	__attribute__((__format__(__printf__, 1, 2)));