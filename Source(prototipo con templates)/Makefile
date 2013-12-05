all: main

tree.o: tree.cpp
	g++ -c tree.cpp

main.o: main.cpp
	g++ -c main.cpp

main: main.o tree.o
	g++ main.o tree.o -o main

clean:
	rm -rf *o main

