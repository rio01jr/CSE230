main: main.o merge_sort.o
	g++ -Wall -o MAIN main.o merge_sort.o
main.o: main.cpp
	g++ -Wall -c main.cpp
merge_sort.o: merge_sort.cpp merge_sort.h
	g++ -Wall -c merge_sort.cpp
clean:
	rm -f *.o MAIN