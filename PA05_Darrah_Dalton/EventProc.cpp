void simulation::processArrival(int time, int transaction, priQueue &event, queue &line)
{
	int customer; 
	int depatureTime; 
	int newDepartureTime;
	int newDepartureTransaction;

	event.remove();
	customer = transaction; 
	if((line.isEmpty()) && tellerAvailable == true){
		depatureTime = currentTime + transaction; 
		newDepartureTime = depatureTime;
		newDepartureTransaction = 0; 
		event.add(newDepartureTime, newDepartureTransaction);
		tellerAvailable = false; 
		line.increment();
		cout << "Processed an Arrival Event at time " << time << endl;
	}
	else {
		line.enqueue(customer);
		line.increment();
		cout << "Processed an Arrival Event at time " << time << endl;
	}	
}

void simulation::processDeparture(int time, int transaction, priQueue &event, queue &line)
{
	int customer; 
	int depatureTime; 
	int newDepartureTime;
	int newDepartureTransaction;

	event.remove();
		
	if(!line.isEmpty()){
		customer = line.peek();
		cout <<"Customer Dequeue: " << customer << endl; 
		line.dequeue();
		depatureTime = currentTime + customer; 
		newDepartureTime = depatureTime;
		newDepartureTransaction = 0; 
		event.add(newDepartureTime, newDepartureTransaction);
		cout << "Processed a Departure Event at time " << depatureTime << endl;
	}
	else {
		tellerAvailable = true; 
	}
}
