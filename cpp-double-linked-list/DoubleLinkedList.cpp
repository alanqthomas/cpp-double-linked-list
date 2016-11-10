#include "DoubleLinkedList.h"

	template <class DataType>
	ListNode<DataType>::ListNode() {
		dataType = NULL;
		pNext = NULL;
		pPrevious = NULL;
	}

	template <class DataType>
	ListNode<DataType>::ListNode(const DataType &newItem) {
		dataType = newItem;
	}

	template <class DataType>
	ListNode<DataType>* ListNode<DataType>::next() const {
		return pNext;
	}

	template <class DataType>
	ListNode<DataType>* ListNode<DataType>::previous() const {
		return pPrevious;
	}

	template <class DataType>
	const DataType& ListNode<DataType>::data() const {
		return &dataType;
	}

	template <class DataType>
	DataType& ListNode<DataType>::data() {
		return &dataType;
	}

	template <class DataType>
	void ListNode<DataType>::next(ListNode *nextNode) {
		pNext = nextNode;
	}

	template <class DataType>
	void ListNode<DataType>::previous(ListNode *previousNode) {
		pPrevious = previousNode;
	}

