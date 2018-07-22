/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** ios / iss.h
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include <ctype.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

////////////////////////////////////////////////////////////////////////////////

typedef struct iss
{
	char *buffer;
	size_t size;
	FILE *fp;
} iss_t;

////////////////////////////////////////////////////////////////////////////////

/*
** Creates a new InputStringStream.
** If `size` equals 0, strlen(input) is used instead
*/
iss_t *iss_create(char *input, size_t size);

/*
** Destroys the given InputStringStream
** Pass `free` as true if you want this function to call free() on the input
** data passed at creation
*/
void iss_destroy(iss_t *iss, bool free);

/*
** Tests if the InputStringStream has reached EnfOfFile
*/
bool iss_is_good(iss_t *iss);

/*
** Read all kinds of data
*/
int iss_readf(iss_t *iss, const char *format, ...);

bool iss_read_bool(iss_t *iss);
int8_t iss_read_i8(iss_t *iss);
int16_t iss_read_i16(iss_t *iss);
int32_t iss_read_i32(iss_t *iss);
int64_t iss_read_i64(iss_t *iss);
char iss_read_char(iss_t *iss);
short iss_read_short(iss_t *iss);
int iss_read_int(iss_t *iss);
long iss_read_long(iss_t *iss);
ssize_t iss_read_ssize(iss_t *iss);

uint8_t iss_read_u8(iss_t *iss);
uint16_t iss_read_u16(iss_t *iss);
uint32_t iss_read_u32(iss_t *iss);
uint64_t iss_read_u64(iss_t *iss);
unsigned char iss_read_uchar(iss_t *iss);
unsigned short iss_read_ushort(iss_t *iss);
unsigned int iss_read_uint(iss_t *iss);
unsigned long iss_read_ulong(iss_t *iss);
size_t iss_read_size(iss_t *iss);

float iss_read_float(iss_t *iss);
double iss_read_double(iss_t *iss);

/*
** These functions returns allocated strings that need to be freed by free()
*/
char *iss_read(iss_t *iss, size_t n);
char *iss_read_line(iss_t *iss);
char *iss_read_delim(iss_t *iss, int delim);

/*
** Extracts characters and discards them, until either `n` characters have been
** extracted, or one compares equal to delim
*/
void iss_ignore(iss_t *iss, size_t n, int c);

/*
** Offset relative functions
*/
long iss_tell(iss_t *iss);
int iss_seek(iss_t *iss, long offset, int whence);