// molar_mass.c: Molar Mass Module impementation for CIS
// Cale Overstreet
// June 21, 2020
// Implementation of molar mass parsing

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "JMZ-String/jmz_string.h"
#include "elements.h"
#include "molar_mass.h"

float molar_mass_calculate(const char *formula) {
	int position = 0;

	jmz_String_Array *split_formula = jmz_string_array_create(1);

	int segment_start = 0;
	int numeric_segment = 0;
	while (formula[position] != '\0') {
		if (isupper(formula[position]))	{
			numeric_segment = 0;
			if(segment_start == position) {
				position++;
				continue;
			}

			char segment[position - segment_start + 1];
			memset(segment, 0, position - segment_start + 1);
			jmz_string_slice(formula, segment, position - segment_start + 1, segment_start, position - 1);

			jmz_string_array_push(split_formula, segment);

			segment_start = position;
		} else if (isdigit(formula[position]) && numeric_segment == 0) {
			numeric_segment = 1;

			char segment[position - segment_start + 1];
			memset(segment, 0, position - segment_start + 1);
			jmz_string_slice(formula, segment, position - segment_start + 1, segment_start, position - 1);

			if (segment_start == position) {
				continue;
			}
			jmz_string_array_push(split_formula, segment);

			segment_start = position;
		} else if (isdigit(formula[position]) && numeric_segment == 1) {
			position++;
			continue;		
		}

		position++;
	}

	char segment[position - segment_start + 1];
	memset(segment, 0, position - segment_start + 1); 
	jmz_string_slice(formula, segment, position - segment_start + 1, segment_start, position - 1);
	jmz_string_array_push(split_formula, segment);

	float sum = molar_mass_value_substitution(split_formula);

	jmz_string_array_destroy(split_formula);

	return sum;
}

float molar_mass_value_substitution(jmz_String_Array *arry) {
	int i = 0;
	float mass_sum = 0;

	while (i < arry->used) {
		if (isalpha(arry->strings[i][0])) {
			float element_mass = periodic_table_get_mass(arry->strings[i]);
			if (element_mass == 0) {
				printf("ERROR: Unable to find Element \"%s\". Aborting calculation.\n", arry->strings[i]);
				return 0;	
			} else if (i + 1 < arry->used && isdigit(arry->strings[i + 1][0])) {
				mass_sum += element_mass * atoi(arry->strings[i + 1]);
				i++;
			} else {
				mass_sum += element_mass;
			}
		}
		i++;
	}

	return mass_sum;
}

int molar_mass_element_exists(const char *element) {
	for (int i = 0; i < sizeof(periodic_table) / sizeof(Element); i++) {
		if (!strcmp(periodic_table[i].symbol, element)) {
			return 1;
		}
	}

	return 0;
}
