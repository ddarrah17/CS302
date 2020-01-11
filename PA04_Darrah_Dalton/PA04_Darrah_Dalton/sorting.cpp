#include <iostream> 
#include "sorting.h"
#include <ctime>
#include <string.h>
#include <fstream> 

bubbleSort::bubbleSort()
{
	swapCount = 0; 
	comparisonCount = 0; 
}

bubbleSort::~bubbleSort()
{
	swapCount = 0; 
	comparisonCount = 0;
	delete [] bubbleData; 
}

void bubbleSort::loadBubble(int size)
{
	int index; 
	bubbleData = new int[size];
	srand((unsigned) time(0));
	for(index = 0; index < size; index++){
		bubbleData[index] = (rand() % 1000000) + 1;
	}
}

void bubbleSort::bubble(int size)
{
	int increment, increment2, swap; 

	for(increment = 0; increment < (size - 1); increment++){
		for(increment2 = 0; increment2 < (size - increment - 1); increment2++){
			comparisonCount++; 
			if(bubbleData[increment2] > bubbleData[increment2 + 1]){
				swap = bubbleData[increment2];
				swapCount++; 
				bubbleData[increment2] = bubbleData[increment2 + 1];
				bubbleData[increment2 + 1] = swap; 	
			}
		}
	}
}		

void bubbleSort::setBubbleSwapCount()
{
	swapCount = 0; 
}

void bubbleSort::setBubbleComparisonCount()
{
	comparisonCount = 0; 
}

unsigned long long int bubbleSort::getBubbleSwapCount()
{
	return swapCount; 
}

unsigned long long int bubbleSort::getBubbleComparisonCount()
{
	return comparisonCount; 
}

float bubbleSort::getAverageTime(float times[])
{
	float avgTime; 
	int index;

	for(index = 0; index < NUM_RUNS; index++){
		avgTime += times[index];
	}

	avgTime = avgTime/NUM_RUNS; 
	
	return avgTime; 
}

radixSort::radixSort()
{
	swapCount = 0; 
	comparisonCount = 0; 
}

radixSort::~radixSort()
{
	swapCount = 0; 
	comparisonCount = 0; 
	delete [] radixData;
}

void radixSort::loadRadix(int size)
{
	radixData = new int[size];
	int index; 
	srand((unsigned) time(0));
	for(index = 0; index < size; index++){
		radixData[index] = (rand() % 1000000) + 1;
	}
}

void radixSort::radix(int size)
{
	int m = getMax(size);
	for(int exp = 1; m / exp > 0; exp *= 10){
		counting(radixData, size, exp);
	}
}

void radixSort::counting(int* arr, int n, int exp)
{
	int output[n];
	int index, count[10] = { 0 };

	for(index = 0; index < n; index++){
		count[(arr[index] / exp) % 10]++;
	} 
	for(index = 1; index < 10; index++){
		count[index] += count[index - 1];
	}
	for(index = n - 1; index >= 0; index--){
		output[count[(arr[index] / exp) % 10] - 1] = arr[index];
		count[(arr[index] / exp) % 10]--;
	}
	for(index = 0; index < n; index++){
		arr[index] = output[index];
	}
}

void radixSort::setRadixSwapCount()
{
	swapCount = 0; 
}

void radixSort::setRadixComparisonCount()
{
	comparisonCount = 0; 
}

int radixSort::getMax(int size)
{
	int index;
    int max = radixData[0];
    for (index = 1; index < size; index++)
        if (radixData[index] > max)
            max = radixData[index];
    return max;
}

unsigned long long int radixSort::getRadixSwapCount()
{
	return swapCount; 
}

unsigned long long int radixSort::getRadixComparisonCount()
{
	return comparisonCount;
}

float radixSort::getAverageTime(float times[])
{
	float avgTime; 
	int index;

	for(index = 0; index < NUM_RUNS; index++){
		avgTime += times[index];
	}
	
	avgTime = avgTime/NUM_RUNS; 

	return avgTime; 
}

quickSort::quickSort()
{
	swapCount = 0; 
	comparisonCount = 0; 

}

quickSort::~quickSort()
{
	swapCount = 0; 
	comparisonCount = 0; 
	delete [] quickData;
}

void quickSort::loadQuick(int size)
{
	quickData = new int[size];
	int index; 
	srand((unsigned) time(0));
	for(index = 0; index < size; index++){
		quickData[index] = (rand() % 1000000) + 1;
	}
}

void quickSort::quick(int top, int bottom)
{
	int middle; 
	if(top < bottom){
		middle = partition(top, bottom);
		quick(top, middle);
		quick(middle + 1, bottom);
	}
	return;
}

void quickSort::setQuickSwapCount()
{	
	swapCount = 0; 
}

void quickSort::setQuickComparisonCount()
{
	comparisonCount = 0; 
}

int quickSort::partition(int top, int bottom)
{
	int dataTop = quickData[top];
	int belowDataTop = top - 1; 	
	int aboveBottom = bottom + 1; 
	int temp; 
	do {
		do {
			comparisonCount++;
			aboveBottom--; 
		} while (dataTop > quickData[aboveBottom]);
		do {
			comparisonCount++;
			belowDataTop++; 
		} while (dataTop < quickData[belowDataTop]);
		if (belowDataTop < aboveBottom) {
			comparisonCount++;
			swapCount++;
			temp = quickData[belowDataTop];
			quickData[belowDataTop] = quickData[aboveBottom];
			quickData[aboveBottom] = temp; 
		}
	} while (belowDataTop < aboveBottom);
	return aboveBottom; 
}

unsigned long long int quickSort::getQuickSwapCount()
{
	return swapCount; 
}

unsigned long long int quickSort::getQuickComparisonCount()
{
	return comparisonCount; 
}

float quickSort::getAverageTime(float times[])
{
	float avgTime; 
	int index;

	for(index = 0; index < NUM_RUNS; index++){
		avgTime += times[index];
	}
	
	avgTime = avgTime/NUM_RUNS; 

	return avgTime; 
}