.PHONY: all clean test calc.a check gcov_report
CC=gcc
FILES= stack.c\
	polish.c\
	parce.c\
	deposit_calc.c\
	credit_calc.c
LDFLAGS= -Wall -Wextra -Werror -std=c11 -g
OS := $(shell uname -s)
LCHECK= `pkg-config --libs check`

ifeq ($(OS), Darwin)
	CC += -D OS_MAC
else
	CC += -D OS_LINUX
endif

default: all

all: clean calc.a

tests: calc.a
ifeq ($(OS), Darwin)
	$(CC) m_tests.c calc.a -o test $(LCHECK)
else
	$(CC) m_tests.c calc.a -o test -lcheck -lpthread -lrt -lm
endif
	./test

clean:
	rm -rf test *.a *.so *.o *.cfg *.gcda *.gcno *.html *.info *.dSYM report

calc.a:
	$(CC) -c $(FILES)
	ar rcs calc.a *.o
	ranlib $@
	cp $@ lib$@

install:
	tar -xf common/SmartCalc_V1.0.tgz -C common/

uninstall:
	rm -rf common/SmartCalc_V1.0.app

dvi:
	open common/page.html

dist:
	tar -cvzf common/SmartCalc_V1.0.tgz SmartCalc_V1.0.app

lib.so:
	$(CC) -fPIC -c $(FILES)
	$(CC) -shared -o libcalc.so *.o

check:
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extension=c *.c
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h
ifeq ($(OS), Darwin)
	CK_FORK=no leaks --atExit -- ./test
else
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all -s ./test
endif

gcov_report: tests
ifeq ($(OS), Darwin)
	$(CC) --coverage $(FILES) m_tests.c -o test $(LCHECK)
	./test
	lcov -t "test" -c -d . -o test.info
	genhtml test.info -o report
	open -a "Google Chrome" report/index.html
else
	$(CC) -fprofile-arcs -ftest-coverage $(FILES) m_tests.c -o test -lcheck -lsubunit -lrt -lpthread -lm -g
	./test
	lcov -t "test" -c -d . -o test.info
	genhtml test.info -o report
	xdg-open report/index.html

endif
