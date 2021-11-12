// jmz_string_array.c: Implementation of dynamic string arrays in C
// Cale Overstreet
// June 27, 2020
// A C-implementation of dynamic string arrays intended for use in parsing. Contains functions like jmz_string_split(const char *str, char delim), which can be used to quickly generate a jmz_string_array with each token being a separate array element.

#include "../jmz_string.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// ---------- JMZ String Array ----------
void *jmz_string_array_create(unsigned int size) {
	jmz_String_Array *arr = malloc(sizeof(jmz_String_Array));
	if (arr == NULL) {
		return NULL;
	}

	if (size == 0) {
		arr->strings = NULL;
	} else {
		arr->strings = malloc(size * sizeof(char*));
		if (arr->strings == NULL) {
			return NULL;
		}
	}

	arr->size = size;
	arr->used = 0;

	return arr;
}

void jmz_string_array_destroy(jmz_String_Array *arr) {
	for (int i = 0; i < arr->used; i++) {
		free(arr->strings[i]);
	}

	if (arr->strings) {
		free(arr->strings);
	}

	free(arr);
}

int jmz_string_array_push(jmz_String_Array *arr, const char *token) {
	if (arr->size == 0) {
		arr->strings = malloc(sizeof(char*));
		arr->size = 1;
	} 

	if (arr->used == arr->size) { // Need to realloc
		char **new_location = realloc(arr->strings, 2 * arr->size * sizeof(char*));
		if (new_location == NULL) {
			return 1;
		}
		arr->size = arr->size * 2;
		arr->strings = new_location;
	}

	arr->strings[arr->used] = calloc(strlen(token) + 1, sizeof(char));
	strcpy(arr->strings[arr->used], token);
	arr->used++;

	return 0;
} 

void jmz_string_array_print_contents(jmz_String_Array *arr) {
	for (int i = 0; i < arr->used; i++) {
		printf("\"%s\"\n", arr->strings[i]);
	}
}

void jmz_string_array_print_header(jmz_String_Array *arr) {
	printf("Allocated Size: %d\nUsed Elements: %d\n", arr->size, arr->used);
}
