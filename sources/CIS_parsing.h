// CIS_parsing.h
// Contains method for string parsing

#include <string>
#include <map>
#include <vector>

namespace CIS {
	extern std::map<std::string, std::string (*)()> CIS_commands;

	void parse_user_input(std::string user_input); // Parses user input and calls necesary function

	float parse_molar_mass(std::string formula); // Takes in chemical formula and returns a float for molar mass

	std::vector<std::string> split_chem_formula(std::string raw_formula); // Splits chemical formula into a vector of components

	void help_printout(); // Help statment to print when "help" is entered.

	void commands_printout(); // Prints outs available commands.
}
