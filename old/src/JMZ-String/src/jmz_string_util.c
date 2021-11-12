// jmz_string_util.c: General string utilities
// Cale Overstreet
// June 27, 2020
// Contains general string manipulation functions

#include "../jmz_string.h"

#include <string.h>

void jmz_string_slice(const char *raw_str, char *buffer, int buffer_size, int start, int end) {
	if (end - start + 1 >= buffer_size) {
		return;
	}

	for (int i = start; i <= end; i++) {
        buffer[i - start] = raw_str[i];
    }	
}

jmz_String_Array *jmz_string_split(const char *raw_str, char delim) {
	jmz_String_Array *arr = jmz_string_array_create(0);

	unsigned int raw_str_len = strlen (raw_str);

	int a = 0;
	int b = 0;

	for (int i = 0; i < raw_str_len; i++) {
		if (raw_str[i] == delim) {
			if (a == b) {
				// If a and b are the same, don't bother pushing to array
				a = i + 1;
				b = i;
			} else {
				int buffer_size = b - a + 1;
				char buffer[buffer_size]; 
				memset(buffer, 0, (buffer_size) * sizeof(char));
				jmz_string_slice(raw_str, buffer, buffer_size, a, b - 1);
				jmz_string_array_push(arr, buffer);
				a = i + 1;
				b = i;
			}
		} else if (i == raw_str_len - 1) {
			int buffer_size = b - a + 2;
			char buffer[buffer_size]; 
			memset(buffer, 0, (b - a + 2) * sizeof(char));
			jmz_string_slice(raw_str, buffer, buffer_size, a, b);
			jmz_string_array_push(arr, buffer);
			a = i + 1;
			b = i;
		} 
		b++;
	}

	return arr;
}

char *jmz_string_replace(const char *raw_str, const char *rep, const char *with) {
	unsigned int rep_len = strlen(rep);
	unsigned int with_len = strlen(with);
}
