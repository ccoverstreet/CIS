// parsing.h: CIS string parsing module
// Cale Overstreet
// June 20, 2020
// This module handles string parsing or user input.

#include <string.h>

typedef struct {
	char **data;
	unsigned int size;
	unsigned int used;
} array_string;

array_string *array_string_create(unsigned int size) {
	array_string *new_array_string = malloc(sizeof(array_string));
	new_array_string->data = malloc(size * sizeof(char*));
	new_array_string->size = size;
	new_array_string->used = 0;

	return new_array_string;
}

void array_string_destroy(array_string *arry) {
	for (int i = 0; i < arry->used; i++) {
		free(arry->data[i]);
	}

	free(arry->data);
	free(arry);
}

void array_string_push(array_string *arry, const char* value) {
	// Push new string to string array
	if (arry->used == arry->size) {
		// Increased allocated size for array of char*
		printf("Need to increase array size\n");
		arry->data = realloc(arry->data, 2 * arry->size * sizeof(char *));
		arry->size = arry->size * 2; // Currently using doubling behavior
	}

	arry->data[arry->used] = calloc(strlen(value) + 1, sizeof(char)); // Initialize a memory to 0 
	strcpy(arry->data[arry->used], value); // Copy passed string to data location
	arry->used++; // Increment used size
	printf("%d: %s %d\n", arry->used, arry->data[arry->used - 1], strlen(arry->data[arry->used - 1]));
}

void array_string_print_all(array_string *arry) {
	for (int i = 0; i < arry->used; i++) {
		printf("%s\n", arry->data[i]);
	}
}
