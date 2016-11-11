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

		// default destructor
		~ListNode() {
			std::cout << "ListNode destroyed.\n";
		}

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
			// Return empty if other list is empty
			if (other.empty()) {
				return;
			}

			// Create a cursor for each list
			ListNode<DataType>* cursorO = other.first();
			ListNode<DataType>* cursor = new ListNode<DataType>(cursorO->data());
			
			// Set the first node 
			firstNode = cursor;
			cursorO = cursorO->next();

			// Iterate through the other list and build the new one
			while (cursorO != NULL) {
				ListNode<DataType>* nxt = new ListNode<DataType>(cursorO->data());
				cursor->next(nxt);

				if (nxt != NULL) {
					nxt->previous(cursor);
				} else {
					lastNode = cursor;
				}

				cursor = cursor->next();
				cursorO = cursorO->next();
			}

			numberNodes = other.numberNodes;
		}

		// destructor
		virtual ~DoubleLinkedList() {
			ListNode<DataType>* cursor;
			ListNode<DataType>* node;
			cursor = firstNode;

			while (cursor != NULL) {
				node = cursor;
				cursor = cursor->next();
				delete node;
			}

			std::cout << "Base destructor for DoubleLinkedList called. Deleted all nodes in list\n";
		}

		// return the number of nodes in the list
		std::size_t size() const {
			return numberNodes;
		}

		// return true if the list is empty
		bool empty() const {
			return firstNode == NULL ? true : false;
		}

		// display the contents of the list to std::cout
		void print() const {
			ListNode<DataType>* cursor;
			cursor = firstNode;
						
			std::cout << "(head)";

			if (cursor == NULL) {
				std::cout << "EMPTY(tail)\n";
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
			ListNode<DataType>* node = new ListNode<DataType>(newItem);
			
			// List is empty
			if (firstNode == NULL) {
				firstNode = node;
				lastNode = node;
			} else { // Push to front
				firstNode->previous(node);
				node->next(firstNode);
				firstNode = node;
			}

			numberNodes++;
			std::cout << "Pushed " << node->data() << " to the front.\n";
		}

		// add an item to the back of the list
		virtual void push_back(const DataType &newItem) {
			ListNode<DataType>* node = new ListNode<DataType>(newItem);

			// List is empty
			if (firstNode == NULL) {
				firstNode = node;
				lastNode = node;
			} else { // Push to back
				node->previous(lastNode);
				lastNode->next(node);
				lastNode = node;
			}

			numberNodes++;
			std::cout << "Pushed " << node->data() << " to the back.\n";
		}

		// remove an item from the front of the list
		virtual void pop_front() {
			// List is empty
			if (firstNode == NULL) {
				std::cout << "The list is empty. No nodes were removed.\n";
				return;
			}

			// Only one node in the list
			if (firstNode == lastNode) {
				std::cout << "Removed" << firstNode->data() << " - the only node in the list.\n";
				delete firstNode;
				firstNode = NULL;
				lastNode = NULL;				
			} else { // Pop off the element				
				std::cout << "Popping off first element: " << firstNode->data() << ".\n";
				firstNode = firstNode->next();
				delete firstNode->previous();
				firstNode->previous(NULL);
			}

			numberNodes--;
		}

		// remove an item from the back of the list
		virtual void pop_back() {
			// List is empty
			if (firstNode == NULL) {
				std::cout << "The list is empty. No nodes were removed.\n";
				return;
			}

			// Only one node in the list
			if (firstNode == lastNode) {
				std::cout << "Removed" << firstNode->data() << " - the only node in the list.\n";
				delete firstNode;
				firstNode = NULL;
				lastNode = NULL;
			} else { // Pop off the element				
				std::cout << "Popping off last element: " << lastNode->data() << ".\n";
				lastNode = lastNode->previous();
				delete lastNode->next();
				lastNode->next(NULL);
			}

			numberNodes--;
		}

		// insert newItem before the existingNode
		virtual void insert_before(ListNode<DataType>* existingNode, const DataType &newItem) {
			ListNode<DataType>* node = new ListNode<DataType>(newItem);

			// Argument null
			if (existingNode == NULL) {
				firstNode = node;
				lastNode = node;
				return;
			}
			
			// Argument is first node
			if (firstNode == existingNode) { 
				firstNode->previous(node);
				node->next(firstNode);
				firstNode = node;
			} else { // All other cases
				ListNode<DataType>* prev = existingNode->previous();
				prev->next(node);
				existingNode->previous(node);
				node->previous(prev);
				node->next(existingNode);
			}

			numberNodes++;
			std::cout << node->data() << " inserted before " << existingNode->data() << ".\n";
		}

		// insert newItem after the existingNode
		virtual void insert_after(ListNode<DataType>* existingNode,	const DataType &newItem) {
			ListNode<DataType>* node = new ListNode<DataType>(newItem);

			// Argument null
			if (existingNode == NULL) {
				firstNode = node;
				lastNode = node;
				return;
			}
			
			// Argument is last node
			if (lastNode == existingNode) { 
				node->previous(lastNode);
				lastNode->next(node);
				lastNode = node;
			} else { // All other cases
				ListNode<DataType>* nxt = existingNode->next();
				existingNode->next(node);
				nxt->previous(node);
				node->previous(existingNode);
				node->next(nxt);
			}

			numberNodes++;
			std::cout << node->data() << " inserted after " << existingNode->data() << ".\n";
		}

		// find the node and return the address to the node. Return nullptr if not found
		virtual ListNode<DataType>* find(const DataType &existingItem) {
			// Iterate through the list
			ListNode<DataType>* cursor = firstNode;
			while (cursor != NULL) {
				if (cursor->data() == existingItem) {
					std::cout << "Found data.\n";
					return cursor;
				}
				cursor = cursor->next();
			}

			// Could not find a matching node
			std::cout << "Data not already in list.\n";
			return NULL;
		}

		// remove the node equal to currentItem
		virtual bool erase(const DataType &currentItem) {
			// Find the item with the argument's value
			std::cout << "Attempting to find the node before erasing.\n";
			ListNode<DataType>* node = DoubleLinkedList::find(currentItem);

			// Node was not in the list
			if (node == NULL) {
				std::cout << "Could not find node.\n";
				return false;
			}

			// Call erase(ListNode<DataType>) to handle logic
			std::cout << "Node found. Attempting to erase.\n";
			return DoubleLinkedList::erase(node);
		}

		// remove the node by address existingNode
		virtual bool erase(ListNode<DataType> *existingNode) {

			// Null argument
			if (existingNode == NULL) {
				std::cout << "Parameter node is NULL. Returning.\n";
				return false;
			}

			// Only one node in list
			if (firstNode == lastNode) {
				firstNode = NULL;
				lastNode = NULL;
				delete existingNode;
				std::cout << "There is only one node in the list - it has been removed.\n";
			} else if (existingNode == firstNode) { // Node is first node
				DoubleLinkedList::pop_front();
				std::cout << "Node was the first node.\n";
			} else if (existingNode == lastNode) { // Node is last node
				DoubleLinkedList::pop_back();
				std::cout << "Node was the last node.\n";
			}
			else {// Node is somewhere in the middle of the list
				ListNode<DataType>* prev = existingNode->previous();
				ListNode<DataType>* nxt = existingNode->next();

				if (prev != NULL && nxt != NULL) {
					prev->next(nxt);
					nxt->previous(prev);
					delete existingNode;
					std::cout << "Node was removed.\n";
				}
				else { // Node is not in a list
					std::cout << "Node was isolated from a list. Nothing to remove it from.\n";
					delete existingNode;
					return false;
				}
			}

			numberNodes--;
			return true;
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
