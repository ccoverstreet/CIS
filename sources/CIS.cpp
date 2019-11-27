//Chemistry Information Program (CIS)
//Cale Overstreet
//Jan. 16, 2019
//This program contains functions that help with chemistry homework
//namely, a molar mass calculator for any molecule
//Currently, the program only supports subscripts of up to two digits
//potential updates for more flexible inputs may occur

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <cctype>
#include <ctype.h>

//Meta Information
std::string Version = "Version 1.3";

//creating Map for molar mass
 std::map<std::string, float> mass = {
     std::make_pair("H", 1.00794),
     std::make_pair("He", 4.0026),
     std::make_pair("Li", 6.94),
     std::make_pair("Be", 9.0122),
     std::make_pair("B", 10.81),
     std::make_pair("C", 12.011),
     std::make_pair("N", 14.007),
     std::make_pair("O", 15.999),
     std::make_pair("F", 18.998),
     std::make_pair("Ne", 20.180),
     std::make_pair("Na", 22.990),
     std::make_pair("Mg", 24.305),
     std::make_pair("Al", 26.982),
     std::make_pair("Si", 28.085),
     std::make_pair("P", 30.974),
     std::make_pair("S", 32.06),
     std::make_pair("Cl", 35.45),
     std::make_pair("Ar", 39.948),
     std::make_pair("K", 39.098),
     std::make_pair("Ca", 40.078),
     std::make_pair("Sc", 44.956),
     std::make_pair("Ti", 47.867),
     std::make_pair("V", 50.942),
     std::make_pair("Cr", 51.996),
     std::make_pair("Mn", 54.938),
     std::make_pair("Fe", 55.845),
     std::make_pair("Co", 58.933),
     std::make_pair("Ni", 58.693),
     std::make_pair("Cu", 63.546),
     std::make_pair("Zn", 65.38),
     std::make_pair("Ga", 69.723),
     std::make_pair("Ge", 72.630),
     std::make_pair("As", 74.922),
     std::make_pair("Se", 78.971),
     std::make_pair("Br", 79.904),
     std::make_pair("Kr", 83.798),
     std::make_pair("Rb", 85.468),
     std::make_pair("Sr", 87.62),
     std::make_pair("Y", 88.906),
     std::make_pair("Zr", 91.224),
     std::make_pair("Nb", 92.906),
     std::make_pair("Mo", 95.95),
     std::make_pair("Tc", 98),
     std::make_pair("Ru", 101.07),
     std::make_pair("Rh", 102.91),
     std::make_pair("Pd", 106.42),
     std::make_pair("Ag", 107.87),
     std::make_pair("Cd", 112.41),
     std::make_pair("In", 114.82),
     std::make_pair("Sn", 118.71),
     std::make_pair("Sb", 121.76),
     std::make_pair("Te", 127.60),
     std::make_pair("I", 126.90),
     std::make_pair("Xe", 131.29),
     std::make_pair("Cs", 132.91),
     std::make_pair("Ba", 137.33),
     std::make_pair("La", 138.91),
     std::make_pair("Ce", 140.12),
     std::make_pair("Pr", 140.91),
     std::make_pair("Nd", 144.24),
     std::make_pair("Pm", 145),
     std::make_pair("Sm", 150.36),
     std::make_pair("Eu", 151.96),
     std::make_pair("Gd", 157.25),
     std::make_pair("Tb", 158.93),
     std::make_pair("Dy", 162.50),
     std::make_pair("Ho", 164.93),
     std::make_pair("Er", 167.26),
     std::make_pair("Tm", 168.93),
     std::make_pair("Yb", 173.05),
     std::make_pair("Lu", 174.97),
     std::make_pair("Hf", 178.49),
     std::make_pair("Ta", 180.95),
     std::make_pair("W", 183.84),
     std::make_pair("Re", 186.21),
     std::make_pair("Os", 190.23),
     std::make_pair("Ir", 192.22),
     std::make_pair("Pt", 195.08),
     std::make_pair("Au", 196.97),
     std::make_pair("Hg", 200.59),
     std::make_pair("Tl", 204.38),
     std::make_pair("Pb", 207.2),
     std::make_pair("Bi", 208.98),
     std::make_pair("Po", 209),
     std::make_pair("At", 210),
     std::make_pair("Rn", 222),
     std::make_pair("Fr", 223),
     std::make_pair("Ra", 226),
     std::make_pair("Ac", 227),
     std::make_pair("Th", 232.04),
     std::make_pair("Pa", 231.04),
     std::make_pair("U", 238.03),
     std::make_pair("Np", 237),
     std::make_pair("Pu", 244),
     std::make_pair("Am", 243),
     std::make_pair("Cm", 247),
     std::make_pair("Bk", 247),
     std::make_pair("Cf", 251),
     std::make_pair("Es", 252),
     std::make_pair("Fm", 257),
     std::make_pair("Md", 258),
     std::make_pair("No", 259),
     std::make_pair("Lr", 266),
     std::make_pair("Rf", 267),
     std::make_pair("Db", 268),
     std::make_pair("Sg", 269),
     std::make_pair("Bh", 270),
     std::make_pair("Hs", 277),
     std::make_pair("Mt", 278),
     std::make_pair("Ds", 281),
     std::make_pair("Rg", 282),
     std::make_pair("Cn", 285),
     std::make_pair("Nh", 286),
     std::make_pair("Fl", 289),
     std::make_pair("Mc", 290),
     std::make_pair("Lv", 293),
     std::make_pair("Ts", 294),
     std::make_pair("Og", 294)
     };

