#include <iostream>
#include <fstream>  
#include <string> 
#include "JSON.h"

using namespace std; 

int main()
{
	json test; 
	bool menuOver = false; 
	int selection = 0; 

	cout << "Menu Options:" << endl; 
	cout << "=====================" << endl; 
	cout << "1. Read in Data File. (Up to 10 Players)" << endl;
	cout << "2. Change Values in Data." << endl; 
	cout << "3. Create JSON file with updated Data." << endl; 
	cout << "4. End Program." << endl; 


	while(menuOver == false){
		cout << endl << "Enter your Selection here: "; 
		cin >> selection; 
		switch(selection){
			case 1: 
				test.readIn(); 
				break; 
			case 2: 
				test.updateFile();
				break; 
			case 3: 
				cout << "File Updates sent to : 'PlayerStatisticsNew.json'." << endl; 
				test.writeOut(); 	
				break; 
			case 4: 
				menuOver = true; 
				break; 
			default: 
				cout << "Invalid Selection. Try Again. " << endl; 
		}

	}
	return 0; 
}