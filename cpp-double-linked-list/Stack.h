#ifndef STACK_H_
#define STACK_H_

#include <iostream>
#include <string>
#include "DoubleLinkedList.h"

template<class DataType>
class Stack {

	// Use a DoubleLinkedList to implement Stack
	private:
		DoubleLinkedList<DataType> list;

	public:
		// Default constructor
		Stack() { }
		
		// Destructor
		~Stack() {
			std::cout << "Stack destructor called.\n";
		}

		// Return whether the stack is empty or not
		bool empty() const {
			return list.empty();
		}

		// Returns the size of the stack
		std::size_t size() const {
			return list.size();
		}

		// Returns the top item in the stack
		DataType& top() {
			DataType& value = list.last()->data();
			return value;
		}

		// Returns the top item in the stack
		const DataType& top() const {
			const DataType& value = list.last()->data();
			return value;
		}

		// Pushes an item to the top of the stack
		void push(const DataType& value) {
			list.push_back(value);
		}

		// Removes the top item in the stack
		void pop() {
			list.pop_back();
		}

		// Prints a representation of the stack
		void print() {
			list.print();
		}
};

#endif /* STACK_H_*/
