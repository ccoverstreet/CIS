// elements.h: Element information
// Cale Overstreet
// June 21, 2020
// Contains the element type and periodic table

#pragma once

typedef struct {
	char name[13];
	char symbol[2];
	float atomic_mass;
} Element;

Element periodic_table[10] = {
	{"Hydrogen", "H", 1.008},
	{"Helium", "He", 4.0026},
	{"Lithium", "Li", 6.94},
	{"Beryllium", "Be", 9.0122},
	{"Boron", "B", 10.81},
	{"Carbon", "C", 12.011},
	{"Nitrogen", "N", 14.007},
	{"Oxygen", "O", 15.999},
	{"Fluorine", "F", 18.988},
	{"Neon", "Ne", 20.180}
};

void periodic_table_print() {
	for (int i = 0; i < sizeof(periodic_table) / sizeof(Element); i++) {
		printf("[%d]: %s %s %f\n", i + 1, periodic_table[i].name, periodic_table[i].symbol, periodic_table[i].atomic_mass);
	}
}

float periodic_table_get_mass(const char *symbol) {
	for (int i = 0; i < sizeof(periodic_table) / sizeof(Element); i++) {
		if (!strcmp(periodic_table[i].symbol, symbol)) {
			return periodic_table[i].atomic_mass;
		}
	}
	return 0;
}
