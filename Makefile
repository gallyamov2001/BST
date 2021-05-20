all: test
test: test.o binary_tree.o
	gcc binary_tree.o test.o -o test -fprofile-arcs -ftest-coverage
test.o: test.c
	gcc -c test.c -fprofile-arcs -ftest-coverage
binary_tree.o: binary_tree.c
	gcc -c binary_tree.c -fprofile-arcs -ftest-coverage
clean: 
	rm -rf *.o *.gcno *.gcda *.gcov test
