COMP = g++ -g -Wall -Wextra -Werror -fsanitize=undefined,address -std=c++20
SRC = main.cpp
BIN = main.out
TESTDIR = testfiles
# 暗黙ルールを無効にする, ディレクトリ移動時の出力を無効にする
MAKEFLAGS :=+ --no-builtin-rules --no-print-directory

# 引数（ターゲット）なし実行でtestをターゲットにする
all: test

$(BIN): $(SRC)
	$(COMP) $(SRC) -o $(BIN)

# make run は手作業で標準入力を行う実行
.phony:run
run: $(BIN)
	./$(BIN)

# make test
# TESTDIR内のtestファイルの内容を標準入力する実行（空のファイルは無視する）
.phony:test
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

.phony:clean
clean:
	-rm $(BIN)

# testファイルをすべて空にする
.phony:clean_test
clean_test:
	@for testfile in $(wildcard $(TESTDIR)/*.test) ; \
	do \
		: > $$testfile ;\
	done

