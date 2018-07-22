/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** log / level.c
*/

#include "my/log.h"

void log_set_level(log_level_t level)
{
	log_data_t *data = log_get_internal_data();

	if (level >= LL_ALL && level <= LL_OFF)
		data->level = level;
}

log_level_t log_get_level(void)
{
	log_data_t *data = log_get_internal_data();

	return (data->level);
}