/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** log / data.c
*/

#include "my/log.h"

log_data_t *log_get_internal_data(void)
{
	static log_data_t data = {LL_WARN, STDERR_FILENO};

	return (&data);
}