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
		return 1; 
	}
	else if(data[top] == originCity){ 
		return -1; 
	}
	else 
		return 0; 
}
 
bool cityStack::travel(string **flightArray, string **requestArray, int row, int col)
{
	bool endPoint;
	int increment, compareVal = -1, check; 
	setOriginCity(requestArray, row, col);
	setDestinationCity(requestArray, row, col + 1);

	for(increment = 0; increment < MAX_FLIGHT; increment++){
		while(endPoint == false){
		compareVal = twoDimCompare(flightArray, originCity, increment, 0);
		//cout << compareVal; 
		if(compareVal == 0){
					push(flightArray[increment][1]);
					check = travelCheck();
					if (check == 1){
						cout << "HPAir can fly from " << originCity << " to " << destinationCity << endl; 
						endPoint = true; 
					}
					else if(check == -1){
						cout << "HPAir can't fly from " << originCity << " to " << destinationCity << endl; 
						endPoint = true;
					}
					else 
						originCity = data[top];
					cout << "Our new origin is : " << originCity << endl; 
		}
		else{

			} 
		}	
	}
	return true; 

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
