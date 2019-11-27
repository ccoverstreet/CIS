all: CIS CIS_2_0

CIS: objects/CIS.o
	g++ -o CIS objects/CIS.o

objects/CIS.o: sources/CIS.cpp
	g++ -o objects/CIS.o -c sources/CIS.cpp


CIS_2_0: objects/CIS_2_0.o objects/CIS_data.o objects/CIS_parsing.o libcalestr.a
	g++ -o CIS_2_0 objects/CIS_2_0.o objects/CIS_data.o objects/CIS_parsing.o calestr/libcalestr.a

libcalestr.a: 
	make calestr/makefile

objects/CIS_2_0.o: sources/CIS_2_0.cpp
	g++ -o objects/CIS_2_0.o -c sources/CIS_2_0.cpp

objects/CIS_data.o: sources/CIS_data.cpp
	g++ -o objects/CIS_data.o -c sources/CIS_data.cpp

objects/CIS_parsing.o: sources/CIS_parsing.cpp
	g++ -o objects/CIS_parsing.o -c sources/CIS_parsing.cpp


clean:
	rm objects/*.o
