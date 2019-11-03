.PHONY: test
test: 
	./make-tests.sh > AllTests.c
	clang CuTest.c AllTests.c test.c -o tests
	./tests
