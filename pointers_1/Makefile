.PHONY: test
test: 
	cmake -Bcmake-build-debug .
	$(MAKE) -Ccmake-build-debug all
	@echo "Make test"
	$(MAKE) -Ccmake-build-debug unit_tests
	@echo "Execute tests (with more debug information)"
	./cmake-build-debug/tests/unit_tests

build-all:
	$(MAKE) main_lines
	cmake -Bcmake-build-debug .
	$(MAKE) -Ccmake-build-debug all
.PHONY: build-all

main_lines: prod.h
	cat prod.h| grep "void\s*main"|awk '{print $$2}' | cut -d\( -f1 > main_lines.txt
	@echo "Detected these main functions:"
	cat main_lines.txt

clean-main-functions:
	rm -f ./by_name.h
	rm -f main_lines.txt
	cp ./by_name.empty ./by_name.h
.PHONY: clean-main-functions

update-main-functions:
	$(MAKE) build-all
	./cmake-build-debug/interpolator/interpolator ${PWD}/by_name.template ${PWD}/main_lines.txt ${PWD}/by_name.h
	## For CLion, you can use these arguments:
	# $ContentRoot$/by_name.template $ContentRoot$/main_lines.txt $ContentRoot$/by_name.h
.PHONY: update-main-functions

install-dependencies:
	$(MAKE) build-all
.PHONY: install-dependencies

clean:
	$(MAKE) clean-main-functions
	rm -rf ./cmake-build-debug/
.PHONY: clean


