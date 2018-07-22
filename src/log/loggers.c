/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** log / loggers.c
*/

#include "my/log.h"

void log_fatal(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	log_write(format, &ap, LL_FATAL);
	va_end(ap);
	exit(EXIT_FAILURE);
}

void log_error(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	log_write(format, &ap, LL_ERROR);
	va_end(ap);
}

void log_warn(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	log_write(format, &ap, LL_WARN);
	va_end(ap);
}

void log_info(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	log_write(format, &ap, LL_INFO);
	va_end(ap);
}

void log_debug(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	log_write(format, &ap, LL_DEBUG);
	va_end(ap);
}