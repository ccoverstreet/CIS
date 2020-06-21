CIS: objects objects/main.o objects/string_array.o objects/molar_mass.o src/elements.h
	gcc objects/*.o -o CIS

objects: 
	mkdir objects

objects/main.o: src/main.c src/string_array.h
	gcc -c src/main.c -o objects/main.o

objects/string_array.o: src/string_array.c src/string_array.h
	gcc -c src/string_array.c -o objects/string_array.o

objects/molar_mass.o: src/molar_mass.c src/elements.h
	gcc -c src/molar_mass.c -o objects/molar_mass.o

run: CIS
	./CIS

memcheck: CIS
	valgrind --tool=memcheck --leak-check=full -s ./CIS
