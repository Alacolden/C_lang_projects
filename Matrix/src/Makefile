CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror -pedantic
TEST_FLAGS = -lcheck -lm -lpthread -lrt -lsubunit
GCOV_FLAGS = -fprofile-arcs -ftest-coverage

SRC = s21_matrix.c
OBJ = $(SRC:.c=.o)
TEST_SRC = s21_test.c
LIB_NAME = s21_matrix.a
TEST_NAME = test_matrix
EXAMPLE_NAME = example
REPORT_DIR = report

.PHONY: all clean test gcov_report run

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c s21_matrix.h
	$(CC) $(CFLAGS) -c $< -o $@

test: $(LIB_NAME) $(TEST_SRC)
	$(CC) $(CFLAGS) $(TEST_SRC) $(LIB_NAME) $(TEST_FLAGS) -o $(TEST_NAME)
	./$(TEST_NAME)

run: $(LIB_NAME) example.c
	$(CC) $(CFLAGS) example.c $(LIB_NAME) -o $(EXAMPLE_NAME) -lm
	./$(EXAMPLE_NAME)

example: run

gcov_report: clean
	$(CC) $(CFLAGS) $(GCOV_FLAGS) $(SRC) $(TEST_SRC) $(TEST_FLAGS) -o $(TEST_NAME)
	./$(TEST_NAME)
	@mkdir -p $(REPORT_DIR)
	gcovr --html-details -o $(REPORT_DIR)/report.html
	gcovr --print-summary
	open $(REPORT_DIR)/report.html || xdg-open $(REPORT_DIR)/report.html || echo "Отчет создан в $(REPORT_DIR)/report.html"

clean:
	rm -rf $(REPORT_DIR) $(TEST_NAME) $(EXAMPLE_NAME) *.a *.o *.gcda *.gcno *.gcov gcov_report

style:
	clang-format -n -style=Google *.c *.h

format:
	clang-format -i -style=Google *.c *.h

rebuild: clean all

help:
	@echo "Доступные команды:"
	@echo "  make all     - собрать библиотеку"
	@echo "  make test    - запустить unit-тесты"
	@echo "  make run     - запустить пример использования"
	@echo "  make example - то же, что и make run"
	@echo "  make gcov_report - создать отчет о покрытии тестами"
	@echo "  make clean   - удалить сгенерированные файлы"
	@echo "  make style   - проверить стиль кода"
	@echo "  make format  - отформатировать код"
	@echo "  make rebuild - пересобрать все"
	@echo "  make help    - показать эту справку"