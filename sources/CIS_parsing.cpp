// CIS_parsing.cpp
// Source for CIS_parsing.h. Contains method for parsing chemical formulas

#include <iostream>
#include "CIS_parsing.h"
#include "CIS_data.h"

#include "../calestr/calestr.h"

float CIS::parse_molar_mass(std::string formula) {
	// Takes in chemical formula in form XA1B2C3... and returns molar mass value.
	float molar_mass = CIS_data::molar_masses.at("He");
	printf("%s\n", calestr::strip(" ASD ").c_str());

	return molar_mass;
}
