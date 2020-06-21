// string_array.c: CIS String Array and Related Functions
// Cale Overstreet
// June 21, 2020
// Contains the array_string type which is used for holding the split user input by a specific delimiter

#include "string_array.h"

#include <stdlib.h>
#include <stdio.h>

array_string* array_string_create(unsigned int size) {
	array_string *new_array_string = malloc(sizeof(array_string));
	new_array_string->strings = malloc(size * sizeof(char*));
	new_array_string->size = size;
	new_array_string->used = 0;

	return new_array_string;
}

void array_string_destroy(array_string  *arry) {
	for (int i = 0; i < arry->used; i++) {
		free(arry->strings[i]);
	}

	free(arry->strings);
	free(arry);
}

void array_string_push(array_string *arry, const char *value) {
	// Push new string to string array
	if (arry->used == arry->size) {
		// Increased allocated size for array of char*
		arry->strings = realloc(arry->strings, 2 * arry->size * sizeof(char *));
		arry->size = arry->size * 2; // Currently using doubling behavior
	}

	arry->strings[arry->used] = calloc(strlen(value) + 1, sizeof(char)); // Initialize a memory to 0 
	strcpy(arry->strings[arry->used], value); // Copy passed string to strings location
	arry->used++; // Increment used size
}

void array_string_print_content(array_string *arry) {
	// Used for debugging
	printf("\nSize: %d char* or %d bytes\n", arry->size, arry->size * sizeof(char*));
	printf("Used: %d char* or %d bytes\n", arry->used, arry->used * sizeof(char*));
	for (int i = 0; i < arry->used; i++) {
		printf("\"%s\"\n", arry->strings[i]);
	}
	printf("\n");
}

// ---------- String Manipulators ----------
void string_slice(const char *raw_string, char *buffer, int start, int end) {
	for (int i = start; i <= end; i++) {
		buffer[i - start] = raw_string[i];
	}
}

array_string *string_split(const char *input_str, char delimiter) {
	array_string *new_array = array_string_create(1);
	int input_str_len = strlen(input_str);

	int a = 0;
	int b = 0;

	for (int i = 0; i < input_str_len; i++) {
		if (input_str[i] == delimiter) {
			if (a == b) {
				// If a and b are the same, don't bother pushing to array
				a = i + 1;
				b = i;
			} else {
				char buffer[b - a + 1];	
				memset(buffer, 0, (b - a + 1) * sizeof(char));
				string_slice(input_str, buffer, a, b - 1);
				array_string_push(new_array, buffer);
				a = i + 1;
				b = i;
			}
		} else if (i == input_str_len - 1) {
			char buffer[b - a + 2];	
			memset(buffer, 0, (b - a + 2) * sizeof(char));
			string_slice(input_str, buffer, a, b);
			array_string_push(new_array, buffer);
			a = i + 1;
			b = i;
		} 
		b++;
	}

	return new_array;
}
