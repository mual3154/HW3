#include<iostream>
#include<string>
#include "HW3-Todo-QueueArray.hpp"

using namespace std;

int main(){
	cout << "main started" << endl;
	TodoQueueArray m; 
	cout << "class made" << endl;
	m.dequeue();
	string xx = "haha";
	m.enqueue(xx);
	m.enqueue("Clean the dishes");
	m.enqueue("make bed");
	m.enqueue("Do laundry");
	m.enqueue("buy detergent");
	m.enqueue("take a shit");
	m.enqueue("Scotty");
	m.dequeue();
	m.dequeue();
	m.dequeue();
	TodoItem* theitem = m.peek();
	cout << theitem->todo <<endl;
	
	

}
