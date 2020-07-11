# IMPORTANT
Transition to Zig should wait until the language matures more. Memory handling needs to be fleshed out and compatibility with tools like valgrind is necessary before I start to convert programs fully to Zig. Zig is a very promising language though. Also, I need to make a library/module for handling strings in Zig. No point in rewriting that code.

# Chemical Information System (CIS)

The CIS is a terminal-based program that can currently calculate the molar mass of a given chemical formula. 

# IMPORTANT

Migration to Zig in progress to make cross platform support much easier. Building C/C++ programs on Windows tends to be a pain.

___
# Installation
To install CIS, run the following commands:
1. `git clone https://github.com/ccoverstreet/CIS.git`
2. `cd CIS`
3. `make`

The above three steps create a single executable file called "CIS". 

To run the program, enter `./CIS` on unix-based systems while in the root of CIS or `CIS_2_0.exe` on Windows systems. 

If you want the packaged stable release, these is a bundled released under the "Releases" tab for Version 2.0. Once unzipped, navigate to the root of the extracted folder and run the `make` command like above. I will also be adding a compiled executables for Windows and other platforms in the future.