//creating map for modes
 std::map<std::string, std::string> modes = {
     std::make_pair("1", "Molar Mass Calculator"),
     std::make_pair("2", "Experimental")
 };

//FUNCTIONS USED BY CIS
void startupInfo(){
    //this function is called to display startup information

    printf("\nChemistry Information System (CIS) %s", Version.c_str());
    printf("\nCale Overstreet");
    printf("\nJan. 16, 2019\n");
}

void releaseNotes(){
    printf("\nRelease Notes:");

    printf("\n\n\tVersion 1.3:");
    printf("\n\t\t1) Added escape measures for incorrect inputs to Molar Mass Calculator");
    printf("\n\t\t   - Incorrect inputs will no longer terminate program");

    printf("\n\n\tVerion 1.2:");
    printf("\n\t\t1) Added 'help', 'info' and 'release' commands for providing\n\t\t   information to the user while using the program");
    printf("\n\t\t2) Streamlined main program loop to reduce irregularities in performance");

    printf("\n\n\tVersion 1.1:");
    printf("\n\t\t1) Completed Periodic Table");

    printf("\n\n\tVersion 1.0");
    printf("\n\t\t1) Program main loop completed\n");
}

void helpMenu(){
    //This function displays the commands and basic info for each
    //can be called with "help" command in CIS

    printf("\nCommands:");
    printf("\n\t1) 'help' - type in help for commands used in CIS");
    printf("\n\t2) 'info' - displays more detailed info on how CIS modes function and acceptable inputs");
    printf("\n\t3) 'mode' - return to mode selection menu");
    printf("\n\t4) 'exit' - terminate program");
    printf("\n\t5) 'release notes' - displays release notes and relevant changes\n");
}

void detailedInfo(){
    //this gives details on proper input to CIS
    //and other uesful information.

    printf("\nFurther Program Information:");
    printf("\n\t1) Inputs have spaces removed, so an input like '   mode  ' is\n\t   read as 'mode'.");
    printf("\n\t2) Currently, the molar mass calculator only has support for\n\t   up to a two digit subscript after each element.");
    printf("\n\t3) This menu will probably never be used as I do not know if\n\t   anyone other than me will use this program.\n");
}

