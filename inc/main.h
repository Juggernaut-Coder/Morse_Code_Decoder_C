#ifndef MAIN_H
#define MAIN_H

/* USE GNU SOURCE */
#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#ifdef __unix__
#include <unistd.h>
#endif

/* Include required standard library headers. */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>
/* GNU gcc (GCC) 10.2.1 HASH TABLE HEADER  */ 
#include <search.h>
#include <errno.h>


/*System constants */ 
#define MORSE_BUFFER_SIZE 8 
#define WORD_BUFFER_SIZE 256 
/* Subsystem headers. */
#include "read.h" /* You can define maximux printfwidth by defining PRINTF_MAX_CHAR_LIMIT inside read.c*/
#include "morse_code.h"

#endif
