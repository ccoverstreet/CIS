CIS: objects objects/main.o
	gcc objects/*.o -o CIS

objects:
	mkdir objects

objects/main.o: src/main.c
	gcc -c src/main.c -o objects/main.o

run: CIS
	./CIS
