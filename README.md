# Chemical Information System (CIS)

The CIS is a terminal-based program that can currently calculate the molar mass of a given chemical formula. Future updates will improve the code readability of the molar mass parsing and features like rest mass lookups and chemical formula solving.

___
# Installation
To install CIS, run the following commands:
1. `git clone --recursive https://github.com/ccoverstreet/CIS.git`
2. `cd CIS`
3. `make`
4. `./CIS_2_0` or `CIS_2_0.exe`

The above three steps create a single executable file called "CIS_2_0". There is also a "CIS" executable which is the old version of the program. Both builds are stable, but "CIS_2_0" is more stable and "CIS" will be removed in the future with "CIS_2_0" becoming the new "CIS".

To run the program, enter `./CIS_2_0` on unix-based systems while in the root of CIS or `CIS_2_0.exe` on Windows systems. The executable can be safely moved to any desired directory as it is statically linked to the helper libary "calestr", which is another of my side projects. Calestr is a small C++ string library that adds functions from languages like Python that make manipulating strings easier.

If you want the packaged stable release, these is a bundled released under the "Releases" tab for Version 1.0. Once unzipped, navigate to the root of the extracted folder and run the `make` command like above. I will also be adding a compiled Windows executable to make it easier to install.
