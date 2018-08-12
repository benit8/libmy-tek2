/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** fs.h
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include <dirent.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#include "string.h"

////////////////////////////////////////////////////////////////////////////////

typedef struct stat stat_t;
typedef struct dirent dirent_t;
typedef int (dir_filter_t)(const dirent_t *);
typedef int (dir_compar_t)(const dirent_t **, const dirent_t **);

////////////////////////////////////////////////////////////////////////////////

bool file_is(const char *filepath, const char *mask);

bool is_file(const char *filepath);
bool is_dir(const char *filepath);
bool is_link(const char *filepath);
bool is_chr(const char *filepath);
bool is_blk(const char *filepath);

bool file_put_contents(const char *filepath, char *contents, bool append);
char *file_get_contents(const char *filepath);
char **file_get_lines(const char *filepath);

size_t filesize(const char *filepath);
size_t filesize_fd(const int fd);