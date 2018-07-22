/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** strpad.c
*/

#include "my/string.h"

char *str_padr(const char *string, const char *pad, size_t pad_size)
{
	size_t string_len = strlen(string);
	size_t pad_len = strlen(pad);
	char *output = NULL;

	if (pad_size <= string_len)
		return (strdup(string));
	output = calloc(pad_size + 1, sizeof(char));
	strcpy(output, string);
	for (size_t i = string_len; i < pad_size; i += pad_len)
		strncat(output, pad, MIN(pad_size - i, pad_len));
	return (output);
}

char *str_padl(const char *string, const char *pad, size_t pad_size)
{
	size_t string_len = strlen(string);
	size_t pad_len = strlen(pad);
	size_t pad_space = 0;
	char *output = NULL;

	if (pad_size <= string_len)
		return (strdup(string));
	output = calloc(pad_size + 1, sizeof(char));
	pad_space = pad_size - string_len;
	for (size_t i = 0; i < pad_space; i += pad_len)
		strncat(output, pad, MIN(pad_space - i, pad_len));
	strcat(output, string);
	return (output);
}

char *str_pad(const char *string, const char *pad, size_t pad_size)
{
	size_t string_len = strlen(string);
	size_t pad_left = (pad_size - string_len) / 2;
	char *output1 = str_padl(string, pad, pad_left + string_len);
	char *output2 = str_padr(output1, pad, pad_size);

	free(output1);
	return (output2);
}