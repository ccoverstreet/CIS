#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "JMZ-String/jmz_string.h"
#include "molar_mass.h"

void help() {
	printf("Chemical Information System\n");
	printf("Commands:\n");
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
	printf("Version 2.0 - RELEASE DATE\n\n");
	printf("Type help for list of commands and usage\n\n");

	// Primary program loop for retrieving user input and branching based on request
	while (1) {
		char input[30];
		printf("[CIS]: ");

		char *result = fgets(input, 30, stdin);
		// Check if input is EOF or error and peacefully close program
		if (result == NULL) {
			printf("EOF\nExiting CIS...\n");
			return 0;
		} else if(strlen(input) == 1) {
			// Check if it's only a newline and continue
			continue;
		}

		remove_newline(input);

		jmz_String_Array *split_input = jmz_string_split(input, ' ');

		// Branch based on input
		if (!strcmp(split_input->strings[0], "exit")) {
			printf("Exiting CIS...\n");
			jmz_string_array_destroy(split_input);
			return 0;
		} else if (!strcmp(split_input->strings[0], "help")){
			help();
		} else if (!strcmp(split_input->strings[0], "mm")) {
			if (split_input->used < 2) {
				printf("Insufficient arguments for mm (Molar Mass) command\n");
			} else {
				float calculated_mass = molar_mass_calculate(split_input->strings[1]);
				if (calculated_mass == 0) {
					printf("ERROR: Unable to calculate molar mass. See above errors\n");
				} else {
					printf("Molar mass of %s: %f g/mol\n", split_input->strings[1], calculated_mass);
				}
			}
		}

		jmz_string_array_destroy(split_input);
	}

	return 0;
}
