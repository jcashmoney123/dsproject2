#pragma once
#include <iostream>
#include "Node.h"
#ifndef LISTLINKED
#define LISTLINKED

template<typename ElementType>
class ListLinked
{
public:
	Node<ElementType>* first = nullptr, * last = nullptr; //our first/last members of the list. very important! they are public so we don't need getters/setters
	void prepend(const ElementType& obj) { //prepend - add to beginning
		auto newNode = new Node<ElementType>(obj); //uses our r-value reference to make a new node
		newNode->next = first; // this is adding to beginning so we set the next of this to be the first.
		first = newNode; // and the first of the list to be our new node.
		if (!last) last = newNode->next; //null check for our "last" member. prevents potential crashing later
	}

	void append(const ElementType& obj) { //append - add to end
		if (empty()) { //null check. if list is new, create the first node. 
		first = new Node<ElementType>(obj); 
		last = first; //very important!!
		return;
		}
		auto newNode = new Node<ElementType>(obj); //else we whip it and since we are adding to end. we create new member and set last to it.
		last->next = newNode;
		last = newNode;
	}

	~ListLinked() {	
		while (!empty()) { //this is pretty cool. using our other functions. we shift our list until it's empty.
			shift();
		}
	}

	bool empty() const { //checks if first is null. if so, then it's empty.
		if (!first) return true;
		return false;
	}


	void shift() { //shifts our list from the beginning. 
		if (empty()) { //checks if list is empty. 
			std::cout << "Tried to shift empty list\n";
			return; 
		}
		auto temp = first; //else we whip it and shift the first element to the next element in like. A-B-C = B-C
		first = first->next;
		delete temp; //frees memory from our old first, "A" in this case. 
	}

};


#endif
