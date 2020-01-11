#include <iostream> 
#include <string> 
#include <fstream>
#include "readFile.h"

using namespace std; 

readFile::readFile(char *cityF, char *requestF, char *flightF)
{
	string tempCity[MAX_CITY];
	string tempRequest[MAX_REQUEST][2];
	string tempFlight[MAX_FLIGHT][2];

	cout << "Parameterized Constructor" << endl; 
	int increment = 0, rowCount = 0, colCount = 0, tempInt;
	string temp;  

	/************************ CITY FILE READ IN  *********************/
	cityFile.clear();
	cityFile.open(cityF);
	if(cityFile.good()){
	for(increment = 0; increment < MAX_CITY; increment++){
		getline(cityFile, tempCity[increment]);
	}
	for(increment = 0; increment < MAX_CITY - 1; increment++){
		cityArray[increment] = tempCity[increment];
		cout << cityArray[increment] << endl;
	}
	}
	else {
		cout << "There was an error opening the city file. " << endl; 
	}
	cityFile.close();
	cout << endl << endl; 
	/************************ REQUEST FILE READ IN  *********************/
	requestFile.clear();
	requestFile.open(requestF);

	if(requestFile.good()){
		for(rowCount = 0; rowCount < MAX_REQUEST; rowCount++){
				getline(requestFile, tempRequest[rowCount][colCount], ',');
				requestFile.ignore();
				getline(requestFile, tempRequest[rowCount][colCount+1]);
				colCount = 0; 
		}
		requestArray = new string*[MAX_REQUEST]; 
		for(rowCount = 0; rowCount < MAX_REQUEST; rowCount++){
			requestArray[rowCount] = new string[2];
			for(colCount = 0; colCount < 2; colCount++){
				requestArray[rowCount][colCount] = tempRequest[rowCount][colCount];
			}
		}
		colCount = 0; 
		for(rowCount = 0; rowCount < MAX_REQUEST; rowCount++){
			cout << requestArray[rowCount][colCount] << ", " << requestArray[rowCount][colCount+1] << endl; 
			colCount = 0; 
		}
	}
	else {
		cout << "There was an error opening the request file. " << endl; 
	}
	requestFile.close();

	/************************ FLIGHT FILE READ IN  *********************/
	flightFile.clear();
	flightFile.open(flightF);

	if(flightFile.good()){
		cout << "flight open" << endl;
		for(rowCount = 0; rowCount < MAX_FLIGHT; rowCount++){
				getline(flightFile, tempFlight[rowCount][colCount], ',');
				flightFile.ignore();
				getline(flightFile, tempFlight[rowCount][colCount+1], '\t'); 
				flightFile >> tempInt >> tempInt; 
				getline(flightFile, temp);
				colCount = 0; 
		}	
		flightArray = new string*[MAX_FLIGHT];
		for(rowCount = 0; rowCount < MAX_FLIGHT; rowCount++){
			flightArray[rowCount] = new string[2];
			for(colCount = 0; colCount < 2; colCount++){
				flightArray[rowCount][colCount] = tempFlight[rowCount][colCount];
			}
		}	
		colCount = 0; 
		for(rowCount = 0; rowCount < MAX_FLIGHT; rowCount++){
			cout << flightArray[rowCount][colCount] << ", " << flightArray[rowCount][colCount+1] << endl; 
			colCount = 0; 
		}
	}
	else {
		cout << "There was an error opening the flight file. " << endl; 
	}
	flightFile.close();

}

string* readFile::getCityArray()
{
	return cityArray;
}

string** readFile::getRequestArray()
{ 
	return requestArray;
}

string** readFile::getFlightArray()
{
	return flightArray;
}
