#include <iostream> 
using namespace std; 

class countingSort{
	public: 
		countingSort();
		~countingSort();
		void loadCounting();
		void counting();
		int	getCountingSwapCount();
		int getCountingComparisonCount();
	private: 
		int swapCount;
		int comparisonCount; 
		int countingArray[MAX_DATA];
};