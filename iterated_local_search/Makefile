
CC = g++ 
CFLAGS = -Wall -std=c99  

all: build clean

build: main.o greedy_heuristic.o local_search.o iterated_local_search.o
	$(CC) $(CFLAGS) main.o greedy_heuristic.o local_search.o iterated_local_search.o

main.o:
	$(CC) $(CFLAGS) -c main.cpp -o main.o

greedy_heuristic.o:
	$(CC) $(CFLAGS) -c greedy_heuristic.cpp -o greedy_heuristic.o

local_search.o:
	$(CC) $(CFLAGS) -c local_search.cpp -o local_search.o

iterated_local_search.o:
	$(CC) $(CFLAGS) -c iterated_local_search.cpp -o iterated_local_search.o

clean:
	rm *.o
