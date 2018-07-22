/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** log / program_name.c
*/

#include "my/log.h"

void log_set_program_name(const char *program_name)
{
	log_data_t *data = log_get_internal_data();

	data->program_name = program_name;
}

const char *log_get_program_name(void)
{
	return ((log_get_internal_data())->program_name);
}