#ifndef HW3_TODO_QUEUELINKEDLIST
#define HW3_TODO_QUEUELINKEDLIST

#include <string>

struct TodoItem
{
	std::string todo;
};

class TodoQueueLinkedList
{
  public:
	TodoQueueLinkedList();
	bool isEmpty();
	bool isFull();
	void enqueue(std::string todoItem);
	void dequeue();
	TodoItem* peek();

	/* for grading purposes we need these following methods */
	TodoItem* getQueueFront() { return queueFront; }
	TodoItem* getQueueEnd()	  { return queueEnd; }

  private:
	TodoItem* queueFront;
	TodoItem* queueEnd;
};

#endif
