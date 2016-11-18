#ifndef STACK_H_
#define STACK_H_

#include <iostream>
#include <string>
#include "DoubleLinkedList.h"

template<class DataType>
class Stack {

	private:
		DoubleLinkedList<DataType> list;

	public:

		Stack() { }
		
		~Stack() {
			std::cout << "Stack destructor called.\n";
		}

		bool empty() const {
			return list.empty();
		}

		std::size_t size() const {
			return list.size();
		}

		DataType& top() {
			DataType& value = list.last()->data();
			return value;
		}

		const DataType& top() const {
			const DataType& value = list.last()->data();
			return value;
		}

		void push(const DataType& value) {
			list.push_back(value);
		}

		void pop() {
			list.pop_back();
		}

		void print() {
			list.print();
		}
};

#endif /* STACK_H_*/
