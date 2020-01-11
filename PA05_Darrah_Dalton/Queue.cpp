#include "Queue.h"
#include <iostream> 
#include <fstream> 

priQueue::priQueue()
{
	int increment; 
	priQueueCount = 0; 
	priQueueData = new int*[MAX_CUSTOMERS+1];
	for(increment = 0; increment < MAX_CUSTOMERS+1; increment++){
		priQueueData[increment] = new int[2]; 
	}
	
}
		
priQueue::~priQueue()
{
	delete [] priQueueData;
}

bool priQueue::isEmpty()
{
	if(priQueueCount == 1){
		return 1; 
	}
	else 
	return 0; 
}

bool priQueue::isFull()
{
	if(priQueueCount == (MAX_CUSTOMERS * 2)+2){
		return 1; 
	}
	else
	return 0; 
}
		
bool priQueue::add(int arrivalTime, int transactionTime)
{
	int increment = 0; 
	if(isFull()){
		return 0; 
	}
	if(priQueueCount == -1){
		priQueueCount++; 
		priQueueData[priQueueCount][0] = arrivalTime; 
		priQueueData[priQueueCount][1] = transactionTime;
		return 1; 
	}
	else 
		for(increment = priQueueCount - 1; increment >= 0; increment--){
			if(arrivalTime > priQueueData[increment][0]){
				priQueueData[increment+1][0] = priQueueData[increment][0];
				priQueueData[increment+1][1] = priQueueData[increment][1];
			}
			else {
				break; 
			}
		}
			priQueueData[increment+1][0] = arrivalTime; 
			priQueueData[increment+1][1] = transactionTime; 
			priQueueCount++; 
		return 1; 
}
		
bool priQueue::remove()
{
	if(!isEmpty()){
		priQueueCount--; 
		//cout << "Count: " << priQueueCount << endl; 
		//cout << "Item Removed: " << priQueueData[priQueueCount][0] << '\t' << priQueueData[priQueueCount][1] << endl; 
		priQueueData[priQueueCount][0] = -1;
		priQueueData[priQueueCount][1] = -1;  
		return 1; 
	}
	else
	return 0; 
}
		
int priQueue::peekArrival()
{
	if(!isEmpty()){
		return priQueueData[priQueueCount-1][0];
	}
	else
	return -1; 
}

int priQueue::peekTransaction()
{
	if(!isEmpty()){
		return priQueueData[priQueueCount-1][1];
	}
	else
	return -1; 
}

int priQueue::getQueueCount()
{
	return priQueueCount; 
}

void priQueue::print()
{
	int increment; 
	for(increment = 1; increment < priQueueCount; increment++){
		cout << increment << ". " << priQueueData[increment][0] << '\t' <<  priQueueData[increment][1] << endl; 
	} 
}


queue::queue()
{
	int increment; 

	front = -1;
    count = 0; 
       
	data = new int*[MAX_CUSTOMERS];
	for(increment = 0; increment < MAX_CUSTOMERS; increment++){
		data[increment] = new int[2]; 
	}
	
}
		
queue::~queue()
{
	front = -1; 
	count = 0; 
	delete [] data; 
}

bool queue::isEmpty()
{
	if(front == -1){
		return true; 
	}
	else
        return false; 
}

bool queue::isFull()
{
	if(count == MAX_CUSTOMERS){
		return true; 
	}
	else 
        return false; 
}
		
bool queue::enqueue(int time, int transaction)
{
	if(isEmpty() == true){
		front = 0; 
		data[front][0] = time;
		data[front][1] = transaction; 
		count++;
		return true; 
	}
	else {
		count++;
		data[count][0] = time;
		data[count][1] = transaction;   
		return true;
	}
        return false; 
}
		
bool queue::dequeue()
{
	if (isEmpty() == true){
		return false; 
	}
	else
		data[front][0] = 0; //Front needs to come off
		data[front][1] = 0; 
		front++;
		count--;
        return true;
}
		
int queue::peekTime()
{
	if(!isEmpty()){
		return data[front][0]; 
	}
	else
	return -1; 
}

int queue::peekTransaction()
{
	if(!isEmpty()){
		return data[front][1];
	}
	else 
	return -1; 
}

void queue::print()
{
	int increment; 

	for(increment = 0; increment < count; increment++){
		cout << data[increment] << endl; 
	} 
}

simulation::simulation(int tellerCt)
{
	tellerCount = tellerCt;
	Ctime = -1; 
	tellerAvailable = true; 
}

simulation::~simulation()
{
	tellerCount = -1; 
	Ctime = -1; 
}

