#include<iostream>
#include<string>
#include "HW3-Todo-StackLinkedList.hpp"

using namespace std;

TodoStackLinkedList::TodoStackLinkedList(){

}

bool TodoStackLinkedList::isEmpty(){
	if(stackHead == NULL){
		return true;
	}
	else{
	return false;
	}
}

void TodoStackLinkedList::push(string todoItem){
	bool empty = isEmpty();
	TodoItem* tmp = new TodoItem;
	tmp->todo = todoItem;
	tmp->next = NULL;
	if(empty)
	{
		stackHead = tmp;
	}
	else{
		cout << "Pushing: " << tmp->todo << endl;
		tmp->next = stackHead;
		stackHead = tmp;
	}
	tmp = NULL;
	delete tmp;
}

void TodoStackLinkedList::pop(){
	bool empty = isEmpty();
	if(!empty){
	TodoItem* tmp;
	tmp = stackHead;
	stackHead = tmp->next;
	cout << "popping: " << tmp->todo <<endl;
	delete tmp;
	}
	else{
	cout << "Stack empty, cannot pop an item" << endl;
	}
}

TodoItem* TodoStackLinkedList::peek(){
	bool empty = isEmpty();
	if(empty)
	{
		cout << "Stack empty, cannot peek" << endl;
	}
	else
	{	
		return stackHead;
	}
}

