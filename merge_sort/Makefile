.PHONY: test
test: ## Compile and test
	./make-tests.sh > AllTests.c
	clang *.c -o tests
	./tests

.PHONY: help
help: ## Print the help command for make goals
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-40s\033[0m %s\n", $$1, $$2}'
