//These are our header files
#include <iostream> 
#include <string.h> 
#include <fstream>
using namespace std; 

//Class definitions are here 
class Employee {

	//Our public items in our employee class are going to be the public functions that the employee class has to utilize. 
	public:
		//Constructor for the employee class
		Employee();

		//Copy constructor for the employee class
		Employee(const Employee& srcEmployee); 

		//Destructor for the employee class
		~Employee();

		//Function is in place to read in Employee's and their data 
		void readInEmployee(Employee *arrayPtr, int employeeCount); 

		//Function is in place to sort the data by Employee ID
		void sortData(Employee *arrayPtr);

		//Function is in place to simply print out all the data of every employee
		void printData(Employee *arrayPtr);

		//Function is in place to get the average age of all employees 
		float getAverage(); 

		//Function is in place to search the database by employee firstname 
		string searchEmployeeFirst(string firstName);

		//Function is in place to search the database by employee lastname
		string searchEmployeeLast(string lastName);

		//Function is in place to clear the entire employee database 
		void clearList();

		//Function is in place to remove selected employee
		void removeEmployee(string employeeName);

		//Function is in place to check if the database is full of employees
		bool isFull(); 

		//Function is in place to check if the database is empty
		bool isEmpty();

		//Function is in place to return the amount of employees currently in database 
		int getNumberEmployeed(int employeeCount); 


	private:
		//This will hold the first name trait of our employee
		string firstName; 
		//This will hold the last name trait of our employee
		string lastName; 
		//This will hold our age of the employee
		int age; 
		//This will hold our ID number of the employee
		int idNumber; 
};