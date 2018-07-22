/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** ios / oss.h
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

typedef struct oss
{
	char *buffer;
	size_t size;
	FILE *fp;
} oss_t;

////////////////////////////////////////////////////////////////////////////////

/*
** Creates a new OutputStringStream.
*/
oss_t *oss_create(void);

/*
** Destroys the given OutputStringStream
*/
void oss_destroy(oss_t *oss);

/*
** Write all kinds of data
*/
bool oss_write(oss_t *oss, const void *buffer, size_t length);
bool oss_writef(oss_t *oss, const char *format, ...);

bool oss_write_bool(oss_t *oss, bool data);
bool oss_write_i8(oss_t *oss, int8_t data);
bool oss_write_i16(oss_t *oss, int16_t data);
bool oss_write_i32(oss_t *oss, int32_t data);
bool oss_write_i64(oss_t *oss, int64_t data);
bool oss_write_char(oss_t *oss, char data);
bool oss_write_short(oss_t *oss, short data);
bool oss_write_int(oss_t *oss, int data);
bool oss_write_long(oss_t *oss, long data);
bool oss_write_ssize(oss_t *oss, ssize_t data);

bool oss_write_u8(oss_t *oss, uint8_t data);
bool oss_write_u16(oss_t *oss, uint16_t data);
bool oss_write_u32(oss_t *oss, uint32_t data);
bool oss_write_u64(oss_t *oss, uint64_t data);
bool oss_write_uchar(oss_t *oss, unsigned char data);
bool oss_write_ushort(oss_t *oss, unsigned short data);
bool oss_write_uint(oss_t *oss, unsigned int data);
bool oss_write_ulong(oss_t *oss, unsigned long data);
bool oss_write_size(oss_t *oss, size_t data);

bool oss_write_float(oss_t *oss, float data);
bool oss_write_double(oss_t *oss, double data);

/*
** Returns an allocated representation of the buffer
** Needs to be freed with free()
*/
char *oss_str(oss_t *oss);

/*
** Offset relative functions
*/
long oss_tell(oss_t *oss);
int oss_seek(oss_t *oss, long offset, int whence);