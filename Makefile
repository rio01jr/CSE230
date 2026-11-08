main: main.o BST.o
	g++ -Wall -o MAIN main.o BST.o
main.o: main.cpp
	g++ -Wall -c main.cpp
merge_sort.o: BST.cpp BST.h
	g++ -Wall -c BST.cpp
clean:
	rm -f *.o MAIN