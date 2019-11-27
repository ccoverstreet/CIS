CIS: objects/CIS.o
	g++ -o CIS objects/CIS.o

objects/CIS.o: sources/CIS.cpp
	g++ -o objects/CIS.o -c sources/CIS.cpp
