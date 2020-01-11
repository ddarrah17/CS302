#driver executable is made
all: employeeTest.o Employee.o
	g++ employeeTest.o Employee.o -o Etest

employeeTest.o: employeeTest.cpp
	g++ -c employeeTest.cpp -o employeeTest.o

Employee.o: Employee.cpp
	g++ -c Employee.cpp -o Employee.o
