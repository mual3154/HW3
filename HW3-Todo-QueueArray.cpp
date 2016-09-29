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
		if(start >=  4){
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
	cout << "Queueing: " << tmp->todo << endl;
	if(empty){
		queueFront = 0;
		queueEnd = 0;
		queue[0] = tmp;
	}
	else if(queueFront == queueEnd+1 || queueFront == 0 && queueEnd == 4){
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
	}
	tmp = NULL;
	delete tmp;
}

void TodoQueueArray::dequeue(){
	bool empty=isEmpty();
	if(empty){
		cout << "Queue empty, cannot dequeue an item" << endl;
	}
	else if(queueEnd == queueFront)
	{
		int tmp = queueFront;
		cout << "dequeueing: " << queue[tmp]->todo << endl;
		queueFront = -1;
		queueEnd=-1;
	}
	else{
		int tmp = queueFront;
		cout << "dequeueing: " << queue[tmp]->todo << endl;
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
