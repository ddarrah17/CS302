#driver executable is made
all: PA03.o FlightMap.v1.o readFile.o
	g++ PA03.o FlightMap.v1.o readFile.o -o v1

PA03.o: PA03.cpp
	g++ -c PA03.cpp -o PA03.o

readFile.o: readFile.cpp
	g++ -c readFile.cpp -o readFile.o

FlightMap.v1.o: FlightMap.v1.cpp
	g++ -c FlightMap.v1.cpp -o FlightMap.v1.o

clean:
	rm *.o PA03_Darrah_Dalton