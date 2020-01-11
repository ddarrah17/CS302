//Include the header files 
#include <iostream> 
#include <string.h> 
#include <fstream> 
#include "Employee.h"

using namespace std; 

//Begin the main function 
int main()
{
	//Begin by creating an array of Employees to a set max size, say [25]

	//We them need an Employee pointer to point at our array to pass into our functions to edit our data in the array 

	//We will assume that what we are getting from the user is a file. Therefore we will need to create a variable to store our file name

	//After we have received the filename and stored it in the correct variable, we will then clear, and open the file. 

	//Running a loop, we will take in the components of the file, as stated in the Employee.cpp file, we are expecting these items in the order of: 

	   //firstname

	   //lastname

	   //age 

	   //ID number

	//If the user has entered the correct format, we will have stored all employees correctly in our database 

	//We can then perform our functions

	   //First, run the sortData function to allign the employees in the order by the date they were hired, as employee ID correlates to the date they were hired. 

	   //After sorting, we can print all the data on our employees to view our info in the proper order 

	   //Next, run the getAverage function to note the average age of the employees

	   //After that we can conduct a search by name to either look specifically for an employee or to see if anyone in the company matches our search name.

	   //Next, maybe we can simulate what would happen if an employee was fired, so we put in the employee name, and remove them from the list, returning their entry to defualt settings.

	   //Finally, the business has failed and all the employees need to be removed from the employee database, therefore we can call our clear function and do this. 

	return 0; 
}