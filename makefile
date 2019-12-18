EXTRA_FLAGS = 

ifeq ($(OS), Windows_NT))
	EXTRA_FLAGS = -static
endif

CIS: objects/CIS.o objects/CIS_data.o objects/CIS_parsing.o libcalestr.a
	g++ $(EXTRA_FLAGS) -o CIS objects/CIS.o objects/CIS_data.o objects/CIS_parsing.o calestr/libcalestr.a

libcalestr.a: 
	cd calestr && make -f makefile

objects/CIS.o: sources/CIS.cpp
	g++ -o objects/CIS.o -c sources/CIS.cpp

objects/CIS_data.o: sources/CIS_data.cpp
	g++ -o objects/CIS_data.o -c sources/CIS_data.cpp

objects/CIS_parsing.o: sources/CIS_parsing.cpp
	g++ -o objects/CIS_parsing.o -c sources/CIS_parsing.cpp


clean:
	rm objects/*.o
