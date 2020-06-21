// parsing.h: CIS string parsing module
// Cale Overstreet
// June 20, 2020
// This module handles string parsing or user input.

#pragma once

#include <string.h>

typedef struct {
	char **strings;
	unsigned int size;
	unsigned int used;
} array_string;

// ---------- Array String ----------
array_string *array_string_create(unsigned int size);
void array_string_destroy(array_string *arry);
void array_string_push(array_string *arry, const char* value);
void array_string_print_content(array_string *arry);

// ---------- String Manipulators ----------
void string_slice(const char *raw_string, char *buffer, int start, int end);
array_string *string_split(const char *input_str, char delimiter);
