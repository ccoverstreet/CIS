// CIS_parsing.cpp
// Source for CIS_parsing.h. Contains method for parsing chemical formulas

#include <iostream>
#include <string>
#include <vector>

#include "CIS_parsing.h"
#include "CIS_data.h"

#include "../calestr/calestr.h"



void CIS::parse_user_input(std::string user_input) {
	// Takes user input, parses, and executes appropriate code

	std::string cleaned_input = calestr::strip(user_input); // Removes trailing and leading whitesapce

	std::vector<std::string> split_input = calestr::split(cleaned_input, " "); // Split by each phrase to make command execution easier

	if (split_input[0] == "exit") {
		exit(0);
	} else if (split_input[0] == "help") {
		CIS::help_printout();
	} else if (split_input[0] == "commands") {
		CIS::commands_printout();
	} else if (split_input[0] == "mm" && split_input.size() > 1) {
		float molar_mass_output = CIS::parse_molar_mass(split_input[1]);
		if (molar_mass_output == -1) {
			printf("Error in chemical formula\n");
		} else {
			printf("Molar mass of %s: %f\n", split_input[1].c_str(), molar_mass_output);
		}
	}
} 


float CIS::parse_molar_mass(std::string formula) {
	// Takes in chemical formula in form A1B2C3... and returns molar mass value.

	if (isdigit(formula[0])) {
		printf("Incorrectly formatted chemical: cannot start with number or lower case letter\n");
	}

	std::vector<std::string> components = CIS::split_chem_formula(formula);

	float molar_mass = 0;
	int i = 0;
	while (i < components.size()) { 
		if (isalpha(components[i][0])) {
			if (CIS_data::molar_masses.count(components[i])) {
				if (i + 1 < components.size() && isdigit(components[i + 1][0])) {
					molar_mass += CIS_data::molar_masses.at(components[i]) * stoi(components[i + 1]);
					i += 2;
					continue;
				} else {
					molar_mass += CIS_data::molar_masses.at(components[i]);
					i += 1;
					continue;
				}
			} else{ // Throw error aka -1
				return -1;
			}
		}

		i++;
	}

	if (molar_mass == 0) {
		return -1;
	}
	return molar_mass;
}

std::vector<std::string> CIS::split_chem_formula(std::string raw_formula) {
	int i = 0;

	std::vector<std::string> components;

	// Splits formula into nice chunks
	while (i < raw_formula.length()) {
		if (isalpha(raw_formula[i])) {
			if (isupper(raw_formula[i])) {
				if (i + 1 < raw_formula.length() && islower(raw_formula[i + 1])) {
					components.push_back(raw_formula.substr(i, 2));
					i += 2;
					continue;
				} else {
					components.push_back(raw_formula.substr(i, 1));
					i++;
					continue;
				}
			} 
		} else { // If not a letter
			int w = 1; // Number of digits;	
			while (i < raw_formula.length() && isdigit(raw_formula[i + w])) {
				w++;
			}

			components.push_back(raw_formula.substr(i, w));
			i += w; // Iterating;
		}

		i++;
	}		

	return components;
}


void CIS::help_printout() {
	// Printout function for help text

	printf("Chemical Information System (CIS)\n");
	printf("Cale Overstreet 11/24/2019\n");

	printf("\nTo see available commands, use command \"commands\"\n");
	printf("This is designed to work similarly to a unix-type terminal. Molar mass parsing still needs work as it works, but is inefficient\n");
}


void CIS::commands_printout() {
	// Printout function for all program commands
	printf("\n");
	
	printf("help: prints out basic program information\n");
	printf("commands: prints out all program commands and usage\n");
	printf("mm: Calculates and prints molar mass of given arguments\n");
	printf("\tExample - mm CO2");

	printf("\n");

}
