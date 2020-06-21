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

Element periodic_table[2] = {
	{"fart", "Fa", 13.4},
	{"farta", "Fb", 13.4}
};

void periodic_table_print() {
	for (int i = 0; i < sizeof(periodic_table) / sizeof(Element); i++) {
		printf("[%d]: %s %s %f\n", i + 1, periodic_table[i].name, periodic_table[i].symbol, periodic_table[i].atomic_mass);
	}
}
