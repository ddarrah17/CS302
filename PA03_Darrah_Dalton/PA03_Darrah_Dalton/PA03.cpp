#include <iostream> 
#include <string> 
#include "FlightMap.v1.h"
#include "readFile.h"


using namespace std; 

int main()
{
	char city[25] = "cityFile.txt", request[25] = "requestFile.txt", flight[25] = "flightFile.txt"; 
	int increment, colCount, rowCount; 
	string *temp;
	string **temp2D; 
	string cityArray[MAX_CITY];
	string **requestArray;
	string **flightArray;
	cityStack b; 
	
	// cout << "Enter your city filename: " ; 
	// cin >> city; 
	// cout << "Enter your request filename: ";
	// cin >> request; 
	// cout << "Enter your flight filename: ";
	// cin >> flight; 

	readFile a(city, request, flight); 
	
	/*********************** THIS READS THE DATA INTO OUR LOCAL CITY ARRAY */ 
	cout << "Data that's stored in our city array : " << endl << endl; 
	temp = a.getCityArray(); 

	for(increment = 0; increment < MAX_CITY; increment++){
		cityArray[increment] = *temp; 
		temp++; 
	}
	temp = NULL;
	for(increment = 0; increment < MAX_CITY; increment++){
		cout << cityArray[increment] << endl; 
	}
	cout << endl << endl; 
	/*********************** THIS READS THE DATA INTO OUR LOCAL REQUEST ARRAY */ 
	cout << "Data that's stored in our request array : " << endl << endl;
	temp2D = a.getRequestArray();

	requestArray = new string*[MAX_REQUEST]; 
		for(rowCount = 0; rowCount < MAX_REQUEST; rowCount++){
			requestArray[rowCount] = new string[2];
			for(colCount = 0; colCount < 2; colCount++){
				requestArray[rowCount][colCount] = temp2D[rowCount][colCount];
			}
		}
		colCount = 0; 
		for(rowCount = 0; rowCount < MAX_REQUEST; rowCount++){
			cout << requestArray[rowCount][colCount] << ", " << requestArray[rowCount][colCount+1] << endl; 
			colCount = 0; 
		}
	cout << endl << endl; 
	/*********************** THIS READS THE DATA INTO OUR LOCAL FLIGHT ARRAY */ 
	cout << "Data that's stored in our flight array : " << endl << endl; 
	temp2D = a.getFlightArray();

	flightArray = new string*[MAX_FLIGHT];
		for(rowCount = 0; rowCount < MAX_FLIGHT; rowCount++){
			flightArray[rowCount] = new string[2];
			for(colCount = 0; colCount < 2; colCount++){
				flightArray[rowCount][colCount] = temp2D[rowCount][colCount];
			}
		}	
		colCount = 0; 
		for(rowCount = 0; rowCount < MAX_FLIGHT; rowCount++){
			cout << flightArray[rowCount][colCount] << ", " << flightArray[rowCount][colCount+1] << endl; 
			colCount = 0; 
		}
	cout << endl << endl;
	for(increment = 0; increment < MAX_REQUEST; increment++){
	cout << endl << "NEW REQUEST" << endl << endl;
	b.travel(flightArray, requestArray, increment, 0);
	}
	return 0; 
}