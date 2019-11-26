
CC = g++ 

all: build clean

build: main.o greedy_heuristic.o local_search.o iterated_local_search.o
	$(CC) main.o greedy_heuristic.o local_search.o iterated_local_search.o

main.o:
	$(CC) -c main.cpp -o main.o

greedy_heuristic.o:
	$(CC) -c greedy_heuristic.cpp -o greedy_heuristic.o

local_search.o:
	$(CC) -c local_search.cpp -o local_search.o

iterated_local_search.o:
	$(CC) -c iterated_local_search.cpp -o iterated_local_search.o

clean:
	rm *.o
