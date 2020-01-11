void partition(int pivot, int *arrayPointer, int sizeOfArray);

void partition(int pivot, int *arrayPointer, int sizeOfArray)
{
    int tempArray[sizeOfArray]; 
    int *pointerHome; 
    pointerHome = arrayPointer; 
    int count = 0; 
    int loop; 
    int lowCount = 0; 
    

    cout << endl; 
    for(loop = 0; loop < sizeOfArray; loop++){
        if(pivot < *arrayPointer){
            count++; 
        }
        arrayPointer++; 
    }
    cout << endl; 

    cout << "YOUR PIVOT IS: " << pivot << endl; 
    cout << "SO The AMOUNT of numbers higher than your pivot is: " << count << endl;
    arrayPointer = pointerHome; 

    tempArray[(sizeOfArray - count)-1] = pivot; 

    //This is declared here to make sure the highcount is initialized to the count. 
    int highCount = sizeOfArray - count; 

    for(loop = 0; loop < sizeOfArray; loop++){
    if(*arrayPointer < pivot){
        tempArray[lowCount] = *arrayPointer; 
       // cout << "LOW COUNT: " << *arrayPointer << endl; 
        lowCount++; 
    }
    else if (*arrayPointer > pivot){
        tempArray[highCount] = *arrayPointer;
       // cout << "HIGH COUNT: " << *arrayPointer << endl;  
        highCount++; 
    }
    else if(*arrayPointer == pivot){
        tempArray[count] = *arrayPointer;
       // cout << "THE TEMPARRAY HAS STORED AS THE SAME AS PIVOT!" << endl; 
    }
    arrayPointer++; 
    }

    arrayPointer = pointerHome; 

    for(loop = 0; loop < sizeOfArray; loop++){
        *arrayPointer = tempArray[loop]; 
        arrayPointer++; 
    }

}
