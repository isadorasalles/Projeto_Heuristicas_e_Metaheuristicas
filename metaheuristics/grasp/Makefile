
CC = g++  

all: build clean

build: main.o grasp.o local_search.o 
	$(CC) main.o grasp.o local_search.o 

main.o:
	$(CC) -c main.cpp -o main.o

grasp.o:
	$(CC) -c grasp.cpp -o grasp.o

local_search.o:
	$(CC) -c local_search.cpp -o local_search.o

clean:
	rm *.o
