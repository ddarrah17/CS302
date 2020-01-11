#include <iostream> 
#include <fstream> 
#include <string> 

using namespace std; 

const int MAX_CITY = 29; 
const int MAX_REQUEST = 8; 
const int MAX_FLIGHT = 31; 

class readFile {
	public: 
	readFile(char *, char *, char *);
	string* getCityArray();
	string** getRequestArray();
	string** getFlightArray();
	
	private: 
	ifstream cityFile; 
	ifstream requestFile; 
	ifstream flightFile; 
	string cityArray[MAX_CITY];
	string** requestArray;
	string** flightArray; 
};