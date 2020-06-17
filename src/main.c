#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
		fgets(input, 30, stdin);

		if (test != NULL) {
			printf("hi");
			test = 'a';
		}

		printf("%s\n", input);
		// Check if EOF was submitted
		if (feof(stdin)) {
			printf("\nExiting CIS\n");
			return 0;
		}

		remove_newline(input_ptr);
		printf("--%s--\n", input_ptr);

		char *token = strtok(input, " ");
		while (token != NULL) {
			if (!strcmp(token, "exit")) {
				printf("Exiting CIS\n");
			} else if (!strcmp(token, "help")) {
				help();
			} else if (!strcmp(token, "mm")) {
				char *banana = token;
				token = strtok(NULL, " ");
				printf("%s-%s\n", banana, token);
			}

			token = strtok(NULL, " ");
		}
	}

	return 0;
}
