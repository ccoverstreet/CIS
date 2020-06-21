#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "parsing.h"

void help() {
	printf("Chemical Information System\n");
	printf("\tmm\tMolar mass eg. \"mm H2O\" gives ~18\n");
}

void remove_newline(char *input) {
	for (int i = 0; i < strlen(input); i++) {
		if (input[i] == '\n') input[i] = '\0';
	}
}

int main() {
	printf("Chemical Information System\n");
	printf("Cale Overstreet\n");
	printf("Version 2.0 - RELEASE DATE\n");
	printf("Type help for list of commands and usage\n");

	// Primary program loop for retrieving user input and branching based on request
	while (1) {
		char input[30];
		char* input_ptr = input;
		printf("[CIS]: ");

		char *result = fgets(input, 30, stdin);
		// Check if input is EOF or error and peacefully close program
		if (result == NULL) {
			printf("EOF\nExiting CIS...\n");
			return 0;
		}

		remove_newline(input);

		array_string *split_input = string_split(input, ' ');
		array_string_print_content(split_input);

		// Branch based on input
		if (!strcmp(split_input->strings[0], "exit")) {
			printf("Exiting CIS...\n");
			array_string_destroy(split_input);
			return 0;
		} else if (!strcmp(split_input->strings[0], "help")){
			help();
		} else if (!strcmp(split_input->strings[0], "mm")) {
			printf("Molar Mass\n");
		}

		array_string_destroy(split_input);
	}

	return 0;
}
