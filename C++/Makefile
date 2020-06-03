main: Matrix.o main.o
	g++ -o main Matrix.o main.o
Matrix.o: Matrix.cpp Matrix.h
	g++ -c -Wall -std=c++14 -g -O0 -pedantic-errors -o Matrix.o Matrix.cpp
main.o: main.cpp Matrix.h
	g++ -c -Wall -std=c++14 -g -O0 -pedantic-errors -o main.o main.cpp