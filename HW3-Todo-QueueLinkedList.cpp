#include<iostream>
#include "HW3-Todo-QueueLinkedList.hpp"

using namespace std;

TodoQueueLinkedList::TodoQueueLinkedList(){

}

bool TodoQueueLinkedList::isEmpty(){
	if(queueFront == NULL){
		return true;
	}
	return false;
}

void TodoQueueLinkedList::enqueue(string todoItem){
	bool empty = isEmpty();
	TodoItem *tmp = new TodoItem;
	tmp->todo = todoItem;
	tmp->next = NULL;
	cout << "Queueing: " << tmp->todo << endl;
	if(empty){
		queueFront = tmp;
		queueEnd = tmp;
	}
	else{
		queueEnd->next = tmp;
		queueEnd = tmp;
	}
	tmp = NULL;
	delete tmp;
}

void TodoQueueLinkedList::dequeue(){
	TodoItem* tmp;
	if(!isEmpty()){
	tmp = queueFront;
	queueFront = queueFront->next;
	cout << "Dequeueing: " << tmp->todo << endl;
	delete tmp;
	}
	else{
		cout << "Queue empty, cannot dequeue" << endl;
	}
}

TodoItem* TodoQueueLinkedList::peek(){
	if(isEmpty()){
		cout << "Queue empty, cannot peek" << endl;
	}
	else{
		return queueFront;
	}
}
