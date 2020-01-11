#include <iostream> 
using namespace std; 

const int MAX_DATA = 1000; 

class bubbleSort{
	public: 
		bubbleSort();
		~bubbleSort();
		void loadBubble();
		void bubble();
		int getBubbleSwapCount();
		int getBubbleComparisonCount();
	private: 
		int swapCount; 
		int comparisonCount; 
		int bubbleData[MAX_DATA];
};
