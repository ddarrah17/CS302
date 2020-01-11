#include <iostream> 
#include <fstream> 
#include "Queue.h"
using namespace std; 

int main()
{
	int userSelection;
	int data, temp; 
	bool simulationDone = false; 
	ofstream fout;
	ifstream fin; 

	simulation case1(1); 
	simulation case2(3); 
	simulation case3(3);

	cout << "Bank Simulation" << endl << endl;
	cout << "1. One Teller, One Line." << endl; 
	cout << "2. Three Tellers, Three Lines." << endl; 
	cout << "3. Three Tellers, One Line." << endl << endl;  

	cout << "Enter your selection: " ;
	cin >> userSelection;

	while(!simulationDone){
		switch(userSelection) {
			case 1:
				cout << "One Teller, One Line." << endl; 
				cout << "Running simulation.." << endl; 
				case1.createFile();
				cout << endl << "****PRIORITY QUEUE CONTENTS****" << endl; 
				case1.simulateOne(); 
				simulationDone = true; 
				break;
			case 2: 
				cout << "Three Tellers, Three Lines." << endl; 
				cout << "Running Simulation.." << endl; 
				case2.createFile();
				case2.simulateTwo();
				case2.createFile();
				case2.simulateTwo();
				case2.createFile();
				case2.simulateTwo();
				simulationDone = true; 
				break;
			case 3: 
				cout << "Three Tellers, One Line." << endl; 
				cout << "Running Simulation.." << endl; 
				case3.simulateThree();
				simulationDone = true;
				break;
			default: 
				cout << "That is not a valid selection, please try again." << endl;
				simulationDone = true;  
		}
	}
	return 0; 
}