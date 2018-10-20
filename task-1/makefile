all: patterns

patterns: main.o
	clang++ main.o -o patterns

main.o: main.cpp
	clang++ -c main.cpp

clean:
	rm -rf *.o patterns