/*
 * BaseDoubleLinkedList.h
 *
 * Implementation of a double linked list.
 *
 * We have the ability to get the first and last entries and navigate
 * through the entries in the linked list.
 *
 * There are actually two classes here:
 *
 * ListNode<DataType>
 *
 * and
 *
 * DoubleLinkedList<DataType>
 *
 */

#ifndef DOUBLELINKEDLIST_H_
#define DOUBLELINKEDLIST_H_

#include <iostream>
#include <iomanip>
#include <cstddef>

// forward declaration of the template class DoubleLinkedList
template<class DataType>
class DoubleLinkedList;

// ListNode class
template<class DataType>
class ListNode
{
	// make DoubleLinkedList<DataType> a friend class
	friend class DoubleLinkedList<DataType>;
	private:
		// contains the actual data
		DataType dataType;
		// pointer to the next item in the list or nullptr 
		// if at the end
		ListNode<DataType>* pNext;
		// pointer to the previous item in the list or nullptr 
		// if at the start
		ListNode<DataType>* pPrevious;

	public:
		// default constructor
		ListNode() {}

		// copy constructor
		ListNode(const DataType &newItem) {
			dataType = newItem;
		}
		// get the next node
		ListNode* next() const {
			return pNext;
		}
		// get the previous node
		ListNode* previous() const {
			return pPrevious;
		}
		// return the data stored in the node as a const
		const DataType& data() const {
			return dataType;
		}
		// return the data stored in the node
		DataType& data() {
			return dataType;
		}

	private:
		// update the next node
		void next(ListNode *nextNode){ 
			pNext = nextNode; 
		}
		// update the previous node
		void previous(ListNode *previousNode) {
			pPrevious = previousNode;
		}
};

// DoubleLinkedList class
template<class DataType>
class DoubleLinkedList
{
	private:
		// number of nodes in the list. Note that std::size_t
		// is defined in header file cstddef.
		std::size_t numberNodes;

		// point to the first node or nullptr for empty list
		ListNode<DataType>* firstNode;

		// point to the last node or nullptr for empty list
		ListNode<DataType>* lastNode;

	public:
		// default constructor
		DoubleLinkedList() { }

		// copy constructor
		DoubleLinkedList(const DoubleLinkedList &other) {
			numberNodes = other.numberNodes;
			firstNode = other.firstNode;
			lastNode = other.lastNode;
		}

		// destructor
		virtual ~DoubleLinkedList() {
			std::cout << "Base destructor for DoubleLinkedList called\n";
		}

		// return the number of nodes in the list
		std::size_t size() const {
			return numberNodes;
		}

		// return true if the list is empty
		bool empty() const {
			return numberNodes < 1 ? true : else;
		}

		// display the contents of the list to std::cout
		void print() const {
			ListNode<DataType>* cursor;
			cursor = firstNode;
						
			std::cout << "(head)";

			if (cursor == NULL) {
				std::cout << "EMPTY";
			} else {
				while (cursor != NULL) {
					std::cout << cursor->data();
					cursor = cursor->next();
					if (cursor == NULL)
						std::cout << "(tail)\n";
					else
						std::cout << " - ";
				}
			}
		}

		// dump the contends in debug format to passed in 
		// ostream - usage to cout would be:
		//   list.debug(std::cout);
		void debug(std::ostream &out) const;

		// first node in the list (or nullptr for empty)
		virtual ListNode<DataType>* first() const {
			return firstNode;
		}

		// last node in the list (or nullptr for empty)
		virtual ListNode<DataType>* last() const {
			return lastNode;
		}

		// add an item to the front of the list
		virtual void push_front(const DataType &newItem) {
			ListNode<int>* node = new ListNode<int>(newItem);
			
			if (firstNode == NULL) {
				firstNode = node;
				lastNode = node;
			} else {
				firstNode->previous(node);
				node->next(firstNode);
				firstNode = node;
			}
			std::cout << "Pushed " << node->data() << " to the front.\n";
		}

		// add an item to the back of the list
		virtual void push_back(const DataType &newItem) {
			ListNode<int>* node = new ListNode<int>(newItem);

			if (firstNode == NULL) {
				firstNode = node;
				lastNode = node;
			}
			else {
				node->previous(lastNode);
				lastNode->next(node);
				lastNode = node;
			}

			std::cout << "Pushed " << node->data() << " to the back.\n";
		}

		// remove an item from the front of the list
		virtual void pop_front() {
			if (firstNode == lastNode) {
				firstNode = NULL;
				lastNode = NULL;
				std::cout << "Removed the last node in the list.\n";
				return;
			}

			if (firstNode == NULL) {
				std::cout << "The list is empty. No noes were removed.\n";
				return;
			}

			std::cout << "Popping off first element: " << firstNode->data() << ".\n";
			firstNode = firstNode->next();	
			firstNode->previous(NULL);
		}

