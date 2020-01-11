#include <iostream> 
#include <string> 
#include <cstring>  
#include "FlightMap.v1.h"
#include "readFile.h"

using namespace std; 


cityStack::cityStack()
{
	cout << "Default constructor" << endl;
	top = -1; 
	max = 20;
	data = new string[max];
}

cityStack::~cityStack()
{
	cout << "Destructor" << endl;
	top = -1; 
	max = 0; 
	delete [] data; 
}

void cityStack::setOriginCity(string** requestArray, int row, int col)
{
	originCity = requestArray[row][col];
	cout << "The origin city is : " << originCity << endl; 
}

void cityStack::setDestinationCity(string** requestArray, int row, int col)
{
	destinationCity = requestArray[row][col];
	cout << "The destination city is : " << destinationCity << endl; 
}

string cityStack::getOriginCity()
{
	return originCity; 
}

string cityStack::getDestinationCity()
{
	return destinationCity; 
}

string cityStack::getTop()
{
	return data[top]; 
}

int cityStack::checkMatches(string **flightArray, bool newMatches)
{
	int matchCounter = 0, increment, compareVal;

	if(!newMatches){
	for(increment = 0; increment < MAX_FLIGHT; increment++){
		compareVal = twoDimCompare(flightArray, originCity, increment, 0);
		if(compareVal == 0){
			matchCounter++; 
		}
	} 
	cout << "The number of matches we have is: " << matchCounter << endl; 
	return matchCounter;
	}
	else{ 
		for(increment = 0; increment < MAX_FLIGHT; increment++){
		compareVal = twoDimCompare(flightArray, data[top], increment, 0);
		if(compareVal == 0){
			matchCounter++; 
		}
	} 
	cout << "The number of matches we have is: " << matchCounter << endl; 
	return matchCounter;
	}
	return 0; 
}

int cityStack::twoDimCompare(string** flightArray, string origin, int row, int col)
{

	if(origin == flightArray[row][col]){
		return 0; 
	}
	else
		 return 1; 
}

int cityStack::travelCheck()
{
	if(data[top] == destinationCity){
		cout << "You made it!" << endl;
		return 1; 
	}
	else if(data[top] == data[top - 2] || data[top] == originCity){
		cout << "The city is repeating, or its back at the starting location. " << endl; 
		return -1; 
	}
	else 
		cout << "The city seems new..." << endl; 
		return 0; 
}
 
bool cityStack::travel(string **flightArray, string **requestArray, int row, int col)
{
	int matchCounter, increment = 0, compareVal, currentIndex = 0, counter = 0, loopCount = 0, loopCount2 = 0;
	int pathCheck, newMatches, increment2; 
	int *matchIndexs;
	int *matchIndexsNew; 
	setOriginCity(requestArray, row, col);
	setDestinationCity(requestArray, row, col + 1);
	
	matchCounter = checkMatches(flightArray, false);
	matchIndexs = new int[matchCounter];

	cout << "Here is the indexs of our matching numbers: " << endl;
	for(increment = 0; increment < MAX_FLIGHT; increment++){
		compareVal = twoDimCompare(flightArray, originCity, increment, 0);
		if(compareVal == 0){
			matchIndexs[loopCount] = increment;

			cout << matchIndexs[loopCount] << endl; 
			loopCount++; 
		}
	} 
	for(increment = 0; increment < matchCounter; increment++){
		clear();
		currentIndex = matchIndexs[increment]; 
		push(flightArray[currentIndex][1]);
		pathCheck = travelCheck();
		if(pathCheck == 1){
			return true; 
		}
		else if(pathCheck == -1){
			pop(); 
		}
		else if(pathCheck == 0){
			newMatches = checkMatches(flightArray, true);
			matchIndexsNew = new int[newMatches];
			cout << "Here is their indexs: " << endl; 
			for(increment2 = 0; increment2 < MAX_FLIGHT; increment2++){
				compareVal = twoDimCompare(flightArray, data[top], increment2, 0);
				if(compareVal == 0){
					matchIndexsNew[loopCount2] = increment2;
					cout << matchIndexsNew[loopCount2] << endl; 
					loopCount2++; 
				}
			} 
	
		}
	}
	return false; 
}

bool cityStack::push(string cityName)
{
	if(!full()){
		top++;
		data[top] = cityName;
		cout << "The city " << cityName << " has now been pushed to stack." << endl;
		return true;
	}
	else 
		return false; 
}

bool cityStack::pop()
{
	if(!empty()){
		data[top] = -1; 
		top--; 
		return true;
	}
	return false; 
}

bool cityStack::empty() const
{
	if(top == -1){
		return true; 
	}
	else 
		return false; 
}	

bool cityStack::full() const
{
	if(top == max){
		return true; 
	}
	else 
		return false; 
}

bool cityStack::clear()
{
	while(top != -1){
		data[top] = -1;
		top--; 
	}
	if(empty()){
		return true; 
	}
	else 
		return false; 
}
