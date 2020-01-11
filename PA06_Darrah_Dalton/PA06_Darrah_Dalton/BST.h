#include <iostream> 

struct Node {
	int value; 
	Node *left;
	Node *right;

	Node(int val){
		this -> value = val; 
		this -> left = NULL; 
		this -> right = NULL; 
	} 

	Node(int val, Node *L, Node *R){
		this -> value = val; 
		this -> left = L; 
		this -> right = R; 
	}
};

class binarySearchTree {
	public:
	/////////////////// * Constuctors & Destructors * ///////////////////
	binarySearchTree(); 
	~binarySearchTree();
	/////////////////// * Public Functions * ///////////////////
	bool isEmpty(); 
	int getHeight(); 
	int getNodeCount(); 
	void add(int);
	bool deleteValue(int);
	/////////////////// * Traversals * ///////////////////
	void preorderTraverse();
	void inorderTraverse();
	void postorderTraverse();
	private: 
	void preorderHelper(Node*);
	void postorderHelper(Node*); 
	void addHelper(Node*, int);
	bool deleteHelper(Node*, Node*, int);
	void inorderHelper(Node*);
	int heightHelper(Node*); 
	Node *root; 
	int nodeCount; 
	
};