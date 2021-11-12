#include "../jmz_string.h" 

#include <stdio.h>

void test_jmz_string_array() {
	printf("\nJarmuz String Array Tests\n");

	// Case where array is initialized with 0 elements
	jmz_String_Array *arr = jmz_string_array_create(0);	

	jmz_string_array_push(arr, "ASDASD");
	
	printf("Added 1 element\n");
	jmz_string_array_print_header(arr);
	jmz_string_array_print_contents(arr);

	jmz_string_array_push(arr, "ASDASD");

	printf("Added 1 element\n");
	jmz_string_array_print_header(arr);
	jmz_string_array_print_contents(arr);

	jmz_string_array_push(arr, "ASDASD");
	jmz_string_array_push(arr, "ASDASD");

	printf("Added 2 elements\n");
	jmz_string_array_print_header(arr);
	jmz_string_array_print_contents(arr);

	jmz_string_array_push(arr, "ASDASD");

	printf("Added 1 element\n");
	jmz_string_array_print_header(arr);
	jmz_string_array_print_contents(arr);

	jmz_string_array_destroy(arr);
}

void test_jmz_string_split() {
	printf("\nJarmuz String Split Test\n");

	const char *test_string_1 = "Hello World";
	char delimiter_1 = ' ';
	char delimiter_2 = 'l';
	jmz_String_Array *arr = jmz_string_split(test_string_1, delimiter_1);
	printf("String \"%s\" delimited by '%c':\n", test_string_1, delimiter_1);
	jmz_string_array_print_header(arr);
	jmz_string_array_print_contents(arr);
	jmz_string_array_destroy(arr);

	jmz_String_Array *arr_2 = jmz_string_split(test_string_1, delimiter_2);
	printf("String \"%s\" delimited by '%c':\n", test_string_1, delimiter_2);
	jmz_string_array_print_header(arr_2);
	jmz_string_array_print_contents(arr_2);
	jmz_string_array_destroy(arr_2);
}

int main() {
	printf("Jarmuz String Library Test Driver\n");

	test_jmz_string_array();

	test_jmz_string_split();

	return 0;
}
