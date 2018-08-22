/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** fs / is_file.c
*/

#include "my/fs.h"

bool is_file(const char *filepath)
{
	stat_t buf;

	return (lstat(filepath, &buf) != -1 && S_ISREG(buf.st_mode));
}

bool is_dir(const char *filepath)
{
	stat_t buf;

	return (lstat(filepath, &buf) != -1 && S_ISDIR(buf.st_mode));
}

bool is_link(const char *filepath)
{
	stat_t buf;

	return (lstat(filepath, &buf) != -1 && S_ISLNK(buf.st_mode));
}

bool is_chr(const char *filepath)
{
	stat_t buf;

	return (lstat(filepath, &buf) != -1 && S_ISCHR(buf.st_mode));
}

bool is_blk(const char *filepath)
{
	stat_t buf;

	return (lstat(filepath, &buf) != -1 && S_ISBLK(buf.st_mode));
}