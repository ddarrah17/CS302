#driver executable is made
all: main.o sorting.o
	g++ main.o sorting.o -o sortTest

main.o: main.cpp
	g++ -c main.cpp -o main.o

sorting.o: sorting.cpp
	g++ -c sorting.cpp -o sorting.o

clean:
	rm *.o PA04_Darrah_Dalton