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
		OrderedDoubleLinkedList();
		// destructor
		virtual ~OrderedDoubleLinkedList();
		// number of items in the list
		std::size_t size() const;
		// is the list empty (true) or does it have entries (false)
		bool empty() const;
		// print the items in the list
		void print() const;
		// display debug information on the passed in ostream
		void debug(std::ostream &out) const;
		// get first node in the list (or nullptr)
		ListNode<DataType>* first() const;
		// get last node in the list (or nullptr)
		ListNode<DataType>* last() const;
		// find the entry and return its address 
		// (nullptr if not found)
		ListNode<DataType>* find(const DataType &existingItem);
		// erase the item by DataType value
		bool erase(const DataType &currentItem);
		// insert the new item into the list (in sorted order)
		// a duplicate entry will be ignored
		void insert(const DataType &newItem);
};

// Your implementation code goes here

#endif /* ORDEREDDOUBLELINKEDLIST_H_ */
