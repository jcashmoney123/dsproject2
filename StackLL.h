#pragma once
#include <iostream>
#include "ListLinked.h"
#ifndef STACKLL
#define STACKLL

template<typename ElementType>
class StackLL
{
private:
	ListLinked<ElementType> list;
public:
	//StackV(); //this is not needed since our linked list takes care of itsself in terms of first/last elements.
    //~StackV(); //the nodes are delt with by the list's destructor. and the list is deleted after the program exits.

	bool empty() const { return list.empty(); } //returns if the list is empty.

	ElementType top() const { return *list.first->data; } //returns the last element of the list. since this is a stack, the last element added is the top.

	ElementType pop() { //removes the last element added to the list.
		if (list.empty()) { //if empty. throw error and return.
			std::cout << "Tried to pop empty list! ";
			return NULL; }
		ElementType temp = *list.first->data; //else we return the top data element. since this is a stack,
		list.shift();						  //the first element will be the element we want. 
		return temp;
	}

	void push(const ElementType& e) { list.prepend(e); } //pushes the newest element to the beginning of the stack.

	void display() const { //simple display function. 
		for (auto i = list.first; i != nullptr; i = i->next) {
			std::cout << *i->data << " ";
		}
		std::cout << "\n";
	}
};
#endif
