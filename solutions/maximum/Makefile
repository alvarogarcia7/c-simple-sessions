.PHONY: test
test: 
	./make-tests.sh > AllTests.c
	clang CuTest.c AllTests.c maximum.c maximumTest.c -o tests
	./tests
