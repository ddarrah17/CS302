//Header files will be going here, iostream & Employee.h, also string.h
#include <iostream>
#include <string.h> 
#include <fstream> 
#include "Employee.h"

using namespace std;  

Employee::Employee() 
{
	//What will happen in this function, is simply that the variables in the private section in the class Employee 
	//will be set to default values, such as a unique first/last name, as well as a default age of -1. This will be done
	//in order to observe if the changes we make with our functions are happening post-creation of the object. 

	  //set employee firstname to default (firstname = "default")

	  //set employee lastname to default (lastname = "default")

	  //set employee age to default (age = -1)

	  //set employee ID to default (ID = -1)
}

Employee::Employee(const Employee& srcEmployee) 
{
	//This is to copy one object, in this case an employee, and take all the data members and put them in a second object with the 
	//exact same data. 

	  //set employee firstname to srcEmployee.firstname 

	  //set employee lastname to srcEmployee.lastname

	  //set employee age to srcEmployee.age

	  //set employee ID to srcEmployee.ID
}

Employee::~Employee()
{
	//This is where the variables we have are then deallocated if necessary, or set back to a defualt number such as 0. 
	 
	  //set employee back to the firstname to default (firstname = "default")

	  //set employee back to the lastname to default (lastname = "default")

	  //set employee back to the age to default (age = -1)

	  //set employee back to the ID to default (ID = -1)

}

void Employee::readInEmployee(Employee *arrayPtr, int employeeCount)
{
	//For this funciton, what will happen is either we could read in a file, (depending on the requirements of the project) or read in the number 
	//of employees that the user wishes to enter first, and then we will read in the data as follows: firstname, lastname, age, IDNumber
	//The employee counter we have, to track the number of employees will also be increased in this function whenever it is called.

	//In our test driver, the file opening and loop creation is all taken care of, therefore all we have to do is read in one employee for our function to work. 

	   //We will read in our first employee by simplying pointing the arrayPtr to the item we want.


}

void Employee::sortData(Employee *arrayPtr)
{
	//This function is in place to check which employee has the closest ID number to 0, as in this company we are assuming the ID number correlates
	//to the date they were hired, therefore, by sorting by employee ID, we are able to see which employee has been with the company the longest.

	   //For this function, it'll be the same concept as the read in, by using the arrayPtr 
}

void Employee::printData(Employee *arrayPtr)
{
	//The purpose of this function is as simple as printing the list of employees out, this will include their full name, age, and ID number. This will 
	//be printed for all the employees when this function is called. 
}

float Employee::getAverage()
{
	//This function will conduct an average of all the employee's ages, and then return a float value, as the value may come back in between two ages.

	//Return statement here to hide warning// 
	return 0; 
}

string Employee::searchEmployeeFirst(string firstName)
{
	//This function, is a function that I would assume would be very helpful to a company. They can enter in an employee's first name, and the function will
	//return any matches to the first name.

	//Return statement here to hide warning// 
	return 0; 
}

string Employee::searchEmployeeLast(string lastName)
{
	//This function, very similar to the previous function, however this function is in place to specifically pinpoint an employee, as last name matches are
	//usually far less common than first name matches

	//Return statement here to hide warning// 
	return 0; 
}

void Employee::clearList()
{
	//This function has the sole purpose of clearing the entire list 
}

void Employee::removeEmployee(string employeeName)
{
	//This function will utilize the search functions to remove a specific employee from the database
}

bool Employee::isFull()
{
	//This will just do a quick check to see if the employee database is full

	   //This function will do a really quick check comparing the current number of employees to the set "max" and complete logic to check if
	   //the database is full

	//Return statement here to hide warning// 
	return 0; 
}

bool Employee::isEmpty()
{
	//Same as the last, but checks if it is empty, rather than full 

	   //This function will do a really quick check comparing the current number of employees to the set "max" and complete logic to check if
	   //the database is empty

	//Return statement here to hide warning// 
	return 0; 
}
 
int Employee::getNumberEmployeed(int employeeCount)
{
	//Returns the number of employees that are currently in the database, this will be a value that is created in the read in function, however is a variable 
	//that is passed in through the testdriver 

	//Return statement here to hide warning// 
	return 0; 
}
