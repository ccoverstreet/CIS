CC = zig cc

CIS: objects objects/main.o objects/molar_mass.o src/JMZ-String/libjmzstring.a src/elements.h
	$(CC) objects/*.o src/JMZ-String/libjmzstring.a -o CIS

objects: 
	mkdir objects

objects/main.o: src/main.c 
	$(CC) -c src/main.c -o objects/main.o

src/JMZ-String/libjmzstring.a: 
	cd src/JMZ-String && make libjmzstring.a

objects/molar_mass.o: src/molar_mass.c src/elements.h
	$(CC) -c src/molar_mass.c -o objects/molar_mass.o

run: CIS
	./CIS

memcheck: CIS
	valgrind --tool=memcheck --leak-check=full -s ./CIS
