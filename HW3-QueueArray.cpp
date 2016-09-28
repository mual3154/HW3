#include<iostream>
#include<string>
#include "HW3-Todo-QueueArray.hpp"

using namespace std;

TodoQueueArray::TodoQueueArray(){
	queueFront = -1;
	queueEnd = -1;
}

bool TodoQueueArray::isEmpty(){
	if(queueFront == -1 && queueEnd == -1){
		return true;
	}
	else{
	return false;
	}
}

bool TodoQueueArray::isFull(){
	int size = 0;
	int start = queueFront;
	while(start != queueEnd){
		if(start >  MAX_QUEUE_SIZE){
			start = 0;
		}
		size++;
		start++;
	}
	
	if(size == MAX_QUEUE_SIZE){
		return true;
	}
	else{
		return false;
	}
}


void TodoQueueArray::enqueue(string todoItem){
	bool empty = isEmpty();
	bool full = isFull();
	TodoItem* tmp = new TodoItem;
	tmp->todo = todoItem;
	if(empty){
		queueFront = 0;
		queueEnd = 0;
		queue[0] = tmp;
	}
	else if(full){
		cout << "Queue full, cannot add new todo item" << endl;
	}
	else{
		if(queueEnd == 4){
			queueEnd = 0;
		}
		else{
			queueEnd++;
		}
		queue[queueEnd] = tmp;
		cout << "Queueing: " << tmp->todo << endl;
	}
	tmp = NULL;
	delete tmp;
}

void TodoQueueArray::dequeue(){
	bool empty=isEmpty();
	if(empty){
		cout << "Queue empty, cannot dequeue an item" << endl;
	}
	else if(queueFront == queueEnd){
		queueFront = queueEnd = -1;
		cout << "Queue empty, cannot dequeue an item" << endl;
	}
	else{
		int tmp = queueFront;
		queueFront++;
		queue[tmp] = NULL;
	}
}
	
TodoItem* TodoQueueArray::peek(){
	bool empty = isEmpty();
	if(!empty){
		return queue[queueFront];
	}
	else{
		cout << "Queue empty, cannot peek" << endl;
	}
}
