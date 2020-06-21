// molar_mass.c: Molar Mass Module impementation for CIS
// Cale Overstreet
// June 21, 2020
// Implementation of molar mass parsing


#include <stdio.h>
#include <ctype.h>

#include "string_array.h"
#include "elements.h"
#include "molar_mass.h"

float molar_mass_calculate(const char *formula) {
	int position = 0;
	float mass_sum = 0;
	while (formula[position] != '\0') {
		int chunk_size = 0;
		if (isupper(formula[position])) {
			// Check if element chunk starts with uppercase
			chunk_size++;
			if (formula[position + 1] != '\0') {
				if (islower(formula[position + 1])) {
					chunk_size++;
					char element_symbol[3] = "";
					string_slice(formula, element_symbol, position, position + chunk_size - 1);
					printf("%d\n", molar_mass_element_exists(element_symbol));
				}
			}
			
		} else {
			printf("ERROR: Element symbol must start with capital\n");
		}

		position++;
	}

	printf("%s\n", formula);

	return 3.3;
}

int molar_mass_element_exists(const char *element) {
	for (int i = 0; i < sizeof(periodic_table) / sizeof(Element); i++) {
		if (!strcmp(periodic_table[i].symbol, element)) {
			return 1;
		}
	}

	return 0;
}
