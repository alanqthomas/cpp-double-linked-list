#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include <string>
#include "DoubleLinkedList.h"

template<class DataType>
class Queue {
	
	// Use a DoubleLinkedList to implement Queue
	private:
		DoubleLinkedList<DataType> list;

public:
	// Default constructor
	Queue() { }

	// Destructor
	~Queue() {
		std::cout << "Queue destructor called. \n";
	}

	// Return whether the queue is empty or not
	bool empty() const {
		return list.empty();
	}

	// Returns the size of the queue
	std::size_t size() const {
		return list.size();
	}

	// Returns the front item in the queue
	DataType& front() {
		DataType& value = list.first()->data();
		return value;
	}

	// Returns the front item in the queue
	const DataType& front() const {
		const DataType& value = list.first()->data();
		return value;
	}

	// Returns the back item in the queue
	DataType& back() {
		DataType& value = list.last()->data();
		return value;
	}

	// Returns the back item in the queue
	const DataType& back() const {
		const DataType& value = list.last()->data();
		return value;
	}

	// Adds the item to the back of the queue
	void push(const DataType& value) {
		list.push_back(value);
	}

	// Removes the front item in the queue
	void pop() {
		list.pop_front();
	}

	// Prints a representation of the queuue
	void print() {
		list.print();
	}
};

#endif /* QUEUE_H_ */
