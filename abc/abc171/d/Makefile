CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -fsanitize=undefined,address -I/home/amon/amlib
LIB_NAME = libam.a
SRCS := $(wildcard /home/amon/amlib/*.c)
OBJS = $(SRCS:.c=.o)
MAIN = main.c
TARGET = a.out
TESTDIR = test
SUBMITTION = sub.c
HEADDER = /home/amon/amlib/am.h

all: test clean

$(LIB_NAME): $(OBJS)
	ar rcs $@ $^

$(TARGET): $(MAIN) $(LIB_NAME)
	$(CC) $(CFLAGS) $(MAIN) -L. -lam -o $@

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY:run
run: $(TARGET)
	./$(TARGET)

.PHONY:test
test: $(TARGET)
	@for testfile in $(wildcard $(TESTDIR)/*.test) ; \
	do \
		if [ -s $$testfile ]; then \
			echo ---------------------- ;\
			echo "exec $$testfile " ;\
			echo "input: "; \
			cat $$testfile ; \
			echo "" ;\
			echo "output: " ;\
			cat $$testfile | ./$(TARGET) ;\
		fi \
		done
	cat $(HEADDER) $(SRCS) $(MAIN) | grep -v '#include "am.h"' > $(SUBMITTION)

.PHONY:clean
clean:
	-rm $(TARGET)
	@for testfile in $(wildcard $(TESTDIR)/*.test) ; \
	do \
		: > $$testfile ;\
	done
