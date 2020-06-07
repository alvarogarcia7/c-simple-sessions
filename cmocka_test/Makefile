.PHONY: test
test: 
	cmake -Bcmake-build-debug .
	$(MAKE) -Ccmake-build-debug all
	@echo "Make test"
	$(MAKE) -Ccmake-build-debug test
	@echo "Execute tests (with more debug information)"
	./cmake-build-debug/unit_tests
