// Chemical Information System (CIS)
// Cale Overstreet 11/24/2019
// CIS is a terminal/command line interface that can be used to retrieve values like molar mass of elements/molecules and rest mass of elements (planned).

#include <iostream>
#include <string>

#include "CIS_data.h"
#include "CIS_parsing.h"
#include "../calestr/calestr.h"



int main() {
	printf("Chemical Information System\n");
	printf("Cale Overstreet 11/24/2019\n");

	printf("\nUseful commands: exit, help\n");

	std::string entry = "";
	while (true) {
		printf("[CIS]$ ");
		std::getline(std::cin, entry);
		if (std::cin.eof() == 1) { // Checks to see if EOF was sent. Kills Program
			return 0;
		}

		if (calestr::strip(entry) == "") {
			continue;
		}

		//printf("\n");
		CIS::parse_user_input(entry);
	}

	return 0;
}
