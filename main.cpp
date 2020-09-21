#include <iostream>
#include "QueueLL.h"
#include "StackLL.h"
using namespace std;

int main()
{
	cout << "STACKS TESTING\n\n\n";
	StackLL<int>* stack = new StackLL<int>;

	cout << stack->pop() << endl;
	cout << "BEFORE ADDING: Empty: " << std::boolalpha << stack->empty() << endl;

	for (int i = 0; i <= 10; i++) stack->push(i);
	stack->display(); //top should be 10;
	printf("\nTOP: %i\n\n", stack->top());
	for (int i = 10; i > 5; i--)	{
		stack->pop();
	}
	//top should be 5.
	cout << "AFTER ADDING: Empty: " << std::boolalpha << stack->empty() << endl;
	stack->display();
	printf("\nTOP: %i\n\n", stack->top());
	delete stack;



	cout << "QUEUES TESTING\n\n\n";
	QueueLL<int>* queue = new QueueLL<int>;
	cout << "\nEmpty: " << std::boolalpha << queue->empty() << endl;
	cout << "TESTING DEQUEUE BEFORE ADDING ELEMENTS: ";
	queue->dequeue();
	queue->enqueue(10);
	queue->enqueue(20); 
	queue->enqueue(30); 
	queue->enqueue(40); 
	queue->enqueue(50); 
	queue->enqueue(60); 
	queue->enqueue(70); 
	queue->display();
	
	cout << "FRONT: " << queue->front() << endl;
	queue->dequeue(); 
	cout << "DEQUEUE ELEMENT\n";
	cout << "FRONT: " << queue->front() << endl;
	queue->display();
	cout << "DEQUEUE ELEMENT\n";
	queue->dequeue(); 
	cout << "FRONT: " << queue->front() << endl;
	cout << "DEQUEUE ELEMENT\n";
	queue->dequeue();
	cout << "FRONT: " << queue->front() << endl;
	queue->display();

	cout << "\nEmpty: " << std::boolalpha << queue->empty() << endl;
	//Delete object
	delete queue;

	
	return 0;
}