void simulation::simulateOne()
{	
	int arrivalTime, transactionTime, newTime, newTransaction;
	int maxWait = 0, lineLength = 0, maxLength = 0;
	float currentTime; 
	priQueue Alpha;
	queue Beta; 

	fin.clear();
	fin.open("data.txt");
	for(int i = 0; i < MAX_CUSTOMERS + 1; i++){
		fin >> arrivalTime; 
		//cout << "Arrival: " << arrivalTime << endl; 
		fin >> transactionTime; 
		//cout << "Transaction: " << transactionTime << endl;
		Alpha.add(arrivalTime, transactionTime);
	}

	Alpha.print();
	
	while(!(Alpha.isEmpty())){

		newTime = Alpha.peekArrival();
		newTransaction = Alpha.peekTransaction();
		
		Ctime = newTime;
		if(newTransaction > 0){
			processArrival(newTime, newTransaction, Alpha, Beta);
		}
		else{
			processDeparture(newTime, newTransaction, Alpha, Beta);
		}
	}
	fin.close();
	float sum = (Ctime/MAX_CUSTOMERS);
	cout << "Final Statistics: " << endl; 
	cout << "Total number of people processed: " << MAX_CUSTOMERS << endl; 
	cout << "Average amount of time spent waiting: " << sum << endl; 
	cout << "Maximum wait time: " << maxWait << endl; 
	cout << "Average length of line: " << lineLength << endl; 
	cout << "Maximum length of the line: " << maxLength << endl; 
}

void simulation::simulateTwo()
{
	tellerAvailable = true; 
	Ctime = 0; 

	int arrivalTime, transactionTime, newTime, newTransaction;
	float currentTime; 
	priQueue Alpha;
	queue Beta; 

	fin.clear();
	fin.open("test.txt");
	for(int i = 0; i < MAX_CUSTOMERS + 1; i++){
		fin >> arrivalTime; 
		//cout << "Arrival: " << arrivalTime << endl; 
		fin >> transactionTime; 
		//cout << "Transaction: " << transactionTime << endl;
		Alpha.add(arrivalTime, transactionTime);
	}

	Alpha.print();
	
	while(!(Alpha.isEmpty())){

		newTime = Alpha.peekArrival();
		newTransaction = Alpha.peekTransaction();
		
		Ctime = newTime;
		if(newTransaction > 0){
			processArrival(newTime, newTransaction, Alpha, Beta);
		}
		else{
			processDeparture(newTime, newTransaction, Alpha, Beta);
		}
	}
	fin.close();
	float sum = (Ctime/MAX_CUSTOMERS);
	cout << "Final Statistics: " << endl; 
	cout << "Total number of people processed: " << MAX_CUSTOMERS << endl; 
	cout << "Average amount of time spent waiting: " << sum << endl << endl << endl; 
}

void simulation::simulateThree()
{
	//The way that I would do this, is that I would have used a teller count
	//in this way, if the count was above 0, I would easily be able to check 
	//whether or not the line could advance. 
}

void simulation::processArrival(int time, int transaction, priQueue &event, queue &line)
{
	int customer; 
	int departureTime; 
	int newDepartureTime;
	int newDepartureTransaction;

	event.remove();

	newDepartureTime = time; 
	newDepartureTransaction = transaction; 

	if((line.isEmpty()) && tellerAvailable == true){
		departureTime = time + transaction;
		event.add(departureTime, 0);
		tellerAvailable = false; 
		cout << "Processed an Arrival Event at time " << time << endl;
	}
	else {
		line.enqueue(newDepartureTime, newDepartureTransaction);
		cout << "Processed an Arrival Event at time " << time << endl;
	}
}

void simulation::processDeparture(int time, int transaction, priQueue &event, queue &line)
{
	int customer; 
	int departureTime; 
	int newTransaction; 
	
	event.remove();
	
	if(transaction == 0){
		cout << "Processed a Departure Event at time " << time << endl; 
	}
	if(line.isEmpty() == false){
		customer = line.peekTransaction();
		line.dequeue();
		departureTime = Ctime + customer; 
		event.add(departureTime, 1);
		cout << "Processed a Departure Event at time " << departureTime << endl;
	}
	else {
		tellerAvailable = true; 
	}
}

void simulation::createFile()
{
	fout.clear();
	fout.open("data.txt");
	srand((unsigned) time(0));
	for(int i =0; i < 100; i++){
	fout << (rand() % 539)+1 << '\t' << (rand() % 19)+1 << endl;
	}
	cout << "File created." << endl; 
}
