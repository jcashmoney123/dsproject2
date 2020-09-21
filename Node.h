#pragma once

template<typename ElementType>
struct Node {
	Node() : data(nullptr){ } //default constructor, sets our data to null so the memory is preserved
	Node(Node<ElementType>&& other) { //uses "r-value reference" this allows us to transfer the data from a node without making a new copy of it as to use in the function
		data = other.data;
		next = other.next;
		other.data = nullptr;
	}
	Node(const ElementType& e) { data = new ElementType(e); } //same as default constructor but with an elementtype, sets data to what we want.
	~Node() { if (data) delete data; } //destructor. frees our memory. must not delete *next though or we will lose access to our linked list.
	ElementType* data; //element data
	Node* next = nullptr; //node* used to linked list.
};