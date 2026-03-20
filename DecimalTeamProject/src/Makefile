OS = $(shell uname)

ifeq ($(OS), Darwin)
	CHECK = -lcheck -lm -lpthread
endif

ifeq ($(OS), Linux)
	CHECK = -lcheck -lsubunit -lm -lrt -lpthread
endif

CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
GCOV_FLAGS = --coverage

SRC_DIR = s21_decimal
TEST_DIR = tests

LIB_NAME = s21_decimal.a
COV_LIB = s21_decimal_coverage.a

SRC = $(shell find $(SRC_DIR) -name "*.c")
OBJ = $(SRC:.c=.o)

TEST_SRC = $(wildcard $(TEST_DIR)/*.c)
TEST_OBJ = $(TEST_SRC:.c=.o)
TEST_BIN = s21_tests

.PHONY: all clean test gcov_report

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ)
	$(AR) rcs $@ $^

test: $(LIB_NAME)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) $(TEST_SRC) -L. -l:$(LIB_NAME) $(CHECK) -o $(TEST_BIN)
	./$(TEST_BIN)

gcov_report: $(SRC) $(TEST_SRC)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) $(SRC) $(TEST_SRC) -o $(TEST_BIN) $(CHECK)
	-./$(TEST_BIN)
	gcovr -r . --html --html-details -o coverage.html

clean:
	rm -rf $(OBJ) $(TEST_OBJ) $(LIB_NAME) $(COV_LIB) $(TEST_BIN) *.o *.gcda *.gcno *.gcov *.html coverage.css coverage.info
