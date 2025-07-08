# noashalom5@gmail.com

CC = clang++
CFLAGS = -Wall -Wextra -std=c++11
OFILES = main.o

Main: main run

main: $(OFILES)
	$(CC) $(CFLAGS) -o main $(OFILES)

main.o: main.cpp myContainer.hpp
	$(CC) $(CFLAGS) -c main.cpp

run: main
	./main

test_exe: test.o
	$(CC) $(CFLAGS) -o test test.o

test: test_exe
	./test

test.o: test.cpp myContainer.hpp doctest.hpp
	$(CC) $(CFLAGS) -c test.cpp

valgrind: main test_exe
	valgrind --leak-check=full --show-leak-kinds=all ./main
	valgrind --leak-check=full --show-leak-kinds=all ./test

clean:
	rm -f *.o main test

.PHONY: Main run test clean valgrind