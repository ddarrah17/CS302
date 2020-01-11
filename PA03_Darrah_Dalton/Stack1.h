#ifndef STACK
#define STACK


template<typename ItemType>

class Stack
{
public:
  //checks if stack is empty
  virtual  bool isEmpty() const=0;
  //adds a new item to the stack
  virtual bool push(const ItemType& newEntry)=0;
  //pops the top item off of the stack
  virtual bool pop();
  //returns teh top item of the stack
  virtual ItemType peek() const;

  //virtual~StackInterface();
};
#endif