float Molar_Mass(std::string in){

    //Processing and cleaning input
    in.erase(std::remove(in.begin(), in.end(), ' '), in.end());

    //Loop terms
    int i = 0;
    float molarMass = 0;
    int tempCoeffInt;
    std::string tempKey;
    std::string tempCoeff;
    std::string partialFormula;
    float tempMass;
    float elementMass;

    //add part to
    //Main Calculation Loop for determining input and output
    while(in[i]){
        if (std::isupper(in[i])){

            //redo To make checking for letters more efficient

            //checking if element has more than one letter for chemical symbol
            if (std::islower(in[i + 1])){ //for elements with two letters

                //putting symbol into temporary storage for lookup and retrieving value from map
                tempKey = in.substr(i, 2);

                //checking if element entered exist (one method of checking for incorrect inputs in molar mass calculator)
                if (mass.find(tempKey) == mass.end()){
                    printf("\n\tInvalid Input\n");
                    return 0;
                }
                tempMass = mass.at(tempKey);

                //coefficient checking portion
                if (std::isdigit(in[i + 2])){
                    if (std::isdigit(in[i + 3])){ //for two digits

                        //extracting numerical values and converting to integer
                        tempCoeff = in.substr(i+2, 2);
                        tempCoeffInt = std::stoi(tempCoeff);

                        //calculating contribution to molar mass and adding and displaying contribution
                        elementMass = tempMass * tempCoeffInt;
                        molarMass += elementMass;
                        partialFormula = in.substr(i, 4); //retrieving element chunk


                        printf("\n%30s%s", "Element Formula: ", partialFormula.c_str());
                        printf("\n%30s%f", "Molar Mass of Element: ", elementMass);


                        i = i + 4;
                        continue;
                    } else{ //for 1 digit

                        //extracting numerical values and converting to integer
                        tempCoeff = in.substr(i+2, 1);
                        tempCoeffInt = std::stoi(tempCoeff);

                        //calculating contribution to molar mass and adding and displaying contribution
                        elementMass = tempMass * tempCoeffInt;
                        molarMass += elementMass;
                        partialFormula = in.substr(i, 3); //retrieving element chunk


                        printf("\n%30s%s", "Element Formula: ", partialFormula.c_str());
                        printf("\n%30s%f", "Molar Mass of Element: ", elementMass);

                        //moving to next iteration
                        i = i + 3;

                    }


                } else{ //for no coefficients

                    //input mass values and adding to total
                    elementMass = tempMass;
                    molarMass += elementMass;

                    //displaying info
                    partialFormula = in.substr(i, 2);
                    printf("\n%30s%s", "Element Formula: ", partialFormula.c_str());
                    printf("\n%30s%f", "Molar Mass of Element: ", elementMass);

                    //moving to next iteration
                    i = i + 2;


                }



            } else{ //for single letter elements
                tempKey = in.substr(i, 1);

                if (mass.find(tempKey) == mass.end()){
                    printf("\n\tInvalid Input\n");
                    return 0;
                }

                tempMass = mass.at(tempKey);

                //Coefficient checking portion
                if (std::isdigit(in[i + 1])){
                    if (std::isdigit(in[i + 2])){ //One-letter, two-digit

                        //extracting numerical values and converting to integer
                        tempCoeff = in.substr(i+1, 2);
                        int tempCoeffInt = std::stoi(tempCoeff);

                        //calculating contribution to molar mass and adding and displaying contribution
                        float elementMass = tempMass * tempCoeffInt;
                        molarMass += elementMass;
                        partialFormula = in.substr(i, 4); //retrieving element chunk


                        printf("\n%30s%s", "Element Formula: ", partialFormula.c_str());
                        printf("\n%30s%f", "Molar Mass of Element: ", elementMass);


                        i = i + 3;
                        continue;
                    } else{ //One-Letter, One-digit

                        //extracting numerical values and converting to integer
                        tempCoeff = in.substr(i+1, 1);
                        tempCoeffInt = std::stoi(tempCoeff);

                        //calculating contribution to molar mass and adding and displaying contribution
                        elementMass = tempMass * tempCoeffInt;
                        molarMass += elementMass;
                        partialFormula = in.substr(i, 2); //retrieving element chunk


                        printf("\n%30s%s", "Element Formula: ", partialFormula.c_str());
                        printf("\n%30s%f", "Molar Mass of Element: ", elementMass);

                        //moving to next iteration
                        i = i + 2;
                    }

                } else{ //One-letter, no digit

                    //input mass values and adding to total
                    elementMass = tempMass;
                    molarMass += elementMass;

                    //displaying info
                    partialFormula = in.substr(i, 1);
                    printf("\n%30s%s", "Element Formula: ", partialFormula.c_str());
                    printf("\n%30s%f", "Molar Mass of Element: ", elementMass);

                    //moving to next iteration
                    i = i + 1;

                }
            }            
        } else{ //second half of validating input, checks to see if too many digits have been entered

            //Warning User
            printf("\n\tError: Incorrect Capitalization of number of subscript digits entered.\n\t       Values displayed may be incorrect.\n");
            return 0;
        }
    }

    //displaying information
    printf("\n\n%30s%s", "Molecular Formula: ", in.c_str());
    printf("\n%30s%f\n", "Molar Mass of Molecule: ", molarMass);

    return molarMass;
}

