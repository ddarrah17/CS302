#include <iostream> 
#include <fstream> 
using namespace std; 

const int MAX_CUSTOMERS = 100; 

class priQueue {
	public: 
		priQueue();
		~priQueue();
		bool isEmpty();
		bool isFull();
		bool add(int, int);
		bool remove();
		int peekArrival();
		int peekTransaction();
		int getQueueCount();
		void print();

	private: 
		int priQueueCount;
		int **priQueueData; 
};

class queue {
	public: 
		queue();
		~queue();
		bool isEmpty();
		bool isFull();
		bool enqueue(int, int);
		bool dequeue();
		int peekTime();
		int peekTransaction();
		void print();
		
	private:
		int count; 
		int front;  
		int **data;

};

class simulation {
	public: 
		simulation(int tellerCt);
		~simulation();
		void simulateOne();
		void simulateTwo();
		void simulateThree();
		void processArrival(int, int, priQueue&, queue&);
		void processDeparture(int, int, priQueue&, queue&);
		void createFile();
	private: 
		bool tellerAvailable; 
		int Ctime; 
		int tellerCount; 
		ofstream fout; 
		ifstream fin; 
};