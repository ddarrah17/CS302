#driver executable is made
all: main.o JSON.o
	g++ main.o JSON.o -o json

main.o: main.cpp
	g++ -c main.cpp -o main.o

JSON.o: JSON.cpp
	g++ -c JSON.cpp -o JSON.o

clean:
	rm *.o PA07_Darrah_Dalton