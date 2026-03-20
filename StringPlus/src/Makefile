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

SRC = $(wildcard s21_*.c)
OBJ = $(SRC:.c=.o)

.PHONY: all clean test gcov_report run_tests

all: 
	make test 
	make clean 
	make gcov_report
	make clean

test: s21_string.a
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_strtok.c -L. s21_string.a $(CHECK) -o strtok_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_strrchr.c -L. s21_string.a $(CHECK) -o strrchr_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_strpbrk.c -L. s21_string.a $(CHECK) -o strpbrk_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_strlen.c -L. s21_string.a $(CHECK) -o strlen_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_strerror.c -L. s21_string.a $(CHECK) -o strerror_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_strstr.c -L. s21_string.a $(CHECK) -o strstr_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_strcspn.c -L. s21_string.a $(CHECK) -o strcspn_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_strncmp.c -L. s21_string.a $(CHECK) -o strncmp_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_strncpy.c -L. s21_string.a $(CHECK) -o strncpy_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_memchr.c -L. s21_string.a $(CHECK) -o memchr_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_memcmp.c -L. s21_string.a $(CHECK) -o memcmp_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_memcpy.c -L. s21_string.a $(CHECK) -o memcpy_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_memset.c -L. s21_string.a $(CHECK) -o memset_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_strchr.c -L. s21_string.a $(CHECK) -o strchr_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_strncat.c -L. s21_string.a $(CHECK) -o strncat_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_sprintf.c -L. s21_string.a $(CHECK) -o sprintf_test
	make run_tests

s21_string.a:
	$(CC) $(CFLAGS) -c s21_*.c
	ar rc s21_string.a *.o
	rm -rf *.o

s21_string_coverage.a:
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -c s21_*.c
	ar rc s21_string_coverage.a *.o
	rm -rf *.o

gcov_report: s21_string_coverage.a
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_strtok.c -L. s21_string_coverage.a $(CHECK) -o strtok_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_strrchr.c -L. s21_string_coverage.a $(CHECK) -o strrchr_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_strpbrk.c -L. s21_string_coverage.a $(CHECK) -o strpbrk_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_strlen.c -L. s21_string_coverage.a $(CHECK) -o strlen_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_strerror.c -L. s21_string_coverage.a $(CHECK) -o strerror_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_strstr.c -L. s21_string_coverage.a $(CHECK) -o strstr_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_strcspn.c -L. s21_string_coverage.a $(CHECK) -o strcspn_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_strncmp.c -L. s21_string_coverage.a $(CHECK) -o strncmp_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_strncpy.c -L. s21_string_coverage.a $(CHECK) -o strncpy_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_memchr.c -L. s21_string_coverage.a $(CHECK) -o memchr_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_memcmp.c -L. s21_string_coverage.a $(CHECK) -o memcmp_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_memcpy.c -L. s21_string_coverage.a $(CHECK) -o memcpy_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_memset.c -L. s21_string_coverage.a $(CHECK) -o memset_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_strchr.c -L. s21_string_coverage.a $(CHECK) -o strchr_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_strncat.c -L. s21_string_coverage.a $(CHECK) -o strncat_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_sprintf.c -L. s21_string_coverage.a $(CHECK) -o sprintf_test
	make run_tests
	gcovr -r . --html --html-details -o coverage.html

clean:
	rm -rf *.o *.a *test *.info *.gcda *.gcno *.html

clang-style:
	cp ../materials/linters/.clang-format ../src
	clang-format -n *.c
	rm .clang-format

run_tests:
	./strerror_test
	./strtok_test
	./strrchr_test
	./strpbrk_test
	./strlen_test
	./strstr_test
	./strcspn_test
	./strncmp_test
	./strncpy_test
	./memchr_test
	./memcmp_test
	./memcpy_test
	./memset_test
	./strchr_test
	./strncat_test
	./sprintf_test