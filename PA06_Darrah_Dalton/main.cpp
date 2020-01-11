#include <iostream>
#include <cstdlib> 
#include "BST.h"
using namespace std; 

void generateUniqueNum(int*, int*);

int main()
{
	int value = 0;
	int nodeCount = 0;  
	int height = 0;
	int index = 0, index2 = 0, indexCount = 0; 
	int copyCount = 0; 
	int uniqueArray[100];
	int uniqueArray2[10];
	int indexCheck[100];
	int overlapCount = 0; 
	bool preClear = false, postClear = false; 
	bool preClear2 = false, postClear2 = false; 
	binarySearchTree BST1;
	binarySearchTree BST2;  

	//Call our function to generate the unique values and store them in an array
	generateUniqueNum(uniqueArray, uniqueArray2);
	
	//Fill our tree data with this array
	for(index = 0; index < 100; index++){
		BST1.add(uniqueArray[index]);
	}
	//Fill in our BST2 with the 10 integers
	for(index = 0; index < 10; index++){
		BST2.add(uniqueArray2[index]);
	}
	
	//Printing Full BST1
	cout << "--------------------------------------------------" << endl; 
	cout << "- 		      BST1			 -" << endl;
	cout << "--------------------------------------------------" << endl; 
	BST1.inorderTraverse();
	nodeCount = BST1.getNodeCount();
	cout << "The node count of BST1 is: " << nodeCount << endl; 
	height = BST1.getHeight();
	cout << "The height of BST1 is: " << height << endl; 
	//Printing Full BST2
	cout << "--------------------------------------------------" << endl; 
	cout << "- 		      BST2			 -" << endl;
	cout << "--------------------------------------------------" << endl; 
	BST2.inorderTraverse();
	BST2.preorderTraverse();
	BST2.postorderTraverse();
	nodeCount = BST2.getNodeCount();
	cout << "The node count of BST2 is: " << nodeCount << endl; 
	height = BST2.getHeight();
	cout << "The height of BST2 is: " << height << endl << endl;
	
	//Running for loops to see what vaules are overlapped	
	for(index = 0; index < 10; index++){
		for(index2 = 0; index2 < 100; index2++){
			if(uniqueArray2[index] == uniqueArray[index2]){
				overlapCount++; 
			}
		}
	}
	cout << "The amount of numbers that overlapped is: " << overlapCount << endl << endl; 
	cout << "Overlapping values: " << endl; 
	
	//Setting up a new array to hold our new values with out the overlaps
	int overLapArray[overlapCount];
	int newData[100-overlapCount];
	for(index = 0; index < 10; index++){
		for(index2 = 0; index2 < 100; index2++){
			if(uniqueArray2[index] == uniqueArray[index2]){
				overLapArray[indexCount] = uniqueArray[index2]; 
				cout << overLapArray[indexCount] << ' '; 
				indexCount++; 
			}
		}
	}

	cout << endl  << endl << "Removing the values that overlap in BST1.." << endl; 
	for(index = 0; index < overlapCount; index++){
		BST1.deleteValue(overLapArray[index]);
	}

	cout << "After the Removal : " << endl << endl; 
	cout << "--------------------------------------------------" << endl; 
	cout << "- 		      BST1			 -" << endl;
	cout << "--------------------------------------------------" << endl; 
	BST1.inorderTraverse(); 
	nodeCount = BST1.getNodeCount();
	cout << "The node count of BST1 is: " << nodeCount << endl; 
	height = BST1.getHeight();
	cout << "The height of BST1 is: " << height << endl; 
	indexCount = 0; 
	
	//Reload an array with the values that are left over
	for(index = 0; index < 100; index++){
		for(index2 = 0; index2 < overlapCount; index2++){
			if(uniqueArray[index] != overLapArray[index2]){
				indexCheck[index]++; 
			}	
		}
	}
	
	indexCount = 0; 
	for(index = 0; index < 100; index++){
		if(indexCheck[index] == overlapCount){
			newData[indexCount] = uniqueArray[index];
			indexCount++; 
		}
	}

	preClear = BST1.isEmpty(); 
	preClear2 = BST2.isEmpty();

	cout << endl << "BST1 is CLEAR : " << boolalpha << preClear << endl; 
	cout << "BST2 is CLEAR : " << boolalpha << preClear2 << endl << endl; 
	cout << "Now clearing BST1 & BST2..." << endl; 
	
	//These for loops run our updated arrays to them to delete ALL remaining values
	for(index = 0; index < 100 - overlapCount; index++){ 
		BST1.deleteValue(newData[index]);
	}
	for(index = 0; index < 10; index++){
		BST2.deleteValue(uniqueArray2[index]);
	}

	//Clearing BST1
	cout << endl; 
	cout << "--------------------------------------------------" << endl; 
	cout << "- 		      BST1			 -" << endl;
	cout << "--------------------------------------------------" << endl; 
	postClear = BST1.isEmpty();
	cout << endl << "BST1 is CLEAR : " << boolalpha << postClear << endl; 
	nodeCount = BST1.getNodeCount();
	cout << "The node count of BST1 is: " << nodeCount << endl; 
	height = BST1.getHeight();
	cout << "The height of BST1 is: " << height << endl << endl; 
	//Clearing BST2
	cout << "--------------------------------------------------" << endl; 
	cout << "- 		      BST2			 -" << endl;
	cout << "--------------------------------------------------" << endl; 
	postClear2 = BST2.isEmpty();
	cout << "BST2 is CLEAR : " << boolalpha << postClear2 << endl; 
	nodeCount = BST2.getNodeCount();
	cout << "The node count of BST2 is: " << nodeCount << endl; 
	height = BST2.getHeight();
	cout << "The height of BST2 is: " << height << endl << endl; 
	return 0; 
}

void generateUniqueNum(int* array, int* second)
{
	int index; 
	int check; 
	bool isDuplicate; 
	srand((unsigned) time(NULL));

	isDuplicate = false;
	for(index = 0; index < 100; index++){
		do {
			isDuplicate = false; 
			array[index] = (rand() % 200) + 1;
			for(check = index - 1; check > -1; check--){
				if(array[index] == array[check]){
					isDuplicate = true; 
				}
			}
		} while(isDuplicate);
	}

	isDuplicate = false;
	for(index = 0; index < 10; index++){
		do {
			isDuplicate = false; 
			second[index] = (rand() % 200) + 1;
			for(check = index - 1; check > -1; check--){
				if((second[index] == second[check]) && second[index] != array[check]){
					isDuplicate = true; 
				}
			}
		} while(isDuplicate);
	}
}

