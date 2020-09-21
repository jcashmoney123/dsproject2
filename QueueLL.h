#pragma once
#include <iostream>
#include "ListLinked.h"
#include "Node.h"
#ifndef QUEUELL
#define QUEUELL

template<typename ElementType> //allows unique data types
class QueueLL
{
private:
	ListLinked<ElementType> list; 
public:
	//QueueV(); //this is not needed since our linked list takes care of itsself in terms of first/last elements.
 	//~QueueV() { } //the nodes are delt with by the list's destructor. and the list is deleted after the program exits.
	bool empty() const { return list.empty(); } //returns if our list is empty

	void enqueue(const ElementType& e) { list.append(e); }

	void dequeue() { list.shift(); } 

	ElementType front() const { return *list.first->data; }

	void display() const { 
		for (auto i = list.first; i != nullptr; i = i->next) {
			std::cout << *i->data << " ";
		}
		std::cout << "\n";
	}
};
#endif

