/*
 * OrderedDoubleLinkedList.h
 *
 * Store the DataType values in sorted order. This ordering
 * is determined by the comparison operators of the DataType
 * class.
 *
 */

#ifndef ORDEREDDOUBLELINKEDLIST_H_
#define ORDEREDDOUBLELINKEDLIST_H_

#include <cstddef>
#include "DoubleLinkedList.h"

template<class DataType>
class OrderedDoubleLinkedList
{
	private:
		// we are making use of the DoubleLinkedList class
		DoubleLinkedList<DataType> list;
	public:
		// default constructor
		OrderedDoubleLinkedList() { }

		// destructor
		virtual ~OrderedDoubleLinkedList() {
			std::cout << "DoubleLinkedList destructor called.\n";
		}

		// number of items in the list
		std::size_t size() const {
			return list.size();
		}

		// is the list empty (true) or does it have entries (false)
		bool empty() const {
			return list.empty();
		}

		// print the items in the list
		void print() const {
			list.print();
		}

		// print debug information to the ostream argument
		void debug(std::ostream &out) const {
			list.debug(out);
		}

		// get first node in the list (or nullptr)
		ListNode<DataType>* first() const {
			return list.first();
		}

		// get last node in the list (or nullptr)
		ListNode<DataType>* last() const {
			return list.last();
		}

		// find the entry and return its address 
		// (nullptr if not found)
		ListNode<DataType>* find(const DataType &existingItem) {
			return list.find(existingItem);
		}

		// erase the item by DataType value
		bool erase(const DataType &currentItem) {
			return list.erase(currentItem);
		}

		void insert(const DataType &newItem);
};

// insert the new item into the list (in sorted order)
// a duplicate entry will be ignored
template<class DataType>
void OrderedDoubleLinkedList<DataType>::insert(const DataType &newItem) {
	// Check if the item already exists in the list
	ListNode<DataType>* foundItem = list.find(newItem);
	if (foundItem != NULL) {
		std::cout << "Item " << newItem << " already exists. Not inserted.\n";
		return;
	}

	// List is empty
	if (list.empty()) {
		list.push_front(newItem);
		std::cout << "List was empty. Inserted node.\n";
		return;
	}

	ListNode<DataType>* cursor = list.first();
	ListNode<DataType>* cursorN = cursor;

	if (newItem < cursor->data()) {
		list.push_front(newItem);
		std::cout << "Node was less than first node.\n";
		return;
	}

	// Iterate list to find where this node will be in order
	while (cursor != NULL) {
		cursorN = cursor->next();

		// Currently on the last node
		if (cursorN == NULL) {
			list.push_back(newItem);
			std::cout << "Node was higher than all nodes in list.\n";
			return;
		}

		// New item is greater than current node, less than next node
		if (cursor->data() < newItem && newItem < cursorN->data()) {
			std::cout << "Placing node after " << cursor->data() << " and before " << cursorN->data() << ".\n";
			list.insert_after(cursor, newItem);
			return;
		}

		cursor = cursor->next();
	}

	// If the method reached this point, something terrible went wrong
}

#endif /* ORDEREDDOUBLELINKEDLIST_H_ */
