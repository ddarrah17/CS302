#include <iostream> 
using namespace std; 

class quickSort{
	public:
		quickSort();
		~quickSort();
		void loadQuick();
		void quick();
		int getQuickSwapCount();
		int getQuickComparisonCount();
	private:  
		int swapCount; 
		int comparisonCount; 
		int quickData[MAX_DATA];
};