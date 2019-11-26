
CC = g++ -std=c++11

all: build clean

build: main.o greedy_heuristic.o local_search.o vnd.o
	$(CC) main.o greedy_heuristic.o local_search.o vnd.o

main.o:
	$(CC) -c main.cpp -o main.o

greedy_heuristic.o:
	$(CC) -c greedy_heuristic.cpp -o greedy_heuristic.o

local_search.o:
	$(CC) -c local_search.cpp -o local_search.o

vnd.o:
	$(CC) -c vnd.cpp -o vnd.o

clean:
	rm *.o
