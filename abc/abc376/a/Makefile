COMP = g++ -g -Wall -Wextra -Werror -fsanitize=undefined,address -std=c++20
SRC = main.cpp
BIN = a.out
TESTDIR = test
MAKEFLAGS :=+ --no-builtin-rules --no-print-directory

all: test

$(BIN): $(SRC)
	$(COMP) $(SRC) -o $(BIN)

.PHONY:run
run: $(BIN)
	./$(BIN)

.PHONY:test
test: $(BIN)
	@for testfile in $(wildcard $(TESTDIR)/*.test) ; \
	do \
		if [ -s $$testfile ]; then \
			echo ---------------------- ;\
			echo "exec $$testfile " ;\
			echo "input: "; \
			cat $$testfile ; \
			echo "" ;\
			echo "output: " ;\
			cat $$testfile | ./$(BIN) ;\
		fi \
		done

.PHONY:clean
clean:
	-rm $(BIN)
	@for testfile in $(wildcard $(TESTDIR)/*.test) ; \
	do \
		: > $$testfile ;\
	done
