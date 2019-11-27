// Chemical Information System (CIS)
// Cale Overstreet 11/24/2019
// CIS is a terminal/command line interface that can be used to retrieve values like molar mass of elements/molecules and rest mass of elements (planned).

#include <iostream>
#include <string>

#include "CIS_data.h"
#include "CIS_parsing.h"



int main() {
	printf("Chemical Information System\n");
	printf("Cale Overstreet 11/24/2019\n");

	printf("\nUseful commands: exit, help");

	printf("%f", CIS_data::molar_masses.at("He"));

	while (true) {
		printf("")
	}


	return 0;
}
