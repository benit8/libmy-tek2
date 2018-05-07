/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** file_is.c
*/

#include "my/fs.h"

bool file_is(const char *path, const char *mask)
{
	int mode = 0;

	for (; *mask != '\0'; ++mask) {
		switch (*mask) {
		case 'f':
			mode |= F_OK;
			break;
		case 'r':
			mode |= R_OK;
			break;
		case 'w':
			mode |= W_OK;
			break;
		case 'x':
			mode |= X_OK;
			break;
		}
	}
	return (access(path, mode) != -1);
}