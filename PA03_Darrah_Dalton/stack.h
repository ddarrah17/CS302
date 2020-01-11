#pragma once
#include <iostream>
#include <string> 

using namespace std; 

template <class ItemType>

class stackInterface {
	
public:
   	virtual bool isEmpty() const = 0;
   	virtual bool push(const ItemType &newEntry) = 0;
   	virtual bool pop() = 0;
   	virtual ItemType peek() const = 0;
};
