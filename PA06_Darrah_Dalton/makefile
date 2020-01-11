#driver executable is made
all: main.o BST.o
	g++ main.o BST.o -o tree

main.o: main.cpp
	g++ -c main.cpp -o main.o

BST.o: BST.cpp
	g++ -c BST.cpp -o BST.o

clean:
	rm *.o PA06_Darrah_Dalton