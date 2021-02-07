.PHONY: test
test: 
	cmake -Bcmake-build-debug .
	$(MAKE) -Ccmake-build-debug all
	@echo "Make test"
	$(MAKE) -Ccmake-build-debug unit_tests
	@echo "Execute tests (with more debug information)"
	./cmake-build-debug/tests/unit_tests

install-dependencies:
	mkdir cmake-build-debug || true
	cmake -Bcmake-build-debug .
	cmake -B cmake-build-debug --build cmake-build-debug --config Debug cmake-build-debug
	$(MAKE) -Ccmake-build-debug all
.PHONY: install-dependencies


