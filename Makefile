all: test
test: test.o binary_tree.o
	gcc binary_tree.o test.o -o test
test.o: test.c
	gcc -c test.c
binary_tree.o: binary_tree.c
	gcc -c binary_tree.c
clean: 
	rm -rf *.o test
