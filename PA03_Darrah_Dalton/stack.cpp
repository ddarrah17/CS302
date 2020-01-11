#include <iostream> 
#ifndef stackInterface
#define stackInterface 

using namespace std; 

class stackInterface {
	public:
	virtual bool isEmpty() const = 0; 
	virtual bool push(const ItemType& ) = 0;
	virtual bool pop() = 0; 
	virtual ItemType peek() const = 0; 
	virtual ~stackInterface { } 
};
#endif 