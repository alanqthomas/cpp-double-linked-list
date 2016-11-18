#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include <string>
#include "DoubleLinkedList.h"

template<class DataType>
class Queue {
	
	private:
		DoubleLinkedList<DataType> list;

public:
	Queue() { }

	~Queue() {
		std::cout << "Queue destructor called. \n";
	}

	bool empty() const {
		return list.empty();
	}

	std::size_t size() const {
		return list.size();
	}

	DataType& front() {
		DataType& value = list.first()->data();
		return value;
	}

	const DataType& front() const {
		const DataType& value = list.first()->data();
		return value;
	}

	DataType& back() {
		DataType& value = list.last()->data();
		return value;
	}

	const DataType& back() const {
		const DataType& value = list.last()->data();
		return value;
	}

	void push(const DataType& value) {
		list.push_back(value);
	}

	void pop() {
		list.pop_front();
	}

	void print() {
		list.print();
	}
};

#endif /* QUEUE_H_ */
