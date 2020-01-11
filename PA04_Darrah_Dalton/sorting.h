#include <iostream> 
#include <fstream> 
using namespace std; 

const int MAX_DATA1 = 1000; 
const int MAX_DATA2 = 10000; 
const int MAX_DATA3 = 100000; 
const int NUM_RUNS = 10; 

class bubbleSort{
	public: 
		bubbleSort();
		~bubbleSort();
		void loadBubble(int);
		void bubble(int);
		void setBubbleSwapCount();
		void setBubbleComparisonCount();
		unsigned long long int getBubbleSwapCount();
		unsigned long long int getBubbleComparisonCount();
		float getAverageTime(float*); 
	private: 
		unsigned long long int swapCount; 
		unsigned long long int comparisonCount; 
		int *bubbleData;
		ofstream bubbleOut; 
};


class quickSort{
	public:
		quickSort();
		~quickSort();
		void loadQuick(int);
		void quick(int, int);
		void setQuickSwapCount();
		void setQuickComparisonCount();
		int partition(int, int);
		unsigned long long int getQuickSwapCount();
		unsigned long long int getQuickComparisonCount();
		float getAverageTime(float*);
	private:  
		unsigned long long int swapCount; 
		unsigned long long int comparisonCount; 
		int *quickData;
		ofstream quickOut; 
};


class radixSort{
	public: 	
		radixSort();
		~radixSort();
		void loadRadix(int);
		void radix(int);
		void counting(int*, int, int);
		void setRadixSwapCount();
		void setRadixComparisonCount();
		int getMax(int);
		unsigned long long int getRadixSwapCount();
		unsigned long long int getRadixComparisonCount();
		float getAverageTime(float*);
	private: 
		unsigned long long int swapCount;
		unsigned long long int comparisonCount; 
		int *radixData;
		ofstream radixOut; 
};