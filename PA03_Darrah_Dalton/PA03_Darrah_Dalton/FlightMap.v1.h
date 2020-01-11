#include <iostream> 
#include <string> 

using namespace std; 

class cityStack {

public: 

	cityStack();
	~cityStack();
	void setOriginCity(string**, int, int);
	void setDestinationCity(string**, int, int);
	string getOriginCity();
	string getDestinationCity();
	string getTop();
	int checkMatches(string**, bool);
	int twoDimCompare(string**, string, int, int);
	int travelCheck();
	bool travel(string**, string**,int ,int);
	bool push(string);
    bool pop();
    bool empty() const;
    bool full() const; 
    bool clear();


private: 

	string originCity; 
	string destinationCity;
	int max;
    int top;
    string* data;
};