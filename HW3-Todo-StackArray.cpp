#include<iostream>
#include<string>
#include "HW3-Todo-StackArray.hpp"

using namespace std;

bool TodoStackArray::isEmpty(){
	if(stackTop == 0){
		return true;
	}
	return false;
}

bool TodoStackArray::isFull(){
	if(stackTop == 5){
		return true;
	}
	return false;
}

void TodoStackArray::push(string todoItem){
	bool full = isFull();
	bool empty = isEmpty();
	TodoItem * thenewone = new TodoItem;
	thenewone->todo = todoItem;
	if(full == true){
		cout << "Stack full, cannot add new todo item" << endl;
	}
	else if(empty == true){
		cout << "pushing: " << thenewone->todo<<endl;
		stack[stackTop] = thenewone;
		stackTop = stackTop+1;
		
	}
	else{
		stackTop = stackTop + 1;
		cout << "pushing: " << thenewone->todo << endl;
		stack[stackTop] = thenewone;
	}
}

void TodoStackArray::pop(){
	bool empty = isEmpty();
	if(empty == true){
		cout << "Stack empty, cannot pop an item" << endl;
	}
	else{
		cout << "popping: " << stack[stackTop]->todo << endl;
		stackTop = stackTop -1;
	}

}

TodoItem* TodoStackArray::peek(){
	bool empty = isEmpty();
	if(empty == false){
		return stack[stackTop];
	}
	else{
		cout<<"Stack empty, cannot peek." <<endl;
	}
	return NULL;
}

TodoStackArray::TodoStackArray(){
	stackTop = 0;
		
}

