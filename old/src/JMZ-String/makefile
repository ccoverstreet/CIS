CC = zig cc

libjmzstring.so: objects objects/jmz_string_array.o objects/jmz_string_util.o
	$(CC) -shared objects/* -o libjmzstring.so

libjmzstring.a: objects objects/jmz_string_array.o objects/jmz_string_util.o
	ar rcs libjmzstring.a objects/*

objects:
	mkdir objects

objects/jmz_string_array.o: src/jmz_string_array.c
<<<<<<< HEAD
	$(CC) -fPIC -c src/jmz_string_array.c -o objects/jmz_string_array.o 

objects/jmz_string_util.o: src/jmz_string_util.c
	$(CC) -fPIC -c src/jmz_string_util.c -o objects/jmz_string_util.o 
=======
	$(CC) -fPIC -c src/jmz_string_array.c -o objects/jmz_string_array.o

objects/jmz_string_util.o: src/jmz_string_util.c
	$(CC) -fPIC -c src/jmz_string_util.c -o objects/jmz_string_util.o
>>>>>>> f04b2ce94a52bf7b138a84d56750b743d9983eef

test_driver: libjmzstring.so test/driver.c
	$(CC) test/driver.c -L. -ljmzstring -o test_driver

memcheck: test_driver
	LD_LIBRARY_PATH=. valgrind --tool=memcheck -s ./test_driver
		
run: test_driver
	LD_LIBRARY_PATH=. ./test_driver
