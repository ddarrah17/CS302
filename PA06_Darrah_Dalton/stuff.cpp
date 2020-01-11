#include <iostream> 
using namespace std; 

class binaryTreeInterface {
	public:
	virtual bool isEmpty() const = 0; 
	virtual int getHeight() const = 0; 
	virtual int getNumberNodes() const = 0; 
	virtual int getRootData() const = 0; 
	virtual void setRootData(const int&) = 0; 
	virtual bool add(const int&) = 0; 
	virtual bool remove(const int&) = 0; 
	virtual void clear() = 0; 
	virtual int getEntry(const int&) const; 
	virtual bool contains(const int&) const = 0; 
	virtual void preorderTraverse(void visit(int&)) const = 0; 
	virtual void inorderTraverse(void visit(int&)) const = 0; 
	virtual void postorderTraverse(void visit(int&)) const = 0; 
}; 

class node {
	public: 
		node();
		node(const node&); 
		node(const node&, node*, node*);
		void setItem(const node&);
		int getItem() const; 
		bool isLeaf() const; 
		node* getLeftPtr() const; 
		node* getRightPtr() const; 
		void setLeftPtr(node*); 
		void setRightPtr(node*);
	private: 
		int data; 
		node* leftPtr; 
		node* rightPtr; 
};

class binaryNodeTree : public binaryTreeInterface{
	private:
		node* rootPtr; 
	protected:
		int get

}; 


node::node(int val)
{
	cout << "Created new node with a value of : " << val << endl; 
	data = val; 
	rightPtr = leftPtr = NULL; 
}

node::node(const node& source)
{

}

node::node(const node& source, node* leftPtr, node* rightPtr)
{

}

void node::setItem(int source)
{
	cout << "Data set to: " << source << endl; 
	data = source;  
	cout << data << endl; 
}

int node::getItem() const
{
	return data; 
}

bool node::isLeaf() const
{
	return false; 
}

node* node::getLeftPtr() const 
{
	return leftPtr; 
}

node* node::getRightPtr() const
{
	return rightPtr; 
}

void node::setLeftPtr(node* lPtr)
{
	leftPtr = lPtr;
}

void node::setRightPtr(node* rPtr)
{
	rightPtr = rPtr;
}
