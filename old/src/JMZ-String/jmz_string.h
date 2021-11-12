// jmz_string.h: External header for Jarmuz String Module
// Cale Overstreet
// June 27, 2020
// Contains definitions shared by module components and external world

#pragma once

typedef struct {
	char **strings;
	unsigned int size;
	unsigned int used;
} jmz_String_Array;

extern void *jmz_string_array_create(unsigned int size); // Returns a pointer to a string array. Returns NULL if unable to allocate; 
extern void jmz_string_array_destroy(jmz_String_Array *arr); // Deallocates a string array
extern int jmz_string_array_push(jmz_String_Array *arr, const char *token); // Push a token onto the string array
extern void jmz_string_array_print_contents(jmz_String_Array *arr);
extern void jmz_string_array_print_header(jmz_String_Array *arr);

// ---------- General String Utils ----------
extern void jmz_string_slice(const char *raw_str, char *buffer, int buffer_size, int start, int end); // Copies section of raw_str intor a buffer from raw_str[start] to raw_str[end] inclusive.
extern jmz_String_Array *jmz_string_split(const char *raw_str, char delim); // Splits a string into an array of tokens. Tokens of 0 length are ignored as they provide little value.
extern char *jmz_string_replace(const char *raw_str, const char *rep, const char *with);


