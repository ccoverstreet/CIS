// molar_mass.h: Molar Mass Module for CIS // Cale Overstreet
// June 21, 2020
// This module handles the parsing of molar mass inputs

#pragma once

#include "JMZ-String/jmz_string.h"

float molar_mass_calculate(const char *formula);

int molar_mass_element_exists(const char *element);

float molar_mass_value_substitution(jmz_String_Array *arry);