int main(){

        startupInfo();
        helpMenu();


        while (true){
            std::string modeTest;
            int mode = 0;

            //selecting mode
            while (mode == 0){
                //presenting user with mode options
                std::cout << "\nSelect Mode (enter number):";
                std::cout << "\n\t1) Molar Mass";
                std::cout << "\n\t2) Experimental"; //maybe some future update
                std::cout << "\n\nMode: ";
                std::getline(std::cin, modeTest);

                //Processing and cleaning input
                modeTest.erase(std::remove(modeTest.begin(), modeTest.end(), ' '), modeTest.end());

                //selecting correct response
                if (modeTest == "exit"){ //terminates program
                    return 0;
                } else if (modeTest == "help"){ //displays help menu
                    helpMenu();
                } else if (modeTest == "mode"){ //diplays mode menu, which is redudant
                    mode = 0;
                } else if (modeTest == "info"){
                    detailedInfo();
                } else if (modeTest == "releasenotes"){
                    releaseNotes();
                } else if (modes.find(modeTest) != modes.end()){ //


                    printf("\n%s selected...\n", modeTest.c_str());
                    mode = std::stoi(modeTest);
                    if (mode == 2){
                    	printf("This does nothing...\n");
                    }
                } else{
                    printf("\n\tInvalid Input\n");
                }

            } //end brace for mode selection loop

            //Creating Execution Loop for Molar Mass Calculator
            while (mode == 1){

                    //Creating input to be parsed
                    std::string inputMolarMass = "";

                    //obtaining input
                    std::cout << "\nEnter Chemical Formula for Element/Molecule: ";
                    std::getline(std::cin, inputMolarMass);

                    //Processing and cleaning input
                    inputMolarMass.erase(std::remove(inputMolarMass.begin(), inputMolarMass.end(), ' '), inputMolarMass.end());

                    //checking to see if any commands were entered and displaying as intended
                    if (inputMolarMass == "help"){
                        helpMenu();
                    } else if (inputMolarMass == "mode"){
                        mode = 0;
                    } else if (inputMolarMass == "exit"){
                        return 0;
                    } else if (inputMolarMass == "info"){
                        detailedInfo();
                    } else if (inputMolarMass == "releasenotes"){
                        releaseNotes();
                    } else {
                        //running through calculator
                        Molar_Mass(inputMolarMass);
                    }

            }//end brace for Molar Mass Calculator Loop

         }//end brace for main program loop

}


