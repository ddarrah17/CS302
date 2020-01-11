#driver executable is made
all: main.o queue.o
	g++ main.o queue.o -o bank

main.o: main.cpp
	g++ -c main.cpp -o main.o

queue.o: queue.cpp
	g++ -c queue.cpp -o queue.o

clean:
	rm *.o PA05_Darrah_Dalton