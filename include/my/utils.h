/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** utils.h
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////////////////////

#ifndef MIN
	#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif

#ifndef MAX
	#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif

////////////////////////////////////////////////////////////////////////////////

typedef unsigned char byte_t;
typedef uintptr_t * ptr_t;