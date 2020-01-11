//  Created by Shehryar Khattak for CS302 Spring 2016 class.
#include <iostream>
#include <fstream>

using namespace std;

//This is a simple swap array that is in place to basically switch two elements in an array of integers.
//This is a key factor in how we sort, or 'partition' our array.
void swap(int array[], int a, int b);

//This function is our kSmall, which will be recursively called until the smallest value is found.
int kSmall(int k, int data[], int first, int last, int sizeOfArray, ofstream &out);

//Out main function
int main()
{

    //Declerations (insert as needed)
    int kSmall_pos;	        //For User Input
    int kSmall_val = 0;     //Populate using your algorithm implementation
    int pivot;              //Pivot position in array
    int *arrayPtr;          //Pointer to our array with data
    int *PointerHome;       //Home pointer
    int temp;               //This int is in place to take in "garbage" values while we count the number of items in the array
    int first;              //First location in the array
    int last;               //Last location in the array
    int wordCount = 0;      //This is our counter for the number of integers in the array
    int loop;               //Our for loop incrementer
    ifstream fin;           //File read in
    ofstream out;           //File output variable
    char fileName[50];     //File name that the user inputs

    //User Input DO NOT MODIFY
    cout<<"Please enter required kth smallest value:";
    cin>>kSmall_pos;

    //File Read code (insert) - This code should be able to parse the data in a text file similar to the provided one and store values in an array for processing.
    cout << "Enter the file you wish to open: " ;
    cin >> fileName;

    fin.clear();
    fin.open(fileName);

    //While loop takes in the data in the array into a "Garbage" array, and we count how many items are presently in the file.
    while(!fin.eof()){
        fin >> temp;
        wordCount++;
    }

    if(kSmall_pos > 0 && kSmall_pos <= wordCount){

    cout << "Size of the array you entered is : " << wordCount << endl;
    int arrayTemp[wordCount];      //Temp array for pass in

    //We close the file to reset the cursor back to the top of the .txt file
    fin.close();

    //We then clear and open the same file again, starting from the top, now knowing the amount of items into the folder.
    fin.clear();
    fin.open(fileName);

    arrayPtr = new int [wordCount];
    PointerHome = arrayPtr;

    for(loop = 0; loop < wordCount; loop++){
        fin >> *arrayPtr;
        arrayPtr++;
    }
    arrayPtr = PointerHome;

    pivot = *arrayPtr;

    for(loop = 0; loop < wordCount; loop++){
        arrayTemp[loop] = *arrayPtr;
        arrayPtr++;
    }
    arrayPtr = PointerHome;

    first = 0;
    last = wordCount - 1;
    //kmsall algorithm implementation or function call (insert) - implement using recursion as indicated

    //We call our fstream output here because we're going to output our data while our kSmall_val runs
    out.clear();
    out.open("log.txt");
    kSmall_val = kSmall(kSmall_pos, arrayTemp, first, last, wordCount, out);
    out.close();

    //Output DO NOT MODIFY
    cout<<"kth smallest value = "<<kSmall_val<<endl;
    }
    else {
        cout << "The value that you have entered is not valid. (Out of array bounds) Please re-try. " << endl;
    }
    return 0;
}

int kSmall(int k, int array[], int first, int last, int sizeOfArray, ofstream &out)
{
    //We initialize our variables to these as they will be continously changing as the recursion will run non-stop
    int pivotIndex = first;
    int leftCount = first;
    int rightCount = last;
    int loop = 0;
    int filePivot = 0;

    filePivot = array[0];

    //We output into our file everytime the function is called
    //This way we can see what is happening to the array every single time it's modified
    out << "*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/" << endl;
    out << "K is : " << k << endl << endl;
    out << "Pivot is : " << filePivot << endl << endl;
    out << "Array is : " << endl;
    for(loop = 0; loop < sizeOfArray; loop++){
        out << array[loop] << " ";
    }
    out << endl << endl;

    //These are our increment conditions for our return. They check the array to see whether they need to move to the left or right
    while (leftCount <= rightCount){
        while (leftCount <= rightCount && array[leftCount] <= array[pivotIndex]){
            leftCount++;
        }
        while (leftCount <= rightCount && array[rightCount] >= array[pivotIndex]){
            rightCount--;
        }
        if(leftCount < rightCount){
             swap(array, leftCount, rightCount);
        }
    }
    swap(array, pivotIndex, rightCount);
    //These if statements are our "End conditions," such that, this is what determines if we stop, or keep going.
    if(k == rightCount + 1){
         return array[rightCount];
    }
    else if(k > rightCount + 1){
        return kSmall(k, array, rightCount + 1, last, sizeOfArray, out);
    }
    else
        return kSmall(k, array, first, rightCount - 1, sizeOfArray, out);
}

void swap(int array[], int a, int b){

    int temp; //Variable to store our data temporarily, and then move it to the desired destination.
    temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}
