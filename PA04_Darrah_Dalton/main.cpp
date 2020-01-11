#include <iostream> 
#include "sorting.h"
#include <time.h> 
#include <ctime>
#include <fstream> 

using namespace std; 

int main()
{
	bubbleSort B; 
	quickSort Q;
	radixSort R;
	float t1, t2, t3, t4, t5, t6; 
	int index; 
	float bubbleTimes[NUM_RUNS], quickTimes[NUM_RUNS], radixTimes[NUM_RUNS];
	float bubbleAvgTime, quickAvgTime, radixAvgTime, bubbleAvgTime2, quickAvgTime2, radixAvgTime2, bubbleAvgTime3, quickAvgTime3, radixAvgTime3; 
	unsigned long long int bubbleAvgCompares, quickAvgCompares, radixAvgCompares, bubbleAvgCompares2, quickAvgCompares2, radixAvgCompares2, bubbleAvgCompares3, quickAvgCompares3, radixAvgCompares3;
	unsigned long long int bubbleAvgSwaps, quickAvgSwaps, radixAvgSwaps, bubbleAvgSwaps2, quickAvgSwaps2, radixAvgSwaps2, bubbleAvgSwaps3, quickAvgSwaps3, radixAvgSwaps3;


	cout << "The sorts are running..." << endl; 
	/* BUBBLE SORT 1000 INTS */
	for(index = 0; index < NUM_RUNS; index++){
	B.loadBubble(MAX_DATA1);
	t1 = clock();
	B.bubble(MAX_DATA1);
	t2 = clock();
	bubbleTimes[index] = ((t2 - t1)/CLOCKS_PER_SEC);
	}
	bubbleAvgTime = B.getAverageTime(bubbleTimes);
	bubbleAvgSwaps = B.getBubbleSwapCount();
	bubbleAvgCompares = B.getBubbleComparisonCount();
	
	/* QUICK SORT 1000 INTS */
	for(index = 0; index < NUM_RUNS; index++){
	Q.loadQuick(MAX_DATA1);
	t3 = clock();
	Q.quick(0, MAX_DATA1);
	t4 = clock();
	quickTimes[index] = ((t4 - t3)/CLOCKS_PER_SEC);
	}
	quickAvgTime = Q.getAverageTime(quickTimes);
	quickAvgSwaps = Q.getQuickSwapCount();
	quickAvgCompares = Q.getQuickComparisonCount();

	/* RADIX SORT 1000 INTS */
	for(index = 0; index < NUM_RUNS; index++){
	R.loadRadix(MAX_DATA1);
	t5 = clock();
	R.radix(MAX_DATA1);
	t6 = clock();
	radixTimes[index] = ((t6-t5)/CLOCKS_PER_SEC);
	}
	radixAvgTime = R.getAverageTime(radixTimes);
	radixAvgSwaps = R.getRadixSwapCount();
	radixAvgCompares = R.getRadixComparisonCount();

	B.setBubbleSwapCount();
	B.setBubbleComparisonCount();
	Q.setQuickSwapCount();
	Q.setQuickComparisonCount();
	R.setRadixSwapCount();
	R.setRadixComparisonCount();

	/* BUBBLE SORT 10000 INTS */
	for(index = 0; index < NUM_RUNS; index++){
	B.loadBubble(MAX_DATA2);
	t1 = clock();
	B.bubble(MAX_DATA2);
	t2 = clock();
	bubbleTimes[index] = ((t2 - t1)/CLOCKS_PER_SEC);
	}
	bubbleAvgTime2 = B.getAverageTime(bubbleTimes);
	bubbleAvgSwaps2 = B.getBubbleSwapCount();
	bubbleAvgCompares2 = B.getBubbleComparisonCount();

	/* QUICK SORT 10000 INTS */
	for(index = 0; index < NUM_RUNS; index++){
	Q.loadQuick(MAX_DATA2);
	t3 = clock();
	Q.quick(0, MAX_DATA2);
	t4 = clock();
	quickTimes[index] = ((t4 - t3)/CLOCKS_PER_SEC);
	}
	quickAvgTime2 = Q.getAverageTime(quickTimes);
	quickAvgSwaps2 = Q.getQuickSwapCount();
	quickAvgCompares2 = Q.getQuickComparisonCount();

	/* RADIX SORT 10000 INTS */
	for(index = 0; index < NUM_RUNS; index++){
	R.loadRadix(MAX_DATA2);
	t5 = clock();
	R.radix(MAX_DATA2);
	t6 = clock();
	radixTimes[index] = ((t6-t5)/CLOCKS_PER_SEC);
	}
	radixAvgTime2 = R.getAverageTime(radixTimes);
	radixAvgSwaps2 = R.getRadixSwapCount();
	radixAvgCompares2 = R.getRadixComparisonCount();

	B.setBubbleSwapCount();
	B.setBubbleComparisonCount();
	Q.setQuickSwapCount();
	Q.setQuickComparisonCount();
	R.setRadixSwapCount();
	R.setRadixComparisonCount();

	/* BUBBLE SORT 100000 INTS */
	for(index = 0; index < NUM_RUNS; index++){
	B.loadBubble(MAX_DATA3);
	t1 = clock();
	B.bubble(MAX_DATA3);
	t2 = clock();
	bubbleTimes[index] = ((t2 - t1)/CLOCKS_PER_SEC);
	}
	bubbleAvgTime3 = B.getAverageTime(bubbleTimes);
	bubbleAvgSwaps3 = B.getBubbleSwapCount();
	bubbleAvgCompares3 = B.getBubbleComparisonCount();

	/* QUICK SORT 100000 INTS */
	for(index = 0; index < NUM_RUNS; index++){
	Q.loadQuick(MAX_DATA3);
	t3 = clock();
	Q.quick(0, MAX_DATA3);
	t4 = clock();
	quickTimes[index] = ((t4 - t3)/CLOCKS_PER_SEC);
	}
	quickAvgTime3 = Q.getAverageTime(quickTimes);
	quickAvgSwaps3 = Q.getQuickSwapCount();
	quickAvgCompares3 = Q.getQuickComparisonCount();

	/* RADIX SORT 100000 INTS */
	for(index = 0; index < NUM_RUNS; index++){
	R.loadRadix(MAX_DATA3);
	t5 = clock();
	R.radix(MAX_DATA3);
	t6 = clock();
	radixTimes[index] = ((t6-t5)/CLOCKS_PER_SEC);
	}
	radixAvgTime3 = R.getAverageTime(radixTimes);
	radixAvgSwaps3 = R.getRadixSwapCount();
	radixAvgCompares3 = R.getRadixComparisonCount();

	cout << "Timings:" << endl; 
	cout << "Size/Algorithm" << '\t' << "Bubble Sort" << '\t' << "Quick Sort" << '\t' << "Radix Sort" << endl; 
	cout << "1000" << '\t' << '\t' << bubbleAvgTime << '\t' << quickAvgTime << '\t' << radixAvgTime << endl;
	cout << "10000" << '\t' << '\t' << bubbleAvgTime2 << '\t' << quickAvgTime2 << '\t' << radixAvgTime2 << endl; 
	cout << "100000" << '\t' << '\t' << bubbleAvgTime3 << '\t' << '\t' << quickAvgTime3 << '\t' << radixAvgTime3 << endl << endl << endl;

	cout << "Comparisons/Swaps" << endl; 
	cout << "Size/Algorithm" << '\t' << "Bubble Sort" << '\t' << '\t' << '\t' << "Quick Sort" << '\t' << '\t' << '\t' << "Radix Sort" << endl; 
	cout << "\t\t" << "Compares" << '\t' << "Swaps" << '\t' << '\t' << "Compares" << '\t' << "Swaps" << '\t' << '\t' << "Compares" << '\t' << "Swaps" << endl;
	cout << "1000" << '\t' << '\t' << bubbleAvgCompares << '\t' << '\t' << bubbleAvgSwaps << '\t' << '\t' << quickAvgCompares << '\t' << '\t' << quickAvgSwaps << '\t' << '\t' << radixAvgCompares << '\t' << '\t' << radixAvgSwaps << endl;
	cout << "10000" << '\t' << '\t' << bubbleAvgCompares2 << '\t' << bubbleAvgSwaps2 << '\t' << quickAvgCompares2 << '\t' << '\t' << quickAvgSwaps2 << '\t' << '\t' << radixAvgCompares2 << '\t' << '\t' << radixAvgSwaps2	 << endl;
	cout << "100000" << '\t' << '\t' << bubbleAvgCompares3 << '\t' << bubbleAvgSwaps3 << '\t' << quickAvgCompares3 << '\t' << quickAvgSwaps3 << '\t' << '\t' << radixAvgCompares3 << '\t' << '\t' << radixAvgSwaps3	 << endl;
	return 0; 
}