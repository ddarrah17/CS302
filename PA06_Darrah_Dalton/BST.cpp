#include "BST.h"
using namespace std; 

binarySearchTree::binarySearchTree()
{
	root = NULL; 
	nodeCount = 0; 
}

binarySearchTree::~binarySearchTree()
{
	nodeCount = 0; 
	root = NULL; 
}

bool binarySearchTree::isEmpty()
{
	if(root == NULL){
		return true; 
	}
	else 
	return false; 
}

int binarySearchTree::getHeight() 
{
	return heightHelper(this -> root); 
}

void binarySearchTree::add(int val)
{
	if(!isEmpty()){
		this -> addHelper(root, val);
	} else {
		//Create a root value if one is not in place
		root = new Node(val);
		//cout << "Created a Root Node." << endl; 
		nodeCount++; 
	}
}

bool binarySearchTree::deleteValue(int value)
{
	nodeCount--; 
	return this -> deleteHelper(NULL, this -> root, value); 
}

void binarySearchTree::preorderTraverse() 
{	
	cout << "| Preorder Traverse |" << endl;
	cout << " -------------------" << endl; 
	preorderHelper(this -> root);
	cout << endl << endl; 
}

void binarySearchTree::inorderTraverse() 
{
	cout << "| Inorder Traverse |" << endl; 
	cout << " ------------------" << endl; 
	inorderHelper(this -> root);
	cout << endl << endl; 
}

void binarySearchTree::postorderTraverse() 
{
	cout << "| Postorder Traverse |" << endl; 
	cout << " --------------------" << endl; 
	postorderHelper(this -> root);
	cout << endl << endl; 
}

void binarySearchTree::preorderHelper(Node* root)
{
	if(root == NULL){ 
		return; 
	}
	else
		cout << root -> value << ' ' << ' ';
		preorderHelper(root -> left);
		preorderHelper(root -> right);
}

void binarySearchTree::postorderHelper(Node* root)
{
	if(root == NULL){
		return; 
	}
	else 
		postorderHelper(root -> left);
		postorderHelper(root -> right);
		cout << root -> value << ' ' << ' '; 
}

void binarySearchTree::addHelper(Node* root, int val)
{
	//Check if the value at the root is greater than our Val
	if(root -> value > val) {
		if((root -> left) == NULL){
			//Create a new node to the left of our data
			root -> left = new Node(val);
			//cout << "Created a Node on the Left." << endl; 
			nodeCount++; 
		} else {
			//This is our recursion statement
			addHelper(root -> left, val);
		}
	} else {
		if((root -> right) == NULL){
			//Create a new node to the right of our data
			root -> right = new Node(val);
			//cout << "Created a Node on the Right." << endl ; 
			nodeCount++; 
		} else {
			//Recursion to go through function again if Right is not NULL
			addHelper(root -> right, val);
		}
	}
}

bool binarySearchTree::deleteHelper(Node* parent, Node* current, int value)
{
	Node *temp; 
	int t; 
	//Check if the current pointer is NULL, if so return NULL
	if(current == NULL){
		return false; 
	}	
	//If it is not NULL, check if the value is what we want 
	if(current -> value == value){
		if(current -> left == NULL || current -> right == NULL){
			Node *temp = current -> left; 
			if(current -> right ){
				temp = current -> right; 
			}
			if(parent){
				if(parent -> left == current){
					parent -> left = temp; 
				} else {
					parent -> right = temp; 
				}
			} else {
				this -> root = temp; 
			}
		} else {
			Node *valid = current -> right; 
			while(valid -> left){
				valid = valid -> left; 
			}
			t = current -> value; 
			current -> value = valid -> value; 
			valid -> value = t; 
			return deleteHelper(current, current -> right, t);
		}
			delete current; 
			return true; 
	}
	return deleteHelper(current, current -> left, value) || deleteHelper(current, current -> right, value); 
}

void binarySearchTree::inorderHelper(Node* root)
{
	if(!root){
		return; 
	}
	inorderHelper(root -> left); 
	cout << root -> value << ' ' << ' '; 
	inorderHelper(root -> right); 
}

int binarySearchTree::getNodeCount()
{
	return nodeCount; 
}

int binarySearchTree::heightHelper(Node* root)
{
	if(!root){
		return 0; 
	}
	else 
		return 1 + max(heightHelper(root -> left), heightHelper(root -> right));
}