		// remove an item from the back of the list
		virtual void pop_back() {
			if (firstNode == lastNode) {
				firstNode = NULL;
				lastNode = NULL;
				std::cout << "Removed the last node in the list.\n";
				return;
			}

			if (firstNode == NULL) {				
				std::cout << "The list is empty. No noes were removed.\n";
				return;
			}

			std::cout << "Popping off last element: " << lastNode->data() << ".\n";
			lastNode = lastNode->previous();
			lastNode->next(NULL);
		}

		// insert newItem before the existingNode
		virtual void insert_before(ListNode<DataType>* existingNode, const DataType &newItem) {
			ListNode<int>* node = new ListNode<int>(newItem);

			if (existingNode == NULL) {
				firstNode = node;
				lastNode = node;
				return;
			} else if (firstNode == existingNode) {
				firstNode->previous(node);
				node->next(firstNode);
				firstNode = node;
			} else {
				ListNode<DataType>* prev = existingNode->previous();
				prev->next(node);
				existingNode->previous(node);
				node->previous(prev);
				node->next(existingNode);
			}

			std::cout << node->data() << " inserted before " << existingNode->data() << ".\n";
		}

		// insert newItem after the existingNode
		virtual void insert_after(ListNode<DataType>* existingNode,	const DataType &newItem) {
			ListNode<int>* node = new ListNode<int>(newItem);

			if (existingNode == NULL) {
				firstNode = node;
				lastNode = node;
				return;
			} else if (lastNode == existingNode) {
				node->previous(lastNode);
				lastNode->next(node);
				lastNode = node;
			} else {
				ListNode<DataType>* nxt = existingNode->next();
				existingNode->next(node);
				nxt->previous(node);
				node->previous(existingNode);
				node->next(nxt);
			}

			std::cout << node->data() << " inserted after " << existingNode->data() << ".\n";
		}

		// find the node and return the address to the node. Return nullptr if not found
		virtual ListNode<DataType>* find(const DataType &existingItem) {

			ListNode<DataType>* cursor = firstNode;

			while (cursor != NULL) {
				if (cursor->data() == existingItem) {
					std::cout << "Found data.\n";
					return cursor;
				}
				cursor = cursor->next();
			}

			std::cout << "Could not find data. Returning NULL.\n";
			return NULL;
		}

		// remove the node equal to currentItem
		virtual bool erase(const DataType &currentItem) {
			std::cout << "Attempting to find the node before erasing.\n";
			ListNode<DataType>* node = DoubleLinkedList::find(currentItem);

			if (node == NULL) {
				std::cout << "Could not find node.\n";
				return false;
			}

			std::cout << "Node found. Attempting to erase.\n";
			return DoubleLinkedList::erase(node);
		}

		// remove the node by address existingNode
		virtual bool erase(ListNode<DataType> *existingNode) {

			if (existingNode == NULL) {
				std::cout << "Parameter node is NULL. Returning.\n";
				return true;
			}

			if (firstNode == lastNode) {
				firstNode = NULL;
				lastNode = NULL;
				std::cout << "There is only one node in the list - it has been removed.\n";
				return true;
			}

			if (existingNode == firstNode) {
				DoubleLinkedList::pop_front();
				std::cout << "Node was the first node.\n";
				return true;
			}

			if (existingNode == lastNode) {
				DoubleLinkedList::pop_back();
				std::cout << "Node was the last node.\n";
				return true;
			}

			ListNode<DataType>* prev = existingNode->previous();
			ListNode<DataType>* nxt = existingNode->next();

			if (prev != NULL && nxt != NULL) {
				prev->next(nxt);
				nxt->previous(prev);
				std::cout << "Node was removed.\n";
				return true;
			}
			else {
				std::cout << "Node was isolated from a list. Nothing to remove it from.\n";
				return false;
			}
		}
};

// your implementation code goes here

// note the code for the debug() function is included
// display a debug version of the list
template<class DataType>
void DoubleLinkedList<DataType>::debug(std::ostream &out) const
{
	const unsigned int ADDRWIDTH = 10;
	out << "START DEBUG" << std::endl;
	out << "first  =" << std::setw(ADDRWIDTH) << firstNode;
	out << ", last=" << std::setw(ADDRWIDTH) << lastNode;
	out << ", # nodes=" << size() << std::endl;
	unsigned int count = 1;

	for (auto current=firstNode; current!= nullptr; current=current->next())
	{
		out << "node " << std::setw(2) << count;
		out << "=" << std::setw(ADDRWIDTH) << current;
		out << ", next=" << std::setw(ADDRWIDTH) 
			<< current->next();
		out << ", previous=" << std::setw(ADDRWIDTH) 
			<< current->previous();
		out << ", value=" << current->data() << std::endl;
		count++;
	}
	out << "END DEBUG" << std::endl;
}

#endif /* DOUBLELINKEDLIST_H_ */
